# $FreeBSD$

PORTNAME=	deno
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Secure JavaScript and TypeScript runtime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	cargo:warning=c/freebsd.c:31:10: error: conflicting types for 'get_cpu_speed'

BUILD_DEPENDS=	binutils>0:devel/binutils \
		gn:devel/gn \
		libunwind>0:devel/libunwind

.include <bsd.port.options.mk>

# clang10+ is required, this conditional can be dropped when 12.1 is EOL
.if (${OSVERSION} >= 1200000 && ${OSVERSION} < 1201515)
BUILD_DEPENDS+=	llvm10>0:devel/llvm10
.endif

USES=	cargo ninja pkgconfig:build python:3.5+,build

USE_GITHUB=	yes
GH_ACCOUNT=	denoland
USE_GNOME=	glib20

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
RUSTY_VERS=	0.12.0

CARGO_ENV+=	CLANG_BASE_PATH=/usr \
		GN=${PREFIX}/bin/gn \
		NINJA=${PREFIX}/bin/ninja \
		V8_FROM_SOURCE=1
RUSTFLAGS+=	-C link-arg=-fuse-ld=lld

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python=${PYTHON_CMD}

CARGO_CRATES=	Inflector-0.11.4 \
		adler-0.2.3 \
		ahash-0.3.8 \
		aho-corasick-0.7.13 \
		alloc-no-stdlib-2.0.1 \
		alloc-stdlib-0.2.1 \
		ansi_term-0.11.0 \
		anyhow-1.0.32 \
		anymap-0.12.1 \
		arc-swap-0.4.7 \
		arrayvec-0.5.1 \
		ast_node-0.7.0 \
		async-compression-0.3.5 \
		atty-0.2.14 \
		autocfg-0.1.7 \
		autocfg-1.0.1 \
		base64-0.11.0 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-buffer-0.9.0 \
		block-padding-0.1.5 \
		brotli-3.3.0 \
		brotli-decompressor-2.3.1 \
		buf_redux-0.8.4 \
		build_const-0.2.1 \
		bumpalo-3.4.0 \
		byte-tools-0.3.1 \
		byteorder-1.3.4 \
		bytes-0.5.6 \
		cargo_gn-0.0.15 \
		cc-1.0.59 \
		cfg-if-0.1.10 \
		chrono-0.4.15 \
		clap-2.33.3 \
		cloudabi-0.0.3 \
		const-random-0.1.8 \
		const-random-macro-0.1.8 \
		cpuid-bool-0.1.2 \
		crc-1.8.1 \
		crc32fast-1.2.0 \
		crossbeam-channel-0.4.4 \
		crossbeam-utils-0.7.2 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		dashmap-3.11.10 \
		deno_doc-0.1.15 \
		deno_lint-0.2.9 \
		derive_more-0.99.11 \
		digest-0.8.1 \
		digest-0.9.0 \
		dissimilar-1.0.2 \
		dlopen-0.1.8 \
		dlopen_derive-0.1.4 \
		dprint-core-0.31.0 \
		dprint-plugin-typescript-0.32.8 \
		dtoa-0.4.6 \
		either-1.6.0 \
		encoding_rs-0.8.24 \
		enum_kind-0.2.0 \
		env_logger-0.7.1 \
		errno-0.1.8 \
		fake-simd-0.1.2 \
		filetime-0.2.12 \
		fixedbitset-0.2.0 \
		flate2-1.0.17 \
		fnv-1.0.7 \
		from_variant-0.1.2 \
		fsevent-2.0.2 \
		fsevent-sys-3.0.2 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.3.5 \
		futures-channel-0.3.5 \
		futures-core-0.3.5 \
		futures-executor-0.3.5 \
		futures-io-0.3.5 \
		futures-macro-0.3.5 \
		futures-sink-0.3.5 \
		futures-task-0.3.5 \
		futures-util-0.3.5 \
		fwdansi-1.1.0 \
		fxhash-0.2.1 \
		generic-array-0.12.3 \
		generic-array-0.14.4 \
		getrandom-0.1.15 \
		h2-0.2.6 \
		hashbrown-0.9.0 \
		headers-0.3.2 \
		headers-core-0.2.0 \
		hermit-abi-0.1.15 \
		http-0.2.1 \
		http-body-0.3.1 \
		httparse-1.3.4 \
		humantime-1.3.0 \
		hyper-0.13.7 \
		hyper-rustls-0.21.0 \
		ident_case-1.0.1 \
		idna-0.2.0 \
		if_chain-1.0.0 \
		indexmap-1.6.0 \
		inotify-0.8.3 \
		inotify-sys-0.1.3 \
		input_buffer-0.3.1 \
		iovec-0.1.4 \
		ipnet-2.3.0 \
		is-macro-0.1.8 \
		itoa-0.4.6 \
		js-sys-0.3.45 \
		jsdoc-0.10.0 \
		jsonc-parser-0.14.0 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		lexical-core-0.7.4 \
		libc-0.2.77 \
		log-0.4.11 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		miniz_oxide-0.4.2 \
		mio-0.6.22 \
		mio-extras-2.0.6 \
		mio-named-pipes-0.1.7 \
		mio-uds-0.6.8 \
		miow-0.2.1 \
		miow-0.3.5 \
		multipart-0.17.0 \
		net2-0.2.35 \
		new_debug_unreachable-1.0.4 \
		nix-0.18.0 \
		nom-5.1.2 \
		notify-5.0.0-pre.3 \
		num-bigint-0.2.6 \
		num-integer-0.1.43 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		once_cell-1.4.1 \
		opaque-debug-0.2.3 \
		opaque-debug-0.3.0 \
		ordered-float-1.1.0 \
		os_pipe-0.9.2 \
		owning_ref-0.4.1 \
		percent-encoding-2.1.0 \
		petgraph-0.5.1 \
		phf-0.8.0 \
		phf_generator-0.8.0 \
		phf_macros-0.8.0 \
		phf_shared-0.8.0 \
		pin-project-0.4.23 \
		pin-project-internal-0.4.23 \
		pin-project-lite-0.1.7 \
		pin-utils-0.1.0 \
		pmutil-0.5.3 \
		ppv-lite86-0.2.9 \
		precomputed-hash-0.1.1 \
		proc-macro-hack-0.5.18 \
		proc-macro-nested-0.1.6 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.21 \
		pty-0.2.2 \
		quick-error-1.2.3 \
		quote-0.6.13 \
		quote-1.0.7 \
		radix_fmt-1.0.0 \
		rand-0.6.5 \
		rand-0.7.3 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.2 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_hc-0.1.0 \
		rand_hc-0.2.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_pcg-0.2.1 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.57 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		relative-path-1.3.2 \
		remove_dir_all-0.5.3 \
		reqwest-0.10.8 \
		retain_mut-0.1.1 \
		ring-0.16.15 \
		rustc_version-0.2.3 \
		rustls-0.18.1 \
		rusty_v8-0.12.0 \
		rustyline-6.3.0 \
		rustyline-derive-0.3.1 \
		ryu-1.0.5 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		scoped-tls-1.0.0 \
		scopeguard-1.1.0 \
		sct-0.6.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		semver-parser-0.9.0 \
		serde-1.0.116 \
		serde_derive-1.0.116 \
		serde_json-1.0.57 \
		serde_urlencoded-0.6.1 \
		sha-1-0.8.2 \
		sha-1-0.9.1 \
		shell-escape-0.1.5 \
		signal-hook-registry-1.2.1 \
		siphasher-0.3.3 \
		slab-0.4.2 \
		smallvec-1.4.2 \
		socket2-0.3.15 \
		sourcemap-6.0.1 \
		spin-0.5.2 \
		stable_deref_trait-1.2.0 \
		static_assertions-1.1.0 \
		string_cache-0.8.0 \
		string_cache_codegen-0.5.1 \
		string_enum-0.3.0 \
		strsim-0.8.0 \
		strsim-0.9.3 \
		swc_atoms-0.2.5 \
		swc_bundler-0.16.1 \
		swc_common-0.10.5 \
		swc_ecma_ast-0.34.0 \
		swc_ecma_codegen-0.40.0 \
		swc_ecma_codegen_macros-0.5.0 \
		swc_ecma_dep_graph-0.8.0 \
		swc_ecma_parser-0.42.0 \
		swc_ecma_parser_macros-0.4.1 \
		swc_ecma_transforms-0.29.3 \
		swc_ecma_transforms_macros-0.1.1 \
		swc_ecma_utils-0.24.0 \
		swc_ecma_visit-0.20.0 \
		swc_ecmascript-0.13.3 \
		swc_macros_common-0.3.1 \
		swc_visit-0.2.2 \
		swc_visit_macros-0.2.1 \
		syn-0.15.44 \
		syn-1.0.41 \
		sys-info-0.7.0 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thiserror-1.0.20 \
		thiserror-impl-1.0.20 \
		thread_local-1.0.1 \
		time-0.1.44 \
		tinyvec-0.3.4 \
		tokio-0.2.22 \
		tokio-macros-0.2.5 \
		tokio-rustls-0.14.1 \
		tokio-tungstenite-0.11.0 \
		tokio-util-0.3.1 \
		toml-0.5.6 \
		tower-service-0.3.0 \
		tracing-0.1.19 \
		tracing-core-0.1.16 \
		tracing-futures-0.2.4 \
		try-lock-0.2.3 \
		tungstenite-0.11.1 \
		twoway-0.1.8 \
		typenum-1.12.0 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.1 \
		untrusted-0.7.1 \
		url-2.1.1 \
		urlencoding-1.1.1 \
		utf-8-0.7.5 \
		utf8parse-0.2.0 \
		uuid-0.8.1 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		walkdir-2.3.1 \
		want-0.3.0 \
		warp-0.2.5 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.68 \
		wasm-bindgen-backend-0.2.68 \
		wasm-bindgen-futures-0.4.18 \
		wasm-bindgen-macro-0.2.68 \
		wasm-bindgen-macro-support-0.2.68 \
		wasm-bindgen-shared-0.2.68 \
		web-sys-0.3.45 \
		webpki-0.21.3 \
		webpki-roots-0.19.0 \
		which-4.0.2 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.7.0 \
		winres-0.1.11 \
		ws2_32-sys-0.2.1

post-patch:
	${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/cargo-crates/rusty_v8-${RUSTY_VERS}/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/cargo-crates/rusty_v8-${RUSTY_VERS}/buildtools/third_party/libc++/BUILD.gn
# clang10+ is required, this conditional can be dropped when 12.1 is EOL
.if (${OSVERSION} >= 1200000 && ${OSVERSION} < 1201515)
	@${PATCH} -d ${PATCH_WRKSRC} ${PATCH_ARGS} < ${FILESDIR}/extrapatch-clang10
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/deno ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
