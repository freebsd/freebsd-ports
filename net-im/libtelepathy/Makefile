# $FreeBSD$
#    $MCom: ports/net-im/libtelepathy/Makefile,v 1.3 2008/02/27 14:00:06 ahze Exp $

PORTNAME=	libtelepathy
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Flexible Communications Framework

LIB_DEPENDS=	libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		gmake libtool:keepla pkgconfig python:build
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 libxslt:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib `pkg-config --libs glib-2.0 telepathy-glib`

.include <bsd.port.mk>
