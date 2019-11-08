# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-settings-daemon
PORTVERSION=	2.4.3
PORTREVISION=	6
CATEGORIES=	sysutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 settings daemon

BUILD_DEPENDS=	cinnamon-session:x11/cinnamon-session \
		gnome-autogen.sh:devel/gnome-common \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libpolkit-gobject-1.so:sysutils/polkit \
		libibus-1.0.so:textproc/ibus \
		libdbus-1.so:devel/dbus \
		libcolord.so:graphics/colord \
		liblcms2.so:graphics/lcms2 \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libpulse.so:audio/pulseaudio \
		libgdbm.so:databases/gdbm \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	cinnamon-session:x11/cinnamon-session \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		autoreconf gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack libgnomekbd \
		libxslt:build
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gudev \
		--disable-systemd \
		--disable-packagekit \
		--with-gnome-distributor="FreeBSD GNOME Project"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.cinnamon.settings-daemon.enums.xml \
		org.cinnamon.settings-daemon.peripherals.gschema.xml \
		org.cinnamon.settings-daemon.plugins.background.gschema.xml \
		org.cinnamon.settings-daemon.plugins.color.gschema.xml \
		org.cinnamon.settings-daemon.plugins.gschema.xml \
		org.cinnamon.settings-daemon.plugins.housekeeping.gschema.xml \
		org.cinnamon.settings-daemon.plugins.keyboard.gschema.xml \
		org.cinnamon.settings-daemon.plugins.media-keys.gschema.xml \
		org.cinnamon.settings-daemon.plugins.orientation.gschema.xml \
		org.cinnamon.settings-daemon.plugins.power.gschema.xml \
		org.cinnamon.settings-daemon.plugins.print-notifications.gschema.xml \
		org.cinnamon.settings-daemon.plugins.xrandr.gschema.xml \
		org.cinnamon.settings-daemon.plugins.xsettings.gschema.xml \

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CUPS SMARTCARD
OPTIONS_DEFAULT=CUPS SMARTCARD
SMARTCARD_DESC=	Smartcard support
CUPS_CONFIGURE_ENABLE=	cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups
SMARTCARD_CONFIGURE_ENABLE=	smartcard-support
SMARTCARD_LIB_DEPENDS=	libnss3.so:security/nss

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/gnome|${PREFIX}/etc/gnome|g' \
		${WRKSRC}/data/org.cinnamon.settings-daemon.plugins.xrandr.gschema.xml.in.in
	@${REINPLACE_CMD} -e '/wacom/d' \
		${WRKSRC}/data/Makefile.am

.include <bsd.port.mk>
