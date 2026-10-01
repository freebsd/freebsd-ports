PORTNAME=	wacli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WhatsApp CLI with offline search and message sync
WWW=		https://github.com/steipete/wacli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/steipete/wacli
GO_TARGET=	./cmd/wacli

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
