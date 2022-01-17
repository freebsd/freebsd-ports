PORTNAME=	quiche
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	junho.choi@gmail.com
COMMENT=	Savoury implementation of the QUIC transport protocol and HTTP/3

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_TAGNAME=	${PORTVERSION}
GH_TUPLE=	google:boringssl:f1c75347d:boringssl/deps/boringssl

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bindgen-0.57.0 \
		bitflags-1.3.2 \
		boring-sys-1.1.1 \
		bumpalo-3.7.0 \
		cc-1.0.70 \
		cexpr-0.4.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-1.2.2 \
		clap-2.33.3 \
		cmake-0.1.45 \
		darling-0.13.0 \
		darling_core-0.13.0 \
		darling_macro-0.13.0 \
		docopt-1.1.1 \
		env_logger-0.6.2 \
		env_logger-0.8.4 \
		fnv-1.0.7 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		humantime-1.3.0 \
		humantime-2.1.0 \
		ident_case-1.0.1 \
		idna-0.1.5 \
		indexmap-1.7.0 \
		iovec-0.1.4 \
		itoa-0.4.8 \
		js-sys-0.3.54 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.101 \
		libloading-0.7.0 \
		libm-0.2.1 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.4.1 \
		mio-0.6.23 \
		miow-0.2.2 \
		net2-0.2.37 \
		nom-5.1.2 \
		once_cell-1.8.0 \
		peeking_take_while-0.1.2 \
		percent-encoding-1.0.1 \
		proc-macro2-1.0.29 \
		quick-error-1.2.3 \
		quote-1.0.9 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		ring-0.16.20 \
		rustc-hash-1.1.0 \
		rustversion-1.0.5 \
		ryu-1.0.5 \
		serde-1.0.130 \
		serde_derive-1.0.130 \
		serde_json-1.0.67 \
		serde_with-1.10.0 \
		serde_with_macros-1.5.0 \
		shlex-0.1.1 \
		slab-0.4.4 \
		spin-0.5.2 \
		strsim-0.8.0 \
		strsim-0.10.0 \
		syn-1.0.76 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		tinyvec-1.3.1 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.6 \
		unicode-normalization-0.1.19 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		untrusted-0.7.1 \
		url-1.7.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wasm-bindgen-0.2.77 \
		wasm-bindgen-backend-0.2.77 \
		wasm-bindgen-macro-0.2.77 \
		wasm-bindgen-macro-support-0.2.77 \
		wasm-bindgen-shared-0.2.77 \
		web-sys-0.3.54 \
		which-3.1.1 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

CARGO_CARGOLOCK=	${QUICHEAPPS_CARGOLOCK}
CARGO_CARGOTOML=	${QUICHEAPPS_CARGOTOML}
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

LIBQUICHE_CARGOTOML=	${WRKSRC}/Cargo.toml
QUICHEAPPS_CARGOLOCK=	${WRKSRC}/tools/apps/Cargo.lock
QUICHEAPPS_CARGOTOML=	${WRKSRC}/tools/apps/Cargo.toml

post-patch:
	@${GREP} -FRl -- '-D_XOPEN_SOURCE=700' ${WRKSRC}/deps/boringssl | \
		${XARGS} ${REINPLACE_CMD} -e 's,-D_XOPEN_SOURCE=700,,'

# build libquiche and apps
do-build:
	@${CARGO_CARGO_RUN} build \
		--manifest-path ${LIBQUICHE_CARGOTOML} \
		--verbose \
		${CARGO_BUILD_ARGS}
	@${CARGO_CARGO_RUN} build \
		--manifest-path ${QUICHEAPPS_CARGOTOML} \
		--verbose \
		${CARGO_BUILD_ARGS}

# install quiche apps and libquiche
do-install:
	${INSTALL_DATA} ${WRKSRC}/include/quiche.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/libquiche.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/libquiche.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche-server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche-client ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
