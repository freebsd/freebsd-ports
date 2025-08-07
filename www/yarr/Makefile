PORTNAME=	yarr
DISTVERSIONPREFIX=v
DISTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Yet another rss reader
WWW=		https://github.com/nkanaev/yarr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license

USES=		go:1.23,modules

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	nkanaev
GH_TUPLE=	\
		golang:net:v0.37.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.31.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.23.0:golang_text/vendor/golang.org/x/text \
		mattn:go-sqlite3:v1.14.24:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3
GO_TARGET=	./cmd/yarr/main.go:yarr
GO_BUILDFLAGS=	-tags "sqlite_foreign_keys release" -ldflags "-X main.Version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
