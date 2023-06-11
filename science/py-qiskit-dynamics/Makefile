PORTNAME=	qiskit-dynamics
DISTVERSION=	0.4.1
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qiskit ODE solver
WWW=		https://qiskit.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}multiset>=3.0.1:devel/py-multiset@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-terra>=0.23.0:science/py-qiskit-terra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jax>0:math/py-jax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-aer>0:science/py-qiskit-aer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-experiments>0:science/py-qiskit-experiments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qutip>0:devel/py-qutip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist pytest # one test hangs forever, see https://github.com/Qiskit/qiskit-experiments/issues/873

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
