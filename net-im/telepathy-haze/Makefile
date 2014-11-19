# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/telepathy-haze/Makefile 19801 2014-08-13 09:46:10Z gusi $

PORTNAME=	telepathy-haze
PORTVERSION=	0.8.0
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
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
