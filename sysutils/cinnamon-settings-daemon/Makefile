# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-settings-daemon
PORTVERSION=	2.4.3
CATEGORIES=	sysutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 settings daemon

BUILD_DEPENDS=	cinnamon-session:${PORTSDIR}/x11/cinnamon-session \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcolord.so:${PORTSDIR}/graphics/colord \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libcinnamon-desktop.so:${PORTSDIR}/x11/cinnamon-desktop \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libgdbm.so:${PORTSDIR}/databases/gdbm \
		libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	cinnamon-session:${PORTSDIR}/x11/cinnamon-session \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		autoreconf:build gettext gmake libtool pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack libgnomekbd \
		libxslt:build
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_XORG=	xxf86misc
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
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
CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client
SMARTCARD_CONFIGURE_ENABLE=	smartcard-support
SMARTCARD_LIB_DEPENDS=	libnss3.so:${PORTSDIR}/security/nss

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/gnome|${PREFIX}/etc/gnome|g' \
		${WRKSRC}/data/org.cinnamon.settings-daemon.plugins.xrandr.gschema.xml.in.in
	@${REINPLACE_CMD} -e '/wacom/d' \
		${WRKSRC}/data/Makefile.am

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
