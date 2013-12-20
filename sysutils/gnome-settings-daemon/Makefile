# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-settings-daemon3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-settings-daemon
PORTVERSION=	3.6.3
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 settings daemon

BUILD_DEPENDS=	gnome-session>=3.0.0:${PORTSDIR}/x11/gnome-session \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcolord.so:${PORTSDIR}/graphics/colord \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libgdbm.so:${PORTSDIR}/databases/gdbm \
		libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	gnome-session>=3.0.0:${PORTSDIR}/x11/gnome-session \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XORG=	xxf86misc
USE_XZ=		yes
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 libgnomekbd gnomehier
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-gudev \
		--disable-systemd \
		--disable-packagekit
#		--disable-ibus \
#--with-pnpids=${LOCALBASE}/share/libgnome-desktop-3.0/pnp.ids
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS SMARTCARD
OPTIONS_DEFAULT=CUPS SMARTCARD
SMARTCARD_DESC=	Smartcard support

GLIB_SCHEMAS=	org.gnome.settings-daemon.enums.xml \
		org.gnome.settings-daemon.peripherals.gschema.xml \
		org.gnome.settings-daemon.plugins.color.gschema.xml \
		org.gnome.settings-daemon.plugins.gschema.xml \
		org.gnome.settings-daemon.plugins.housekeeping.gschema.xml \
		org.gnome.settings-daemon.plugins.keyboard.gschema.xml \
		org.gnome.settings-daemon.plugins.media-keys.gschema.xml \
		org.gnome.settings-daemon.plugins.power.gschema.xml \
		org.gnome.settings-daemon.plugins.print-notifications.gschema.xml \
		org.gnome.settings-daemon.plugins.xrandr.gschema.xml \
		org.gnome.settings-daemon.plugins.xsettings.gschema.xml

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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnome-settings-daemon-3.0/lib*.so

.include <bsd.port.mk>
