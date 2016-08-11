# $FreeBSD$

PORTNAME=	ktux
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11-clocks kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tux-in-a-Spaceship screen saver

USE_KDE4=	kdelibs workspace automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	qt3support moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
