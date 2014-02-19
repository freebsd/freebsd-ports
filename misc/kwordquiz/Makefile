# $FreeBSD$

PORTNAME=	kwordquiz
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Flash card trainer for KDE 4

USE_KDE4=	kdehier kdelibs kdeprefix libkdeedu automoc4
USES=		cmake:outsource
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

.include <bsd.port.mk>
