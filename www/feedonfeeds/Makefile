# ex:ts=8
# Ports collection makefile for:	feedonfeeds
# Date created:			Jul 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	feedonfeeds
PORTVERSION=	0.1.7
CATEGORIES=	www
MASTER_SITES=	http://minutillo.com/steve/feedonfeeds/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server side personal RSS (and Atom) aggregator

USE_PHP=	yes
WANT_PHP_WEB=	yes
USE_MYSQL=	yes
NO_BUILD=	yes
DATADIR?=	${PREFIX}/www/data/feedonfeeds

do-install:
	${CP} -R ${WRKSRC}/ ${DATADIR}

.include <bsd.port.mk>
