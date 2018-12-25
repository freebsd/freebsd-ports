# $FreeBSD$

PORTNAME=	kalgebra
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	math kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graph calculator

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libanalitza.so:math/analitza-kde4

CMAKE_ARGS=	-DBUILD_mobile:BOOL=FALSE

USES=		cmake kde:4 qt:4 tar:xz
USE_GL=		glu
USE_KDE=	kdelibs libkeduvocdocument automoc4
USE_QT=		corelib declarative gui opengl \
		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
