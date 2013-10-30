# $FreeBSD$

PORTNAME=	redis-rack
PORTVERSION=	1.5.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis Store for Rack

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

RUN_DEPENDS=	rubygem-rack15>=1.5:${PORTSDIR}/www/rubygem-rack15 \
		rubygem-redis-store>=1.1.0:${PORTSDIR}/devel/rubygem-redis-store


.include <bsd.port.mk>
