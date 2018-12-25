# $FreeBSD$

PORTNAME=	ktux
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	x11-clocks kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tux-in-a-Spaceship screen saver

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs workspace automoc4
USE_QT=		qt3support moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
