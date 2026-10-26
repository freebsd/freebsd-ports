PORTNAME=	GPy
DISTVERSION=	1.15.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gpy-${DISTVERSION}
PYDISTUTILS_PKGNAME=	gpy

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gaussian process toolbox
WWW=		https://sheffieldml.github.io/GPy/ \
		https://github.com/SheffieldML/GPy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}cython>=0.29:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3.0:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramz>0.9.6:science/py-paramz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	distutils autoplist pytest

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

POST_PLIST=	fix-plist

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/GPy/*/*${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/GPy/*/*/*${PYTHON_TAG}.so

fix-plist: # remove byte-compiled entries for Python-2-only files
	@${REINPLACE_CMD} \
		-e "s|.*__pycache__/mpi_test__.*$$||" \
		-e "s|.*todo/__pycache__/eq_ode1.*$$||" \
		-e "s|.*old_tests/__pycache__/bcgplvm_tests.*$$||" \
		-e "s|.*old_tests/__pycache__/cgd_tests.*$$||" \
		-e "s|.*old_tests/__pycache__/gp_transformation_tests.*$$||" \
		-e "s|.*old_tests/__pycache__/gplvm_tests.*$$||" \
		-e "s|.*old_tests/__pycache__/mapping_tests.*$$||" \
		-e "s|.*old_tests/__pycache__/psi_stat_expectation_tests.*$$||" \
		-e "s|.*old_tests/__pycache__/sparse_gplvm_tests.*$$||" \
		${TMPPLIST}

PYTEST_IGNORED_TESTS=	test_brownian_kernel \
			test_multiout_regression \
			TestStateSpaceKernels \
			test_epccassification \
			test_warped_gp_cubic_sine

TEST_ENV=	${MAKE_ENV}
TEST_ARGS=	--disable-plugin-autoload -p timeout

# tests as of 1.15.0: 348 passed, 16 skipped, 19 deselected, 21 warnings in 116.78s

.include <bsd.port.mk>
