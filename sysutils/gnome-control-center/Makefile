# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-control-center3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-control-center
PORTVERSION=	3.6.3
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 3 project

BUILD_DEPENDS=	gnome-settings-daemon>=3.4.0:${PORTSDIR}/sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libxklavier.so:${PORTSDIR}/x11/libxklavier \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libcolord.so:${PORTSDIR}/graphics/colord \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libsocialweb.so:${PORTSDIR}/www/libsocialweb \
		libpwquality.so:${PORTSDIR}/security/libpwquality \
		libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	gnome-eject:${PORTSDIR}/sysutils/gnome-mount \
		gnome-settings-daemon>=3.4.0:${PORTSDIR}/sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		apg:${PORTSDIR}/security/apg \
		gcm-calibrate:${PORTSDIR}/graphics/gnome-color-manager

CONFLICTS=	gnome-media-2.[0-9]*

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig shared-mime-info
USE_GNOME=	gnomeprefix gnomehier intlhack libxml2 gnomemenus3 \
		libgnomekbd gnomedesktop3 gconf2
USE_XORG=	xscrnsaver x11 xxf86misc kbproto xi
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-libsocialweb=yes --disable-systemd
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS
CUPS_DESC=	Cups (printing) support
CHEESE_DESC=	Cheese webcam support

OPTIONS_DEFINE_i386=	CHEESE
OPTIONS_DEFAULT_i386=	CHEESE
OPTIONS_DEFINE_amd64=	CHEESE
OPTIONS_DEFAULT_amd64=	CHEESE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
PLIST_SUB+=	CUPS=""
.else
PLIST_SUB+=	CUPS="@comment "
CONFIGURE_ARGS+=--disable-cups
.endif

.if ${PORT_OPTIONS:MCHEESE}
CONFIGURE_ARGS+=--with-cheese
BUILD_DEPENDS+=	cheese>=3.0.1:${PORTSDIR}/multimedia/cheese
LIB_DEPENDS+=	libcheese.so:${PORTSDIR}/multimedia/cheese
.else
CONFIGURE_ARGS+=--without-cheese
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|datetime wacom|datetime|g' \
		${WRKSRC}/panels/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/control-center-1/panels/lib*.so

.include <bsd.port.mk>
