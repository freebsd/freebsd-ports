# $FreeBSD$

PORTNAME=	redis-rails
PORTVERSION=	5.0.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis for Ruby on Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-redis-actionpack-rails60>5.0<6:databases/rubygem-redis-actionpack-rails60 \
		rubygem-redis-activesupport-rails60>5.0<6:devel/rubygem-redis-activesupport-rails60 \
		rubygem-redis-store>=1.2<2:devel/rubygem-redis-store

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
