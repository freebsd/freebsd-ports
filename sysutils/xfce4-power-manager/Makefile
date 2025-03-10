PORTNAME=	xfce4-power-manager
PORTVERSION=	4.20.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Power manager for the Xfce Desktop
WWW=		https://gitlab.xfce.org/xfce/xfce4-power-manager

LICENSE=	GPLv2

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libnotify.so:devel/libnotify \
		libpolkit-gobject-1.so:sysutils/polkit \
		libupower-glib.so:sysutils/upower

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_XFCE=	libmenu panel xfconf
USE_XORG=	ice sm x11 xext xrandr xscrnsaver xtst

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-network-manager \
		--enable-polkit \
		--enable-x11 \
		--enable-xfce4panel
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS WAYLAND
OPTIONS_DEFAULT=	WAYLAND
OPTIONS_SUB=		yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

WAYLAND_LIB_DEPENDS=		libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	wayland

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.post.mk>
