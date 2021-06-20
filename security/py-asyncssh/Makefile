PORTNAME=	asyncssh
PORTVERSION=	2.7.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Asynchronous SSHv2 client and server library

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=2.8:security/py-cryptography@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	BCRYPT FIDO2 GSSAPI LIBNACL NETTLE PKCS11 PYOPENSSL
OPTIONS_DEFAULT=BCRYPT FIDO2 PYOPENSSL
BCRYPT_DESC=	OpenSSH private key encryption
FIDO2_DESC=	FIDO2 support
GSSAPI_DESC=	GSSAPI key exchange and authentication
LIBNACL_DESC=	Curve25519, Ed25519 and Chacha20-Poly1305 support
NETTLE_DESC=	UMAC cryptographic hashes
PKCS11_DESC=	PKCS \#11 support
PYOPENSSL_DESC=	X.509 certificate authentication

BCRYPT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.3:security/py-bcrypt@${PY_FLAVOR}
FIDO2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fido2>=0.9.1:security/py-fido2@${PY_FLAVOR}
GSSAPI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gssapi>=1.2.0:security/py-gssapi@${PY_FLAVOR}
LIBNACL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libnacl>=1.4.2:security/py-libnacl@${PY_FLAVOR}
NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
PKCS11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-pkcs11>=0.7.0:security/py-python-pkcs11@${PY_FLAVOR}
PYOPENSSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=17.0.0:security/py-openssl@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m unittest -v

.include <bsd.port.mk>
