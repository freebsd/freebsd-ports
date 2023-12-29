PORTNAME=	hmmlearn
DISTVERSION=	0.3.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Unsupervised learning and inference of Hidden Markov Models
WWW=		https://github.com/hmmlearn/hmmlearn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	wheel-${PYTHON_VER}:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.3:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.19:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.16:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.19:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.16:science/py-scikit-learn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/hmmlearn/_hmmc.cpython-39.so

# 2023-12-29: Tests currently fail due to known upstream issues
do-test:
	# setup.py builds directly to prefix by default, so we need to build
	# again within the project for pytest to work
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} setup.py develop)
	(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYTHON_VER} --capture=no)

.include <bsd.port.mk>
