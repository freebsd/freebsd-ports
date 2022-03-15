PORTNAME=	quiche
PORTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	junho.choi@gmail.com
COMMENT=	Savoury implementation of the QUIC transport protocol and HTTP/3

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	cloudflare
GH_TAGNAME=	${PORTVERSION}
GH_TUPLE=	google:boringssl:f1c75347d:boringssl/quiche/deps/boringssl

CARGO_CRATES=	aho-corasick-0.7.18 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bindgen-0.59.2 \
		bitflags-1.3.2 \
		boring-sys-2.0.0 \
		bumpalo-3.9.1 \
		cc-1.0.72 \
		cexpr-0.6.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-1.3.1 \
		cmake-0.1.48 \
		darling-0.13.1 \
		darling_core-0.13.1 \
		darling_macro-0.13.1 \
		docopt-1.1.1 \
		env_logger-0.6.2 \
		fnv-1.0.7 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		humantime-1.3.0 \
		ident_case-1.0.1 \
		idna-0.1.5 \
		indexmap-1.8.0 \
		iovec-0.1.4 \
		itoa-1.0.1 \
		js-sys-0.3.56 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.117 \
		libloading-0.7.3 \
		libm-0.2.2 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.4.1 \
		minimal-lexical-0.2.1 \
		mio-0.6.23 \
		miow-0.2.2 \
		net2-0.2.37 \
		nom-7.1.0 \
		once_cell-1.9.0 \
		peeking_take_while-0.1.2 \
		percent-encoding-1.0.1 \
		proc-macro2-1.0.36 \
		quick-error-1.2.3 \
		quote-1.0.15 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		ring-0.16.20 \
		rustc-hash-1.1.0 \
		rustversion-1.0.6 \
		ryu-1.0.9 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.78 \
		serde_with-1.12.0 \
		serde_with_macros-1.5.1 \
		shlex-1.1.0 \
		slab-0.4.5 \
		spin-0.5.2 \
		strsim-0.10.0 \
		syn-1.0.86 \
		termcolor-1.1.2 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-xid-0.2.2 \
		untrusted-0.7.1 \
		url-1.7.2 \
		version_check-0.9.4 \
		wasm-bindgen-0.2.79 \
		wasm-bindgen-backend-0.2.79 \
		wasm-bindgen-macro-0.2.79 \
		wasm-bindgen-macro-support-0.2.79 \
		wasm-bindgen-shared-0.2.79 \
		web-sys-0.3.56 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/quiche-client \
		bin/quiche-server \
		include/quiche.h \
		lib/libquiche.a \
		lib/libquiche.so
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS QLOG
OPTIONS_DEFAULT=DOCS QLOG

QLOG_DESC=	Enable qlog support
QLOG_VARS=	CARGO_FEATURES+=qlog

post-patch:
	@${GREP} -FRl -- '-D_XOPEN_SOURCE=700' ${WRKSRC}/quiche/deps/boringssl | \
		${XARGS} ${REINPLACE_CMD} -e 's,-D_XOPEN_SOURCE=700,,'

# build libquiche and apps
do-build:
	@${CARGO_CARGO_RUN} build \
		--verbose \
		--workspace \
		${CARGO_BUILD_ARGS}

# install quiche apps and libquiche
do-install:
	${INSTALL_DATA} ${WRKSRC}/quiche/include/quiche.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/libquiche.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/libquiche.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche-server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche-client ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
