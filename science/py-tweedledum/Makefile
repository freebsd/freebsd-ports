PORTNAME=	tweedledum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1-20221123
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for analysis, compilation, synthesis of quantum circuits
WWW=		https://github.com/boschmitt/tweedledum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

#BROKEN_FreeBSD_14=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=265751

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		cmake:devel/cmake-core

USES=		compiler:c++17-lang python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/boschmitt/tweedledum/issues/176

USE_GITHUB=	yes
GH_ACCOUNT=	boschmitt
GH_TAGNAME=	9d3a2fa
GH_TUPLE=	pybind:pybind11:v2.12.0:pybind11

#MAKE_ENV=	CMAKE_ARGS=-DTWEEDLEDUM_USE_EXTERNAL_PYBIND11=ON # external pybind11 should work but it fails to configure
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/python/test

post-extract:
	@${RM} -r ${WRKSRC}/external/pybind11
	@${CP} -r ${WRKSRC_pybind11} ${WRKSRC}/external/pybind11

.include <bsd.port.mk>
