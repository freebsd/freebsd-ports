# New ports collection Makefile for:	cantor
# Date created:				5 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cantor
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 frontend to mathematical software

LIB_DEPENDS=	spectre.1:${PORTSDIR}/print/libspectre

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qtestlib_build xmlpatterns \
		moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	KALGEBRA "KAlgebra backend" on \
		MAXIMA "Maxima backend" off \
		OCTAVE "Octave backend" off \
		R "R backend" off

.include <bsd.port.options.mk>

.ifndef(WITHOUT_KALGEBRA)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kalgebra:${PORTSDIR}/math/kalgebra
.endif

.ifdef(WITH_MAXIMA)
RUN_DEPENDS+=	maxima:${PORTSDIR}/math/maxima
.endif

.ifdef(WITH_OCTAVE)
RUN_DEPENDS+=	octave:${PORTSDIR}/math/octave
.endif

.ifdef(WITH_R)
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
