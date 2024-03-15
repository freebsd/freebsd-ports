PORTNAME=	gh-md-toc
DISTVERSION=	0.10.0
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Easy TOC creation for GitHub README.md
WWW=		https://github.com/ekalinin/github-markdown-toc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl>0:ftp/curl \
		jq>0:textproc/jq

USE_GITHUB=	yes
GH_ACCOUNT=	ekalinin
GH_PROJECT=	github-markdown-toc

NO_BUILD=	yes

PLIST_FILES=	bin/gh-md-toc

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gh-md-toc ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
