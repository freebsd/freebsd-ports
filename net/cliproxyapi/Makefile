PORTNAME=	cliproxyapi
DISTVERSIONPREFIX=	v
DISTVERSION=	7.2.83
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Proxy providing OpenAI/Gemini/Claude/Codex/Grok compatible APIs
WWW=		https://github.com/router-for-me/CLIProxyAPI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26,modules

GO_MODULE=	github.com/router-for-me/CLIProxyAPI/v7
GO_TARGET=	./cmd/server:cliproxyapi

PLIST_FILES=	bin/cliproxyapi

PORTDOCS=	README.md config.example.yaml env.cluster.example env.example

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/config.example.yaml \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/.env.example ${STAGEDIR}${DOCSDIR}/env.example
	${INSTALL_DATA} ${WRKSRC}/.env.cluster.example \
		${STAGEDIR}${DOCSDIR}/env.cluster.example

.include <bsd.port.mk>
