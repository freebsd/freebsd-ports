# Created by: gahr
# $FreeBSD$

PORTNAME=	carve
PORTVERSION=	1.4.0
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, robust constructive solid geometry library

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

OPTIONS_DEFINE=	DOCS GUI

USES=		cmake:outsource compiler:c++11-lib tar:tgz
USE_GL=		glut
USE_LDCONFIG=	yes

PORTDOCS=	*

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-std=c++11
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	libglui.so:devel/glui
PLIST_SUB+=	GUI=""
CMAKE_ARGS+=	-DCARVE_WITH_GUI:BOOL=true
.else
CONFIGURE_ARGS+=--with-gui=no
PLIST_SUB+=	GUI="@comment "
CMAKE_ARGS+=	-DCARVE_WITH_GUI:BOOL=false
.endif

post-patch:
	${FIND} ${WRKSRC} -name "*.cpp" -o -name "*.h" -o -name "*.hpp" | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|::tr1||g'
	${REINPLACE_CMD} -e '/gtest/s|^|#|; /tests/s|^|#|' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|__is_heap|is_heap|' ${WRKSRC}/lib/triangulator.cpp

post-install:
	${LN} -sf libcarve.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcarve.so.${PORTVERSION:R:R}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/carve.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
