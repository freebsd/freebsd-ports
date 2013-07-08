# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amq-client
PORTVERSION=	1.0.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A fully-featured, low-level AMQP 0.9.1 client in Ruby

RUN_DEPENDS=	rubygem-amq-protocol>=0.9.0:${PORTSDIR}/net/rubygem-amq-protocol \
		rubygem-eventmachine>=0:${PORTSDIR}/devel/rubygem-eventmachine

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
