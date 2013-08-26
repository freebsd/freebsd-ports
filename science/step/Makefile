# $FreeBSD$

PORTNAME=	step
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	science kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 interactive physics simulator

LIB_DEPENDS=	qalculate.5:${PORTSDIR}/math/libqalculate \
		gsl:${PORTSDIR}/math/gsl

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource
USE_QT4=	opengl moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

pre-configure:
	# Avoid building translations, should the user pass
	# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
