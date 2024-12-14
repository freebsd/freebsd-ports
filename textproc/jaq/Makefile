PORTNAME=	jaq
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	jq clone focused on correctness, speed, and simplicity
WWW=		https://github.com/01mf02/jaq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	01mf02

CARGO_BUILD_ARGS=	--package=jaq
CARGO_INSTALL_PATH=	jaq
CARGO_CRATES=	aho-corasick-1.1.3 \
		atty-0.2.14 \
		autocfg-1.4.0 \
		base64-0.22.1 \
		bitflags-1.3.2 \
		bumpalo-3.14.0 \
		cc-1.2.1 \
		cfg-if-1.0.0 \
		chrono-0.4.38 \
		codesnake-0.2.1 \
		console_log-1.0.0 \
		dyn-clone-1.0.17 \
		env_logger-0.10.2 \
		equivalent-1.0.1 \
		fastrand-1.9.0 \
		foldhash-0.1.3 \
		getrandom-0.2.15 \
		hashbrown-0.15.1 \
		hermit-abi-0.1.19 \
		hifijson-0.2.2 \
		indexmap-2.6.0 \
		instant-0.1.13 \
		itoa-1.0.11 \
		js-sys-0.3.72 \
		libc-0.2.164 \
		libm-0.2.11 \
		libmimalloc-sys-0.1.39 \
		log-0.4.22 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		mimalloc-0.1.43 \
		num-traits-0.2.19 \
		once_cell-1.20.2 \
		proc-macro2-1.0.89 \
		quote-1.0.37 \
		redox_syscall-0.2.16 \
		regex-lite-0.1.6 \
		remove_dir_all-0.5.3 \
		ryu-1.0.18 \
		serde-1.0.215 \
		serde_derive-1.0.215 \
		serde_json-1.0.133 \
		shlex-1.3.0 \
		syn-2.0.87 \
		tempfile-3.3.0 \
		typed-arena-2.0.2 \
		unicode-ident-1.0.13 \
		unicode-width-0.1.13 \
		urlencoding-2.1.3 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.95 \
		wasm-bindgen-backend-0.2.95 \
		wasm-bindgen-macro-0.2.95 \
		wasm-bindgen-macro-support-0.2.95 \
		wasm-bindgen-shared-0.2.95 \
		web-sys-0.3.72 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yansi-1.0.1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L/usr/local/lib/gcc${GCC_DEFAULT} -latomic
.endif

.include <bsd.port.mk>
