# $FreeBSD$

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

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT4=	opengl xml moc_build qmake_build rcc_build uic_build
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

pre-configure:
	# Avoid building translations, should the user pass
	# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
