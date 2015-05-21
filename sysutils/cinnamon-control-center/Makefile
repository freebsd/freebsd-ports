# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-control-center
PORTVERSION=	2.4.2
CATEGORIES=	sysutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for Cinnamon

BUILD_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss \
		cinnamon-settings-daemon>=0:${PORTSDIR}/sysutils/cinnamon-settings-daemon \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libcheese.so:${PORTSDIR}/multimedia/cheese \
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
		libcinnamon-menu-3.so:${PORTSDIR}/x11/cinnamon-menus \
		libgjs.so:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	py*-dbus>=0:${PORTSDIR}/devel/py-dbus \
		cinnamon-settings-daemon>=0:${PORTSDIR}/sysutils/cinnamon-settings-daemon \
		ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml

USES=		autoreconf:build gettext gmake libtool pathfix \
		python:2 pkgconfig
USE_GNOME=	evolutiondataserver3 gconf2 gnomeprefix \
		gtk30 intlhack libgnomekbd
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_XORG=	x11 xfixes sm
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-compile-warnings=no
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS
CUPS_CONFIGURE_ENABLE=	cups
CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client

post-patch:
	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g' \
		${WRKSRC}/panels/common/cc-common-language.c

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
