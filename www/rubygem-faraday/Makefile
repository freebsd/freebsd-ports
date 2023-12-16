PORTNAME=	faraday
PORTVERSION=	2.7.12
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/REST API client library in Ruby
WWW=		https://github.com/lostisland/faraday

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-faraday-net_http>=2.0<3.1:www/rubygem-faraday-net_http \
		rubygem-ruby2_keywords>=0.0.4:devel/rubygem-ruby2_keywords

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	faraday_project

.include <bsd.port.mk>
