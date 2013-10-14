# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Thunar
PORTVERSION=	1.6.3
CATEGORIES=	x11-fm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME:L}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce file manager

LIB_DEPENDS=	libtumbler-1.so:${PORTSDIR}/deskutils/xfce4-tumbler

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20 intltool intlhack gdkpixbuf2
USE_LDCONFIG=	yes
USE_XFCE=	configenv libexo libmenu libutil
USE_XORG=	sm x11
USES=		desktop-file-utils gmake pathfix perl5 pkgconfig

OPTIONS_DEFINE=	DBUS DOCS GVFS NLS NOTIFY STARTUP
OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS=	PLUG_APR PLUG_SBR PLUG_TPA PLUG_UCA PLUG_WALL
OPTIONS_DEFAULT=	DBUS GVFS NOTIFY PLUG_APR PLUG_SBR PLUG_UCA PLUG_WALL STARTUP

# Override NOTIFY_DESC
NOTIFY_DESC=	Display notifications
STARTUP_DESC=	Startup notification
PLUG_APR_DESC=	Advanced Properties plugin
PLUG_SBR_DESC=	Simple Builtin Renamers plugin
PLUG_TPA_DESC=	Trash Panel Applet plugin
PLUG_UCA_DESC=	User Customizable Actions plugin
PLUG_WALL_DESC=	Wallpaper plugin

CONFIGURE_ARGS+=--enable-gio-unix \
		--disable-gudev

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	WITH_DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	WITH_DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-notifications
.else
CONFIGURE_ARGS+=--disable-notifications
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=	--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MPLUG_APR}
LIB_DEPENDS+=	libexif.so:${PORTSDIR}/graphics/libexif
CONFIGURE_ARGS+=--enable-apr-plugin --enable-exif
PLIST_SUB+=	PLUGIN_APR=""
.else
CONFIGURE_ARGS+=--disable-apr-plugin --disable-exif
PLIST_SUB+=	PLUGIN_APR="@comment "
.endif

.if ${PORT_OPTIONS:MPLUG_SBR}
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--enable-sbr-plugin --enable-pcre
PLIST_SUB+=	PLUGIN_SBR=""
.else
CONFIGURE_ARGS+=--disable-sbr-plugin --disable-pcre
PLIST_SUB+=	PLUGIN_SBR="@comment "
.endif

.if ${PORT_OPTIONS:MPLUG_TPA}
CONFIGURE_ARGS+=--enable-tpa-plugin
PLIST_SUB+=	PLUGIN_TPA=""
USE_XFCE+=	panel
.else
CONFIGURE_ARGS+=--disable-tpa-plugin
PLIST_SUB+=	PLUGIN_TPA="@comment "
.endif

.if ${PORT_OPTIONS:MPLUG_UCA}
CONFIGURE_ARGS+=--enable-uca-plugin
PLIST_SUB+=	PLUGIN_UCA=""
.else
CONFIGURE_ARGS+=--disable-uca-plugin
PLIST_SUB+=	PLUGIN_UCA="@comment "
.endif

.if ${PORT_OPTIONS:MPLUG_WALL}
CONFIGURE_ARGS+=--enable-wallpaper-plugin
PLIST_SUB+=	PLUGIN_WALL=""
.else
CONFIGURE_ARGS+=--disable-wallpaper-plugin
PLIST_SUB+=	PLUGIN_WALL="@comment "
.endif

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if ${PORT_OPTIONS:MGVFS}
USE_GNOME+=gvfs
.endif

.include <bsd.port.mk>
