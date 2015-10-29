# Created by: arved
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	1.3.1
CATEGORIES=	multimedia kde
MASTER_SITES=	SF/kaffeine/current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia player based on KDE and VLC

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libvlc.so:${PORTSDIR}/multimedia/vlc

USES=		cmake cpe gettext gmake pkgconfig
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	corelib dbus gui network phonon sql svg xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	xscrnsaver

CPE_VENDOR=	kaffeine
CPE_PRODUCT=	kaffeine_player

.include <bsd.port.mk>
