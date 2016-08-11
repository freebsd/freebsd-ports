# $FreeBSD$

PORTNAME=	step
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	science kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 interactive physics simulator

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:math/eigen2
LIB_DEPENDS=	libqalculate.so:math/libqalculate \
		libgsl.so:math/gsl

USE_KDE4=	kdelibs automoc4
USES=		cmake:outsource pkgconfig tar:xz
USE_QT4=	opengl moc_build qmake_build rcc_build uic_build

pre-configure:
# Avoid building translations, should the user pass
# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
