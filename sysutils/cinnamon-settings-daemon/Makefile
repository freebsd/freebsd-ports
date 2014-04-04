# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/cinnamon-settings-daemon/Makefile 19448 2014-04-04 07:28:02Z gusi $

PORTNAME=	cinnamon-settings-daemon
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 settings daemon

BUILD_DEPENDS=	cinnamon-session:${PORTSDIR}/x11/cinnamon-session \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
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
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_GNOME=	gnomehier gnomeprefix intlhack libgnomekbd \
		libxslt:build
USES=		gettext gmake pathfix pkgconfig tar:xz
USE_XORG=	xxf86misc
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool autoconf automake
PATHFIX_MAKEFILEIN=	Makefile.am
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gudev \
		--disable-systemd \
		--disable-packagekit \
		--with-gnome-distributor="FreeBSD GNOME Project"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.cinnamon.settings-daemon.enums.xml \
		org.cinnamon.settings-daemon.peripherals.gschema.xml \
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

OPTIONS_DEFINE=	CUPS SMARTCARD
OPTIONS_DEFAULT=CUPS SMARTCARD
SMARTCARD_DESC=	Smartcard support

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
		${WRKSRC}/data/org.cinnamon.settings-daemon.plugins.xrandr.gschema.xml.in.in

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/cinnamon-settings-daemon-3.0/lib*.so

.include <bsd.port.mk>
