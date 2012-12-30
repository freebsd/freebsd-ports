# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	Thunar
PORTVERSION=	1.6.2
CATEGORIES=	x11-fm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME:L}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce file manager

LIB_DEPENDS=	tumbler-1:${PORTSDIR}/deskutils/xfce4-tumbler

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils gnomehack gtk20 intltool intlhack gdkpixbuf2
USE_LDCONFIG=	yes
USE_XFCE=	configenv libexo libmenu libutil
USE_XORG=	sm x11
USE_PKGCONFIG=	build

OPTIONS_DEFINE=	DBUS DOCS GVFS NLS NOTIFY STARTUP
OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS=	PLUG_APR PLUG_SBR PLUG_TPA PLUG_UCA PLUG_WALL
OPTIONS_DEFAULT=	DBUS GVFS NOTIFY PLUG_APR PLUG_SBR PLUG_UCA PLUG_WALL STARTUP

# Override NOTIFY_DESC
NOTIFY_DESC=	Display notifications
STARTUP_DESC=	Startup notification
PLUG_APR_DESC=	Thunar Advanced Properties plugin
PLUG_SBR_DESC=	Thunar Simple Builtin Renamers plugin
PLUG_TPA_DESC=		Thunar Trash Panel Applet plugin
PLUG_UCA_DESC=		Thunar User Customizable Actions plugin
PLUG_WALL_DESC=		Thunar Wallpaper plugin

CONFIGURE_ARGS+=	--disable-gtk-doc-html \
		--enable-gio-unix \
		--disable-gudev

MAN1=		Thunar.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	WITH_DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	WITH_DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
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
LIB_DEPENDS+=	exif:${PORTSDIR}/graphics/libexif
CONFIGURE_ARGS+=--enable-apr-plugin --enable-exif
PLIST_SUB+=	PLUGIN_APR=""
.else
CONFIGURE_ARGS+=--disable-apr-plugin --disable-exif
PLIST_SUB+=	PLUGIN_APR="@comment "
.endif

.if ${PORT_OPTIONS:MPLUG_SBR}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
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
LIB_DEPENDS+=	startup-notification-1:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if ${PORT_OPTIONS:MGVFS}
USE_GNOME+=gvfs
.endif

post-patch:
# Downgrade GLib to 2.28
	@${REINPLACE_CMD} -e 's|2.30.|2.28.|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name '*.c' -type f \
		| ${XARGS} ${REINPLACE_CMD} -e \
		's|g_format_size (|g_format_size_for_display (|g'

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
