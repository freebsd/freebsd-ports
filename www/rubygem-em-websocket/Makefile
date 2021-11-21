# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	em-websocket
PORTVERSION=	0.5.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	EventMachine based WebSocket server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	rubygem-eventmachine>=0.12.9:devel/rubygem-eventmachine \
		rubygem-http_parser.rb>=0<1:net/rubygem-http_parser.rb

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
