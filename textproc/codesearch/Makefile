# $FreeBSD$

PORTNAME=	codesearch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	textproc

MAINTAINER=	eborisch@gmail.com
COMMENT=	Fast (indexed) text search tool from Google

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	google

GO_PKGNAME=	github.com/google/codesearch
GO_TARGET=	./cmd/cgrep \
		./cmd/cindex \
		./cmd/csearch

CONFLICTS_INSTALL=	hs-cgrep

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
