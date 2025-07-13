PORTNAME=	cinnamon-settings-daemon
DISTVERSION=	6.4.3
CATEGORIES=	sysutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cinnamon desktop settings daemon
WWW=		https://github.com/linuxmint/cinnamon-settings-daemon

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gln:sysutils/coreutils
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libxklavier.so:x11/libxklavier \
		libnspr4.so:devel/nspr \
		libfontconfig.so:x11-fonts/fontconfig \
		libupower-glib.so:sysutils/upower \
		libpulse.so:audio/pulseaudio \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	cinnamon-session:x11/cinnamon-session

USES=		compiler:c11 gettext-runtime gnome meson pkgconfig \
		python:build shebangfix xorg
USE_GNOME=	cairo dconf gdkpixbuf glib20 gtk30 libgnomekbd pango
USE_XORG=	x11 xext xfixes xi xorgproto

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

MESON_ARGS=	-Duse_logind=disabled

SHEBANG_GLOB=	*.py
BINARY_ALIAS=	ln=gln

USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.cinnamon.settings-daemon.enums.xml \
		org.cinnamon.settings-daemon.peripherals.gschema.xml \
		org.cinnamon.settings-daemon.peripherals.wacom.gschema.xml \
		org.cinnamon.settings-daemon.plugins.color.gschema.xml \
		org.cinnamon.settings-daemon.plugins.gschema.xml \
		org.cinnamon.settings-daemon.plugins.housekeeping.gschema.xml \
		org.cinnamon.settings-daemon.plugins.media-keys.gschema.xml \
		org.cinnamon.settings-daemon.plugins.power.gschema.xml \
		org.cinnamon.settings-daemon.plugins.xrandr.gschema.xml \
		org.cinnamon.settings-daemon.plugins.xsettings.gschema.xml

OPTIONS_DEFINE=		COLORD CUPS GUDEV POLKIT SMARTCARD WACOM
OPTIONS_DEFAULT=	COLORD CUPS GUDEV POLKIT SMARTCARD WACOM
OPTIONS_SUB=		yes

COLORD_MESON_ENABLED=	use_color
COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord \
			liblcms2.so:graphics/lcms2

CUPS_MESON_ENABLED=	use_cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

GUDEV_DESC=		GUdev support
GUDEV_MESON_ENABLED=	use_gudev
GUDEV_LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev

POLKIT_DESC=		Polkit support
POLKIT_MESON_ENABLED=	use_polkit
POLKIT_LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

SMARTCARD_DESC=		Smartcard support
SMARTCARD_MESON_ENABLED=use_smartcard
SMARTCARD_LIB_DEPENDS=	libnss3.so:security/nss

WACOM_DESC=		Tablet support with libwacom
WACOM_MESON_ENABLED=	use_wacom
WACOM_LIB_DEPENDS=	libwacom.so:x11/libwacom
WACOM_USE=		GNOME=librsvg2
WACOM_IMPLIES=		GUDEV

.include <bsd.port.mk>
