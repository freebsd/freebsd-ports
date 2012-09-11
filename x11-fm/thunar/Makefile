# New ports collection makefile for:	thunar
# Date created:		19.04.2006
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Thunar
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	x11-fm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 file manager

LIB_DEPENDS=	tumbler-1.0:${PORTSDIR}/deskutils/xfce4-tumbler

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils gnomehack gtk20 intltool intlhack pkgconfig gdkpixbuf2
USE_LDCONFIG=	yes
USE_XFCE=	configenv libexo libmenu libutil
USE_XORG=	sm x11

OPTIONS_DEFINE=	 STARTUP DBUS NOTIFY NLS DOCS PLUG_APR PLUG_APR_EXIF PLUG_SBR PLUG_SBR_PCRE PLUG_TPA PLUG_UCA PLUG_WALL GVFS
OPTIONS_DEFAULT= STARTUP DBUS NOTIFY PLUG_APR PLUG_SBR PLUG_SBR_PCRE PLUG_UCA PLUG_WALL GVFS
STARTUP_DESC=	Enable startup notification support
PLUG_APR_DESC=	Thunar Advanced Properties plugin
PLUG_APR_EXIF_DESC=	Exif support for the APR plugin
PLUG_SBR_DESC=	Thunar Simple Builtin Renamers plugin
PLUG_SBR_PCRE_DESC=	Regular expression support for the SBR plugin
PLUG_TPA_DESC=		Thunar Trash Panel Applet plugin
PLUG_UCA_DESC=		Thunar User Customizable Actions plugin
PLUG_WALL_DESC=		Thunar Wallpaper plugin

CONFIGURE_ARGS+=	--disable-gtk-doc-html \
		--enable-gio-unix \
		--disable-gudev

MAN1=		Thunar.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
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
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
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
CONFIGURE_ARGS+=--enable-apr-plugin
PLIST_SUB+=	PLUGIN_APR=""
.if ${PORT_OPTIONS:MPLUG_APR_EXIF}
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
CONFIGURE_ARGS+=--enable-exif
.else
CONFIGURE_ARGS+=--disable-exif
.endif
.else
CONFIGURE_ARGS+=--disable-apr-plugin --disable-exif
PLIST_SUB+=	PLUGIN_APR="@comment "
.endif

.if ${PORT_OPTIONS:MPLUG_SBR}
CONFIGURE_ARGS+=--enable-sbr-plugin
PLIST_SUB+=	PLUGIN_SBR=""
.if ${PORT_OPTIONS:MPLUG_SBR_PCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--enable-pcre
.else
CONFIGURE_ARGS+=--disable-pcre
.endif
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
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if ${PORT_OPTIONS:MGVFS}
USE_GNOME+=gvfs
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
