PORTNAME=	xfce4-settings
PORTVERSION=	4.18.4
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 settings application
WWW=		https://docs.xfce.org/xfce/xfce4-settings/start

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcolord.so:graphics/colord \
		libfontconfig.so:x11-fonts/fontconfig \
		libxklavier.so:x11/libxklavier

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome \
		libtool pkgconfig python shebangfix tar:bzip2 xfce xorg
USE_GNOME=	cairo glib20 gdkpixbuf2 gtk30 intltool
USE_XFCE=	garcon libexo xfconf
USE_XORG=	x11 xcursor xi xorgproto xrandr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pluggable-dialogs
SHEBANG_FILES=	dialogs/mime-settings/helpers/xfce4-compose-mail

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		LIBINPUT NLS NOTIFY UPOWER
OPTIONS_DEFAULT=	LIBINPUT NOTIFY
OPTIONS_SUB=		yes

LIBINPUT_DESC=		Libinput support
UPOWER_DESC=		Power management tasks

LIBINPUT_BUILD_DEPENDS=	${LOCALBASE}/include/xorg/libinput-properties.h:x11-drivers/xf86-input-libinput
LIBINPUT_CONFIGURE_ENABLE=	xorg-libinput

NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext-runtime

NOTIFY_CONFIGURE_ENABLE=	libnotify
NOTIFY_LIB_DEPENDS=		libnotify.so:devel/libnotify

UPOWER_CONFIGURE_ENABLE=	upower-glib
UPOWER_LIB_DEPENDS=		libupower-glib.so:sysutils/upower

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Rodent|elementary-xfce|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c
	@${REINPLACE_CMD} -e 's|IconThemeName" type="empty|IconThemeName" type="string" value="elementary-xfce|' \
		${WRKSRC}/xfsettingsd/xsettings.xml

.include <bsd.port.mk>
