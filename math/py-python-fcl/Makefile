PORTNAME=	python-fcl
PORTVERSION=	0.0.12
PORTREVISION=	6
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Python bindings for the Flexible Collision Library
WWW=		https://libraries.io/pypi/python-fcl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfcl05.so:math/fcl05 \
		liboctomap.so:math/octomap
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++11-lang eigen:3 python

USE_PYTHON=	autoplist concurrent cython0 distutils

PYDISTUTILS_BUILD_TARGET=	build_ext

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fcl/fcl*.so

.include <bsd.port.mk>
