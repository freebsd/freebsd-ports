PORTNAME=	pyaudi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2-1
DISTVERSIONSUFFIX=	-g899eb78
PORTREVISION=	17
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library implementing the algebra of Taylor polynomials
WWW=		http://darioizzo.github.io/audi/ \
		https://github.com/darioizzo/audi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_armv7=	compilation fails: constraints not satisfied for class template 'd_packed_monomial' [with T = unsigned long long, PSize = 8]
BROKEN_i386=	not for 32-bit systems, see https://github.com/darioizzo/audi/issues/62

BUILD_DEPENDS=	audi>0:math/audi \
		pybind11>0:devel/pybind11
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libboost_serialization.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libgmp.so:math/gmp \
		libmp++.so:math/mppp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libobake.so:math/obake \
		libtbb.so:devel/onetbb

USES=		cmake:testing compiler:c++20-lang python
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	darioizzo
GH_PROJECT=	audi

WRKSRC_SUBDIR=	pyaudi

CMAKE_OFF=	AUDI_BUILD_TESTS
CMAKE_ARGS=	-DPYTHON_VERSION_MAJOR=3

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
