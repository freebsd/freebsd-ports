# ex:ts=8
# Ports collection makefile for:	gofish
# Date created:			Apr 1, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gofish
PORTVERSION=	0.29
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gioria@FreeBSD.org
COMMENT=	GoFish Gopher Server

GOPHERROOT?=	${PREFIX}/gopher
GOPHERUSER?=	nobody
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gopherroot=${GOPHERROOT} \
		--with-gopheruser=${GOPHERUSER}

MAN1=	gmap2cache.1 gofish.1 gopherd.1 mkcache.1
MAN5=	dotcache.5 gofish.5

.include <bsd.port.mk>
