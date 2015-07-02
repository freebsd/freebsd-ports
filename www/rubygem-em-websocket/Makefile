# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	em-websocket
PORTVERSION=	0.5.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	EventMachine based WebSocket server

LICENSE=	MIT

RUN_DEPENDS=	rubygem-eventmachine>=0.12.9:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-http_parser.rb>=0.6.0:${PORTSDIR}/net/rubygem-http_parser.rb

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
