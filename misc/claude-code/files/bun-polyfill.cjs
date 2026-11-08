// bun-polyfill.cjs - the Bun runtime APIs, implemented on top of Node.
//
// Loaded with "node --require" ahead of the ESM entry point, so that the
// Bun-targeted build of claude-code runs under FreeBSD's native node -- and
// imported again by that entry point itself, because claude-code relaunches
// itself as "node cli ..." without our --require (see scripts/post-extract).
// Whichever comes first does the work; the second finds it done.
'use strict';

const LOADED = Symbol.for('freebsd-ports.claude-code.bun-polyfill');

if (globalThis[LOADED])
	return;
globalThis[LOADED] = true;

const { spawn, execFileSync } = require('child_process');
const fs = require('fs');
const path = require('path');
const http = require('http');
const net = require('net');
const crypto = require('crypto');
const os = require('os');

// Bun.Image, from graphics/node-bun-image: Bun's own codec sources behind the
// same chainable API, so the image parts of the bundle work rather than falling
// back to sending an unresized original (or refusing one that is over the API
// limits).
//
// Resolved relative to this file rather than by bare name, so nothing has to
// put ${PREFIX}/lib/node_modules on NODE_PATH: this file lives in
// .../node_modules/@anthropic-ai/claude-code, and the package is two
// directories up. The bare-name require is a fallback for anyone who has set
// NODE_PATH, or who has the package somewhere else.
//
// The package is optional and is deliberately not a dependency of this port, so
// not having it is the ordinary case. Failing to load it must therefore never be
// fatal: whatever goes wrong -- not installed, installed but its native addon
// will not load against this node, installed but broken -- the global is simply
// left undefined, which is the state the bundle already copes with. Every
// Bun.Image call site sits inside a try whose catch degrades to sending the
// image unprocessed, so an image already inside the API's size and dimension
// limits still goes through untouched, and a larger one is refused with a clear
// message rather than resized.
let bunImage;

for (const spec of ['../../bun-image', 'bun-image']) {
	try {
		const image = require(spec).Image;

		// Only stop looking once something usable turned up: a
		// package that loads but exports no Image must not shadow
		// one further along.
		if (image) {
			bunImage = image;
			break;
		}
	} catch {
		/* not there, or not loadable here; that is allowed */
	}
}

// Matches the CSI sequences that carry no width of their own.
const ANSI_RE = /\x1B\[[0-9;]*[mGKHFJRABCDEFMPXZ]/g;

// The Buffer a stream was collected into owns a slice of a larger pool, so
// hand back just this buffer's own bytes.
function toArrayBuffer(buf)
{
	return (buf.buffer.slice(buf.byteOffset,
	    buf.byteOffset + buf.byteLength));
}

const COMBINING_RE = /^\p{M}$/u;

// Bun.stringWidth - visual column width. Control characters count for
// nothing, East Asian wide characters and emoji for two.
function stringWidth(str, _opts)
{
	const s = String(str).replace(ANSI_RE, '');
	let w = 0;

	for (const ch of s) {
		const cp = ch.codePointAt(0);

		if (cp <= 0x1f || (cp >= 0x7f && cp <= 0x9f))
			continue;
		// Combining marks hang off the glyph before them and take no
		// column of their own, so a decomposed accent -- e followed by
		// U+0301 -- is one column wide, not two.
		if (COMBINING_RE.test(ch))
			continue;
		// Joiners and format characters hold an emoji sequence
		// together without being drawn themselves. xterm, asked
		// directly with a cursor-position report, reserves four
		// columns for a woman-technologist: two, nothing, two.
		if (cp === 0x200d || (cp >= 0x200b && cp <= 0x200f) ||
		    cp === 0xfeff)
			continue;
		if ((cp >= 0x1100 && cp <= 0x115f) ||
		    cp === 0x2329 || cp === 0x232a ||
		    (cp >= 0x2e80 && cp <= 0x303e) ||
		    (cp >= 0x3040 && cp <= 0xa4c6) ||
		    (cp >= 0xa960 && cp <= 0xa97c) ||
		    (cp >= 0xac00 && cp <= 0xd7a3) ||
		    (cp >= 0xf900 && cp <= 0xfaff) ||
		    (cp >= 0xfe10 && cp <= 0xfe19) ||
		    (cp >= 0xfe30 && cp <= 0xfe6b) ||
		    (cp >= 0xff01 && cp <= 0xff60) ||
		    (cp >= 0xffe0 && cp <= 0xffe6) ||
		    (cp >= 0x1f300 && cp <= 0x1f9ff) ||
		    (cp >= 0x20000 && cp <= 0x3fffd))
			w += 2;
		else
			w += 1;
	}
	return (w);
}

// Bun.stripANSI
function stripANSI(str)
{
	return (String(str).replace(ANSI_RE, ''));
}

// Bun.wrapAnsi - word wrap that measures with stringWidth(), so that ANSI
// sequences do not count towards the column budget.
function wrapAnsi(str, width, _opts)
{
	if (!str)
		return (str);

	const lines = String(str).split('\n');
	const result = [];

	for (const line of lines) {
		if (stringWidth(line) <= width) {
			result.push(line);
			continue;
		}

		let cur = '';
		let curW = 0;

		for (const word of line.split(' ')) {
			const ww = stringWidth(word);

			if (curW + (cur ? 1 : 0) + ww > width && cur) {
				result.push(cur);
				cur = word;
				curW = ww;
			} else {
				cur = cur ? cur + ' ' + word : word;
				curW += (cur === word ? 0 : 1) + ww;
			}
		}
		if (cur)
			result.push(cur);
	}
	return (result.join('\n'));
}

// Bun.sliceAnsi - slice by visible columns, carrying the SGR state across the
// cut so the piece keeps its colours. The renderer clips every line to the
// viewport with this, and a missing one costs no error at all: it just paints
// nothing, which is what an unpolyfilled 2.1.282 does.
function sliceAnsi(str, begin, end)
{
	const s = String(str);
	const to = end === undefined ? Infinity : end;
	let out = '';
	let col = 0;
	let i = 0;

	while (i < s.length) {
		if (s[i] === '\x1B') {
			const m = /^\x1B\[[0-9;]*[A-Za-z]/.exec(s.slice(i));
			const seq = m ? m[0] : s[i];

			// Escapes occupy no columns, so they are kept wherever
			// they fall, including ahead of the slice.
			out += seq;
			i += seq.length;
			continue;
		}

		const ch = String.fromCodePoint(s.codePointAt(i));
		const w = stringWidth(ch);

		if (col >= to)
			break;
		if (col >= begin)
			out += ch;
		col += w;
		i += ch.length;
	}
	return (out);
}

// Bun.sleepSync - block for a number of milliseconds. Atomics.wait parks the
// thread rather than spinning it.
function sleepSync(ms)
{
	const t = Number(ms) || 0;

	if (t > 0)
		Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, t);
}

// Bun.hash - a SHA-256 prefix as a BigInt, with the named digests hung off
// it. Nothing here needs the real xxHash, only a stable value.
function bunHashCore(data)
{
	const buf = Buffer.isBuffer(data) ? data : Buffer.from(String(data));
	const h = crypto.createHash('sha256').update(buf).digest('hex');

	return (BigInt('0x' + h.slice(0, 16)));
}

bunHashCore.xxHash64 = bunHashCore;

bunHashCore.xxHash32 = (data, _seed) => {
	const buf = Buffer.isBuffer(data) ? data : Buffer.from(String(data));

	const h = crypto.createHash('sha256').update(buf).digest();

	return (h.readUInt32BE(0));
};

bunHashCore.adler32 = (data) => {
	const buf = Buffer.isBuffer(data) ? data : Buffer.from(String(data));
	let a = 1, b = 0;

	for (let i = 0; i < buf.length; i++) {
		a = (a + buf[i]) % 65521;
		b = (b + a) % 65521;
	}
	return ((b << 16) | a);
};

// Bun.spawn - a child_process shim.
//
// Bun hands back a process whose stdout and stderr are readable streams with
// .text() and .arrayBuffer() on them, so attach those to node's streams.
function makeReadableWithHelpers(nodeStream)
{
	if (!nodeStream)
		return (null);

	const collect = () => new Promise((resolve, reject) => {
		const chunks = [];

		nodeStream.on('data', (c) => chunks.push(c));
		nodeStream.on('end', () => resolve(Buffer.concat(chunks)));
		nodeStream.on('error', reject);
	});

	nodeStream.text = () => collect().then((buf) => buf.toString('utf8'));
	nodeStream.arrayBuffer = () => collect().then(toArrayBuffer);

	return (nodeStream);
}

// Anything node does not recognise, including the absent option, becomes a
// pipe -- which is what Bun does with it too.
function stdioMode(mode)
{
	if (mode === 'pipe' || mode === 'inherit' || mode === 'ignore')
		return (mode);
	return ('pipe');
}

function bunSpawn(command, opts)
{
	opts = opts || {};

	let exe, args;

	if (Array.isArray(command)) {
		[exe, ...args] = command;
	} else {
		exe = command;
		args = [];
	}

	// The PTY option is ignored: a real terminal is handled out of line,
	// by the --bg-pty-host subprocess.
	const spawnOpts = {
		cwd: opts.cwd || process.cwd(),
		env: opts.env || process.env,
		stdio: [
		    stdioMode(opts.stdin),
		    stdioMode(opts.stdout),
		    stdioMode(opts.stderr),
		],
	};

	let proc;

	try {
		proc = spawn(exe, args, spawnOpts);
	} catch (e) {
		// A pseudo-process that has already failed.
		return ({
			pid: -1,
			stdin: null,
			stdout: null,
			stderr: null,
			exited: Promise.resolve(1),
			exitCode: 1,
			signalCode: null,
			kill: () => {},
			ref: () => {},
			unref: () => {},
		});
	}

	const exitedPromise = new Promise((resolve) => {
		proc.on('close', (code, sig) => resolve(code ?? (sig ? 1 : 0)));
		proc.on('error', () => resolve(1));
	});

	const result = {
		pid: proc.pid,
		stdin: proc.stdin || null,
		stdout: makeReadableWithHelpers(proc.stdout),
		stderr: makeReadableWithHelpers(proc.stderr),
		exited: exitedPromise,
		exitCode: null,
		signalCode: null,
		kill: (sig) => {
			try {
				proc.kill(sig);
			} catch {}
		},
		ref: () => {},
		unref: () => {
			proc.unref();
		},
	};

	exitedPromise.then((code) => {
		result.exitCode = code;
	});

	return (result);
}

// Bun.which
function bunWhich(cmd, _opts)
{
	try {
		const r = execFileSync('/usr/bin/which', [cmd], {
			encoding: 'utf8',
			stdio: ['ignore', 'pipe', 'ignore'],
		});

		return (r.trim() || null);
	} catch {
		return (null);
	}
}

// Bun.file - a BunFile-alike over fs.
function bunFile(src, _opts)
{
	const fpath = typeof src === 'string' ? src :
	    (src && src.path) ? src.path : String(src);

	return ({
		path: fpath,
		exists: async () => {
			try {
				await fs.promises.access(fpath);
				return (true);
			} catch {
				return (false);
			}
		},
		text: () => fs.promises.readFile(fpath, 'utf8'),
		json: () => fs.promises.readFile(fpath, 'utf8')
		    .then(JSON.parse),
		arrayBuffer: () => fs.promises.readFile(fpath)
		    .then(toArrayBuffer),
		bytes: () => fs.promises.readFile(fpath),
		stream: () => fs.createReadStream(fpath),
		// Bun's Blob#image(), which Bun.file() inherits: shorthand for
		// new Bun.Image(this). The path is handed over rather than the
		// bytes, so the read happens off-thread at terminal time the way
		// it does on Bun. Absent when Bun.Image is, so the shape still
		// matches what the rest of this object promises.
		...(bunImage ? { image: () => new bunImage(fpath) } : {}),
		get size() {
			try {
				return (fs.statSync(fpath).size);
			} catch {
				return (0);
			}
		},
		type: 'application/octet-stream',
		writer: () => {
			const ws = fs.createWriteStream(fpath);

			return ({
				write: (d) => ws.write(d),
				end: () => new Promise((r) => ws.end(r)),
			});
		},
	});
}

// Bun.write
function bunWrite(dest, data)
{
	const fpath = typeof dest === 'string' ? dest :
	    (dest && dest.path) ? dest.path : null;

	if (!fpath)
		return (Promise.resolve(0));

	const content = typeof data === 'string' ?
	    Buffer.from(data, 'utf8') :
	    Buffer.isBuffer(data) ? data : Buffer.from(String(data));

	return (fs.promises.writeFile(fpath, content)
	    .then(() => content.length));
}

// Bun.serve - a Fetch-API server on top of http.createServer().
function bunServe(opts)
{
	opts = opts || {};

	const hostname = opts.hostname || '127.0.0.1';
	const requestedPort = opts.port || 0;

	const server = http.createServer(async (req, res) => {
		if (!opts.fetch) {
			res.writeHead(501);
			res.end();
			return;
		}

		const chunks = [];

		req.on('data', (c) => chunks.push(c));
		await new Promise((r) => req.on('end', r));

		const body = chunks.length ? Buffer.concat(chunks) : null;
		const port = server.address()?.port ?? requestedPort;
		const url = `http://${hostname}:${port}${req.url}`;
		const headers = Object.fromEntries(
		    Object.entries(req.headers).map(([k, v]) =>
		    [k, Array.isArray(v) ? v.join(', ') : v]));

		let request;

		try {
			request = new Request(url, {
				method: req.method,
				headers,
				...(body ? { body } : {}),
			});
		} catch {
			res.writeHead(400);
			res.end();
			return;
		}

		try {
			const response = await opts.fetch(request, bunServer);

			if (!(response instanceof Response)) {
				res.writeHead(204);
				res.end();
				return;
			}

			const respHeaders = {};

			response.headers.forEach((v, k) => {
				respHeaders[k] = v;
			});
			res.writeHead(response.status, respHeaders);
			res.end(Buffer.from(await response.arrayBuffer()));
		} catch (e) {
			if (opts.error) {
				try {
					opts.error(e);
				} catch {}
			}
			res.writeHead(500);
			res.end(String(e));
		}
	});

	if (opts.error)
		server.on('error', opts.error);
	server.listen(requestedPort, hostname);

	// Referenced by the request handler above, which cannot run until
	// listen() has taken effect, by which point this is assigned.
	const bunServer = {
		get port() {
			return (server.address()?.port ?? requestedPort);
		},
		hostname,
		stop: (_force) => new Promise((r) => server.close(r)),
		ref: () => server.ref(),
		unref: () => server.unref(),
		reload: () => {},
		fetch: opts.fetch,
	};

	return (bunServer);
}

// Bun.connect / Bun.listen - TCP and UNIX socket shims.
function makeBunSocket(sock, handlers)
{
	const bs = {
		data: sock,
		write: (d) => sock.write(d),
		end: () => sock.end(),
		ref: () => {
			sock.ref();
			return (bs);
		},
		unref: () => {
			sock.unref();
			return (bs);
		},
	};

	sock.on('data', (d) => {
		if (handlers?.data)
			handlers.data(bs, d);
	});
	sock.on('error', (e) => {
		if (handlers?.error)
			handlers.error(bs, e);
	});
	sock.on('close', () => {
		if (handlers?.close)
			handlers.close(bs);
	});

	return (bs);
}

function bunConnect(opts)
{
	opts = opts || {};

	return (new Promise((resolve, reject) => {
		const connOpts = opts.unix ? { path: opts.unix } :
		    { host: opts.hostname || 'localhost', port: opts.port };
		const sock = net.createConnection(connOpts);
		const bs = makeBunSocket(sock, opts.socket);

		sock.on('connect', () => {
			if (opts.socket?.open)
				opts.socket.open(bs);
			resolve(bs);
		});
		sock.on('error', (e) => {
			if (opts.socket?.error)
				opts.socket.error(bs, e);
			reject(e);
		});
	}));
}

function bunListen(opts)
{
	opts = opts || {};

	const srv = net.createServer((sock) => {
		const bs = makeBunSocket(sock, opts.socket);

		if (opts.socket?.open)
			opts.socket.open(bs);
	});

	if (opts.unix)
		srv.listen(opts.unix);
	else
		srv.listen(opts.port || 0, opts.hostname || '0.0.0.0');

	return ({
		stop: () => new Promise((r) => srv.close(r)),
		ref: () => srv.ref(),
		unref: () => srv.unref(),
	});
}

// Bun.deepEquals
function deepEquals(a, b, _strict)
{
	if (a === b)
		return (true);
	if (a === null || b === null)
		return (a === b);
	if (typeof a !== typeof b)
		return (false);

	if (Array.isArray(a)) {
		if (!Array.isArray(b) || a.length !== b.length)
			return (false);
		return (a.every((v, i) => deepEquals(v, b[i])));
	}

	if (typeof a === 'object') {
		const ka = Object.keys(a);
		const kb = Object.keys(b);

		if (ka.length !== kb.length)
			return (false);
		return (ka.every((k) => deepEquals(a[k], b[k])));
	}

	return (false);
}

// Bun.semver
const bunSemver = {
	order: (a, b) => {
		const pa = String(a).replace(/-.*$/, '').split('.').map(Number);
		const pb = String(b).replace(/-.*$/, '').split('.').map(Number);

		for (let i = 0; i < 3; i++) {
			if ((pa[i] || 0) !== (pb[i] || 0))
				return ((pa[i] || 0) > (pb[i] || 0) ? 1 : -1);
		}
		return (0);
	},
	// Optimistic: every version satisfies every range.
	satisfies: (_v, _r) => true,
};

// Bun.YAML / Bun.TOML / Bun.JSONL - minimal parsers, good for flat
// key/value input only. The real implementations are preferred below.
// "key: value", with the leading indentation captured so that anything
// nested can be skipped.
const YAML_LINE_RE = /^(\s*)([^#:\s][^:]*?)\s*:\s*(.*)$/;

const bunYAML = {
	parse: (str) => {
		const obj = {};

		for (const line of String(str).split('\n')) {
			const m = line.match(YAML_LINE_RE);

			// Skip the indented and the malformed.
			if (!m || m[1])
				continue;

			const v = m[3].trim();

			obj[m[2].trim()] =
			    v === 'true' ? true :
			    v === 'false' ? false :
			    v === 'null' ? null :
			    v.startsWith('"') || v.startsWith("'") ?
			    v.slice(1, -1) :
			    isNaN(v) || v === '' ? v : Number(v);
		}
		return (obj);
	},
	stringify: (obj) => Object.entries(obj)
	    .map(([k, v]) => `${k}: ${JSON.stringify(v)}`)
	    .join('\n') + '\n',
};

const bunTOML = {
	parse: (str) => {
		const obj = {};

		for (const line of String(str).split('\n')) {
			const m = line.match(
			    /^([a-zA-Z_][a-zA-Z0-9_-]*)\s*=\s*(.+)$/);

			if (!m)
				continue;

			const v = m[2].trim();

			obj[m[1]] =
			    v === 'true' ? true :
			    v === 'false' ? false :
			    (v.startsWith('"') || v.startsWith("'")) ?
			    v.slice(1, -1) :
			    !isNaN(v) ? Number(v) : v;
		}
		return (obj);
	},
};

// Bun.JSONL.parseChunk has to return {values, error, done, read}, an
// incremental parse result. Leaving it undefined makes the bundle fall back
// to its own De()/ze() buffer parsers, which is what we want.
const bunJSONL = {};

// Bun.Transpiler - stub. Nothing in the extracted tree imports a TypeScript
// transpiler, so this only has to exist, not work.
class BunTranspiler {
	constructor(_opts) {}
	transform(code) {
		return ({ code, map: null });
	}
	transformSync(code) {
		return (code);
	}
	scan(_code) {
		return ({ exports: [], imports: [] });
	}
	scanImports(_code) {
		return ([]);
	}
}

// Bun.Terminal - stub. The real PTY runs in the --bg-pty-host subprocess.
class BunTerminal {
	constructor(_opts) {
		this._buf = [];
	}
	write(data) {
		process.stdout.write(data);
	}
	resize(_cols, _rows) {}
	get bufferedAmount() {
		return (0);
	}
}

// localStorage - the Web Storage API, backed by a file.
//
// Bun provides this through --localstorage-file; keep the JSON in the
// directory claude-code already uses for its own state.
function makeLocalStorage()
{
	const dir = path.join(os.homedir(), '.claude');
	const file = path.join(dir, 'localstorage.json');

	let store = {};

	try {
		fs.mkdirSync(dir, { recursive: true });
		if (fs.existsSync(file))
			store = JSON.parse(fs.readFileSync(file, 'utf8'));
	} catch {}

	function persist()
	{
		try {
			fs.writeFileSync(file, JSON.stringify(store), 'utf8');
		} catch {}
	}

	return ({
		get length() {
			return (Object.keys(store).length);
		},
		key(i) {
			return (Object.keys(store)[i] ?? null);
		},
		getItem(k) {
			return (Object.prototype.hasOwnProperty.call(store, k) ?
			    store[k] : null);
		},
		setItem(k, v) {
			store[String(k)] = String(v);
			persist();
		},
		removeItem(k) {
			delete store[k];
			persist();
		},
		clear() {
			store = {};
			persist();
		},
	});
}

globalThis.localStorage = makeLocalStorage();

// Install the global Bun object.
globalThis.Bun = {
	version: '1.2.0',
	revision: 'node-polyfill',

	isStandaloneExecutable: false,

	// The entry point's absolute path. Bun fills this in before any user
	// code runs; node has process.argv[1] ready by the time a --require'd
	// module loads, so it can be taken once here.
	main: process.argv[1] ? path.resolve(process.argv[1]) : undefined,

	// Hashing
	hash: bunHashCore,

	// String utilities
	stringWidth,
	sliceAnsi,
	sleepSync,
	stripANSI,
	wrapAnsi,

	// Process
	spawn: bunSpawn,
	which: bunWhich,

	// File system
	file: bunFile,
	write: bunWrite,

	// Stdin
	stdin: { stream: process.stdin },

	// Networking
	serve: bunServe,
	connect: bunConnect,
	listen: bunListen,

	// Equality
	deepEquals,

	// Semver
	semver: bunSemver,

	// Parsers
	YAML: bunYAML,
	TOML: bunTOML,
	JSONL: bunJSONL,

	// Transpiler
	Transpiler: BunTranspiler,

	// Terminal / PTY
	Terminal: BunTerminal,

	// Images. Undefined when graphics/node-bun-image is not installed; see
	// the loader above.
	Image: bunImage,

	// Bun.unsafe -- JavaScriptCore knobs with no node equivalent. Only
	// setJITPolicy is called, as `Bun.unsafe.setJITPolicy?.(1)`: the optional
	// call guards the function, not the property lookup ahead of it, so an
	// absent Bun.unsafe throws where a no-op costs nothing. 2.1.282 reached
	// it from three separate spots on the way up, and the throw read as
	// "Claude Code exited after an unrecoverable interface error".
	unsafe: {
		setJITPolicy: (_policy) => {},
	},

	// Memory and GC
	gc: (_full) => {
		if (typeof global.gc === 'function')
			global.gc();
	},
	generateHeapSnapshot: (dest) => {
		try {
			return (require('v8').writeHeapSnapshot(dest));
		} catch {
			return (null);
		}
	},

	// Not needed for CLI operation.
	SQL: null,

	// macOS-only in the real Bun.
	WebView: { closeAll: () => {} },

	// Anthropic's own Bun extensions.
	ant: {
		get memoryPressureLevel() {
			return (0);
		},
		setDumpable: () => {},
		getPeerPid: (_sock) => null,
		getPeerUid: (_sock) => null,
	},

	// Miscellany the bundle refers to.
	readableStreamToText: async (stream) => {
		const chunks = [];

		for await (const c of stream)
			chunks.push(Buffer.from(c));
		return (Buffer.concat(chunks).toString('utf8'));
	},
	readableStreamToArrayBuffer: async (stream) => {
		const chunks = [];

		for await (const c of stream)
			chunks.push(Buffer.from(c));
		return (toArrayBuffer(Buffer.concat(chunks)));
	},

	password: {
		hash: async (p) => crypto.createHash('sha256')
		    .update(String(p)).digest('hex'),
		verify: async (p, h) => crypto.createHash('sha256')
		    .update(String(p)).digest('hex') === h,
	},

	CryptoHasher: class {
		constructor(alg) {
			this._h = crypto.createHash(
			    alg === 'SHA-1' ? 'sha1' : alg.toLowerCase());
		}
		update(d) {
			this._h.update(d);
			return (this);
		}
		digest(enc) {
			return (this._h.digest(enc || 'hex'));
		}
	},

	// Bun.SHA256, used as Bun.SHA256.hash(bytes, "base64") to key the
	// prompt-cache breakpoints. Bun's digest returns raw bytes when no
	// encoding is named and a string when one is, and the hash is a static
	// on the class rather than a free function, so keep both shapes:
	// 2.1.288 calls only the static, but the instance form is what the
	// class is for and costs three lines.
	SHA256: class {
		static byteLength = 32;

		static hash(input, enc) {
			const h = crypto.createHash('sha256').update(input);

			return (enc ? h.digest(enc)
			    : new Uint8Array(h.digest()));
		}

		constructor() {
			this._h = crypto.createHash('sha256');
		}
		update(d) {
			this._h.update(d);
			return (this);
		}
		digest(enc) {
			return (enc ? this._h.digest(enc)
			    : new Uint8Array(this._h.digest()));
		}
	},

	// Bun.env is process.env.
	env: process.env,
};

// Bun's import.meta.require, exposed as a global.
//
// Node has no per-module hook for import.meta.require, so post-extract
// rewrites every call site to globalThis.__bunRequire instead. Every call
// site resolves a sibling of this file, so one require rooted at this
// file's directory serves all of them.
//
// Two things Bun does here that node will not:
//
//   - Cycles. These chunks import each other circularly, and node refuses
//     require() of an ES module that is still mid-evaluation
//     (ERR_REQUIRE_CYCLE_MODULE) where Bun hands back the live namespace.
//     Deferring the require to the first property access does not cover it,
//     because the call sites read their export at once -- the shape is
//     `var T = __bunRequire("./chunk-x.js").SomeTool` -- and so capture
//     whatever is there while the cycle is still open. Each export is
//     therefore handed back as a proxy of its own, forwarding to the real
//     value once the graph settles. 2.1.258 made this fatal rather than
//     merely degraded: an undefined entry reached a tool list that is mapped
//     over unguarded, and claude died on startup with "Cannot read
//     properties of undefined (reading 'name')".
//
//   - Text assets. Bun resolves import.meta.require of a .md or .txt sibling
//     to the contents of the file, which the call sites use as a string;
//     node parses it as JavaScript and throws. Read the file instead, or
//     the prompts built from those assets come out empty.
const { createRequire } = require('module');
const bunReq = createRequire(__filename);

// Stands in for module[name] until the module can be loaded, forwarding on
// every use, so that a binding captured mid-cycle still ends up at the real
// export. The target is an arrow function to keep callable exports callable:
// unlike a plain function it brings no non-configurable own property that
// ownKeys() would then be obliged to report.
const bunLazyExport = (load, name) => {
	const value = () => load()?.[name];

	return (new Proxy(() => {}, {
		get: (_, prop) => value()?.[prop],
		set: (_, prop, val) => {
			const v = value();
			if (v !== undefined && v !== null)
				v[prop] = val;
			return (true);
		},
		has: (_, prop) => prop in (value() ?? {}),
		ownKeys: () => Reflect.ownKeys(value() ?? {}),
		getOwnPropertyDescriptor: (_, prop) => {
			const v = value();
			if (v === undefined || v === null || !(prop in v))
				return (undefined);
			return ({
				value: v[prop],
				enumerable: true,
				configurable: true,
				writable: true,
			});
		},
		apply: (_, self, args) => Reflect.apply(value(), self, args),
		construct: (_, args) => Reflect.construct(value(), args),
	}));
};

globalThis.__bunRequire = function (spec) {
	// The .md, .txt and .mjs siblings of the chunks are text assets that Bun
	// hands back as strings, and node must not be asked to require() them: it
	// will not refuse an .mjs, it will run it. One of the two -- runner-scaffold
	// -- creates directories and starts work from the current directory as soon
	// as it is loaded, so requiring it where the bundle only wanted its text
	// turns reading a template into running a script in the user's project.
	//
	// Only those three extensions, and only on a path: the same shim is handed
	// bare builtin names ("util", "stream", "fs"), which are modules, and
	// .node addons, which are not text and must keep failing as before.
	//
	// Reported by Grzegorz Junka, of the Yoonka ports overlay.
	if (/^[.\/].*\.(md|txt|mjs)$/.test(spec)) {
		try {
			return (fs.readFileSync(path.resolve(__dirname, spec),
			    'utf8'));
		} catch (e) {
			return ({ default: '' });
		}
	}

	try {
		return (bunReq(spec));
	} catch (e) {
		if (e.code !== 'ERR_REQUIRE_CYCLE_MODULE') {
			// Not a cycle, so the only other thing Bun loads here that
			// node will not is a text asset.
			try {
				return (fs.readFileSync(path.resolve(__dirname, spec),
				    'utf8'));
			} catch (_) {
				return ({ default: '' });
			}
		}

		let cached = null;

		// A failure is never cached: the cycle closes later on, and every
		// access after that has to reach the real namespace.
		const resolve = () => {
			if (cached === null) {
				try {
					cached = bunReq(spec);
				} catch (_) { }
			}
			return (cached);
		};

		return (new Proxy({}, {
			get: (_, prop) => {
				const mod = resolve();
				if (mod !== null && prop in mod)
					return (mod[prop]);
				// Still mid-cycle. Named exports become
				// forwarders; `then` is left alone so that the
				// namespace is never taken for a thenable.
				if (typeof prop !== 'string' || prop === 'then')
					return (undefined);
				return (bunLazyExport(resolve, prop));
			},
			has: (_, prop) => prop in (resolve() ?? {}),
			ownKeys: () => Reflect.ownKeys(resolve() ?? {}),
			getOwnPropertyDescriptor: (_, prop) => ({
				value: resolve()?.[prop],
				enumerable: true,
				configurable: true,
				writable: true,
			}),
		}));
	}
};

// Prefer the real npm implementations of the text-measuring and wrapping
// helpers over the approximations above.
//
// Before upstream moved to Bun (2.1.210 or so) the released cli.js bundled
// string-width and wrap-ansi; the identifiers ambiguousIsNarrow and
// countAnsiEscapeCodes are still visible in 2.1.110. Those packages handle
// cases the approximations here do not -- notably re-opening SGR state after
// a wrap, without which a bold span crossing a line boundary bleeds into the
// lines that follow. They are ESM, but node >= 22.12 can require() a
// synchronous ES module, so a plain require works from this CommonJS preload.
// How wide an emoji sequence is turns out to be a property of the terminal,
// not of Unicode: xterm, asked with a cursor-position report, reserves four
// columns for a skin-toned thumb because it counts code points, while any
// terminal implementing grapheme clustering reserves two. string-width
// answers two. Neither answer is right everywhere and the port cannot know
// which terminal it will run under, so this keeps the library's answer
// rather than tuning to one emulator. The cost is that a code span sitting
// immediately after an emoji can have its colour land a couple of columns
// off under xterm; the text itself is placed correctly.
try {
	const sw = require('string-width');
	const f = typeof sw === 'function' ? sw : sw.default;

	if (typeof f === 'function') {
		globalThis.Bun.stringWidth = (s, opts) =>
		    (s == null ? 0 : f(String(s), opts));
	}
} catch (e) { /* keep the built-in approximation */ }

try {
	const wa = require('wrap-ansi');
	const f = typeof wa === 'function' ? wa : wa.default;

	if (typeof f === 'function') {
		// wrap-ansi expands tabs to spaces; Bun's wrapAnsi leaves them
		// alone. That difference is not cosmetic: the caller wraps the
		// plain text, then re-applies the styling to the wrapped lines
		// at offsets it computed against the string it passed in. Hand
		// back a string in which one tab has become several spaces and
		// every one of those offsets is short by the difference, so the
		// code spans in the paragraphs after a tab-indented block open
		// and close mid-word. Carry the tabs through as a zero-width
		// control character -- string-width scores it the same as a
		// tab, so the wrap points do not move -- and restore them.
		globalThis.Bun.wrapAnsi = (s, width, opts) => {
			if (!s)
				return (s);

			const str = String(s);

			if (!str.includes('\t') || str.includes('\x01'))
				return (f(str, width, opts));

			return (f(str.replaceAll('\t', '\x01'), width, opts)
			    .replaceAll('\x01', '\t'));
		};
	}
} catch (e) { /* keep the built-in approximation */ }

try {
	const sl = require('slice-ansi');
	const f = typeof sl === 'function' ? sl : sl.default;

	if (typeof f === 'function') {
		globalThis.Bun.sliceAnsi = (s, begin, end) =>
		    (s == null ? s : f(String(s), begin, end));
	}
} catch (e) { /* keep the built-in approximation */ }

try {
	const sa = require('strip-ansi');
	const f = typeof sa === 'function' ? sa : sa.default;

	if (typeof f === 'function') {
		globalThis.Bun.stripANSI = (s) =>
		    (s == null ? s : f(String(s)));
	}
} catch (e) { /* keep the built-in approximation */ }

// Same rationale for the structured-data helpers. The approximations above
// are only good enough for flat key/value input:
//
//   - YAML backs skill, command and agent frontmatter, where a list-valued
//     allowed-tools or a nested settings block collapsed to an empty string.
//   - semver.satisfies() answered true for every range, and order() ignored
//     prerelease tags, so 1.0.0-alpha and 1.0.0 compared equal.
//   - deepEquals missed Date, RegExp, Map, Set, NaN and the typed arrays,
//     all of which node's own util.isDeepStrictEqual handles.
try {
	const y = require('yaml');

	if (y && typeof y.parse === 'function') {
		globalThis.Bun.YAML = {
			parse: (s, opts) => y.parse(String(s), opts),
			stringify: (v, opts) => y.stringify(v, opts),
		};
	}
} catch (e) { /* keep the built-in approximation */ }

try {
	const sv = require('semver');

	if (sv && typeof sv.satisfies === 'function') {
		globalThis.Bun.semver = {
			order: (a, b) => sv.compare(String(a), String(b)),
			satisfies: (v, r) => sv.satisfies(String(v), String(r),
			    { includePrerelease: true }),
		};
	}
} catch (e) { /* keep the built-in approximation */ }

try {
	const { isDeepStrictEqual } = require('util');

	if (typeof isDeepStrictEqual === 'function') {
		globalThis.Bun.deepEquals = (a, b, _strict) =>
		    isDeepStrictEqual(a, b);
	}
} catch (e) { /* keep the built-in approximation */ }

// Bun.zstdDecompress / zstdDecompressSync, new in 2.1.251 and used to read
// the zstd-compressed cache files. Node has had native zstd in zlib since 22,
// and both call sites want a Buffer back so they can .toString('utf8') it.
try {
	const zlib = require('zlib');
	const { promisify } = require('util');

	if (typeof zlib.zstdDecompressSync === 'function') {
		globalThis.Bun.zstdDecompressSync = (data, opts) =>
		    zlib.zstdDecompressSync(data, opts);
	}
	if (typeof zlib.zstdDecompress === 'function') {
		const zstdAsync = promisify(zlib.zstdDecompress);

		globalThis.Bun.zstdDecompress = (data, opts) =>
		    (opts ? zstdAsync(data, opts) : zstdAsync(data));
	}
} catch (e) { /* no zstd support in this node build */ }

// Bun.ant.CellSegmenter, which the Ink renderer has built its cell grid
// through since 2.1.271. The implementation is clawgod's, installed beside
// this file by the port -- see the Makefile for why it is not written here.
// Requiring it is what installs it: the module assigns onto Bun.ant and
// no-ops when a real implementation is already in place. Releases before
// 2.1.271 never ask for it, so an absent file is not an error.
try {
	require('./bun-ant-shim.cjs');
} catch (e) { /* older release, or shim not installed */ }
