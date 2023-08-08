PORTNAME=	docker-api
PORTVERSION=	1.34.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Simple REST client for the Docker Remote API
WWW=		https://rubygems.org/gems/docker-api

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-excon>=0.47.0:devel/rubygem-excon \
		rubygem-multi_json>=0:devel/rubygem-multi_json

USES=		gem
NO_ARCH=	yes

.include <bsd.port.mk>
