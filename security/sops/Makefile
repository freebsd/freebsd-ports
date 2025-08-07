PORTNAME=	sops
DISTVERSIONPREFIX=	v
DISTVERSION=	3.10.2
PORTREVISION=	1
CATEGORIES=	security editors

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Editor of encrypted files that supports YAML, JSON and BINARY formats
WWW=		https://github.com/mozilla/sops

LICENSE=	MPL20

USES=		go:1.23,modules

GO_MODULE=	go.mozilla.org/sops/v3
GO_TARGET=	./cmd/sops

PLIST_FILES=	bin/sops
PORTDOCS=	CHANGELOG.rst README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
