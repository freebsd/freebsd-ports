PORTNAME=	libnacl
PORTVERSION=	1.8.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for libsodium based on ctypes

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes
TEST_ARGS=	discover -s tests

.include <bsd.port.mk>
