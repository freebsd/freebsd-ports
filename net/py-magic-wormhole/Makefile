PORTNAME=	magic-wormhole
PORTVERSION=	0.12.0
CATEGORIES=	net
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Get things from one computer to another, safely

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=16.3.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}autobahn>=0.14.1:www/py-autobahn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Automat>=0.3.0:devel/py-Automat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hkdf>0:security/py-hkdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>=0:devel/py-humanize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0.6:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0.3.0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spake2>=0.8:security/py-spake2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.13.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=17.5.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txtorcon>=18.0.2:security/py-txtorcon@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
