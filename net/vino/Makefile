# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/net/vino/Makefile 19321 2014-03-25 13:15:22Z gusi $

PORTNAME=	vino
PORTVERSION=	3.12.0
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC server that allows for remote access to your GNOME desktop

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libavahi-glib.so:${PORTSDIR}/net/avahi-app

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack
USE_XORG=	xdamage xfixes xtst
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--without-network-manager \
		--disable-http-server
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.Vino.enums.xml org.gnome.Vino.gschema.xml

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--without-libnotify
.endif

.include <bsd.port.mk>
