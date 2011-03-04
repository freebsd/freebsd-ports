# New ports collection makefile for:	thunar
# Date created:		19.04.2006
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Thunar
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	x11-fm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME:L}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 file manager

LIB_DEPENDS=	tumbler-1.0:${PORTSDIR}/deskutils/xfce4-tumbler

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils glib20 gnomehack gtk20 intltool intlhack pkgconfig gdkpixbuf2
USE_LDCONFIG=	yes
USE_XFCE=	configenv libexo libmenu libutil
USE_XORG=	sm x11

OPTIONS=	DBUS		"Enable D-BUS support"				on  \
		NLS		"Enable Native Language Support"		on  \
		STARTUP		"Enable startup notification support"		on  \
		NOTIFY		"Enable mount notifications support"		on  \
		APIDOCS		"Install api documentation"			on  \
		PLUG_APR	"Thunar Advanced Properties plugin"		on  \
		PLUG_APR_EXIF	"Exif support for the APR plugin"		off \
		PLUG_SBR	"Thunar Simple Builtin Renamers plugin"		on  \
		PLUG_SBR_PCRE	"Regular expression support for the SBR plugin"	off \
		PLUG_TPA	"Thunar Trash Panel Applet plugin"		on  \
		PLUG_UCA	"Thunar User Customizable Actions plugin"	on  \
		PLUG_WALL	"Thunar Wallpaper plugin"			on

CONFIGURE_ARGS+=	--disable-debug \
		--enable-gio-unix \
		--disable-gudev

MAN1=		Thunar.1

.include  <bsd.port.pre.mk>

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	WITH_DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	WITH_DBUS="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-notifications
.else
CONFIGURE_ARGS+=--disable-notifications
.endif

.if defined(WITHOUT_APIDOCS)
CONFIGURE_ARGS+=	--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.else
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.endif

.if !defined(WITHOUT_PLUG_APR)
CONFIGURE_ARGS+=--enable-apr-plugin
PLIST_SUB+=	PLUGIN_APR=""
.if defined(WITH_PLUG_APR_EXIF)
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
CONFIGURE_ARGS+=--enable-exif
.else
CONFIGURE_ARGS+=--disable-exif
.endif
.else
CONFIGURE_ARGS+=--disable-apr-plugin --disable-exif
PLIST_SUB+=	PLUGIN_APR="@comment "
.endif

.if !defined(WITHOUT_PLUG_SBR)
CONFIGURE_ARGS+=--enable-sbr-plugin
PLIST_SUB+=	PLUGIN_SBR=""
.if defined(WITH_PLUG_SBR_PCRE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--enable-pcre
.else
CONFIGURE_ARGS+=--disable-pcre
.endif
.else
CONFIGURE_ARGS+=--disable-sbr-plugin --disable-pcre
PLIST_SUB+=	PLUGIN_SBR="@comment "
.endif

.if !defined(WITHOUT_PLUG_TPA)
#USE_XFCE+=	xfcehack
CONFIGURE_ARGS+=--enable-tpa-plugin
PLIST_SUB+=	PLUGIN_TPA=""
USE_XFCE+=	panel
.else
CONFIGURE_ARGS+=--disable-tpa-plugin
PLIST_SUB+=	PLUGIN_TPA="@comment "
.endif

.if !defined(WITHOUT_PLUG_UCA)
CONFIGURE_ARGS+=--enable-uca-plugin
PLIST_SUB+=	PLUGIN_UCA=""
.else
CONFIGURE_ARGS+=--disable-uca-plugin
PLIST_SUB+=	PLUGIN_UCA="@comment "
.endif

.if !defined(WITHOUT_PLUG_WALL)
CONFIGURE_ARGS+=--enable-wallpaper-plugin
PLIST_SUB+=	PLUGIN_WALL=""
.else
CONFIGURE_ARGS+=--disable-wallpaper-plugin
PLIST_SUB+=	PLUGIN_WALL="@comment "
.endif

.if !defined(WITHOUT_STARTUP)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if (${OSVERSION} < 701000)
CFLAGS+=	-DHAVE_SYS_MOUNT_H
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/docs/Makefile.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|enable_val|enableval|g' ${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
