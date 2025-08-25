PORTNAME=	csvw
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.1
CATEGORIES=	misc python
#MASTER_SITES=	PYPI # tests are broken there
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to work with CSVW described tabular data
WWW=		https://github.com/cldf/csvw

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=18.1:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>0:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}language-tags>0:textproc/py-language-tags@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>0:textproc/py-rdflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=2:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritemplate>=3.0.0:net/py-uritemplate@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}frictionless>0:devel/py-frictionless@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	cldf
GH_TUPLE=	w3c:csvw:0f3a1fd:csvw/tests/fixtures/csvw

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests as of 3.5.1: 782 passed, 16 xfailed in 15.37s

.include <bsd.port.mk>
