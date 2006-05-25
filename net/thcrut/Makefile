# Ports collection makefile for:  thcrut
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thcrut
PORTVERSION=	1.2.5
CATEGORIES=	net
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	Local network discovery tool

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libnet=${LOCALBASE} \
		 	--sysconfdir=${DATADIR}

.include <bsd.port.mk>
