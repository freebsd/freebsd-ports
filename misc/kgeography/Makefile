# $FreeBSD$

PORTNAME=	kgeography
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 geography trainer

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
