# $FreeBSD$

PORTNAME=	redis-rack
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Redis Store for Rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rack16>=1.5:www/rubygem-rack16 \
		rubygem-redis-store>=1.2.0:devel/rubygem-redis-store

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
