PORTNAME=	wego
DISTVERSION=	2.1
PORTREVISION=	3
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
		mattn:go-colorable:v0.1.12:mattn_gocolorable/vendor/github.com/mattn/go-colorable \
		mattn:go-runewidth:v0.0.13:mattn_gorunewidth/vendor/github.com/mattn/go-runewidth \
		schachmat:ingo:a4bdc0729a3f:schachmat_ingo/vendor/github.com/schachmat/ingo \
		mattn:go-isatty:v0.0.14:mattn_goisatty/vendor/github.com/mattn/go-isatty \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		golang:sys:39ccf1dd6fa6:golang_sys/vendor/golang.org/x/sys
GO_TARGET=	wego

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
