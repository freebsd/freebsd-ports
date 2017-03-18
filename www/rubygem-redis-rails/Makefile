# $FreeBSD$

PORTNAME=	redis-rails
PORTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis for Ruby on Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-redis-actionpack>=5:databases/rubygem-redis-actionpack \
		rubygem-redis-activesupport>=5:devel/rubygem-redis-activesupport \
		rubygem-redis-store>=1.2.0:devel/rubygem-redis-store

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
