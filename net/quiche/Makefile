PORTNAME=	quiche
DISTVERSION=	0.22.0
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

CARGO_FEATURES=		ffi pkg-config-meta
CARGO_BUILD=		yes
CARGO_BUILD_ARGS+=	--workspace
CARGO_TEST=		yes
CARGO_TEST_ARGS+=	--all-targets

PLIST_FILES=	bin/quiche-client \
		bin/quiche-server \
		include/quiche.h \
		lib/libquiche.a \
		lib/libquiche.so \
		lib/libquiche.so.${DISTVERSION} \
		lib/libquiche.so.${MAJOR_VER} \
		libdata/pkgconfig/quiche.pc
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS QLOG
OPTIONS_DEFAULT=	DOCS QLOG

QLOG_DESC=	Enable qlog support
QLOG_VARS=	CARGO_FEATURES+=qlog

MAJOR_VER=	${DISTVERSION:C/\..*//}

post-patch:
	@${GREP} -FRl -- '-D_XOPEN_SOURCE=700' ${WRKSRC}/quiche/deps/boringssl | \
		${XARGS} ${REINPLACE_CMD} -e 's,-D_XOPEN_SOURCE=700,,'

# install quiche apps and libquiche
do-install:
	${INSTALL_DATA} ${WRKSRC}/quiche/include/quiche.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/libquiche.so ${STAGEDIR}${PREFIX}/lib/libquiche.so.${DISTVERSION}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libquiche.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libquiche.so.${MAJOR_VER}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libquiche.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libquiche.so
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/libquiche.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche-server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/quiche-client ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
