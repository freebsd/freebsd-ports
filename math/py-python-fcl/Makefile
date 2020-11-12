# $FreeBSD$

PORTNAME=	python-fcl
PORTVERSION=	0.0.12
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Python bindings for the Flexible Collision Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfcl05.so:math/fcl05 \
		liboctomap.so:math/octomap
BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang eigen:3 python

USE_PYTHON=	distutils autoplist concurrent cython

PYDISTUTILS_BUILD_TARGET=	build_ext

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fcl/fcl.so

.include <bsd.port.mk>
