PORTNAME=	typescript-go
PORTVERSION=	7.0.0.g20251209
CATEGORIES=	lang

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	JavaScript with syntax for types
WWW=		https://www.typescriptlang.org/ \
		https://devblogs.microsoft.com/typescript/typescript-native-port/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	typescript-go
GH_TAGNAME=	8372401975e9186b2270c89c2c821e2efaf9c522
GH_TUPLE=	microsoft:TypeScript:9e8eaa1746b0d09c3cd29048126ef9cf24f29c03:typescript/_submodules/TypeScript

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
