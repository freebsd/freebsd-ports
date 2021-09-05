PORTNAME=	heyoka
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library for ODE integration via Taylor's method and LLVM

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libheyoka.so:math/heyoka \
		libmp++.so:math/mppp \
		libspdlog.so:devel/spdlog
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang python:3.7+
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni
GH_PROJECT=	${PORTNAME}.py

CMAKE_ON=	HEYOKA_PY_ENABLE_IPO
CMAKE_ARGS=	-DFREEBSD_PYTHON_DISTVERSION=${PYTHON_DISTVERSION}

.include <bsd.port.mk>
