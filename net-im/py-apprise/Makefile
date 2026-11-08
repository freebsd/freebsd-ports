PORTNAME=	apprise
DISTVERSION=	1.13.1
CATEGORIES=	net-im python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nick@kirby.cx
COMMENT=	Push Notifications that work with just about every platform!
WWW=		https://github.com/caronc/apprise

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>0:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gntp>0:net/py-gntp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paho-mqtt>0:net/py-paho-mqtt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PGPy>=0:security/py-pgpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}slixmpp>=0:net-im/py-slixmpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}smpplib>=0:net-im/py-smpplib@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	autoplist concurrent cryptography_test pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		BLINK CRYPTO GROWL MQTT PGP SMPP XMPP
OPTIONS_DEFAULT=	BLINK CRYPTO GROWL MQTT PGP SMPP XMPP

BLINK_DESC=	Enables blink1:// support
CRYPTO_DESC=	Enables message services requiring cryptography
GROWL_DESC=	Enables growl:// support
MQTT_DESC=	Enables mqtt:// support
PGP_DESC=	Enables mailto:// and deltachat:// support
SMPP_DESC=	Enables smpp:// support
XMPP_DESC=	Enables xmpp:// support

BLINK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hidapi>=0:comms/py-hidapi@${PY_FLAVOR}
CRYPTO_USE=		PYTHON=cryptography
GROWL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gntp>=0:net/py-gntp@${PY_FLAVOR}
MQTT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paho-mqtt>=0:net/py-paho-mqtt@${PY_FLAVOR}
PGP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PGPy>=0:security/py-pgpy@${PY_FLAVOR}
SMPP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}smpplib>=0:net-im/py-smpplib@${PY_FLAVOR}
XMPP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}slixmpp>=0:net-im/py-slixmpp@${PY_FLAVOR}

.include <bsd.port.mk>
