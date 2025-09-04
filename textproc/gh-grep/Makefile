PORTNAME=	gh-grep
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3
PORTREVISION=	7
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Print lines matching a pattern in repositories using GitHub API
WWW=		https://github.com/k1LoW/gh-grep

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/k1LoW/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_MODULE}/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
