PORTNAME=	securesystemslib
PORTVERSION=	0.25.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Cryptographic and general-purpose routines
WWW=		https://github.com/secure-systems-lab/securesystemslib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=3.3.2:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>1.2.0:security/py-pynacl@${PY_FLAVOR}
TEST_DEPENDS=	${LOCALBASE}/bin/gpg:security/gnupg

USES=		python:3.7+ pytest
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

PYTEST_ARGS=	tests

.include <bsd.port.mk>
