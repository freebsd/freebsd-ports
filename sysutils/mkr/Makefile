PORTNAME=	mkr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.62.0
CATEGORIES=	sysutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Command line tool for Mackerel
WWW=		https://github.com/mackerelio/mkr

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/mackerelio/mkr
GO_BUILDFLAGS=	-ldflags="-s -w"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}&|" \
		${WRKSRC}/vendor/github.com/mackerelio/mackerel-agent/config/config_unix.go

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
