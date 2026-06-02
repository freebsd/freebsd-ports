PORTNAME=	qcmanybody
DISTVERSION=	0.7.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Many-body expansion tools for quantum chemistry
WWW=		https://github.com/MolSSI/QCManyBody

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=1.10.17:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcelemental>=0.28.0:science/py-qcelemental@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geometric>0:science/py-geometric@${PY_FLAVOR} \
		nwchem:science/nwchem \
		${PYTHON_PKGNAMEPREFIX}optking>0:science/py-optking@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcengine>0:science/py-qcengine@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 0.7.1:
# Results (338.17s (0:05:38)):
#      557 passed
#      832 skipped

.include <bsd.port.mk>
