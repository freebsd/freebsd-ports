# Created by: Axel Steiner <ast@treibsand.com>
# $FreeBSD$

PORTNAME=	libcmime
PORTVERSION=	0.1.15
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.libcmime.org/files/

MAINTAINER=	ast@treibsand.com
COMMENT=	Lightweight C mime library

LICENSE=	MIT

USES=		bison cmake pkgconfig
USE_LDCONFIG=	yes
CMAKE_ARGS=	--no-warn-unused-cli

OPTIONS_DEFINE=	DEBUG DOCS DOXYGEN
OPTIONS_SUB=	yes
DOCS_ALL_TARGET=doc

PORTDOCS=	AUTHORS CHANGELOG INSTALL README

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.33:textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/flex
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DENABLE_DEBUG=TRUE
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen>=1.8:devel/doxygen \
		dot:graphics/graphviz
CMAKE_ARGS+=	-DENABLE_DOC=TRUE
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|\$${CMAKE_INSTALL_LIBDIR}(/pkgconfig)|$${CMAKE_INSTALL_PREFIX}/libdata\1|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -E -e 's|libcmime-\$${CMIME_MAJOR_VERSION}.\$${CMIME_MINOR_VERSION}.\$${CMIME_MICRO_VERSION}|libcmime|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -E -e 's|STRIP_FROM_PATH        = ../src|STRIP_FROM_PATH        = ../|' \
		${WRKSRC}/Doxyfile.cmake

.include <bsd.port.mk>
