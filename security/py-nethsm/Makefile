PORTNAME=	nethsm
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	aishapoval@mts.ru
COMMENT=	Python client for NetHSM
WWW=		https://pypi.org/project/nethsm/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=14.5.14,:security/py-certifi@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.7.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.0:net/py-urllib3@${PY_FLAVOR} 

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=14.5.14,:security/py-certifi@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.7.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.0:net/py-urllib3@${PY_FLAVOR} 

PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel
PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2.0<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python:3.9-3.11 shebangfix
USE_PYTHON=	allflavors autoplist concurrent pep517 
SHEBANG_GLOB=	*.py
NO_ARCH=	yes

.include <bsd.port.mk>
