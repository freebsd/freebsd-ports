# Ports collection makefile for:	rubygem-amqp
# Date created:				20 Feb 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amqp
PORTVERSION=	0.8.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An implementation of the AMQP protocol for RabbitMQ clients

RUN_DEPENDS=	rubygem-eventmachine>=0:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-amq-client>=0.8.3:${PORTSDIR}/net/rubygem-amq-client \
		rubygem-amq-protocol>=0.8.0:${PORTSDIR}/net/rubygem-amq-protocol

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
