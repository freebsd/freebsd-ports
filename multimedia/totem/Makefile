# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$
#   $MCom: ports/multimedia/totem/Makefile,v 1.151 2010/09/27 19:04:37 kwm Exp $

PORTNAME=	totem
PORTVERSION=	2.32.0
PORTREVISION?=	6
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Gstreamer-based video player for the GNOME 2 Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	libgdata.so:${PORTSDIR}/devel/libgdata \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon \
		${PYTHON_SITELIBDIR}/atom/__init__.py:${PORTSDIR}/devel/py-gdata

CONFLICTS=	totem-3.[0-9]*

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake libtool:keepla pathfix \
		pkgconfig python shebangfix tar:bzip2
SHEBANG_FILES=	data/totem-bugreport.py
USE_GNOME=	gnomehier gnomeprefix intlhack nautilus2 pygtk2
USE_GSTREAMER=	core gconf hal good mpeg2dec soup ugly python gio
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lXrandr
CONFIGURE_ENV=	BROWSER_PLUGIN_DIR="${WEBPLUGIN_DIR}"
CONFIGURE_ARGS=	--with-plugins="${TOTEM_PLUGINS}"

GCONF_SCHEMAS=	totem-handlers.schemas totem-video-thumbnail.schemas \
		totem.schemas

OPTIONS_DEFINE=	LIRC GALAGO BROWSER_PLUGINS PUBLISH TRACKER
GALAGO_DESC=	Galago support
BROWSER_PLUGINS_DESC=	Plugins for gecko browser
PUBLISH_DESC=	Publish (network playlist) plugin
TRACKER_DESC=	Tracker local search plugin

OPTIONS_DEFAULT=	BROWSER_PLUGINS
# check configure script for allowed_plugins="..." for new plugins
TOTEM_PLUGINS=	thumbnail screensaver ontop gromit media-player-keys \
		properties skipto youtube opensubtitles screenshot \
		brasero-disc-recorder coherence_upnp dbus-service iplayer

# Not using:
# TOTEM_PLUGINS= mythtv bemused jamendo

.include <bsd.port.options.mk>

.if defined(WITH_PUBLISH)
LIB_DEPENDS+=	libepc-1.0.so:${PORTSDIR}/www/libepc
PLIST_SUB+=	PUBLISH=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} publish
.else
PLIST_SUB+=	PUBLISH="@comment "
.endif

#.if defined(WITH_TRACKER)
#LIB_DEPENDS+=	tracker-gtk.0:${PORTSDIR}/sysutils/tracker-libtrackergtk
#TOTEM_PLUGINS:=	${TOTEM_PLUGINS} tracker
#PLIST_SUB+=	TRACKER=""
#.else
PLIST_SUB+=	TRACKER="@comment "
#.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	liblirc_client.so:${PORTSDIR}/comms/lirc
PLIST_SUB+=	LIRC=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} lirc
.else
PLIST_SUB+=	LIRC="@comment "
.endif

.if ${PORT_OPTIONS:MGALAGO}
LIB_DEPENDS+=	libgalago.so:${PORTSDIR}/devel/libgalago
PLIST_SUB+=	GALAGO=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} galago
.else
PLIST_SUB+=	GALAGO="@comment "
.endif

.if ${PORT_OPTIONS:MBROWSER_PLUGINS}
CONFIGURE_ARGS+=--enable-browser-plugins \
		--enable-gmp-plugin \
		--enable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS=""

USES+=		webplugin:native
WEBPLUGIN_FILES=	libtotem-cone-plugin.so libtotem-gmp-plugin.so \
			libtotem-mully-plugin.so \
			libtotem-narrowspace-plugin.so
.else
CONFIGURE_ARGS+=--disable-browser-plugins \
		--disable-basic-plugin \
		--disable-gmp-plugin \
		--disable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS="@comment "
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
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/backend/bacon-video-widget-gst-0.10.c

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vala/vapi
	${INSTALL_DATA} ${WRKSRC}/bindings/vala/totem.vapi ${STAGEDIR}${PREFIX}/share/vala/vapi
	${INSTALL_DATA} ${WRKSRC}/bindings/vala/totem.deps ${STAGEDIR}${PREFIX}/share/vala/vapi

.include <bsd.port.mk>
