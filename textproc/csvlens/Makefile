PORTNAME=	csvlens
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Command line csv viewer
WWW=		https://github.com/YS-L/csvlens

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	YS-L

PLIST_FILES=	bin/csvlens

PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/csvlens

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
