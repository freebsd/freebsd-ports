# New ports collection makefile for:	bgpq
# Date created:				21 Jan 2002
# Whom:					Alexandre Snarskii <snar@paranoia.ru>
#
# $FreeBSD$

PORTNAME=	bgpq
PORTVERSION=	1.0.7.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	snar@paranoia.ru

MAN8=		bgpq.8

HAS_CONFIGURE=	yes

post-install:
	strip ${PREFIX}/bin/bgpq

.include <bsd.port.mk>
