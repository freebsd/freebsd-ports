# Created by: Douglas Thrift <douglas@douglasthrift.net>

PORTNAME=	keyring
PORTVERSION=	18.0.1
PORTEPOCH=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Store and access your passwords safely

LICENSE=	PSFL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}entrypoints>=0:devel/py-entrypoints@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

OPTIONS_DEFINE=		DBUS KEYRINGS_ALT SECRET_SERVICE
OPTIONS_DEFAULT=	KEYRINGS_ALT SECRET_SERVICE
DBUS_DESC=		Install Python DBUS to support the kwallet backend
KEYRINGS_ALT_DESC=	Install Alternate Python keyring implementations backend
SECRET_SERVICE_DESC=	Install SecretStorage to support the SecretService backend

DBUS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}
KEYRINGS_ALT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyrings.alt>0:security/py-keyrings.alt@${PY_FLAVOR}
SECRET_SERVICE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}SecretStorage>0:security/py-SecretStorage@${PY_FLAVOR}

.include <bsd.port.mk>
