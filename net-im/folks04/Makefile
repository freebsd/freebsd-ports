# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net-im/folks04/Makefile,v 1.2 2012/04/27 13:28:44 kwm Exp $

PORTNAME=	folks
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gee:${PORTSDIR}/devel/libgee06 \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

CONFLICTS=	folks-0.[6-9].[0-9]*

LATEST_LINK=	${PORTNAME}04
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	intlhack gnomehier
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=22

.include <bsd.port.mk>
