# $FreeBSD$

PORTNAME=	parley
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Vocabulary trainer for KDE 4

USES=		cmake:outsource kde:4 tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	kdelibs libkdeedu attica automoc4
USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xrender

.include <bsd.port.mk>
