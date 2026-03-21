PORTNAME=	peco
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Simplistic interactive filtering tool
WWW=		https://github.com/peco/peco

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules

GO_MODULE=	github.com/peco/peco
GO_TARGET=	./cmd/peco

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	Changes README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
