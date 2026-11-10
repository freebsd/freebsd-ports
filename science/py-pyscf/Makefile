PORTNAME=	pyscf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.15.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for quantum chemistry
WWW=		https://pyscf.org/ \
		https://github.com/pyscf/pyscf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.7:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.13:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libcint.so:science/libcint \
		libxc.so:science/libxc \
		libxcfun.so:science/xcfun
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=2.7:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.13:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		fortran blaslapack:openblas compiler:c++11-lang gmake python
USE_PYTHON=	distutils autoplist pytest
USE_GITHUB=	yes

POST_PLIST=	fix-plist

TEST_ENV=	${MAKE_ENV} \
		LD_LIBRARY_PATH= \
		OMP_NUM_THREADS=1 \
		OPENBLAS_NUM_THREADS=1 \
		PYTHONPATH=${FILESDIR}:${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/pyscf
# The full suite takes more than 1h on 4 cores. Skipped to fit into the time limit: pbc (periodic systems, about a quarter of all tests),
# adc, grad, mcpdft, tdscf, gw, and the *_slow*/*_high_cost tests.
# Deselected tests need third derivatives of XC functionals (libxc here has max_deriv_order 2), others fail with the libxc/xcfun mismatch.
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_timeout -p xdist.plugin -n 4 --timeout=120 -v -rfE --durations=40 \
		--import-mode=importlib \
		-k "not _high_cost and not _skip" \
		--ignore=adc \
		--ignore=examples \
		--ignore=gw \
		--ignore=grad \
		--ignore=mcpdft \
		--ignore=pbc \
		--ignore=tdscf \
		--ignore-glob="*_slow*.py" \
		--ignore-glob="*test_bz*" \
		--ignore=lib/vhf/test/test_nr_direct.py \
		--deselect=df/test/test_df.py::KnownValues::test_rsh_df_custom_storage \
		--deselect=df/test/test_df_grad.py \
		--deselect=df/test/test_df_hessian.py::KnownValues::test_rhf_hess \
		--deselect=df/test/test_df_hessian.py::KnownValues::test_rks_gga_hess \
		--deselect=df/test/test_df_hessian.py::KnownValues::test_rks_lda_hess \
		--deselect=dft/test/test_he.py::KnownValues::test_wb97 \
		--deselect=dft/test/test_libxc.py::KnownValues::test_deriv_order \
		--deselect=dft/test/test_libxc.py::KnownValues::test_lda \
		--deselect=dft/test/test_libxc.py::KnownValues::test_m06 \
		--deselect=dft/test/test_numint.py::KnownValues::test_get_rho_mo_input \
		--deselect=dft/test/test_numint.py::KnownValues::test_get_rho_with_derivatives_restricted_dm_input \
		--deselect=dft/test/test_numint.py::KnownValues::test_get_rho_with_derivatives_restricted_mo_input \
		--deselect=dft/test/test_numint.py::KnownValues::test_get_rho_with_derivatives_unrestricted_mo_input \
		--deselect=dft/test/test_numint.py::KnownValues::test_uks_gga_wv1 \
		--deselect=dft/test/test_numint.py::KnownValues::test_uks_gga_wv2 \
		--deselect=dft/test/test_xc_deriv.py \
		--deselect=dft/test/test_xcfun.py \
		--deselect=eph/test/test_rhf.py \
		--deselect=eph/test/test_rks.py \
		-c ${WRKSRC}/pytest.ini

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64
# base libomp lacks the aarch64 microtask invoker, OpenMP regions with >15 arguments abort ("Too many args to microtask")
MAKE_ENV+=	CMAKE_CONFIGURE_ARGS=-DENABLE_OPENMP=OFF
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyscf/lib/lib*.so

fix-plist:
	@${REINPLACE_CMD} -e 's|.*pyscf_lib_placeholder.so$$||' ${TMPPLIST}

post-test:
	@${ECHO} "==> simple test ..."
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test.py

# tests as of 2.15.0: 17 failed, 2136 passed, 240 skipped, 89 warnings, 417 subtests passed in 130.83s (0:02:10), for 17 failures see https://github.com/pyscf/pyscf/issues/3621

.include <bsd.port.mk>
