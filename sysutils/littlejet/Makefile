PORTNAME=	littlejet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.2
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Create, deploy, manage and scale FreeBSD jails anywhere
WWW=		https://github.com/DtxdF/LittleJet/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	jq>=0:textproc/jq \
		cpdup>=0:sysutils/cpdup \
		sansi>=0:textproc/sansi

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	LittleJet

NO_BUILD=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
