PORTNAME=	xql
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.0
CATEGORIES=	textproc

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Run SQL against SharePoint Lists and CSV files
WWW=		https://excelano.com/xql/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/excelano/xql
GO_TARGET=	./cmd/xql
GO_LDFLAGS=	-X main.version=${DISTVERSION}

PLIST_FILES=	bin/xql

.include <bsd.port.mk>
