# New ports collection makefile for:	rubygem-amazon-ecs
# Date created:		2007-07-18
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	amazon-ecs
PORTVERSION=	2.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A generic Amazon E-commerce REST API written in Ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-nokogiri>=1.4.0:${PORTSDIR}/textproc/rubygem-nokogiri \
		${RUBY_PKGNAMEPREFIX}hmac>=0.3.2:${PORTSDIR}/security/ruby-hmac

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
