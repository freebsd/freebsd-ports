# $FreeBSD$

PORTNAME=	redis-rails
PORTVERSION=	5.0.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Redis for Ruby on Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-redis-actionpack-rails5>0:databases/rubygem-redis-actionpack-rails5 \
		rubygem-redis-activesupport-rails5>0:devel/rubygem-redis-activesupport-rails5 \
		rubygem-redis-store>=1.2:devel/rubygem-redis-store

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
