# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-settings-daemon/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	gnome-settings-daemon
PORTVERSION=	3.14.3
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 settings daemon

BUILD_DEPENDS=	gnome-session>=0:${PORTSDIR}/x11/gnome-session \
		geoclue>=0:${PORTSDIR}/net/geoclue \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcolord.so:${PORTSDIR}/graphics/colord \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libgdbm.so:${PORTSDIR}/databases/gdbm \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgeocode-glib.so:${PORTSDIR}/net/geocode-glib \
		libgweather-3.so:${PORTSDIR}/net/libgweather
RUN_DEPENDS=	gnome-session>=0:${PORTSDIR}/x11/gnome-session \
		geoclue>=0:${PORTSDIR}/net/geoclue \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XORG=	xxf86misc
USE_GNOME=	gnomedesktop3 gnomeprefix intlhack libxslt
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-gudev \
		--disable-systemd \
		--disable-rfkill \
		--disable-network-manager \
		--disable-packagekit
#		--disable-ibus \
#--with-pnpids=${LOCALBASE}/share/libgnome-desktop-3.0/pnp.ids
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CUPS SMARTCARD
OPTIONS_DEFAULT=CUPS SMARTCARD
SMARTCARD_DESC=	Smartcard support
CUPS_CONFIGURE_ENABLE=	cups
CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client
SMARTCARD_CONFIGURE_ENABLE=	smartcard-support
SMARTCARD_LIB_DEPENDS=	libnss3.so:${PORTSDIR}/security/nss

GLIB_SCHEMAS=	org.gnome.settings-daemon.enums.xml \
		org.gnome.settings-daemon.peripherals.gschema.xml \
		org.gnome.settings-daemon.plugins.color.gschema.xml \
		org.gnome.settings-daemon.plugins.datetime.gschema.xml \
		org.gnome.settings-daemon.plugins.gschema.xml \
		org.gnome.settings-daemon.plugins.housekeeping.gschema.xml \
		org.gnome.settings-daemon.plugins.keyboard.gschema.xml \
		org.gnome.settings-daemon.plugins.media-keys.gschema.xml \
		org.gnome.settings-daemon.plugins.power.gschema.xml \
		org.gnome.settings-daemon.plugins.print-notifications.gschema.xml \
		org.gnome.settings-daemon.plugins.sharing.gschema.xml \
		org.gnome.settings-daemon.plugins.xrandr.gschema.xml \
		org.gnome.settings-daemon.plugins.xsettings.gschema.xml
# work around missing cursor with xorg-server 1.12.
GLIB_SCHEMAS+=	cursor-plugin.gschema.override

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/gnome|${PREFIX}/etc/gnome|g' \
		${WRKSRC}/data/org.gnome.settings-daemon.plugins.xrandr.gschema.xml.in.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/cursor-plugin.gschema.override \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas

.include <bsd.port.mk>
