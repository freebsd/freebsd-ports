PORTNAME=	websocketd
PORTVERSION=	0.4.1
DISTVERSIONPREFIX=	v
PORTREVISION=	23
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Turn any program that uses STDIN/STDOUT into a WebSocket server
WWW=		http://websocketd.com/ \
		https://github.com/joewalnes/websocketd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/joewalnes/websocketd

PLIST_FILES=	bin/websocketd

.include <bsd.port.mk>
