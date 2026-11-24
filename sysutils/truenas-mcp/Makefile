PORTNAME=	truenas-mcp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	sysutils

MAINTAINER=	longros@FreeBSD.org
COMMENT=	MCP server to monitor and manage TrueNAS
WWW=		https://github.com/truenas/truenas-mcp

LICENSE=	GPL-3.0-only
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.27+,modules
GO_MODULE=	github.com/truenas/truenas-mcp
GO_TARGET=	./cmd/truenas-mcp
GO_LDFLAGS=	-X main.Version=${DISTVERSION}

PLIST_FILES=	bin/truenas-mcp

.include <bsd.port.mk>
