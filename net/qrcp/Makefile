PORTNAME=	qrcp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
CATEGORIES=	net

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Transfer files over wifi by scanning a QR code
WWW=		https://qrcp.sh/ \
		https://github.com/claudiodangelis/qrcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/claudiodangelis/qrcp
GO_LDFLAGS=	-w \
		-X ${GO_MODULE}/version.version=${DISTVERSION} \
		-X ${GO_MODULE}/version.date=${RELEASE_DATE}
RELEASE_DATE=	2026-11-21

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
