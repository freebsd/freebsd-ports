# New ports collection makefile for:	gnome-settings-daemon
# Date created:				14 Jan 2008
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/sysutils/gnome-settings-daemon/Makefile,v 1.2 2009/04/18 10:59:37 kwm Exp $
#

PORTNAME=	gnome-settings-daemon
PORTVERSION=	2.26.1
PORTREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 settings daemon

LIB_DEPENDS=	pulse.0:${PORTSDIR}/audio/pulseaudio
RUN_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb

USE_XORG=	xxf86misc
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop libgnomekbd
USE_GETTEXT=	yes
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-gstreamer=0.10
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	apps_gnome_settings_daemon_keybindings.schemas \
		apps_gnome_settings_daemon_xrandr.schemas \
		apps_gnome_settings_daemon_screensaver.schemas \
		desktop_gnome_font_rendering.schemas \
		desktop_gnome_keybindings.schemas \
		gnome-settings-daemon.schemas

.include <bsd.port.mk>
