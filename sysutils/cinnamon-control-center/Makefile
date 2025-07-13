PORTNAME=	cinnamon-control-center
DISTVERSION=	6.4.1
CATEGORIES=	sysutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for Cinnamon
WWW=		https://github.com/linuxmint/cinnamon-control-center

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	iso-codes>0:misc/iso-codes
LIB_DEPENDS=	libcinnamon-desktop.so:x11/cinnamon-desktop \
		libcinnamon-menu-3.so:x11/cinnamon-menus \
		libfontconfig.so:x11-fonts/fontconfig \
		libnotify.so:devel/libnotify \
		libpolkit-gobject-1.so:sysutils/polkit \
		libxklavier.so:x11/libxklavier \
		libupower-glib.so:sysutils/upower \
		libgudev-1.0.so:devel/libgudev
RUN_DEPENDS=	iso-codes>0:misc/iso-codes

USES=		gettext gnome meson pkgconfig python:build shebangfix xorg
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libgnomekbd
USE_XORG=	x11 xorgproto

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_LDCONFIG=	yes

MESON_ARGS=	-Dnetworkmanager=false \
		-Dmodemmanager=false

SHEBANG_GLOB=	*.py

GLIB_SCHEMAS=	org.cinnamon.control-center.display.gschema.xml

OPTIONS_DEFINE=		COLORD WACOM
OPTIONS_DEFAULT=	COLORD WACOM
OPTIONS_SUB=		yes

WACOM_DESC=		Wacom management panel support

COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_MESON_TRUE=	color

WACOM_LIB_DEPENDS=	libwacom.so:x11/libwacom
WACOM_USE=		XORG=xi
WACOM_MESON_TRUE=	wacom

.include <bsd.port.mk>
