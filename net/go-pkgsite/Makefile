PORTNAME=	go-pkgsite
PORTVERSION=    ${MODVERSION:S/-/./g:R}
DISTVERSIONPREFIX=	v
CATEGORIES=	net devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Go documentation server
WWW=		https://pkg.go.dev/golang.org/x/pkgsite/cmd/pkgsite

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
MODVERSION=	0.0.0-20250911091732-133263251ca1
GO_MODULE=	golang.org/x/pkgsite@v${MODVERSION}

GO_TARGET=	./cmd/pkgsite
PLIST_FILES=	${GO_TARGET:T:S,^,bin/,}

.include <bsd.port.mk>
