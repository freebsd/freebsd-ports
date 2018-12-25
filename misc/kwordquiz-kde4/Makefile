# $FreeBSD$

PORTNAME=	kwordquiz
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	misc kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Flash card trainer for KDE 4

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs libkeduvocdocument automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
