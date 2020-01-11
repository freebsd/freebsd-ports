# $FreeBSD$

PORTNAME=	asyncssh
PORTVERSION=	1.16.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Asynchronous SSHv2 client and server library

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=2.6.1:security/py-cryptography@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	BCRYPT GSSAPI LIBNACL PYOPENSSL
OPTIONS_DEFAULT=BRCYPT PYOPENSSL
BCRYPT_DESC=	OpenSSH private key encryption
GSSAPI_DESC=	GSSAPI key exchange and authentication
LIBNACL_DESC=	Curve25519, Ed25519 and Chacha20-Poly1305 support
PYOPENSSL_DESC=	X.509 certificate authentication

BCRYPT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.3:security/py-bcrypt@${PY_FLAVOR}
GSSAPI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gssapi>=1.2.0:security/py-gssapi@${PY_FLAVOR}
LIBNACL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libnacl>=1.4.2:security/py-libnacl@${PY_FLAVOR}
PYOPENSSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=17.0.0:security/py-openssl@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
