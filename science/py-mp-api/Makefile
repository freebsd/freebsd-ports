PORTNAME=	mp-api
DISTVERSION=	0.46.4
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mp_api-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API for server for the Materials Project
WWW=		https://materialsproject.github.io/api/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deltalake>0:databases/py-deltalake@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}emmet-core>=0.87.1:science/py-emmet-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>=2024.12.10:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.10:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=20.0.0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatgen>2024.2.20:science/py-pymatgen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.23.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4.1:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 0.46.4: disable tests that require network access to the Materials
# Project API or an API key (test_core_fetch_tools, test_core_search_tools,
# test_blessed_entry, test_regression_batching) and the client-initialization
# test (test_mix_in) that fails without an API key in the clean environment.
PYTEST_BROKEN_TESTS=	test_core_fetch_tools \
			test_core_search_tools \
			test_mix_in \
			test_blessed_entry \
			test_regression_batching

# tests as of 0.46.4: 22 passed 131 skipped

.include <bsd.port.mk>
