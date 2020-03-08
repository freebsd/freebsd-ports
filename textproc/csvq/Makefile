# $FreeBSD$

PORTNAME=	csvq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.4
CATEGORIES=	textproc

MAINTAINER=	vulcan@wired.sh
COMMENT=	SQL-like query language for csv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	mithrandie
GH_TUPLE=	golang:crypto:3d3f9f413869:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:f43be2a4598c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.1:golang_text/vendor/golang.org/x/text \
		mitchellh:go-homedir:v1.0.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mithrandie:go-file:v2.0.2:mithrandie_go_file/vendor/github.com/mithrandie/go-file/v2 \
		mithrandie:go-text:v1.3.1:mithrandie_go_text/vendor/github.com/mithrandie/go-text \
		mithrandie:readline-csvq:v1.1.1:mithrandie_readline_csvq/vendor/github.com/mithrandie/readline-csvq \
		mithrandie:ternary:v1.1.0:mithrandie_ternary/vendor/github.com/mithrandie/ternary \
		urfave:cli:v1.20.0:urfave_cli/vendor/github.com/urfave/cli

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
