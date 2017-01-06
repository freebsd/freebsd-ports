# Created by: gahr
# $FreeBSD$

PORTNAME=	carve
PORTVERSION=	1.4.0
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, robust constructive solid geometry library

LICENSE=	GPLv2

BROKEN=		Unfetchable (google code has gone away)

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

OPTIONS_DEFINE=	DOCS GUI
OPTIONS_SUB=	yes

USES=		cmake:outsource compiler:c++11-lib tar:tgz
USE_GL=		glut
USE_LDCONFIG=	yes

PORTDOCS=	*

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-std=c++11
LDFLAGS+=	-L${LOCALBASE}/lib

GUI_LIB_DEPENDS=	libglui.so:devel/glui
GUI_CONFIGURE_OFF=	--with-gui=no
GUI_CMAKE_BOOL=		CARVE_WITH_GUI

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
