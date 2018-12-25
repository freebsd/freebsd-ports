# $FreeBSD$

PORTNAME=	krfb
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	net kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VNC server for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt@qt4

USES=		alias cmake jpeg kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		corelib gui network \
		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
