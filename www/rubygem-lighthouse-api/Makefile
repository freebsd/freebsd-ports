# Ports collection makefile for:	rubygem-lighthouse-api
# Date created:				13 January 2011
# Whom:					Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$

PORTNAME=	lighthouse-api
PORTVERSION=	2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Ruby interface for lighthouse ticketing system

RUN_DEPENDS+=	rubygem-activesupport>=3.0.3:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-activeresource>=3.0.3:${PORTSDIR}/www/rubygem-activeresource

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
