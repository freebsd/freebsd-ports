# $FreeBSD$

PORTNAME=	faye
PORTVERSION=	1.2.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple pub/sub messaging for the web

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cookiejar>=0.3.0:www/rubygem-cookiejar \
		rubygem-em-http-request>=0.3.0:www/rubygem-em-http-request \
		rubygem-eventmachine>=0.12.0:devel/rubygem-eventmachine \
		rubygem-faye-websocket>=0.9.1:www/rubygem-faye-websocket \
		rubygem-multi_json>=1.0.0:devel/rubygem-multi_json \
		rubygem-rack>=1.0.0:www/rubygem-rack \
		rubygem-websocket-driver>=0.5.1:www/rubygem-websocket-driver

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
