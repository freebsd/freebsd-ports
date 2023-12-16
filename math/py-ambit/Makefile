PORTNAME=	ambit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for tensor product calculations
WWW=		https://github.com/jturney/ambit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

PY_DEPENDS=	${PYNUMPY}
BUILD_DEPENDS=	pybind11>0:devel/pybind11 \
		${PY_DEPENDS}
LIB_DEPENDS=	libambit.so:math/ambit \
		libhdf5.so:science/hdf5 \
		libopenblas.so:math/openblas
RUN_DEPENDS=	${PY_DEPENDS}

USES=		cmake compiler:c++17-lang python:build
USE_PYTHON=	flavors pytest

USE_GITHUB=	yes
GH_ACCOUNT=	jturney

WRKSRC_SUBDIR=	pyambit

CMAKE_ARGS=	-DPYMOD_INSTALL_LIBDIR:STRING=/python${_PYTHON_VERSION}/site-packages \
		-DFREEBSD_PYTHON_VER=${PYTHON_VER}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}

post-install: # remove share/cmake/ambit/ambitTargets-Python-%%CMAKE_BUILD_TYPE%%.cmake, and tests
	@${RM} -r \
		${STAGEDIR}${PREFIX}/share \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ambit/tests

pre-test:
	@${RM} ${WRKSRC}/__init__.py # tests fail with __init__.py

.include <bsd.port.mk>
