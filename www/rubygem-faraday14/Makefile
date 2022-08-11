PORTNAME=	faraday
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	14

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTTP/REST API client library in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-em_http>=1.0<2:www/rubygem-faraday-em_http \
		rubygem-faraday-em_synchrony>=1.0<2:www/rubygem-faraday-em_synchrony \
		rubygem-faraday-excon1>=1.1<2:devel/rubygem-faraday-excon1 \
		rubygem-faraday-net_http1>=1.0<2:www/rubygem-faraday-net_http1 \
		rubygem-faraday-net_http_persistent1>=1.1<2:www/rubygem-faraday-net_http_persistent1 \
		rubygem-multipart-post>=1.2<3:www/rubygem-multipart-post \
		rubygem-ruby2_keywords>=0.0.4:devel/rubygem-ruby2_keywords

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.4\.

.include <bsd.port.mk>
