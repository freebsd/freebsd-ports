#!/usr/bin/env python3
# Copyright (c) 2026 The FreeBSD Ports Project
# SPDX-License-Identifier: BSD-2-Clause
#
# A caching, resuming stand-in for the npm registry, for the pnpm install in
# this port's pre-configure (and for "make gen-node-modules").
#
# brave-core pulls in about 1700 packages, a few of which are tens of megabytes.
# pnpm gives up on a slow tarball and starts it again from zero, so on a link
# that cannot hold a connection long enough the install never finishes.  With a
# frozen lockfile pnpm resolves nothing over the network -- it asks only for
# tarballs, by a path it derives from the registry URL -- so those requests can
# be served from here instead:
#
#     python3 npm-fetch-proxy.py --cache ~/npm-cache &
#     cd .../work/brave-browser-*/src/brave
#     corepack pnpm install --frozen-lockfile --registry=http://127.0.0.1:8899
#
# Anything already in the cache is served from disk.  Anything else is fetched
# with a byte range request that picks up where the last attempt stopped, over
# as many attempts as it takes, and is only handed to pnpm once it is complete,
# so pnpm sees a fast, reliable registry and its integrity check still decides
# whether the bytes are good.  Interrupting and re-running loses nothing.

import argparse
import http.server
import os
import shutil
import sys
import threading
import time
import urllib.error
import urllib.request

UPSTREAM = "https://registry.npmjs.org"

_locks = {}
_locks_guard = threading.Lock()


def path_lock(path):
    """One download at a time per tarball, however many ask for it."""
    with _locks_guard:
        return _locks.setdefault(path, threading.Lock())


def log(msg):
    sys.stderr.write("%s\n" % msg)
    sys.stderr.flush()


def human(n):
    for unit in ("B", "KiB", "MiB", "GiB"):
        if n < 1024 or unit == "GiB":
            return "%.1f %s" % (n, unit)
        n /= 1024.0


def fetch(url, dest, attempts, timeout):
    """Download url to dest, resuming a partial .part file across attempts."""
    part = dest + ".part"
    os.makedirs(os.path.dirname(dest), exist_ok=True)
    attempt = 0
    while attempts == 0 or attempt < attempts:
        attempt += 1
        have = os.path.getsize(part) if os.path.exists(part) else 0
        req = urllib.request.Request(url)
        if have:
            req.add_header("Range", "bytes=%d-" % have)
        try:
            with urllib.request.urlopen(req, timeout=timeout) as r:
                # A server that ignores the range restarts the file, so the
                # local copy has to go with it.
                if have and r.status != 206:
                    have = 0
                total = r.headers.get("Content-Length")
                total = have + int(total) if total is not None else None
                mode = "r+b" if have else "wb"
                with open(part, mode) as out:
                    out.seek(have)
                    while True:
                        chunk = r.read(256 * 1024)
                        if not chunk:
                            break
                        out.write(chunk)
                        have += len(chunk)
                if total is not None and have != total:
                    raise IOError("got %d of %d bytes" % (have, total))
        except urllib.error.HTTPError as e:
            # 416 means the range starts past the end: the file is already here.
            if e.code == 416:
                pass
            elif e.code in (408, 429) or e.code >= 500:
                log("  %s: HTTP %s, attempt %d" % (os.path.basename(dest),
                                                   e.code, attempt))
                time.sleep(min(2 ** min(attempt, 6), 60))
                continue
            else:
                # The registry says this tarball does not exist, or refuses it.
                # Trying again cannot change that, and retrying forever would
                # hang the install instead of failing it.
                log("  %s: HTTP %s, giving up" % (os.path.basename(dest),
                                                  e.code))
                return False
        except Exception as e:
            got = os.path.getsize(part) if os.path.exists(part) else 0
            log("  %s: %s, %s so far, attempt %d" %
                (os.path.basename(dest), e, human(got), attempt))
            time.sleep(min(2 ** min(attempt, 6), 60))
            continue
        os.rename(part, dest)
        return True
    return False


class Handler(http.server.BaseHTTPRequestHandler):
    protocol_version = "HTTP/1.1"

    def do_GET(self):
        path = self.path.split("?", 1)[0]
        dest = os.path.join(self.server.cache, path.lstrip("/"))
        if not os.path.exists(dest):
            with path_lock(path):
                if not os.path.exists(dest):
                    log("fetching %s" % path)
                    if not fetch(UPSTREAM + path, dest,
                                 self.server.attempts, self.server.timeout):
                        self.send_error(504, "gave up on %s" % path)
                        return
        try:
            size = os.path.getsize(dest)
            self.send_response(200)
            self.send_header("Content-Type", "application/octet-stream")
            self.send_header("Content-Length", str(size))
            self.end_headers()
            with open(dest, "rb") as f:
                shutil.copyfileobj(f, self.wfile)
        except (BrokenPipeError, ConnectionResetError):
            pass

    def log_message(self, *args):
        pass


class Server(http.server.ThreadingHTTPServer):
    daemon_threads = True
    allow_reuse_address = True


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--cache", default=os.path.expanduser("~/npm-cache"),
                   help="directory the tarballs are kept in")
    p.add_argument("--port", type=int, default=8899)
    p.add_argument("--attempts", type=int, default=0,
                   help="attempts per tarball, 0 for no limit (default)")
    p.add_argument("--timeout", type=int, default=120,
                   help="seconds before an attempt is considered stalled")
    args = p.parse_args()

    os.makedirs(args.cache, exist_ok=True)
    srv = Server(("127.0.0.1", args.port), Handler)
    srv.cache, srv.attempts, srv.timeout = args.cache, args.attempts, args.timeout
    log("serving %s from %s" % (UPSTREAM, args.cache))
    log("use: pnpm install --frozen-lockfile --registry=http://127.0.0.1:%d"
        % args.port)
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
