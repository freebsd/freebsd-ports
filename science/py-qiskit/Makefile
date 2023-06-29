PORTNAME=	qiskit
DISTVERSION=	0.43.2
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qiskit meta-package: SDK for working with quantum computers
WWW=		https://qiskit.org/

LICENSE=	BSD2CLAUSE

# required submodules
PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qiskit-aer>0:science/py-qiskit-aer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-terra>0:science/py-qiskit-terra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-ibmq-provider>0:science/py-qiskit-ibmq-provider@${PY_FLAVOR}
# optional submodules (list: https://github.com/Qiskit/qiskit#optional-components)
OPT_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qiskit-finance>0:science/py-qiskit-finance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-optimization>0:science/py-qiskit-optimization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-machine-learning>0:misc/py-qiskit-machine-learning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-nature>0:science/py-qiskit-nature@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-experiments>0:science/py-qiskit-experiments@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS} \
		${OPT_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

WRKSRC=		${WRKDIR}/qiskit-metapackage-${PORTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
