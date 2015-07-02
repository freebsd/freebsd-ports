# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amqp
PORTVERSION=	1.5.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the AMQP protocol for RabbitMQ clients

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-amq-protocol>=1.9.2:${PORTSDIR}/net/rubygem-amq-protocol \
		rubygem-eventmachine>=0:${PORTSDIR}/devel/rubygem-eventmachine

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
