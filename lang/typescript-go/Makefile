PORTNAME=	typescript-go
DISTVERSIONPREFIX=	typescript/v
DISTVERSION=	7.0.2
CATEGORIES=	lang

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	JavaScript with syntax for types
WWW=		https://www.typescriptlang.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	typescript-go
GH_TUPLE=	microsoft:TypeScript:4d4f005c8541e0255a9d8791205fdce326e462bc:typescript/_submodules/TypeScript

GO_MOD_DIST=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GH_TAGNAME}/
GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./cmd/tsgo

PLIST_FILES=	bin/tsc
PORTDOCS=	CHANGES.md CONTRIBUTING.md README.md SECURITY.md SUPPORT.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/tsgo \
		${STAGEDIR}${PREFIX}/bin/tsc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
