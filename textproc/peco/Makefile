PORTNAME=	peco
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.11
PORTREVISION=	16
CATEGORIES=	textproc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Simplistic interactive filtering tool
WWW=		https://github.com/peco/peco

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	\
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		google:btree:0c3044bc8bad:google_btree/vendor/github.com/google/btree \
		jessevdk:go-flags:v1.1.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		lestrrat-go:pdebug:39f9a71bcabe:lestrrat_go_pdebug/vendor/github.com/lestrrat-go/pdebug \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		nsf:termbox-go:v1.1.1:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		pkg:errors:248dadf4e906:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		stretchr:testify:18a02ba4a312:stretchr_testify/vendor/github.com/stretchr/testify

GO_TARGET=	./cmd/peco

PLIST_FILES=	bin/peco
PORTDOCS=	Changes README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
