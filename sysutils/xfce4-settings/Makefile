# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-settings
PORTVERSION=	4.10.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 settings application

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	configenv garcon libexo libmenu libutil xfconf
USE_XORG=	inputproto x11 xi
USES=		pathfix pkgconfig gmake

CONFIGURE_ARGS=	--enable-pluggable-dialogs \
		--enable-gio-unix

OPTIONS_DEFINE=		XKLAVIER XCURSOR XRANDR NOTIFY NLS SOUND
OPTIONS_DEFAULT=	XKLAVIER XCURSOR XRANDR NOTIFY NLS
SOUND_DESC=		Enable sound control

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXKLAVIER}
LIB_DEPENDS+=	libxklavier.so:${PORTSDIR}/x11/libxklavier
CONFIGURE_ARGS+=--enable-libxklavier
.else
CONFIGURE_ARGS+=--disable-libxklavier
.endif

.if ${PORT_OPTIONS:MXCURSOR}
USE_XORG+=	xcursor
CONFIGURE_ARGS+=--enable-xcursor
.else
CONFIGURE_ARGS+=--disable-xcursor
.endif

.if ${PORT_OPTIONS:MXRANDR}
USE_XORG+=	xrandr
CONFIGURE_ARGS+=--enable-xrandr
PLIST_SUB+=	XRANDR=""
.else
CONFIGURE_ARGS+=--disable-xrandr
PLIST_SUB+=	XRANDR="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSOUND}
LIB_DEPENDS+=	libcanberra.so:${PORTSDIR}/audio/libcanberra
CONFIGURE_ARGS+=--enable-sound-settings
.else
CONFIGURE_ARGS+=--disable-sound-settings
.endif

post-patch:
	# until xfce4-icon-theme is back we rely on Tango
	@${REINPLACE_CMD} -e 's|Rodent|Tango|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c
	@${REINPLACE_CMD} -e 's|IconThemeName" type="empty|IconThemeName" type="string" value="Tango|; \
		s|"ThemeName" type="empty|"ThemeName" type="string" value="Xfce|' \
		${WRKSRC}/xfsettingsd/xsettings.xml
	@${REINPLACE_CMD} -e 's|xkl_config_registry_load (settings->priv->xkl_registry)|xkl_config_registry_load (settings->priv->xkl_registry, FALSE)|g; \
		s|xkl_engine_stop_listen (settings->priv->xkl_engine)|xkl_engine_stop_listen (settings->priv->xkl_engine, FALSE)|g' \
		${WRKSRC}/dialogs/keyboard-settings/xfce-keyboard-settings.c

.include <bsd.port.mk>
