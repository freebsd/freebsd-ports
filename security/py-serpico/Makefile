PORTNAME=	serpico
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Security scanner for FreeBSD packages and releases

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nvdlib>=0:security/py-nvdlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
USE_PYTHON=	pep517

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/wazuh
	${INSTALL_DATA} ${WRKSRC}/ossec/etc/rules/local_rules.xml ${STAGEDIR}${EXAMPLESDIR}/wazuh
	${INSTALL_DATA} ${WRKSRC}/wazuh-dashboard/FreeBSD_VD_Dashboard.ndjson ${STAGEDIR}${EXAMPLESDIR}/wazuh

post-install:
	${INSTALL_MAN} ${WRKSRC}/serpico.1 ${STAGEDIR}${PREFIX}/share/man/man1/serpico.1

.include <bsd.port.mk>
