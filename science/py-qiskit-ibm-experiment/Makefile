PORTNAME=	qiskit-ibm-experiment
DISTVERSION=	0.3.3
CATEGORIES=	science python # quantum-computing
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IBM Experiment submodule for Quiskit framework for quantum computing
WWW=		https://qiskit.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.8.0:devel/py-dateutil@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-terra>=0.18.0:science/py-qiskit-terra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests_ntlm>=1.1.0:www/py-requests_ntlm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist pytest # Many tests are skipped: Only runs on staging, see https://github.com/Qiskit/qiskit-ibm-experiment/issues/49

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

NO_ARCH=	yes

.include <bsd.port.mk>
