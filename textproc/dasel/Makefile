PORTNAME=	dasel
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Query and update data structures from the command line

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=	${DISTVERSION}

GO_MODULE=	github.com/tomwright/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-tags noupdater \
		-ldflags "\
		-s -w \
		-X ${GO_MODULE}/internal.Version=${_BUILD_VERSION}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CODE_OF_CONDUCT.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
