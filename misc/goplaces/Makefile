PORTNAME=	goplaces
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern Google Places CLI in Go
WWW=		https://github.com/steipete/goplaces

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/steipete/goplaces
GO_TARGET=	./cmd/goplaces

PLIST_FILES=	bin/goplaces

.include <bsd.port.mk>
