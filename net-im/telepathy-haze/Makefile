# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/telepathy-haze/Makefile 18907 2013-11-21 19:28:11Z gusi $

PORTNAME=	telepathy-haze
PORTVERSION=	0.6.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-haze/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libpurple connection manager for telepathy

LIB_DEPENDS=	libpurple.so:${PORTSDIR}/net-im/libpurple \
		libidn.so:${PORTSDIR}/dns/libidn \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

USES=		gmake pathfix pkgconfig
USE_GNOME=	libxslt:build
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
