PORTNAME=	jaq
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	jq clone focused on correctness, speed, and simplicity
WWW=		https://github.com/01mf02/jaq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

BROKEN_i386=	compilation fails: undefined symbol: __atomic_load_8

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	01mf02

CARGO_BUILD_ARGS=	--package=jaq
CARGO_INSTALL_PATH=	jaq
CARGO_CRATES=	aho-corasick-1.1.3 \
		arbitrary-1.4.1 \
		autocfg-1.4.0 \
		base64-0.22.1 \
		bitflags-2.9.0 \
		bumpalo-3.14.0 \
		cc-1.2.20 \
		cfg-if-1.0.0 \
		chrono-0.4.40 \
		codesnake-0.2.1 \
		console_log-1.0.0 \
		dyn-clone-1.0.19 \
		env_logger-0.10.2 \
		equivalent-1.0.2 \
		errno-0.3.11 \
		fastrand-2.3.0 \
		foldhash-0.1.5 \
		getrandom-0.2.16 \
		hashbrown-0.15.2 \
		hermit-abi-0.5.0 \
		hifijson-0.2.2 \
		indexmap-2.9.0 \
		is-terminal-0.4.16 \
		itoa-1.0.15 \
		js-sys-0.3.77 \
		libc-0.2.172 \
		libm-0.2.13 \
		libmimalloc-sys-0.1.42 \
		linux-raw-sys-0.4.15 \
		log-0.4.27 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		mimalloc-0.1.46 \
		num-traits-0.2.19 \
		once_cell-1.20.3 \
		proc-macro2-1.0.95 \
		quote-1.0.40 \
		regex-lite-0.1.6 \
		rustix-0.38.44 \
		rustversion-1.0.20 \
		ryu-1.0.20 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_json-1.0.140 \
		shlex-1.3.0 \
		syn-2.0.100 \
		tempfile-3.15.0 \
		typed-arena-2.0.2 \
		unicode-ident-1.0.17 \
		unicode-width-0.1.13 \
		urlencoding-2.1.3 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		web-sys-0.3.77 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		yansi-1.0.1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L/usr/local/lib/gcc${GCC_DEFAULT} -latomic
.endif

.include <bsd.port.mk>
