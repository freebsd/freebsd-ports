PORTNAME=	cells
PORTVERSION=	2.2.7
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	pydio-

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Nextgen file sharing platform for organizations

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/pydio/cells
USE_GITHUB=	yes
GH_ACCOUNT=	pydio

PLIST_FILES=	bin/cells
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install pydio-cells README file

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
