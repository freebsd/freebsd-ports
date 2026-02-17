PORTNAME=	typescript-go
PORTVERSION=	7.0.0.g20260217
CATEGORIES=	lang

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	JavaScript with syntax for types
WWW=		https://www.typescriptlang.org/ \
		https://devblogs.microsoft.com/typescript/typescript-native-port/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	typescript-go
GH_TAGNAME=	daa761e5c641bde53ad14a349cc813c3296ae2f2
GH_TUPLE=	microsoft:TypeScript:1dcae83560d6f1bf293fc91da39b040cbc0d4207:typescript/_submodules/TypeScript

GO_MOD_DIST=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GH_TAGNAME}/
GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./cmd/tsgo

PLIST_FILES=	bin/tsgo
PORTDOCS=	CHANGES.md CONTRIBUTING.md README.md SECURITY.md SUPPORT.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
