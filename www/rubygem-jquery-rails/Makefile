# Ports collection makefile for:	rubygem-jquery-rails
# Date created:				13 January 2011
# Whom:					Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$

PORTNAME=	jquery-rails
PORTVERSION=	0.2.7
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Provides a rails generator for jquery

RUN_DEPENDS+=	rubygem-rails>=3.0:${PORTSDIR}/www/rubygem-rails \
		rubygem-thor>=0.14.4:${PORTSDIR}/devel/rubygem-thor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
