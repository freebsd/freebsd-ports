PORTNAME=	secp256k1
PORTVERSION=	0.13.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	FFI bindings to libsecp256k1

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.8.0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libsecp256k1.so:math/secp256k1

USES=		localbase python:3.6+ pkgconfig
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
