PORTNAME=	asyncssh
PORTVERSION=	2.21.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Asynchronous SSHv2 client and server library
WWW=		https://github.com/ronf/asyncssh

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent cryptography pep517 unittest

NO_ARCH=	yes

CPE_VENDOR=	asyncssh_project

OPTIONS_DEFINE=	BCRYPT FIDO2 GSSAPI LIBNACL PKCS11 PYOPENSSL
OPTIONS_DEFAULT=BCRYPT FIDO2 PYOPENSSL
BCRYPT_DESC=	OpenSSH private key encryption
FIDO2_DESC=	FIDO2 support
GSSAPI_DESC=	GSSAPI key exchange and authentication
LIBNACL_DESC=	Curve25519, Ed25519 and Chacha20-Poly1305 support
PKCS11_DESC=	PKCS \#11 support
PYOPENSSL_DESC=	X.509 certificate authentication

BCRYPT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.3:security/py-bcrypt@${PY_FLAVOR}
FIDO2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fido2>=2:security/py-fido2@${PY_FLAVOR}
GSSAPI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gssapi>=1.2.0:security/py-gssapi@${PY_FLAVOR}
LIBNACL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libnacl>=1.4.2:security/py-libnacl@${PY_FLAVOR}
PKCS11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-pkcs11>=0.7.0:security/py-python-pkcs11@${PY_FLAVOR}
PYOPENSSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyopenssl>=23.0.0,1:security/py-pyopenssl@${PY_FLAVOR}

.include <bsd.port.mk>
