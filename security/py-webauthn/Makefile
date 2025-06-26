PORTNAME=	webauthn
PORTVERSION=	2.6.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WebAuthn Python module
WWW=		https://duo-labs.github.io/py_webauthn/ \
		https://github.com/duo-labs/py_webauthn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.1:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cbor2>=5.6.5:devel/py-cbor2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=25.0.0,1:security/py-openssl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517 unittest

NO_ARCH=	yes

.include <bsd.port.mk>
