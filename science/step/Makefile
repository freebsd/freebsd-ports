# New ports collection Makefile for:	step
# Date created:				6 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	step
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	science kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 interactive physics simulator

LIB_DEPENDS=	qalculate.5:${PORTSDIR}/math/libqalculate \
		gsl.16:${PORTSDIR}/math/gsl

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl xml moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

pre-configure:
	# Fix GSL_INCLUDE_DIR.
	${REINPLACE_CMD} -e 's|gsl_|gsl/gsl_|g' \
		${WRKSRC}/cmake/modules/FindGSL.cmake
	# Avoid building translations, should the user pass
	# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
