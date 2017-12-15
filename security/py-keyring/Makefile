# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	keyring
DISTVERSION=	10.5.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Store and access your passwords safely

LICENSE=	PSFL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.1:devel/py-setuptools_scm@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		DBUS KEYRINGS_ALT SECRET_SERVICE
OPTIONS_DEFAULT=	KEYRINGS_ALT SECRET_SERVICE
DBUS_DESC=		Install Python DBUS to support the kwallet backend
KEYRINGS_ALT_DESC=	Install Alternate Python keyring implementations backend
SECRET_SERVICE_DESC=	Install SecretStorage to support the SecretService backend

DBUS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${FLAVOR}
KEYRINGS_ALT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyrings.alt>0:security/py-keyrings.alt@${FLAVOR}
SECRET_SERVICE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}SecretStorage>=1.0.0:security/py-SecretStorage@${FLAVOR}

.include <bsd.port.mk>
