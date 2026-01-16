PORTNAME=	codesearch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0-rc.1
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Fast (indexed) text search tool from Google
WWW=		https://github.com/google/codesearch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/google/codesearch
GO_TARGET=	./cmd/cgrep \
		./cmd/cindex \
		./cmd/csearch \
		./cmd/csweb

CONFLICTS_INSTALL=	hs-cgrep

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
