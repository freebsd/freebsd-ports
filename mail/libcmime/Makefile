# Created by: Axel Steiner <ast@treibsand.com>
# $FreeBSD$

PORTNAME=	libcmime
PORTVERSION=	0.1.11
CATEGORIES=	mail
MASTER_SITES=	http://www.libcmime.org/files/

MAINTAINER=	ast@treibsand.com
COMMENT=	Lightweight C mime library

LICENSE=	MIT

USES=		bison cmake pkgconfig
USE_LDCONFIG=	yes
CMAKE_ARGS=	--no-warn-unused-cli

OPTIONS_DEFINE=	DEBUG DOCS

PORTDOCS=	AUTHORS CHANGELOG INSTALL README

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.33:${PORTSDIR}/textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/flex
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DENABLE_DEBUG=TRUE
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|\$${CMAKE_INSTALL_LIBDIR}(/pkgconfig)|$${CMAKE_INSTALL_PREFIX}/libdata\1|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
