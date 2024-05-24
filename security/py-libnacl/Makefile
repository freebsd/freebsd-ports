PORTNAME=	libnacl
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for libsodium based on ctypes
WWW=		https://libnacl.readthedocs.io/en/latest/ \
		https://github.com/saltstack/libnacl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}
LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes
TEST_ARGS=	discover -s tests

.include <bsd.port.mk>
