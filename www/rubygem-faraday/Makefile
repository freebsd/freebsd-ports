# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>

PORTNAME=	faraday
PORTVERSION=	1.9.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/REST API client library in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-em_http>=1.0<2:www/rubygem-faraday-em_http \
		rubygem-faraday-em_synchrony>=1.0<2:www/rubygem-faraday-em_synchrony \
		rubygem-faraday-excon>=1.1<2:devel/rubygem-faraday-excon \
		rubygem-faraday-httpclient>=1.0<2:www/rubygem-faraday-httpclient \
		rubygem-faraday-multipart>=1.0<2:www/rubygem-faraday-multipart \
		rubygem-faraday-net_http>=1.0<2:www/rubygem-faraday-net_http \
		rubygem-faraday-net_http_persistent>=1.0<2:www/rubygem-faraday-net_http_persistent \
		rubygem-faraday-patron>=1.0<2:www/rubygem-faraday-patron \
		rubygem-faraday-rack>=1.0<2:www/rubygem-faraday-rack \
		rubygem-faraday-retry>=1.0<2:www/rubygem-faraday-retry \
		rubygem-ruby2_keywords>=0.0.4:devel/rubygem-ruby2_keywords

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	faraday_project

.include <bsd.port.mk>
