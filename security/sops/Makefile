# $FreeBSD$

PORTNAME=	sops
DISTVERSION=	3.3.1
CATEGORIES=	security editors

MAINTAINER=	dg@syrec.org
COMMENT=	Editor of encrypted files that supports YAML, JSON and BINARY formats

LICENSE=	MPL20

USES=		go

GO_PKGNAME=	go.mozilla.org/sops
GO_TARGET=	./cmd/sops

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla

PLIST_FILES=	bin/sops

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.rst CHANGELOG.rst

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
