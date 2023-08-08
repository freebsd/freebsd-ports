PORTNAME=	qiskit-machine-learning
DISTVERSION=	0.6.1
CATEGORIES=	misc python # quantum-computing, machine-learning
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum Machine Learning for Quiskit framework for quantum computing
WWW=		https://qiskit.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dill>=0.3.4:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastdtw>0:math/py-fastdtw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5:sysutils/py-psutil@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}qiskit-terra>=0.22:science/py-qiskit-terra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.20.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest # several tests fail with "No module named 'threadpoolctl'", see https://reviews.freebsd.org/D35513

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

NO_ARCH=	yes

.include <bsd.port.mk>
