# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	cinnamon-control-center
PORTVERSION=	1.8.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	gnome-control-center replacement for Cinnamon

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gnome-settings-daemon>=3.4.0:${PORTSDIR}/sysutils/gnome-settings-daemon \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libcheese.so:${PORTSDIR}/multimedia/cheese \
		libkrb5support.so:${PORTSDIR}/security/krb5 \
		libcaribou.so:${PORTSDIR}/accessibility/caribou \
		libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libmuffin.so:${PORTSDIR}/x11-wm/muffin \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libtelepathy-logger.so:${PORTSDIR}/net-im/telepathy-logger \
		libgnomekbdui.so:${PORTSDIR}/x11/libgnomekbd \
		libfolks.so:${PORTSDIR}/net-im/folks \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libcroco-0.6.so:${PORTSDIR}/textproc/libcroco \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter \
		libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst \
		libgjs.so:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		gnome-settings-daemon>=3.4.0:${PORTSDIR}/sysutils/gnome-settings-daemon \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml

FETCH_ARGS=	-Fpr
USE_XORG=	x11 xfixes sm
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack gtk30 gconf2 gnomemenus3 \
		gnomedesktop3 evolutiondataserver3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env automake:env aclocal:env autoheader:env
USE_PYTHON=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS+=--enable-compile-warnings=no

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
PLIST_SUB+=	CUPS=""
.else
CONFIGURE_ARGS+=--disable-cups
PLIST_SUB+=	CUPS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g' \
		${WRKSRC}/panels/common/cc-common-language.c

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

.include <bsd.port.mk>
