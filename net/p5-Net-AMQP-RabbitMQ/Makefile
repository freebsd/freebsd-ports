# $FreeBSD$

PORTNAME=	Net-AMQP-RabbitMQ
PORTVERSION=	2.30000
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Interact with RabbitMQ over AMQP using librabbitmq

BUILD_DEPENDS=	p5-Math-Int64>0.34:math/p5-Math-Int64
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
