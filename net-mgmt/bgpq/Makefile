# New ports collection makefile for:	bgpq
# Date created:				21 Jan 2002
# Whom:					Alexandre Snarskii <snar@paranoia.ru>
#
# $FreeBSD$

PORTNAME=	bgpq
PORTVERSION=	1.0.7.6
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	snar@paranoia.ru
COMMENT=	Bgpq - lightweight access-list generator for cisco routers

MAN8=		bgpq.8
PLIST_FILES=	bin/bgpq

HAS_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${PREFIX}/bin/bgpq

.include <bsd.port.mk>
