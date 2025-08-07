PORTNAME=	carapace
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	shells

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Multi-shell multi-command argument completer
WWW=		https://carapace.sh/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/carapace-sh/carapace-bin
GO_TARGET=	./cmd/carapace
GO_BUILDFLAGS=	-ldflags "-s -w -X main.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-build:
	cd ${GO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} generate ./cmd/...

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
