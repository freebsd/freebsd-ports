PORTNAME=	gomi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.5
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Unix rm(1) command that can restore deleted files
WWW=		https://github.com/b4b4r07/gomi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/b4b4r07/gomi
#GO_BUILDFLAGS=	-ldflags "\
#		-w -s \
#		-X github.com/b4b4r07/gomi/Version=${DISTVERSION}"
#		cannot set Version, https://github.com/b4b4r07/gomi/issues/32

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
