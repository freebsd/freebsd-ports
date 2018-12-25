# $FreeBSD$

PORTNAME=	step
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	10
CATEGORIES=	science kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 interactive physics simulator

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libqalculate.so:math/libqalculate \
		libgsl.so:math/gsl

USES=		cmake eigen:2 kde:4 pkgconfig qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		opengl moc_build qmake_build rcc_build uic_build

pre-configure:
# Avoid building translations, should the user pass
# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
