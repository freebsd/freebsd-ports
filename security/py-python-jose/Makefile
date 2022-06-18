# Created by: Dan Langille <dvl@sourcefire.com>

PORTNAME=	python-jose
PORTVERSION=	3.3.0
CATEGORIES=	security
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Client SDK for TIP API which require Authentication Tokens

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rsa>0:security/py-rsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
