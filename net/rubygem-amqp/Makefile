# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amqp
PORTVERSION=	1.6.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the AMQP protocol for RabbitMQ clients

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-amq-protocol>=2.0.1:net/rubygem-amq-protocol \
		rubygem-eventmachine>=0:devel/rubygem-eventmachine

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
