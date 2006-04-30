# New ports collection makefile for:	gnomecontrolcenter2
# Date created:				04 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnomecontrolcenter2/Makefile,v 1.109 2006/04/18 02:28:56 marcus Exp $
#

PORTNAME=	gnomecontrolcenter2
PORTVERSION=	2.14.1
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/control-center/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	control-center-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 2 project

LIB_DEPENDS=	xklavier.10:${PORTSDIR}/x11/libxklavier

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_GSTREAMER=	good
WANT_GNOME=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack metacity nautilus2 \
		gnomemenus desktopfileutils nautilus2
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS= --enable-gstreamer=0.10 \
		--disable-hal
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GCONF_SCHEMAS=	apps_gnome_settings_daemon_default_editor.schemas \
		apps_gnome_settings_daemon_keybindings.schemas \
		apps_gnome_settings_daemon_screensaver.schemas \
		desktop_gnome_font_rendering.schemas \
		desktop_gnome_peripherals_keyboard_xkb.schemas \
		fontilus.schemas themus.schemas

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mevolutiondataserver}!=""
USE_GNOME+=	evolutiondataserver
CONFIGURE_ARGS+=--enable-aboutme
PLIST_SUB+=	ABOUTME=""
.else
CONFIGURE_ARGS+=--disable-aboutme
PLIST_SUB+=	ABOUTME="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[{]prefix[}]/share/pixmaps|{datadir}/pixmaps|g'
	@${REINPLACE_CMD} -e 's|/bin/tar|/usr/bin/tar|g ; \
		s|/bin/gzip|/usr/bin/gzip|g' \
		${WRKSRC}/capplets/theme-switcher/gnome-theme-installer.c

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
