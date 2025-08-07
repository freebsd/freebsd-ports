PORTNAME=	markdownfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1-67
DISTVERSIONSUFFIX=	-g3438a10
PORTREVISION=	30
CATEGORIES=	textproc

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Tool for linting and formatting Markdown in-place (similar to gofmt)
WWW=		https://github.com/shurcooL/markdownfmt

LICENSE=	MIT
# License file is not included.

USES=		go:modules
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GH_TUPLE=	golang:crypto:22d7a77e9e5f:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		russross:blackfriday:a477dd164691:russross_blackfriday/vendor/github.com/russross/blackfriday \
		shurcooL:go:6713ea532688:shurcool_go/vendor/github.com/shurcooL/go
USE_GITHUB=	yes
GH_ACCOUNT=	shurcooL

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
