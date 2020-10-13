# $FreeBSD$

PORTNAME=	quiche
DISTVERSIONPREFIX=	v
DISTVERSION=	${GIT_VERSION}
DISTVERSIONSUFFIX=	-g${GIT_HASH}
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	junho.choi@gmail.com
COMMENT=	Savoury implementation of the QUIC transport protocol and HTTP/3

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_PROJECT=	quiche
GH_TAGNAME=	${GIT_HASH}
GH_TUPLE=	google:boringssl:597b810:boringssl/deps/boringssl

# git describe
GIT_VERSION=	0.5.1-6
GIT_HASH=	c15dd5c

OPTIONS_DEFINE=	DOCS QLOG
OPTIONS_DEFAULT=DOCS QLOG

QLOG_VARS=	CARGO_FEATURES+=qlog
QLOG_DESC=	Enable qlog support

PORTDOCS=	README.md

CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/quiche-client \
		bin/quiche-server \
		include/quiche.h \
		lib/libquiche.a \
		lib/libquiche.so

CARGO_CRATES=	aho-corasick-0.7.13 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		bumpalo-3.4.0 \
		cc-1.0.58 \
		cfg-if-0.1.10 \
		cmake-0.1.44 \
		docopt-1.1.0 \
		env_logger-0.6.2 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		hermit-abi-0.1.15 \
		humantime-1.3.0 \
		idna-0.1.5 \
		iovec-0.1.4 \
		itoa-0.4.6 \
		js-sys-0.3.44 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.74 \
		libm-0.2.1 \
		log-0.4.11 \
		matches-0.1.8 \
		memchr-2.3.3 \
		mio-0.6.22 \
		miow-0.2.1 \
		net2-0.2.34 \
		once_cell-1.4.0 \
		percent-encoding-1.0.1 \
		proc-macro2-1.0.19 \
		quick-error-1.2.3 \
		quote-1.0.7 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		ring-0.16.15 \
		ryu-1.0.5 \
		serde-1.0.114 \
		serde_derive-1.0.114 \
		serde_json-1.0.57 \
		serde_with-1.4.0 \
		serde_with_macros-1.1.0 \
		slab-0.4.2 \
		spin-0.5.2 \
		strsim-0.9.3 \
		syn-1.0.36 \
		termcolor-1.1.0 \
		thread_local-1.0.1 \
		tinyvec-0.3.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-xid-0.2.1 \
		untrusted-0.7.1 \
		url-1.7.2 \
		wasm-bindgen-0.2.67 \
		wasm-bindgen-backend-0.2.67 \
		wasm-bindgen-macro-0.2.67 \
		wasm-bindgen-macro-support-0.2.67 \
		wasm-bindgen-shared-0.2.67 \
		web-sys-0.3.44 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

LIBQUICHE_CARGOTOML=	${WRKSRC}/Cargo.toml
QUICHEAPPS_CARGOTOML=	${WRKSRC}/tools/apps/Cargo.toml
QUICHEAPPS_CARGOLOCK=	${WRKSRC}/tools/apps/Cargo.lock

CARGO_CARGOTOML=	${QUICHEAPPS_CARGOTOML}
CARGO_CARGOLOCK=	${QUICHEAPPS_CARGOLOCK}

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
