# New ports collection makefile for:	oauth
# Date created:				Dec 03, 2008
# Whom:					wenheping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	oauth
PORTVERSION=	0.3.6
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Rubygem for Creating both OAuth Consumers and Service Providers

RUN_DEPENDS=	${RUBY_PKGNAMEPREFIX}hmac>=0.3.2:${PORTSDIR}/security/ruby-hmac

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=		bin/oauth

.include <bsd.port.mk>
