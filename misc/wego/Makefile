PORTNAME=	wego
DISTVERSION=	2.3
PORTREVISION=	7
CATEGORIES=	misc

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Weather client for the terminal
WWW=		https://github.com/schachmat/wego

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	schachmat
GH_TUPLE=	\
		golang:sys:v0.8.0:golang_sys/vendor/golang.org/x/sys \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.19:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		rivo:uniseg:v0.4.4:rivo_uniseg/vendor/github.com/rivo/uniseg \
		schachmat:ingo:a4bdc0729a3f:schachmat_ingo/vendor/github.com/schachmat/ingo
GO_TARGET=	wego

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
