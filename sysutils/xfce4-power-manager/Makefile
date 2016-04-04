# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xfce4-power-manager
PORTVERSION=	1.6.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME}/${PORTVERSION:R}/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Power manager for the Xfce Desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libnotify.so:devel/libnotify \
	libdbus-glib-1.so:devel/dbus-glib \
	libpolkit-gobject-1.so:sysutils/polkit \
	libupower-glib.so:sysutils/upower

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	glib20 gtk30 intltool intlhack
USE_XFCE=	panel
INSTALLS_ICONS=	yes
USE_XORG=	xrandr x11 xext xtst xscrnsaver
CONFIGURE_ARGS=	--disable-network-manager \
		--enable-polkit \
		--enable-xfce4panel
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
