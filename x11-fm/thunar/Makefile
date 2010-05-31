# New ports collection makefile for:	thunar
# Date created:		19.04.2006
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Thunar
PORTVERSION=	1.0.2
CATEGORIES=	x11-fm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 file manager

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils glib20 gnomehack gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libexo libutil

OPTIONS=	DBUS		"Enable D-BUS support"				on  \
		JPEG		"Enable JPEG support"				on  \
		FAM		"Enable FAM support"				on  \
		HAL		"Enable HAL support"				on  \
		GCONF		"Enable GCONF support"				off \
		STARTUP		"Enable startup notification support"		on  \
		PLUG_APR	"Thunar Advanced Properties plugin"		on  \
		PLUG_APR_EXIF	"Exif support for the APR plugin"		off \
		PLUG_SBR	"Thunar Simple Builtin Renamers plugin"		on  \
		PLUG_SBR_PCRE	"Regular expression support for the SBR plugin"	off \
		PLUG_TPA	"Thunar Trash Panel Applet plugin"		on  \
		PLUG_UCA	"Thunar User Customizable Actions plugin"	on  \
		PLUG_WALL	"Thunar Wallpaper plugin"			on


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

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--enable-jpeg
.else
CONFIGURE_ARGS+=--disable-jpeg
.endif

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.endif

.if defined(WITH_FAM)
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
.endif

.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
.else
CONFIGURE_ARGS+=--disable-gconf
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
.if !defined(WITH_FAM)
	@${REINPLACE_CMD} -e 's|gamin|no-gamin|g; s|fam|no-fam|g' ${WRKSRC}/configure
.endif
.if !defined(WITH_HAL)
	@${REINPLACE_CMD} -e 's|hal-storage|no-hal-storage|g' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|enable_val|enableval|g' ${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
