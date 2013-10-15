# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xfce4-power-manager
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Power manager for the Xfce Desktop

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify \
	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext pkgconfig gmake
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	configenv libutil libmenu panel xfconf
INSTALLS_ICONS=	yes
USE_XORG=	xrandr x11 xext
CONFIGURE_ARGS=	--disable-network-manager \
		--enable-polkit

.include <bsd.port.mk>
