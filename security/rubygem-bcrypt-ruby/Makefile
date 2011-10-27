# Ports collection makefile for:	rubygem-bcrypt-ruby
# Date created:				13 January 2011
# Whom:					Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$

PORTNAME=	bcrypt-ruby
PORTVERSION=	3.0.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Sophisticated and secure hash algorithm for passwords

RUN_DEPENDS+=	bcrypt:${PORTSDIR}/security/bcrypt

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
