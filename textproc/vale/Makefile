PORTNAME=	vale
DISTVERSIONPREFIX=	v
DISTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command-line tool that brings editorial style guide to life
WWW=		https://vale.sh/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_BUILDFLAGS+=	-ldflags="-s -w -X main.Version=${DISTVERSION}"
GO_MODULE=	github.com/errata-ai/${PORTNAME}/v3
GO_TARGET=	./cmd/vale

PLIST_FILES=	bin/vale

.include <bsd.port.mk>
