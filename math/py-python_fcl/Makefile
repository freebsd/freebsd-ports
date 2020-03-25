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

NEEDED_DEPENDS=	${PYNUMPY} \
		eigen>0:math/eigen3
LIB_DEPENDS=	libfcl05.so:math/fcl05 \
		liboctomap.so:math/octomap
BUILD_DEPENDS=	${NEEDED_DEPENDS}
RUN_DEPENDS=	${NEEDED_DEPENDS}

USES=		compiler:c++11-lang python

USE_PYTHON=	distutils autoplist concurrent cython

PYDISTUTILS_BUILD_TARGET=	build_ext

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fcl/fcl.so

.include <bsd.port.mk>
