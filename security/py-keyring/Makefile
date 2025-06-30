PORTNAME=	keyring
PORTVERSION=	25.6.0
PORTEPOCH=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Store and access your passwords safely
WWW=		https://github.com/jaraco/keyring

LICENSE=	PSFL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=1.15.0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.classes>=0:devel/py-jaraco.classes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.context>=0:devel/py-jaraco.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.functools>=0:devel/py-jaraco.functools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		DBUS SECRET_SERVICE
OPTIONS_DEFAULT=	SECRET_SERVICE
DBUS_DESC=		Install Python DBUS to support the kwallet backend
SECRET_SERVICE_DESC=	Install SecretStorage to support the SecretService backend

DBUS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}
SECRET_SERVICE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}SecretStorage>=3.2:security/py-SecretStorage@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
