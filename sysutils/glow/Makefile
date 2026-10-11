PORTNAME=	glow
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Render markdown on the CLI, with pizzazz!
WWW=		https://github.com/charmbracelet/glow

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=	${DISTVERSION}
_BUILD_SHA=	add5e7a

GO_MODULE=	github.com/charmbracelet/${PORTNAME}/v3
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.Version=${_BUILD_VERSION} \
		-X main.CommitSHA=${_BUILD_SHA}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
