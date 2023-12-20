PORTNAME=	reproduce
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	AppJail image builder
WWW=		https://github.com/DtxdF/reproduce

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF

NO_BUILD=	yes

PLIST_FILES=	bin/appjail-reproduce
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
