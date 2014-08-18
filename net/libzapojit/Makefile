# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/net/libzapojit/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	libzapojit
PORTVERSION=	0.0.3
CATEGORIES=	net devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GObject wrapper for the Skydrive and Hotmail API

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		librest-0.7.so:${PORTSDIR}/devel/librest

USES=		gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
