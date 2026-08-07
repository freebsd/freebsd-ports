PORTNAME=	endf
DISTVERSION=	0.1.12
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to ENDF-6 and ACE format nuclear data files
WWW=		https://endf-python.readthedocs.io/en/latest/ \
		https://github.com/paulromano/endf-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.10.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>0:math/py-uncertainties@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	pep517 autoplist pytest concurrent

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

# tests as of 0.1.12: 16 passed in 0.58s

.include <bsd.port.mk>
