PORTNAME=	qrcp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.7
CATEGORIES=	net

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Transfer files over wifi by scanning a QR code
WWW=		https://qrcp.sh/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/claudiodangelis/qrcp
GO_LDFLAGS=	-w \
		-X github.com/claudiodangelis/qrcp/version.version=${DISTVERSION} \
		-X github.com/claudiodangelis/qrcp/version.date=${RELEASE_DATE}
RELEASE_DATE=	2026-09-30

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
