# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	openid-redis-store
PORTVERSION=	0.0.2
#PORTREVISION=	0
CATEGORIES=	www ruby
MASTER_SITES=	RG

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Implementation of the ruby-openid Store interface that stores information in Redis

RUN_DEPENDS=	rubygem-redis>=0:${PORTSDIR}/databases/rubygem-redis \
	rubygem-ruby-openid>=0:${PORTSDIR}/www/rubygem-ruby-openid

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
