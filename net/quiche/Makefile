PORTNAME=	quiche
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	junho.choi@gmail.com
COMMENT=	Savoury implementation of the QUIC transport protocol and HTTP/3

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_TAGNAME=	${PORTVERSION}
GH_TUPLE=	google:boringssl:067cfd92f:boringssl/deps/boringssl

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bindgen-0.57.0 \
		bitflags-1.2.1 \
		boring-sys-1.1.1 \
		bumpalo-3.6.1 \
		cc-1.0.67 \
		cexpr-0.4.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-1.2.0 \
		clap-2.33.3 \
		cmake-0.1.45 \
		darling-0.12.3 \
		darling_core-0.12.3 \
		darling_macro-0.12.3 \
		docopt-1.1.1 \
		env_logger-0.6.2 \
		env_logger-0.8.3 \
		fnv-1.0.7 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		glob-0.3.0 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.18 \
		humantime-1.3.0 \
		humantime-2.1.0 \
		ident_case-1.0.1 \
		idna-0.1.5 \
		indexmap-1.6.2 \
		iovec-0.1.4 \
		itoa-0.4.7 \
		js-sys-0.3.50 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.93 \
		libloading-0.7.0 \
		libm-0.2.1 \
		log-0.4.14 \
		matches-0.1.8 \
		memchr-2.3.4 \
		mio-0.6.23 \
		miow-0.2.2 \
		net2-0.2.37 \
		nom-5.1.2 \
		once_cell-1.7.2 \
		peeking_take_while-0.1.2 \
		percent-encoding-1.0.1 \
		proc-macro2-1.0.26 \
		quick-error-1.2.3 \
		quote-1.0.9 \
		regex-1.4.5 \
		regex-syntax-0.6.23 \
		ring-0.16.20 \
		rustc-hash-1.1.0 \
		rustversion-1.0.4 \
		ryu-1.0.5 \
		serde-1.0.125 \
		serde_derive-1.0.125 \
		serde_json-1.0.64 \
		serde_with-1.8.0 \
		serde_with_macros-1.4.1 \
		shlex-0.1.1 \
		slab-0.4.2 \
		spin-0.5.2 \
		strsim-0.8.0 \
		strsim-0.10.0 \
		syn-1.0.69 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		tinyvec-1.2.0 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.5 \
		unicode-normalization-0.1.17 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		untrusted-0.7.1 \
		url-1.7.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wasm-bindgen-0.2.73 \
		wasm-bindgen-backend-0.2.73 \
		wasm-bindgen-macro-0.2.73 \
		wasm-bindgen-macro-support-0.2.73 \
		wasm-bindgen-shared-0.2.73 \
		web-sys-0.3.50 \
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
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/libquiche.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/libquiche.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/quiche-server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/quiche-client ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
