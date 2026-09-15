PORTNAME=	python-fcl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0.11
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Python bindings for the Flexible Collision Library
WWW=		https://github.com/berkeleyautomation/python-fcl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfcl.so:math/fcl \
		liboctomap.so:math/octomap
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++11-lang eigen:3 python
USE_GITHUB=	yes
GH_ACCOUNT=	berkeleyautomation

USE_PYTHON=	autoplist concurrent cython pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKDIR=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fcl/fcl*.so

# tests as of 0.7.0.11: 12 passed, 3 skipped in 0.08s
# (3 signed-distance tests skipped due to upstream FCL bug on FreeBSD)

.include <bsd.port.mk>
