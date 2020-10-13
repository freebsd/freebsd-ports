# $FreeBSD$

PORTNAME=	duf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Disk Usage/Free Utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	muesli
GH_TUPLE=	golang:crypto:5c72a883971a:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:af09f7315aff:golang_sys/vendor/golang.org/x/sys \
		jedib0t:go-pretty:v6.0.5:jedib0t_go_pretty_v6/vendor/github.com/jedib0t/go-pretty/v6 \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		muesli:termenv:v0.7.4:muesli_termenv/vendor/github.com/muesli/termenv

_BUILD_VERSION=	${DISTVERSION}
_BUILD_SHA=	0c4c730

GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.Version=${_BUILD_VERSION} \
		-X main.CommitSHA=${_BUILD_SHA}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
