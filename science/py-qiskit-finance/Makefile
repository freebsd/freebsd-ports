PORTNAME=	qiskit-finance
DISTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	science finance python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum Finance module from the Qiskit quantum computing framework
WWW=		https://qiskit.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastdtw>0:math/py-fastdtw@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}Nasdaq-Data-Link>0:finance/py-Nasdaq-Data-Link@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-optimization>=0.2.0:science/py-qiskit-optimization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-terra>=0.20.0:science/py-qiskit-terra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yfinance>=0.1.70:finance/py-yfinance@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ddt>0:devel/py-ddt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # one test hangs forever, see https://github.com/Qiskit/qiskit-experiments/issues/873

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit
GH_TAGNAME=	88091bc

NO_ARCH=	yes

.include <bsd.port.mk>
