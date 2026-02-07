PORTNAME=	kimpy
DISTVERSION=	2.1.3
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to the KIM-API
WWW=		https://openkim.org/kim-api/

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
LIB_DEPENDS=	libkim-api.so:science/kim-api
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++20-lang pkgconfig python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/openkim/kimpy/issues/16

TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/kimpy/*${PYTHON_TAG}.so

# tests as of 2.1.3: 21 passed in 2.91s

.include <bsd.port.mk>
