# $FreeBSD$

PORTNAME=	cantor
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	math kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 frontend to mathematical software

LIB_DEPENDS=	libspectre.so:print/libspectre \
		libqalculate.so:math/libqalculate \
		libanalitza.so:math/analitza

USE_KDE4=	kdelibs kdeprefix automoc4
USES=		cmake:outsource pkgconfig python:2 tar:xz
USE_QT4=	corelib qtestlib_build xml xmlpatterns \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LUAJIT MAXIMA OCTAVE R SAGE SCILAB
OPTIONS_SUB=	yes # R LUAJIT

LUAJIT_DESC=	Build LuaJIT backend and install LuaJIT
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_CMAKE_OFF=	-DWITH_LuaJIT:BOOL=FALSE

MAXIMA_DESC=	Install Maxima
MAXIMA_RUN_DEPENDS=	maxima:math/maxima

OCTAVE_DESC=	Install Octave
OCTAVE_RUN_DEPENDS=	octave:math/octave

R_DESC=		Build R backend and install R
R_BUILD_DEPENDS=	R:math/R
R_RUN_DEPENDS=		R:math/R
# Required to set CFLAGS for -lgfortran.
R_USES=		fortran
R_CMAKE_OFF=	-DWITH_R:BOOL=FALSE

SAGE_DESC=	Install Sage
SAGE_RUN_DEPENDS=	sage:math/sage

SCILAB_DESC=	Install Scilab
SCILAB_RUN_DEPENDS=	scilab:math/scilab

post-patch:
	${REINPLACE_CMD} -e '/FIND_PROGRAM(_GFORTRAN_EXECUTABLE/s,gfortran,${FC},' \
		${WRKSRC}/cmake/FindR.cmake

.include <bsd.port.mk>
