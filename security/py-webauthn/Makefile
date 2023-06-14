PORTNAME=	webauthn
PORTVERSION=	1.2.1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WebAuthn Python module
WWW=		https://github.com/duo-labs/py_webauthn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=0.24.0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=21.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cattrs>=1.8.0:devel/py-cattrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cbor2>=4.0.1:devel/py-cbor2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=3.4.7:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=20.0.1,1:security/py-openssl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes

.include <bsd.port.mk>
