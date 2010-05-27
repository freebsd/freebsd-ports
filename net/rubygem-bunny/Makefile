# Ports collection makefile for:	rubygem-bunny
# Date created:				19 Mar 2010
# Whom:					renchap@cocoa-x.com
#
# $FreeBSD$
#

PORTNAME=	bunny
PORTVERSION=	0.6.0
CATEGORIES=	net
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Another synchronous Ruby AMQP client

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

# we care about not passing -A to allow HTTP redirect
FETCH_ARGS=	-pRr

.include <bsd.port.mk>
