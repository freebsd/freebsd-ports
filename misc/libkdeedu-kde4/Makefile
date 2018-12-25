# $FreeBSD$

PORTNAME=	libkdeedu
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	misc kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries used by KDE educational applications

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		corelib gui xml moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
