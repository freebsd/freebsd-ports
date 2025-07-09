PORTNAME=	websocketd
PORTVERSION=	0.4.1
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Turn any program that uses STDIN/STDOUT into a WebSocket server
WWW=		http://websocketd.com/ \
		https://github.com/joewalnes/websocketd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

#GO_MODULE=	github.com/joewalnes/websocketd

PLIST_FILES=	bin/websocketd

USE_GITHUB=	yes
GH_ACCOUNT=	joewalnes
GH_TUPLE=	gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket

.include <bsd.port.mk>
