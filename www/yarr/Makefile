PORTNAME=	yarr
DISTVERSIONPREFIX=v
DISTVERSION=	2.0
CATEGORIES=	www

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Yet another rss reader

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license

USES=		go:modules

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	nkanaev
GH_TAGNAME=	0c5385c
GH_TUPLE=	\
		golang:net:d3edc9973b7e:golang_net/vendor/golang.org/x/net \
		golang:sys:eeed37f84f13:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		mattn:go-sqlite3:v1.14.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3

GO_TARGET=	./src/main.go:yarr
GO_BUILDFLAGS=	-tags "sqlite_foreign_keys release" -ldflags "-X main.Version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
