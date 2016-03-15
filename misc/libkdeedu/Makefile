# $FreeBSD$

PORTNAME=	libkdeedu
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries used by KDE educational applications

USE_KDE4=	kdelibs kdeprefix automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	corelib gui xml moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
