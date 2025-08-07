PORTNAME=	up
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
PORTREVISION=	28
CATEGORIES=	textproc

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Ultimate plumber, a tool for writing pipes with instant live preview
WWW=		https://github.com/akavel/up

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	akavel
GH_TUPLE=	gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v1.4.0:gdamore_tcell/vendor/github.com/gdamore/tcell \
		golang:sys:201ba4db2418:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.3:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag

PLIST_FILES=	bin/up
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-test:
	 cd ${GO_WRKSRC}; ${SETENV} ${GO_ENV} ${GO_CMD} test

.include <bsd.port.mk>
