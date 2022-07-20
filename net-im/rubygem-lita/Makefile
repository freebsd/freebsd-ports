PORTNAME=	lita
PORTVERSION=	4.8.0
PORTREVISION=	1
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Multi-service chat bot with extendable behavior

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	redis>=0:databases/redis \
		rubygem-bundler>=2.0:sysutils/rubygem-bundler \
		rubygem-faraday1>=1.0:www/rubygem-faraday1 \
		rubygem-http_router>=0.11:www/rubygem-http_router \
		rubygem-i18n>=1.8,2:devel/rubygem-i18n \
		rubygem-ice_nine>=0.11:devel/rubygem-ice_nine \
		rubygem-multi_json>=1.15:devel/rubygem-multi_json \
		rubygem-puma>=4.3:www/rubygem-puma \
		rubygem-rack>=2.2,3:www/rubygem-rack \
		rubygem-redis-namespace>=1.7:databases/rubygem-redis-namespace \
		rubygem-thor>=1.0:devel/rubygem-thor

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/lita

SHEBANG_FILES=	script/ci

.include <bsd.port.mk>
