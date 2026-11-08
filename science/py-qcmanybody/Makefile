PORTNAME=	qcmanybody
DISTVERSION=	0.8.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Many-body expansion tools for quantum chemistry
WWW=		https://molssi.github.io/QCManyBody/dev/ \
		https://github.com/MolSSI/QCManyBody

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcelemental>=0.50.4:science/py-qcelemental@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geometric>0:science/py-geometric@${PY_FLAVOR} \
		nwchem:science/nwchem \
		${PYTHON_PKGNAMEPREFIX}optking>0:science/py-optking@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcengine>0:science/py-qcengine@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 0.8.0: 560 passed, 830 skipped, 6 warnings in 411.12s (0:06:51)

.include <bsd.port.mk>
