# $FreeBSD$

PORTNAME=	klettres
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Alphabet learning tool for KDE 4

USE_KDE4=	kdelibs automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
