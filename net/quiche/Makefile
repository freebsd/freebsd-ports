PORTNAME=	quiche
DISTVERSION=	0.18.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	junho.choi@gmail.com
COMMENT=	Savoury implementation of the QUIC transport protocol and HTTP/3
WWW=		https://crates.io/crates/quiche

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_TUPLE=	google:boringssl:f1c75347d:boringssl/quiche/deps/boringssl
USE_LDCONFIG=	yes

CARGO_FEATURES=	ffi \
		pkg-config-meta

PLIST_FILES=	bin/quiche-client \
		bin/quiche-server \
		include/quiche.h \
		lib/libquiche.a \
		lib/libquiche.so \
		libdata/pkgconfig/quiche.pc
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
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/libquiche.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/libquiche.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche-server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche-client ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
