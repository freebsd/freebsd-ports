PORTNAME=	em-websocket
PORTVERSION=	0.5.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	EventMachine based WebSocket server
WWW=		https://github.com/igrigorik/em-websocket

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	rubygem-eventmachine>=0.12.9:devel/rubygem-eventmachine \
		rubygem-http_parser.rb>=0<1:net/rubygem-http_parser.rb

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
