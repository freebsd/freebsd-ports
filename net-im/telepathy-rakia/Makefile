# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-rakia/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	telepathy-rakia
PORTVERSION=	0.8.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SIP connection manager based around the Sofia-SIP library

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libsofia-sip-ua-glib.so:net/sofia-sip \
		libtelepathy-glib.so:net-im/telepathy-glib

USES=		gmake pathfix pkgconfig python:build
USE_GNOME=	glib20 libxslt:build
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
