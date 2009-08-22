# New ports collection makefile for: giFToxic
# Date Created:			23 December 2003
# Whom:				Joel Diaz <joeldiaz@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	giFToxic
PORTVERSION=	0.0.9
PORTREVISION=	9
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	joeldiaz@bellsouth.net
COMMENT=	GTK2 client for giFT

LIB_DEPENDS=	gift.0:${PORTSDIR}/net-p2p/gift

USE_GNOME=	gtk20 gnomeprefix gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-included-gettext

.include <bsd.port.mk>
