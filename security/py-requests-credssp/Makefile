PORTNAME=	requests-credssp
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Authentication handler for using CredSSP with Python Requests
WWW=		https://github.com/jborean93/requests-credssp

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyopenssl>=16.0.0:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.3.1:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyspnego>0:security/py-pyspnego@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>
