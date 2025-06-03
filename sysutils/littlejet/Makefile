PORTNAME=	littlejet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Create, deploy, manage and scale FreeBSD jails anywhere
WWW=		https://github.com/DtxdF/LittleJet/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	cpdup>=0:sysutils/cpdup \
		jq>=0:textproc/jq \
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
