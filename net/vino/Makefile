# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	vino
PORTVERSION=	3.18.1
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC server that allows for remote access to your GNOME desktop

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libdbus-glib-1.so:devel/dbus-glib \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libnotify.so:devel/libnotify \
		libavahi-glib.so:net/avahi-app

PORTSCOUT=	limitw:1,even

USES=		cpe gettext gmake gnome pathfix pkgconfig tar:xz
CPE_VENDOR=	david_king
USE_GNOME=	gtk30 intlhack
USE_XORG=	xdamage xfixes xtst
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.Vino.enums.xml org.gnome.Vino.gschema.xml

.include <bsd.port.mk>
