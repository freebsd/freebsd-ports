PORTNAME=	faraday
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/REST API client library in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-em_http>=1.0<2:www/rubygem-faraday-em_http \
		rubygem-faraday-em_synchrony>=1.0<2:www/rubygem-faraday-em_synchrony \
		rubygem-faraday-excon1>=1.1<2:devel/rubygem-faraday-excon1 \
		rubygem-faraday-httpclient1>=1.0<2:www/rubygem-faraday-httpclient1 \
		rubygem-faraday-multipart>=1.0<2:www/rubygem-faraday-multipart \
		rubygem-faraday-net_http1>=1.0<2:www/rubygem-faraday-net_http1 \
		rubygem-faraday-net_http_persistent1>=1.0<2:www/rubygem-faraday-net_http_persistent1 \
		rubygem-faraday-patron1>=1.0<2:www/rubygem-faraday-patron1 \
		rubygem-faraday-rack1>=1.0<2:www/rubygem-faraday-rack1 \
		rubygem-faraday-retry1>=1.0<2:www/rubygem-faraday-retry1 \
		rubygem-ruby2_keywords>=0.0.4:devel/rubygem-ruby2_keywords

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	faraday_project

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
