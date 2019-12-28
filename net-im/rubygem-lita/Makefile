# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lita
PORTVERSION=	4.7.1
PORTREVISION=	3
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Multi-service chat bot with extendable behavior

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	redis>=0:databases/redis \
		rubygem-bundler>=1.3:sysutils/rubygem-bundler \
		rubygem-faraday>=0.8.7:www/rubygem-faraday \
		rubygem-http_router>=0.11.2:www/rubygem-http_router \
		rubygem-i18n>=0.6.9:devel/rubygem-i18n \
		rubygem-ice_nine>=0.11.0:devel/rubygem-ice_nine \
		rubygem-multi_json>=1.7.7:devel/rubygem-multi_json \
		rubygem-puma>=2.7.1:www/rubygem-puma \
		rubygem-rack16>=1.5.2<2.0.0:www/rubygem-rack16 \
		rubygem-redis-namespace>=1.3.0:databases/rubygem-redis-namespace \
		rubygem-thor>=0.18.1:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/lita

.include <bsd.port.mk>
