# Ports collection makefile for:	rubygem-amqp
# Date created:				Dec 16, 2011
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>	
#
# $FreeBSD$

PORTNAME=	amqp
PORTVERSION=	0.6.7
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An implementation of the AMQP protocol for RabbitMQ clients

RUN_DEPENDS=	rubygem-eventmachine>=0.12.4:${PORTSDIR}/devel/rubygem-eventmachine

NO_LATEST_LINK=	yes
PORTSCOUT=	limit:0.6.7

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
