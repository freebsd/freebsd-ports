# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amqp
PORTVERSION=	1.8.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the AMQP protocol for RabbitMQ clients

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-amq-protocol>=2.2.0:net/rubygem-amq-protocol \
		rubygem-eventmachine>=0:devel/rubygem-eventmachine

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
