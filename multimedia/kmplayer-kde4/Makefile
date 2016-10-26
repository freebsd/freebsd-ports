# Created by: Kris Moore
# $FreeBSD$

PORTNAME=	kmplayer
PORTVERSION=	0.11.5b
PORTEPOCH=	3
CATEGORIES=	multimedia audio kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE frontend to Phonon / KDE4

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libphonon.so:multimedia/phonon \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		cmake:outsource gettext-runtime kde:4 pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_QT4=	corelib dbus gui network svg xml \
		moc_build qmake_build rcc_build uic_build
USE_KDE=	automoc4 kdelibs soprano
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	KDE

PORTSCOUT=	limit:^0.11.

.include <bsd.port.mk>
