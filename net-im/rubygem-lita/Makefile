# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lita
PORTVERSION=	4.4.2
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Multi-service chat bot with extendable behavior

LICENSE=	MIT

RUN_DEPENDS=	redis>=0:${PORTSDIR}/databases/redis \
		rubygem-bundler>=1.3:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-faraday>=0.8.7:${PORTSDIR}/www/rubygem-faraday \
		rubygem-http_router>=0.11.1:${PORTSDIR}/www/rubygem-http_router \
		rubygem-i18n>=0.6.9:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-ice_nine>=0.11.0:${PORTSDIR}/devel/rubygem-ice_nine \
		rubygem-multi_json>=1.7.7:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-puma>=2.7.1:${PORTSDIR}/www/rubygem-puma \
		rubygem-rack15>=1.5.2:${PORTSDIR}/www/rubygem-rack15 \
		rubygem-redis-namespace>=1.3.0:${PORTSDIR}/databases/rubygem-redis-namespace \
		rubygem-thor>=0.18.1:${PORTSDIR}/devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/lita

.include <bsd.port.mk>
