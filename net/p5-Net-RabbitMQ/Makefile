PORTNAME=	Net-RabbitMQ
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JESUS
PKGNAMEPREFIX=	p5-
DISTNAME=	Net--RabbitMQ-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module to interact with RabbitMQ over AMQP using librabbitmq

BUILD_DEPENDS=	${LOCALBASE}/sbin/rabbitmqctl:net/rabbitmq
RUN_DEPENDS=	${LOCALBASE}/sbin/rabbitmqctl:net/rabbitmq

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/._*

.include <bsd.port.mk>
