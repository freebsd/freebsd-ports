# New ports collection makefile for:	gnomecontrolcenter2
# Date created:				04 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomecontrolcenter2
PORTVERSION=	2.10.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/control-center/2.10
DISTNAME=	control-center-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 2 project

LIB_DEPENDS=	xklavier.10:${PORTSDIR}/x11/libxklavier

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_GSTREAMER=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack metacity nautilus2 \
		gnomemenus desktopfileutils
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GCONF_SCHEMAS=	apps_gnome_settings_daemon_default_editor.schemas \
		apps_gnome_settings_daemon_keybindings.schemas \
		apps_gnome_settings_daemon_screensaver.schemas \
		desktop_gnome_font_rendering.schemas \
		desktop_gnome_peripherals_keyboard_xkb.schemas \
		fontilus.schemas themus.schemas

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[{]prefix[}]/share/pixmaps|{datadir}/pixmaps|g'
	@${REINPLACE_CMD} -e 's|mozilla-thunderbird|thunderbird|g' \
		${WRKSRC}/capplets/default-applications/gnome-default-applications-properties-structs.c
	@${REINPLACE_CMD} -e 's|/bin/tar|/usr/bin/tar|g ; \
		s|/bin/gzip|/usr/bin/gzip|g' \
		${WRKSRC}/capplets/theme-switcher/gnome-theme-installer.c

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
