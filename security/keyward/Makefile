PORTNAME=	keyward
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	security

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI for managing SSH keys and config
WWW=		https://github.com/gateway-of-last-resort/keyward

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/gateway-of-last-resort/keyward
GO_TARGET=	./cmd/keyward

PLIST_FILES=	bin/keyward

.include <bsd.port.mk>
