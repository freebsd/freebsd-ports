PORTNAME=	jaq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
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
CARGO_CRATES=	ahash-0.8.6 \
		aho-corasick-1.0.2 \
		allocator-api2-0.2.16 \
		anstream-0.6.4 \
		anstyle-1.0.4 \
		anstyle-parse-0.2.2 \
		anstyle-query-1.0.0 \
		anstyle-wincon-3.0.1 \
		ariadne-0.1.5 \
		atty-0.2.14 \
		base64-0.21.2 \
		bincode-1.3.3 \
		bitflags-1.3.2 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		chumsky-0.9.3 \
		clap-4.4.7 \
		clap_builder-4.4.7 \
		clap_derive-4.4.7 \
		clap_lex-0.6.0 \
		colorchoice-1.0.0 \
		colored_json-3.0.1 \
		dyn-clone-1.0.11 \
		either-1.8.1 \
		env_logger-0.10.0 \
		equivalent-1.0.0 \
		fastrand-1.9.0 \
		getrandom-0.2.10 \
		hashbrown-0.14.2 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		hifijson-0.2.0 \
		indexmap-2.0.0 \
		instant-0.1.12 \
		itertools-0.10.5 \
		itoa-1.0.8 \
		libc-0.2.147 \
		libm-0.2.7 \
		libmimalloc-sys-0.1.33 \
		log-0.4.19 \
		memchr-2.5.0 \
		memmap2-0.5.10 \
		mimalloc-0.1.37 \
		once_cell-1.18.0 \
		proc-macro2-1.0.69 \
		quote-1.0.29 \
		redox_syscall-0.2.16 \
		regex-1.9.0 \
		regex-automata-0.3.0 \
		regex-syntax-0.7.3 \
		remove_dir_all-0.5.3 \
		ryu-1.0.14 \
		serde-1.0.190 \
		serde_derive-1.0.190 \
		serde_json-1.0.99 \
		strsim-0.10.0 \
		syn-2.0.38 \
		tempfile-3.3.0 \
		time-0.3.22 \
		time-core-0.1.1 \
		time-macros-0.2.9 \
		unicode-ident-1.0.10 \
		urlencoding-2.1.3 \
		utf8parse-0.2.1 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5 \
		yansi-0.5.1 \
		zerocopy-0.7.20 \
		zerocopy-derive-0.7.20

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L/usr/local/lib/gcc${GCC_DEFAULT} -latomic
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
