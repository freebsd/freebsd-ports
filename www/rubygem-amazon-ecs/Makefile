# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	amazon-ecs
PORTVERSION=	2.2.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Generic Amazon E-commerce REST API written in Ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-nokogiri>=1.4:${PORTSDIR}/textproc/rubygem-nokogiri \
		${RUBY_PKGNAMEPREFIX}hmac>=0.3:${PORTSDIR}/security/ruby-hmac

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
