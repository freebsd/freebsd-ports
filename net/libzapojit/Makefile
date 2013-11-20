# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/net/libzapojit/Makefile 18583 2013-06-23 11:12:45Z kwm $

PORTNAME=	libzapojit
PORTVERSION=	0.0.2
CATEGORIES=	net devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GObject wrapper for the Skydrive and Hotmail API

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		librest-0.7.so:${PORTSDIR}/devel/librest

USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
