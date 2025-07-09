PORTNAME=	gomi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Unix rm(1) command that can restore deleted files
WWW=		https://github.com/babarot/gomi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=		${DISTVERSIONFULL}
_BUILD_REVISION=	e1d0be9
_BUILD_DATE=		$$(date +%Y-%m-%dT%H:%M:%SZ)

GO_MODULE=	github.com/babarot/gomi
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION} \
		-X main.revision=${_BUILD_REVISION} \
		-X main.buildDate=${_BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
