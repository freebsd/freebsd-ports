PORTNAME=	typescript-go
PORTVERSION=	7.0.0.g20260506
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
GH_TAGNAME=	ee4225a856389fc94c8ce4a5fd9af771dbbc2c0b
GH_TUPLE=	microsoft:TypeScript:c3bd12d888b86f676718b16e64d7d2abcb423514:typescript/_submodules/TypeScript

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
