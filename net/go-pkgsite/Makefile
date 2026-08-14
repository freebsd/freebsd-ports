PORTNAME=	go-pkgsite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	net devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Go documentation server
WWW=		https://pkg.go.dev/golang.org/x/pkgsite/cmd/pkgsite

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.26+
GO_MODULE=	golang.org/x/pkgsite

GO_TARGET=	./cmd/pkgsite
PLIST_FILES=	${GO_TARGET:T:S,^,bin/,}

.include <bsd.port.mk>
