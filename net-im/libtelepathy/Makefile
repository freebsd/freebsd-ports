# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/libtelepathy/Makefile 19913 2014-09-25 22:29:26Z kwm $

PORTNAME=	libtelepathy
PORTVERSION=	0.3.3
PORTREVISION=	3
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Flexible Communications Framework

LIB_DEPENDS=	libtelepathy-glib.so:net-im/telepathy-glib \
		libdbus-glib-1.so:devel/dbus-glib

USES=		gmake libtool pathfix pkgconfig python:2.7,build
USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxslt:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lglib-2.0 `pkg-config --libs telepathy-glib`
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
