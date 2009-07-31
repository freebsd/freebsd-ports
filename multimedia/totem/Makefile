# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#   $MCom: ports/multimedia/totem/Makefile,v 1.126 2009/04/03 10:17:44 kwm Exp $
#

PORTNAME=	totem
PORTVERSION=	2.26.3
PORTREVISION?=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A gstreamer-based video player for the GNOME 2 Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	musicbrainz:${PORTSDIR}/audio/libmusicbrainz \
		totem-plparser.12:${PORTSDIR}/multimedia/totem-pl-parser
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon \
		${PYTHON_SITELIBDIR}/atom/__init__.py:${PORTSDIR}/devel/py-gdata

USE_PYTHON=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack desktopfileutils \
		nautilus2 ltverhack pygtk2
GNOME_DESKTOP_VERSION=2
WANT_GSTREAMER=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib -lXrandr" \
		BROWSER_PLUGIN_DIR="${WEBPLUGINS_DIR}"
CONFIGURE_ARGS=	--with-plugins="${TOTEM_PLUGINS}"

MAN1=		totem.1 totem-video-thumbnailer.1
GCONF_SCHEMAS=	totem-handlers.schemas totem-video-thumbnail.schemas \
		totem.schemas
CONFLICTS?=	totem-xine-[0-9]*

OPTIONS=	LIRC "Enable lirc support" off \
		GALAGO "Enable Galago support" off \
		BROWSER_PLUGINS "Enable install plugins for gecko browser" on \
		PUBLISH "Enable Publish (network playlist) plugin" off \
		TRACKER "Enable tracker local search plugin" off

# check configure script for allowed_plugins="..." for new plugins
TOTEM_PLUGINS=	thumbnail screensaver ontop gromit media-player-keys \
		properties skipto youtube
# Not using:
# TOTEM_PLUGINS= mythtv bemused

.include <bsd.port.pre.mk>

.if defined(WITH_PUBLISH)
LIB_DEPENDS+=	epc-1.0.2:${PORTSDIR}/www/libepc
PLIST_SUB+=	PUBLISH=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} publish
.else
PLIST_SUB+=	PUBLISH="@comment "
.endif

.if defined(WITH_TRACKER)
LIB_DEPENDS+=	tracker-gtk.0:${PORTSDIR}/sysutils/tracker-libtrackergtk
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} tracker
PLIST_SUB+=	TRACKER=""
.else
PLIST_SUB+=	TRACKER="@comment "
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
PLIST_SUB+=	LIRC=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} lirc
.else
PLIST_SUB+=	LIRC="@comment "
.endif

.if defined(WITH_GALAGO)
LIB_DEPENDS+=	galago.3:${PORTSDIR}/devel/libgalago
PLIST_SUB+=	GALAGO=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} galago
.else
PLIST_SUB+=	GALAGO="@comment "
.endif

.if !defined(WITHOUT_BROWSER_PLUGINS)
CONFIGURE_ARGS+=--enable-browser-plugins \
		--enable-gmp-plugin \
		--enable-complex-plugin \
		--enable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS=""

USE_WEBPLUGINS=		gecko19 webkit-gtk2
WEBPLUGINS_FILES=	libtotem-basic-plugin.so libtotem-complex-plugin.so \
			libtotem-cone-plugin.so libtotem-gmp-plugin.so \
			libtotem-mully-plugin.so \
			libtotem-narrowspace-plugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.else
CONFIGURE_ARGS+=--disable-browser-plugins \
		--disable-basic-plugin \
		--disable-gmp-plugin \
		--disable-complex-plugin \
		--disable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS="@comment "
.endif

.if !defined(WITH_TOTEM_XINE) || ${SLAVE_PORT}=="no"
CONFIGURE_ARGS+=--enable-gstreamer=yes
USE_GSTREAMER+=	core gconf hal good mpeg2dec soup ugly python gio
WITHOUT_DVDNAV=	yes
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--enable-xine=yes
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if defined(WITH_DVDNAV) && !defined(WITHOUT_DVDNAV)
LIB_DEPENDS+=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav
.endif

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif

pre-everything::
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"

post-patch:
	@${CP} -f ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
	@${REINPLACE_CMD} -e 's|dbus >= 0.61|dbus-1 >= 0.61|g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/backend/bacon-video-widget-gst-0.10.c

post-install:
	@-update-desktop-database
	${MKDIR} ${PREFIX}/share/vala/vapi
	${INSTALL_DATA} ${WRKSRC}/bindings/vala/totem.vapi ${PREFIX}/share/vala/vapi
	${INSTALL_DATA} ${WRKSRC}/bindings/vala/totem.deps ${PREFIX}/share/vala/vapi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
