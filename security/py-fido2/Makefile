PORTNAME=	fido2
PORTVERSION=	2.0.0
CATEGORIES=	security python
MASTER_SITES=	PYPI \
		https://github.com/Yubico/python-fido2/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	FIDO2/WebAuthn library for implementing clients and servers
WWW=		https://developers.yubico.com/python-fido2/ \
		https://github.com/Yubico/python-fido2

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=2.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography pep517 unittest

NO_ARCH=	yes

.include <bsd.port.mk>
