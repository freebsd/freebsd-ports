PORTNAME=	leaves
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	sysutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Text-mode disk usage visualization utility
WWW=		https://github.com/patonw/leaves

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	patonw

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
