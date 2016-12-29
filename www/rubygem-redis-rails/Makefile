# $FreeBSD$

PORTNAME=	redis-rails
PORTVERSION=	4.0.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis for Ruby on Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-redis-actionpack4>=4:databases/rubygem-redis-actionpack4 \
		rubygem-redis-activesupport>=4:devel/rubygem-redis-activesupport \
		rubygem-redis-store>=1.1.0:devel/rubygem-redis-store

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
