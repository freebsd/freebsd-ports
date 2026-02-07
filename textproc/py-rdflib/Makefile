PORTNAME=	rdflib
DISTVERSION=	7.5.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for RDF manipulation
WWW=		https://github.com/RDFLib/rdflib

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.4.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.1.0<4:devel/py-pyparsing@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}berkeleydb>=0:databases/py-berkeleydb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2,2<4,2:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subtests>=0:devel/py-pytest-subtests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0:devel/py-tabulate@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

CPE_VENDOR=	rdflib_project

OPTIONS_DEFINE=	BERKELEYDB HTML HTTPX LXML NETWORKX ORJSON
BERKELEYDB_DESC=BDB support
HTML_DESC=	HTML support
HTTPX_DESC=	HTTPX support
LXML_DESC=	XML support
ORJSON_DESC=	JSON support
NETWORKX_DESC=	Network support

BERKELEYDB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}berkeleydb>=0:databases/py-berkeleydb@${PY_FLAVOR}
HTML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5rdf>=1.2<2:www/py-html5rdf@${PY_FLAVOR}
HTTPX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1<0.29:www/py-httpx@${PY_FLAVOR}
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=4.3<7.0:devel/py-lxml@${PY_FLAVOR}
NETWORKX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>=2,2<4,2:math/py-networkx@${PY_FLAVOR}
ORJSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}orjson>=3.9.14<4:devel/py-orjson@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}isodate>=0.7.2<1.0.0:devel/py-isodate@${PY_FLAVOR}
.endif

post-patch:
	# conflict with security/sequoia-sq, see https://github.com/RDFLib/rdflib/issues/3337
	@${REINPLACE_CMD} -e 's|sq|sparqlquery|g' \
		${WRKSRC}/pyproject.toml \
		${WRKSRC}/rdflib/tools/sparqlquery.py

.include <bsd.port.post.mk>
