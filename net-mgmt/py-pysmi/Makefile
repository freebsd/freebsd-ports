PORTNAME=	pysmi
DISTVERSION=	1.4.4
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	SNMP/SMI MIB parsing in Python
WWW=		https://www.pysnmp.com/pysmi/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.11:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26.0:www/py-requests@${PY_FLAVOR}

# Officially: 3.8-3.12
USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

BASEDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BASEDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
