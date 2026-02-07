PORTNAME=	faye
PORTVERSION=	1.4.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple pub/sub messaging for the web
WWW=		https://faye.jcoglan.com/

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cookiejar>=0.3.0:www/rubygem-cookiejar \
		rubygem-em-http-request>=1.1.6:www/rubygem-em-http-request \
		rubygem-eventmachine>=0.12.0:devel/rubygem-eventmachine \
		rubygem-faye-websocket>=0.11.0:www/rubygem-faye-websocket \
		rubygem-multi_json>=1.0.0:devel/rubygem-multi_json \
		rubygem-rack>=1.0.0,3:www/rubygem-rack \
		rubygem-websocket-driver>=0.5.1:www/rubygem-websocket-driver

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	faye_project

.include <bsd.port.mk>
