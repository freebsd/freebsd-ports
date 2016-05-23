# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	thunar-vfs
PORTVERSION=	1.2.0
PORTREVISION=	11
CATEGORIES=	x11-fm xfce
MASTER_SITES=	XFCE/src/archive/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	The virtual filesystem for Thunar

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libgamin-1.so:devel/gamin

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 gdkpixbuf2 intltool intlhack
USE_XFCE=	libexo
USE_XORG=	x11
USES=		desktop-file-utils gettext-tools gmake jpeg libtool pathfix perl5 pkgconfig \
		xfce tar:bzip2

CONFIGURE_ARGS=	--disable-debug --without-html-dir

OPTIONS_DEFINE=	NLS HAL DBUS STARTUP GCONF
OPTIONS_DEFAULT=	HAL DBUS STARTUP
STARTUP_DESC=	Startup notification
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
HAL_LIB_DEPENDS=	libhal.so:sysutils/hal
HAL_CONFIGURE_WITH=	volume-manager=hal
HAL_CONFIGURE_OFF=	--with-volume-manager=freebsd
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_CONFIGURE_ENABLE=	dbus
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
STARTUP_CONFIGURE_ENABLE=	startup-notification
GCONF_USE=	gnome=gconf2
GCONF_CONFIGURE_ENABLE=	gnome-thumbnailers
OPTIONS_SUB=	yes

.include <bsd.port.mk>
