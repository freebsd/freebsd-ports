# $FreeBSD$

PORTNAME=	step
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	8
CATEGORIES=	science kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 interactive physics simulator

LIB_DEPENDS=	libqalculate.so:math/libqalculate \
		libgsl.so:math/gsl

USES=		cmake:outsource eigen:2 kde:4 pkgconfig tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	opengl moc_build qmake_build rcc_build uic_build

pre-configure:
# Avoid building translations, should the user pass
# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
