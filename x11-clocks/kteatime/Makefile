# $FreeBSD$

PORTNAME=	kteatime
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-clocks kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Handy timer for steeping tea

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
