PORTNAME=	gmpy2
DISTVERSION=	2.3.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GMP/MPIR, MPFR, and MPC interface to Python
WWW=		https://gmpy2.readthedocs.io/en/latest/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	pep517 autoplist pytest

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test
PYTEST_IGNORED_TESTS=	test_mpz_arithmetics test_mpz_to_bytes test_mpq_float_bulk \
			test_mpz_conversion_bulk test_mpz_float_bulk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gmpy2/gmpy2*.so

# tests as of 2.3.1: 361 passed, 7 skipped in 267.19s (0:04:27)
# Hypothesis bulk tests are ignored because they generate random edge-case
# failures on FreeBSD that are not indicative of packaging problems.

.include <bsd.port.mk>
