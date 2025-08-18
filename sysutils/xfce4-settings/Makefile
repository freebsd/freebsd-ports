PORTNAME=	xfce4-settings
PORTVERSION=	4.20.2
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce settings management
WWW=		https://gitlab.xfce.org/xfce/xfce4-settings

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hwdata>0:misc/hwdata
LIB_DEPENDS=	libcolord.so:graphics/colord \
		libfontconfig.so:x11-fonts/fontconfig \
		libxklavier.so:x11/libxklavier
RUN_DEPENDS=	hwdata>0:misc/hwdata

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome \
		libtool pkgconfig python shebangfix tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libxml2:build
USE_XFCE=	garcon libexo xfconf
USE_XORG=	x11 xcursor xext xi xorgproto xrandr

SHEBANG_FILES=	dialogs/mime-settings/helpers/xfce4-compose-mail
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-x11 \
		--with-pnp-ids-path=${LOCALBASE}/share/hwdata/pnp.ids
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		LIBINPUT NLS NOTIFY UPOWER WAYLAND
OPTIONS_DEFAULT=	LIBINPUT NOTIFY UPOWER WAYLAND
OPTIONS_SUB=		yes

LIBINPUT_DESC=	Libinput support
UPOWER_DESC=	Power management tasks

LIBINPUT_BUILD_DEPENDS=		xf86-input-libinput>0:x11-drivers/xf86-input-libinput
LIBINPUT_CONFIGURE_ENABLE=	xorg-libinput

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

NOTIFY_LIB_DEPENDS=		libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	libnotify

UPOWER_LIB_DEPENDS=		libupower-glib.so:sysutils/upower
UPOWER_CONFIGURE_ENABLE=	upower-glib

WAYLAND_LIB_DEPENDS=		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell \
				libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	gtk-layer-shell wayland

post-patch:
	@${REINPLACE_CMD} -e 's|Rodent|elementary-xfce|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c
	@${REINPLACE_CMD} -e 's|IconThemeName" type="string" value="Adwaita|IconThemeName" type="string" value="elementary-xfce|' \
		${WRKSRC}/xfsettingsd/xsettings.xml

.include <bsd.port.mk>
