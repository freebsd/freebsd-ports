PORTNAME=	csvq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18.1
PORTREVISION=	16
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	SQL-like query language for csv
WWW=		https://mithrandie.github.io/csvq/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/mithrandie/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
