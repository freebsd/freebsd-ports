PORTNAME=	qiskit-ibmq-provider # is being split into qiskit-ibm-provider, qiskit-ibm-runtime, qiskit-ibm-experiment
DISTVERSION=	0.20.2
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qiskit Provider for accessing IBM quantum devices and simulators
WWW=		https://qiskit.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8.0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-terra>=0.18.0:science/py-qiskit-terra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests_ntlm>=1.1.0:www/py-requests_ntlm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=10.0:devel/py-websockets@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=5.3.1:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=4.4.0:devel/py-nbformat@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
