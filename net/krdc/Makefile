# $FreeBSD$

PORTNAME=	krdc
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	net kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDP and VNC client for KDE

LIB_DEPENDS=	libvncserver.so:net/libvncserver \
		libtelepathy-qt4.so:net-im/telepathy-qt4

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	FREERDP
FREERDP_DESC=	Remote Desktop support via FreeRDP
FREERDP_RUN_DEPENDS=	xfreerdp:net/freerdp

.include <bsd.port.mk>
