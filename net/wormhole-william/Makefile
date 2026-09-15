PORTNAME=	wormhole-william
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.8
CATEGORIES=	net www

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Go implementation of Magic Wormhole
WWW=		https://github.com/psanford/wormhole-william/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/psanford/wormhole-william
GO_TARGET=	.:${PORTNAME}

PLIST_FILES=	bin/wormhole-william

.include <bsd.port.mk>
