# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-settings-daemon/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	gnome-settings-daemon
PORTVERSION=	3.12.2
PORTREVISION=	1
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
USE_GNOME=	gnomehier gnomedesktop3 gnomeprefix intlhack
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-gudev \
		--disable-systemd \
		--disable-rfkill \
		--disable-packagekit
#		--disable-ibus \
#--with-pnpids=${LOCALBASE}/share/libgnome-desktop-3.0/pnp.ids
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	CUPS SMARTCARD
OPTIONS_DEFAULT=CUPS SMARTCARD
SMARTCARD_DESC=	Smartcard support

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
		org.gnome.settings-daemon.plugins.xrandr.gschema.xml \
		org.gnome.settings-daemon.plugins.xsettings.gschema.xml
# work around missing cursor with xorg-server 1.12.
GLIB_SCHEMAS+=	cursor-plugin.gschema.override

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
PLIST_SUB+=	CUPS=""
.else
PLIST_SUB+=	CUPS="@comment "
CONFIGURE_ARGS+=--disable-cups
.endif

.if ${PORT_OPTIONS:MSMARTCARD}
LIB_DEPENDS+=	libnss3.so:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=--enable-smartcard-support
PLIST_SUB+=	SMARTCARD=""
.else
CONFIGURE_ARGS+=--disable-smartcard-support
PLIST_SUB+=	SMARTCARD="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/gnome|${PREFIX}/etc/gnome|g' \
		${WRKSRC}/data/org.gnome.settings-daemon.plugins.xrandr.gschema.xml.in.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/cursor-plugin.gschema.override \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas

.include <bsd.port.mk>
