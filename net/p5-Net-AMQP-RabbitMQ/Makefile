PORTNAME=	Net-AMQP-RabbitMQ
PORTVERSION=	2.40012
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interact with RabbitMQ over AMQP using librabbitmq
WWW=		https://github.com/net-amqp-rabbitmq/net-amqp-rabbitmq

NOT_FOR_ARCHS=		mips mips64
NOT_FOR_ARCHS_REASON=	Endianness not known

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Math-Int64>0.34:math/p5-Math-Int64

USES=		perl5
USE_PERL5=	configure

PORTSCOUT=	skipv:2.200002,2.200001,2.200000,2.100001,2.100000

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/AMQP/RabbitMQ/RabbitMQ.so

.include <bsd.port.mk>
