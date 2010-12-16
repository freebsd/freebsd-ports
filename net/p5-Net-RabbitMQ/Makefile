# New ports collection makefile for:	p5-Net-RabbitMQ
# Date created:		2010-09-07
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Net-RabbitMQ
PORTVERSION=	0.1.8
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=		../../authors/id/J/JE/JESUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module to interact with RabbitMQ over AMQP using librabbitmq

BUILD_DEPENDS=	${LOCALBASE}/sbin/rabbitmqctl:${PORTSDIR}/net/rabbitmq
RUN_DEPENDS=	${LOCALBASE}/sbin/rabbitmqctl:${PORTSDIR}/net/rabbitmq

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=		Net::RabbitMQ.3

.include <bsd.port.mk>
