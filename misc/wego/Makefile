PORTNAME=	wego
DISTVERSION=	2.4
PORTREVISION=	2
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
		mattn:go-colorable:v0.1.14:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-runewidth:v0.0.23:mattn_go_runwidth/vendor/github.com/mattn/go-runewidth \
		muesli:mango:v0.2.0:muesli_mango/vendor/github.com/muesli/mango \
		muesli:roff:v0.1.0:muesli_roff/vendor/github.com/muesli/roff \
		schachmat:ingo:a4bdc0729a3f:schachmat_ingo/vendor/github.com/schachmat/ingo \
		clipperhouse:uax29:v2.2.0:clipperhouse_uax29/vendor/github.com/clipperhouse/uax29/v2 \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		golang:sys:v0.29.0:golang_sys/vendor/golang.org/x/sys
GO_TARGET=	wego

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-install:
		${STAGEDIR}${PREFIX}/bin/wego --man > ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
