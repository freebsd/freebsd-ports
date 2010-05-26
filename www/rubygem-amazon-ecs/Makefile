# New ports collection makefile for:	rubygem-amazon-ecs
# Date created:		2007-07-18
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	amazon-ecs
PORTVERSION=	0.5.7
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A generic Amazon E-commerce REST API written in Ruby

BUILD_DEPENDS=	rubygem-hpricot>=0.4:${PORTSDIR}/www/rubygem-hpricot \
		${RUBY_PKGNAMEPREFIX}hmac>=0.3.2:${PORTSDIR}/security/ruby-hmac
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
