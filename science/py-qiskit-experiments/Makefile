PORTNAME=	qiskit-experiments
DISTVERSION=	0.5.3
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Experiments submodule for Quiskit framework for quantum computing
WWW=		https://qiskit.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lmfit>0:math/py-lmfit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.4:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}qiskit-dynamics>=0.3.0:science/py-qiskit-dynamics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-terra>=0.22:science/py-qiskit-terra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-ibm-experiment>=0.2.5:science/py-qiskit-ibm-experiment@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-ibmq-provider>=0.16.0:science/py-qiskit-ibmq-provider@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rustworkx>0:math/py-rustworkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>0:math/py-uncertainties@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qiskit-aer>0:science/py-qiskit-aer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # one test hangs forever, see https://github.com/Qiskit/qiskit-experiments/issues/873; several tests fail, see https://github.com/Qiskit-Extensions/qiskit-experiments/issues/1220

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
