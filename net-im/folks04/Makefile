# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net-im/folks04/Makefile,v 1.2 2012/04/27 13:28:44 kwm Exp $

PORTNAME=	folks
PORTVERSION=	0.4.3
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	04

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to aggregate people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	libgee.so:${PORTSDIR}/devel/libgee06 \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

CONFLICTS=	folks-0.[6-9].[0-9]*

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	intlhack gnomehier
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=22

.include <bsd.port.mk>
