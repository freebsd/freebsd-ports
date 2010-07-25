# New ports collection makefile for:	gnome-settings-daemon
# Date created:				14 Jan 2008
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/sysutils/gnome-settings-daemon/Makefile,v 1.4 2010/06/23 20:44:39 kwm Exp $
#

PORTNAME=	gnome-settings-daemon
PORTVERSION=	2.30.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 settings daemon

LIB_DEPENDS=	pulse.0:${PORTSDIR}/audio/pulseaudio \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb

USE_XORG=	xxf86misc
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop libgnomekbd
USE_GETTEXT=	yes
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	apps_gnome_settings_daemon_housekeeping.schemas \
		apps_gnome_settings_daemon_keybindings.schemas \
		apps_gnome_settings_daemon_xrandr.schemas \
		desktop_gnome_font_rendering.schemas \
		desktop_gnome_keybindings.schemas \
		desktop_gnome_peripherals_touchpad.schemas \
		gnome-settings-daemon.schemas

.include <bsd.port.mk>
