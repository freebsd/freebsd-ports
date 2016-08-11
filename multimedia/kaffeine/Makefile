# Created by: arved
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	multimedia kde
MASTER_SITES=	SF/kaffeine/current

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Multimedia player based on KDE and VLC

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libvlc.so:multimedia/vlc-qt4

USES=		cmake cpe gettext pkgconfig
USE_KDE4=	automoc4 kdelibs
USE_QT4=	corelib dbus gui network phonon sql svg xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	xscrnsaver

CPE_VENDOR=	kaffeine
CPE_PRODUCT=	kaffeine_player

.include <bsd.port.mk>
