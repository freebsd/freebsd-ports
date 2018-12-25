# Created by: Kris Moore
# $FreeBSD$

PORTNAME=	kmplayer
PORTVERSION=	0.11.5b
PORTREVISION=	3
PORTEPOCH=	3
CATEGORIES=	multimedia audio kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE frontend to Phonon / KDE4

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

NOT_FOR_ARCHS=		aarch64
NOT_FOR_ARCHS_REASON=	prcpucfg.h:764:2: error: "Unknown CPU architecture"

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libphonon.so:multimedia/phonon@qt4 \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		cmake gettext-runtime kde:4 pkgconfig qt:4
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_QT=		corelib dbus gui network svg xml \
		moc_build qmake_build rcc_build uic_build
USE_KDE=	automoc4 kdelibs soprano
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	KDE

PORTSCOUT=	limit:^0.11.

.include <bsd.port.mk>
