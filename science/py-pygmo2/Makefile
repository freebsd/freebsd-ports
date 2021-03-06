# $FreeBSD$

PORTNAME=	pygmo2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.16.1
PORTREVISION=	1
CATEGORIES=	science graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python platform to perform parallel computations of optimisation tasks

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libpagmo.so:science/pagmo2 \
		libboost_serialization.so:devel/boost-libs \
		libnlopt.so:math/nlopt
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang python:3.7+
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	esa

CMAKE_ON=	PYGMO_ENABLE_IPO

CXXFLAGS+=	-I${LOCALBASE}/include/coin # see https://github.com/esa/pygmo2/issues/58

do-test: # requires to have the package installed; test taken from azure-pipelines.yml
	@${PYTHON_CMD} -c "import pygmo; pygmo.test.run_test_suite(1); pygmo.mp_island.shutdown_pool(); pygmo.mp_bfe.shutdown_pool()"

.include <bsd.port.mk>
