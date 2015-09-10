# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgal
PORTVERSION=	4.6
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/34703/
DISTNAME=	CGAL-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Computational geometry library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libmpfr.so:${PORTSDIR}/math/mpfr \
		libgmp.so:${PORTSDIR}/math/gmp

USE_LDCONFIG=		yes
USES=			cmake tar:bzip2 shebangfix
SHEBANG_FILES=		scripts/cgal_create_CMakeLists
HAS_CONFIGURE=		yes
LDFLAGS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI
GUI_DESC=		Build libCGAL_ImageIO and libCGAL_Qt4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build gui opengl svg
LIB_DEPENDS+=	libGLU.so:${PORTSDIR}/graphics/libGLU
CMAKE_ARGS=	-DWITH_CGAL_Qt3=OFF
PLIST_SUB+=	GUI=""
.else
USE_QT4=	corelib qmake_build moc_build rcc_build svg uic_build
CMAKE_ARGS=	-DWITH_CGAL_Qt4=OFF -DWITH_CGAL_ImageIO=OFF -DWITH_CGAL_Qt3=OFF
PLIST_SUB+=	GUI="@comment "
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/auxiliary/cgal_create_cmake_script.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
