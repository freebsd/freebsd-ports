PORTNAME=	emmet-core
DISTVERSION=	0.87.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	emmet_core-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Materials API Toolkit for the Materials Project
WWW=		https://github.com/materialsproject/emmet

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pubchempy>0:science/py-pubchempy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blake3>0:security/py-blake3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inflect>=7.5.0:devel/py-inflect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>=2024.2.2:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.12:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybtex>=0.24:textproc/py-pybtex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatgen>=2024.6.10:science/py-pymatgen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatgen-io-validation>=0.1.1:science/py-pymatgen-io-validation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7:devel/py-typing-extensions@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

# tests as of 0.87.1: not enabled because the sdist is missing the upstream
# test_files/ fixture directory used by the majority of the test suite.

.include <bsd.port.mk>
