# $FreeBSD$

PORTNAME=	cantor
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 frontend to mathematical software

LIB_DEPENDS=	spectre.1:${PORTSDIR}/print/libspectre \
		qalculate.5:${PORTSDIR}/math/libqalculate \
		analitza.5:${PORTSDIR}/math/analitza

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT4=	qtestlib_build xmlpatterns \
		moc_build qmake_build rcc_build uic_build
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	MAXIMA OCTAVE R
MAXIMA_DESC=	Maxima backend
OCTAVE_DESC=	Octave backend
R_DESC=		R backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAXIMA}
RUN_DEPENDS+=	maxima:${PORTSDIR}/math/maxima
.endif

.if ${PORT_OPTIONS:MOCTAVE}
RUN_DEPENDS+=	octave:${PORTSDIR}/math/octave
.endif

.if ${PORT_OPTIONS:MR}
BUILD_DEPENDS+=	R:${PORTSDIR}/math/R
RUN_DEPENDS+=	R:${PORTSDIR}/math/R
# Required to set CFLAGS for -lgfortran.
USE_FORTRAN=	yes
PLIST_SUB+=	R=""
.else
CMAKE_ARGS+=	-DWITH_R:BOOL=FALSE
PLIST_SUB+=	R="@comment "
.endif

.include <bsd.port.mk>
