# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net-im/telepathy-haze/Makefile,v 1.7 2012/06/13 00:59:50 mezz Exp $

PORTNAME=	telepathy-haze
PORTVERSION=	0.6.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-haze/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libpurple connection manager for telepathy

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	purple:${PORTSDIR}/net-im/libpurple \
		idn:${PORTSDIR}/dns/libidn \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig

MAN8=		telepathy-haze.8

NO_STAGE=	yes
.include <bsd.port.mk>
