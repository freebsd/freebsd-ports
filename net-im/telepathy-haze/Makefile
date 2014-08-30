# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net-im/telepathy-haze/Makefile,v 1.7 2012/06/13 00:59:50 mezz Exp $

PORTNAME=	telepathy-haze
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-haze/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libpurple connection manager for telepathy

LIB_DEPENDS=	libpurple.so:${PORTSDIR}/net-im/libpurple \
		libidn.so:${PORTSDIR}/dns/libidn \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig
USE_GNOME=	libxslt:build

.include <bsd.port.mk>
