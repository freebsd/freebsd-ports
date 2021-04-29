# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>

PORTNAME=	faraday
PORTVERSION=	1.4.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/REST API client library in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-excon>=1.1<2:devel/rubygem-faraday-excon \
		rubygem-faraday-net_http>=1.0<2:www/rubygem-faraday-net_http \
		rubygem-faraday-net_http_persistent>=1.1<2:www/rubygem-faraday-net_http_persistent \
		rubygem-multipart-post>=1.2<3:www/rubygem-multipart-post \
		rubygem-ruby2_keywords>=0.0.4:devel/rubygem-ruby2_keywords

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
