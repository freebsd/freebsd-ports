# $FreeBSD$

PORTNAME=	rav1e
DISTVERSION=	0.1.0
PORTREVISION?=	1
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Fast and safe AV1 encoder

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS+=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	xiph
PLIST_FILES?=	bin/${PORTNAME}

CARGO_CRATES=	adler32-1.0.4 \
		aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		aom-sys-0.1.3 \
		arbitrary-0.2.0 \
		arc-swap-0.4.3 \
		arg_enum_proc_macro-0.3.0 \
		arrayvec-0.5.1 \
		atty-0.2.13 \
		autocfg-0.1.7 \
		backtrace-0.3.40 \
		backtrace-sys-0.1.32 \
		better-panic-0.2.0 \
		bincode-1.2.0 \
		bindgen-0.51.1 \
		bitflags-1.2.1 \
		bitstream-io-0.8.4 \
		bstr-0.2.8 \
		byteorder-1.3.2 \
		c2-chacha-0.2.3 \
		cast-0.2.2 \
		cc-1.0.47 \
		cexpr-0.3.6 \
		cfg-if-0.1.10 \
		chrono-0.4.9 \
		clang-sys-0.28.1 \
		clap-2.33.0 \
		clicolors-control-1.0.1 \
		console-0.9.1 \
		crc32fast-1.2.0 \
		criterion-0.3.0 \
		criterion-plot-0.4.0 \
		crossbeam-deque-0.7.2 \
		crossbeam-epoch-0.8.0 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.6 \
		crossbeam-utils-0.7.0 \
		csv-1.1.1 \
		csv-core-0.1.6 \
		ctor-0.1.12 \
		dav1d-sys-0.2.1 \
		deflate-0.7.20 \
		difference-2.0.0 \
		either-1.5.3 \
		encode_unicode-0.3.6 \
		env_logger-0.6.2 \
		err-derive-0.2.1 \
		error-chain-0.10.0 \
		getrandom-0.1.13 \
		glob-0.3.0 \
		hermit-abi-0.1.3 \
		humantime-1.3.0 \
		image-0.22.3 \
		inflate-0.4.5 \
		interpolate_name-0.2.3 \
		itertools-0.8.1 \
		itoa-0.4.4 \
		lazy_static-1.4.0 \
		libc-0.2.65 \
		libloading-0.5.2 \
		log-0.4.8 \
		memchr-2.2.1 \
		memoffset-0.5.3 \
		metadeps-1.1.2 \
		nom-4.2.3 \
		noop_proc_macro-0.1.0 \
		num-derive-0.3.0 \
		num-integer-0.1.41 \
		num-iter-0.1.39 \
		num-rational-0.2.2 \
		num-traits-0.2.8 \
		num_cpus-1.11.0 \
		output_vt100-0.1.2 \
		paste-0.1.6 \
		paste-impl-0.1.6 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.17 \
		png-0.15.0 \
		ppv-lite86-0.2.6 \
		pretty_assertions-0.6.1 \
		pretty_env_logger-0.3.1 \
		proc-macro-error-0.2.6 \
		proc-macro-hack-0.5.11 \
		proc-macro2-1.0.6 \
		quick-error-1.2.2 \
		quote-1.0.2 \
		rand-0.7.2 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_os-0.2.2 \
		rand_xoshiro-0.3.1 \
		rayon-1.2.0 \
		rayon-core-1.6.0 \
		redox_syscall-0.1.56 \
		regex-1.3.1 \
		regex-automata-0.1.8 \
		regex-syntax-0.6.12 \
		rustc-demangle-0.1.16 \
		rustc-hash-1.0.1 \
		rustc_version-0.2.3 \
		ryu-1.0.2 \
		same-file-1.0.5 \
		scan_fmt-0.2.4 \
		scopeguard-1.0.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.102 \
		serde_derive-1.0.102 \
		serde_json-1.0.41 \
		shlex-0.1.1 \
		signal-hook-0.1.11 \
		signal-hook-registry-1.1.1 \
		simd_helpers-0.1.0 \
		strsim-0.8.0 \
		syn-1.0.8 \
		synstructure-0.12.2 \
		termcolor-1.0.5 \
		termios-0.3.1 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		tinytemplate-1.0.2 \
		toml-0.2.1 \
		unicode-width-0.1.6 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		walkdir-2.2.9 \
		wasi-0.7.0 \
		which-3.1.0 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2 \
		y4m-0.4.0

.ifndef PKGNAMEPREFIX
OPTIONS_DEFINE=	FFMPEG
OPTIONS_DEFAULT=FFMPEG

FFMPEG_BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
FFMPEG_VARS=		CARGO_FEATURES+=avformat-sys
.endif

post-patch:
	@${REINPLACE_CMD} 's/env!("VERGEN_SEMVER_LIGHTWEIGHT")/"${DISTVERSIONFULL}"/' \
		${WRKSRC}/src/capi.rs ${WRKSRC}/src/lib.rs

.if !target(post-install)
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.endif

.include <bsd.port.mk>
