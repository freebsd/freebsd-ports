PORTNAME=	tgrep
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.21
CATEGORIES=	textproc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Trigram-indexed grep for fast regex search in large codebases locally
WWW=		https://github.com/microsoft/tgrep

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft

CARGO_INSTALL_PATH=	tgrep-cli

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	BENCHMARKS.md CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
