# New ports collection makefile for:	gnome-settings-daemon
# Date created:				14 Jan 2008
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-settings-daemon/Makefile,v 1.16 2008/03/14 06:19:50 mezz Exp $
#

PORTNAME=	gnome-settings-daemon
PORTVERSION=	2.22.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 settings daemon

USE_XORG=	xxf86misc
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop libgnomekbd
USE_GETTEXT=	yes
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gstreamer=0.10
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	apps_gnome_settings_daemon_keybindings.schemas \
		apps_gnome_settings_daemon_screensaver.schemas \
		desktop_gnome_font_rendering.schemas \
		gnome-settings-daemon.schemas

.include <bsd.port.mk>
