PORTNAME=	saltyrtc.server
PORTVERSION=	5.0.1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	SaltyRTC compliant signalling server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libnacl>=1.5:security/py-libnacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logbook>=1.0:devel/py-logbook@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}u-msgpack-python>=2.7:devel/py-u-msgpack-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0.700:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=8.0:devel/py-websockets@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}collective.checkdocs>=0.2:textproc/py-collective.checkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=3.7:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=0:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ordered-set>=3.0:devel/py-ordered-set@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.2:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3.7:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.9:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.5:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=1.10:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	saltyrtc-server

SUB_LIST=	ETCDIR=${PREFIX}/etc/saltyrtc-server PYTHON_CMD=${PYTHON_CMD}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
