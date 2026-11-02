PORTNAME=	napalm-logs
DISTVERSION=	0.11.0
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Cross-vendor normalisation for network syslog messages
WWW=		https://github.com/napalm-automation/napalm-logs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateparser>0:devel/py-dateparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>0:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyNaCl>0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>0:devel/py-sentry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}u-msgpack-python>0:devel/py-u-msgpack-python@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	napalm-automation
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PREFIX=${PREFIX} PYTHON_VER=${PYTHON_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/napalm_logs/config/__init__.py

.include <bsd.port.mk>
