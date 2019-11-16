# $FreeBSD$

PORTNAME=	up
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Ultimate plumber, a tool for writing pipes with instant live preview

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	akavel
GH_TUPLE=	gdamore:encoding:b23993cbb635:encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:493f3b46b3c2:tcell/vendor/github.com/gdamore/tcell \
		lucasb-eyer:go-colorful:231272389856:gocolorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.3:goisatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.2:gorunewidth/vendor/github.com/mattn/go-runewidth \
		spf13:pflag:v1.0.3:pflag/vendor/github.com/spf13/pflag \
		golang:text:f21a4dfb5e38:text/vendor/golang.org/x/text

PLIST_FILES=	bin/up
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-test:
	 cd ${GO_WRKSRC}; ${SETENV} ${GO_ENV} ${GO_CMD} test

.include <bsd.port.mk>
