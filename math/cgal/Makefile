# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgal
PORTVERSION=	4.8.1
CATEGORIES=	math
MASTER_SITES=	https://github.com/CGAL/cgal/releases/download/releases%2FCGAL-4.8.1/
DISTNAME=	CGAL-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Computational geometry library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:devel/boost-libs
LIB_DEPENDS=	libmpfr.so:math/mpfr \
		libgmp.so:math/gmp

BROKEN_sparc64:	Does not build: fails to compile all_files.cpp

USE_LDCONFIG=		yes
USES=			cmake shebangfix tar:xz
USE_QT5=		buildtools_build core qmake_build widgets
SHEBANG_FILES=		scripts/cgal_create_CMakeLists \
			scripts/cgal_create_cmake_script
HAS_CONFIGURE=		yes

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_DESC=		Build libCGAL_ImageIO and libCGAL_Qt4
GUI_USE=		GL=glu,gl QT5=gui,opengl
GUI_CMAKE_OFF=		-DWITH_CGAL_Qt4=OFF -DWITH_CGAL_ImageIO=OFF

.include <bsd.port.options.mk>

.if ${ARCH} == i386 && ${OSVERSION} >= 1100000
USE_GCC=	yes
.endif

.include <bsd.port.mk>
