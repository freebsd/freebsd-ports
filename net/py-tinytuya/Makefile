PORTNAME=	tinytuya
PORTVERSION=	1.20.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	manu@FreeBSD.org
COMMENT=	Python module to control and monitor Tuya WiFi smart devices
WWW=		https://github.com/jasonacox/tinytuya \
		https://pypi.org/project/tinytuya/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
