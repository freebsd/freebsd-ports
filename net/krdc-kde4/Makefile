# $FreeBSD$

PORTNAME=	krdc
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	6
CATEGORIES=	net kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDP and VNC client for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libvncserver.so:net/libvncserver \
		libtelepathy-qt4.so:net-im/telepathy-qt@qt4

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	FREERDP
FREERDP_DESC=	Remote Desktop support via FreeRDP
FREERDP_RUN_DEPENDS=	xfreerdp:net/freerdp

.include <bsd.port.mk>
