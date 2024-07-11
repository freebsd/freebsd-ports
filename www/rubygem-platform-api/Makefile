PORTNAME=	platform-api
PORTVERSION=	3.7.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby HTTP client for the Heroku API
WWW=		https://github.com/heroku/platform-api

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-heroics>=0.1.1<0.2:www/rubygem-heroics \
		rubygem-moneta>=1.0.0<2:devel/rubygem-moneta \
		rubygem-rate_throttle_client>=0.1.0<0.2:www/rubygem-rate_throttle_client

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
