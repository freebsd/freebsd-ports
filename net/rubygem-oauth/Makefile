# New ports collection makefile for:	oauth
# Date created:				Dec 03, 2008
# Whom:					wenheping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	oauth
PORTVERSION=	0.3.5
CATEGORIES=	net rubygems
MASTER_SITES=	RF/oauth

MAINTAINER=	wenheping@gmail.com
COMMENT=	Rubygem for Creating both OAuth Consumers and Service Providers

BUILD_DEPENDS=	${RUBY_PKGNAMEPREFIX}hmac>=0.3.2:${PORTSDIR}/security/ruby-hmac
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=		bin/oauth

.include <bsd.port.mk>
