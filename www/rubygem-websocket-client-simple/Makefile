PORTNAME=	websocket-client-simple
PORTVERSION=	0.9.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple WebSocket client for Ruby
WWW=		https://github.com/ruby-jp/websocket-client-simple

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-event_emitter>=0:devel/rubygem-event_emitter \
		rubygem-mutex_m>=0:devel/rubygem-mutex_m \
		rubygem-websocket>=0:www/rubygem-websocket

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
