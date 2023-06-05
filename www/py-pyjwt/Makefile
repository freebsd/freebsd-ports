PORTNAME=	pyjwt
PORTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyJWT-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in Python
WWW=		https://github.com/jpadilla/pyjwt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}-pyjwt1

CPE_VENDOR=	pyjwt_project

OPTIONS_DEFINE=	CRYPTO
OPTIONS_DEFAULT=CRYPTO

CRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=3.4.0,1:security/py-cryptography@${PY_FLAVOR}

.include <bsd.port.mk>
