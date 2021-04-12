# Created by: Oliver Lehmann <oliver@FreeBSD.org>

PORTNAME=	xfce4-settings
PORTVERSION=	4.16.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 settings application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcolord.so:graphics/colord \
		libfontconfig.so:x11-fonts/fontconfig \
		libxklavier.so:x11/libxklavier

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome \
		libtool python pkgconfig shebangfix tar:bzip2 xfce xorg
USE_GNOME=	cairo glib20 gtk30 intltool
USE_XFCE=	garcon libexo xfconf
USE_XORG=	xorgproto x11 xcursor xi xrandr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pluggable-dialogs
INSTALLS_ICONS=	yes
SHEBANG_FILES=	dialogs/mime-settings/helpers/xfce4-compose-mail

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NOTIFY NLS UPOWER LIBINPUT
OPTIONS_DEFAULT=	NOTIFY
OPTIONS_SUB=		yes
OPTIONS_DEFAULT_FreeBSD_12=	LIBINPUT
OPTIONS_DEFAULT_FreeBSD_13=	LIBINPUT
OPTIONS_DEFAULT_FreeBSD_14=	LIBINPUT
OPTIONS_DEFAULT+=	${OPTIONS_DEFAULT_${OPSYS}_${OSREL:R}}

UPOWER_DESC=		Power management tasks
LIBINPUT_DESC=		Libinput support

NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext-runtime

NOTIFY_CONFIGURE_ENABLE=	libnotify
NOTIFY_LIB_DEPENDS=		libnotify.so:devel/libnotify

UPOWER_CONFIGURE_ENABLE=	upower-glib
UPOWER_LIB_DEPENDS=		libupower-glib.so:sysutils/upower

LIBINPUT_BUILD_DEPENDS=	${LOCALBASE}/include/xorg/libinput-properties.h:x11-drivers/xf86-input-libinput
LIBINPUT_CONFIGURE_ENABLE=	xorg-libinput

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Rodent|Adwaita|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c
	@${REINPLACE_CMD} -e 's|IconThemeName" type="empty|IconThemeName" type="string" value="Adwaita|' \
		${WRKSRC}/xfsettingsd/xsettings.xml

.include <bsd.port.mk>
