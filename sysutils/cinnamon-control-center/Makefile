# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-control-center
PORTVERSION=	2.4.2
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/9363a4a1e121344ae98f22b55fb28623cf0f6038/panels/datetime/data/:tzpng
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	gnome3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for Cinnamon

BUILD_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		cinnamon-settings-daemon>=0:sysutils/cinnamon-settings-daemon \
		gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libupower-glib.so:sysutils/upower \
		libcheese.so:multimedia/cheese \
		libcaribou.so:accessibility/caribou \
		libgtop-2.0.so:devel/libgtop \
		libmuffin.so:x11-wm/muffin \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libtelepathy-logger.so:net-im/telepathy-logger \
		libgnomekbdui.so:x11/libgnomekbd \
		libfolks.so:net-im/folks \
		libpulse.so:audio/pulseaudio \
		libcroco-0.6.so:textproc/libcroco \
		libdbus-glib-1.so:devel/dbus-glib \
		libclutter-glx-1.0.so:graphics/clutter \
		libclutter-gst-2.0.so:multimedia/clutter-gst \
		libcinnamon-menu-3.so:x11/cinnamon-menus \
		libgjs.so:lang/gjs
RUN_DEPENDS=	py*-dbus>=0:devel/py-dbus \
		cinnamon-settings-daemon>=0:sysutils/cinnamon-settings-daemon \
		ca_root_nss>=0:security/ca_root_nss \
		py*-lxml>=0:devel/py-lxml

USES=		autoreconf gettext gmake libtool pathfix \
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
CUPS_LIB_DEPENDS=	libcups.so:print/cups

MISSING_PNG=timezone_8.5.png timezone_8.5_dim.png
.for i in ${MISSING_PNG}
DISTFILES+=${i}:tzpng
.endfor

post-extract:
.for i in ${MISSING_PNG}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}/panels/datetime/data/.
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g' \
		${WRKSRC}/panels/common/cc-common-language.c

.include <bsd.port.mk>
