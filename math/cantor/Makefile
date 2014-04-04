# $FreeBSD$

PORTNAME=	cantor
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 frontend to mathematical software

LIB_DEPENDS=	libspectre.so:${PORTSDIR}/print/libspectre \
		libqalculate.so:${PORTSDIR}/math/libqalculate \
		libanalitza.so:${PORTSDIR}/math/analitza

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource pkgconfig tar:xz
USE_QT4=	corelib qtestlib_build xml xmlpatterns \
		moc_build qmake_build rcc_build uic_build
USE_PYTHON=	2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MAXIMA OCTAVE R SAGE SCILAB
OPTIONS_SUB=	yes # R

MAXIMA_DESC=	Install Maxima
MAXIMA_RUN_DEPENDS=	maxima:${PORTSDIR}/math/maxima

OCTAVE_DESC=	Install Octave
OCTAVE_RUN_DEPENDS=	octave:${PORTSDIR}/math/octave

R_DESC=		Build R backend and install R
R_BUILD_DEPENDS=	R:${PORTSDIR}/math/R
R_RUN_DEPENDS=		R:${PORTSDIR}/math/R
# Required to set CFLAGS for -lgfortran.
R_USE=		FORTRAN=yes
R_CMAKE_OFF=	-DWITH_R:BOOL=FALSE

SAGE_DESC=	Install Sage
SAGE_RUN_DEPENDS=	sage:${PORTSDIR}/math/sage

SCILAB_DESC=	Install Scilab
SCILAB_RUN_DEPENDS=	scilab:${PORTSDIR}/math/scilab

.include <bsd.port.mk>
