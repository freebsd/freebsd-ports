# New ports collection makefile for:	gnome-jabber
# Date created:				4 July 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-jabber
PORTVERSION=	0.4
PORTREVISION=	8
CATEGORIES=	net-im gnome
MASTER_SITES=	SF

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 Jabber Client

LIB_DEPENDS=	gnet-2.0.0:${PORTSDIR}/net/gnet2

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-jabber.schemas

.include <bsd.port.mk>
