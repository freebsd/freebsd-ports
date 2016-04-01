# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgal
PORTVERSION=	4.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/34703/
DISTNAME=	CGAL-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Computational geometry library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:devel/boost-libs
LIB_DEPENDS=	libmpfr.so:math/mpfr \
		libgmp.so:math/gmp

USE_LDCONFIG=		yes
USES=			cmake tar:bzip2 shebangfix
USE_QT4=		corelib qmake_build moc_build rcc_build uic_build svg
CMAKE_ARGS=		-DWITH_CGAL_Qt3=OFF
SHEBANG_FILES=		scripts/cgal_create_CMakeLists
HAS_CONFIGURE=		yes
LDFLAGS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_DESC=		Build libCGAL_ImageIO and libCGAL_Qt4
GUI_USE=		GL=glu QT4=gui,opengl
GUI_CMAKE_OFF=		-DWITH_CGAL_Qt4=OFF -DWITH_CGAL_ImageIO=OFF

post-install:
	${INSTALL_MAN} ${WRKSRC}/auxiliary/cgal_create_cmake_script.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
