PORTNAME=	openmc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Monte Carlo neutron and photon transport simulation code (Python)
WWW=		https://openmc.org/ \
		https://docs.openmc.org/en/stable/ \
		https://github.com/openmc-dev/openmc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}endf>0:science/py-endf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>0:math/py-uncertainties@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		openmc>0:science/openmc \
		${PY_DEPENDS}
RUN_DEPENDS=	openmc>0:science/openmc \
		${PY_DEPENDS}

USES=		python
USE_PYTHON=	pep517 cython concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-dev

PLIST_FILES=	${PYTHON_SITELIBDIR}/openmc/lib/libopenmc.so

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	# link the library
	@${LN} -s ${LOCALBASE}/lib/libopenmc.so ${STAGEDIR}${PYTHON_SITELIBDIR}/openmc/lib/libopenmc.so

pre-test:
	# link the library
	@if ! [ -e ${WRKSRC}/openmc/lib/libopenmc.so ]; then ${LN} -s ${LOCALBASE}/lib/libopenmc.so ${WRKSRC}/openmc/lib/libopenmc.so; fi

# The full test suite needs the NNDC HDF5 cross-section data set, which is not
# available in the ports build environment.  Limit pytest to the subset of
# tests that exercise the Python API without running the OpenMC Monte Carlo
# executable or loading nuclear data libraries.
TEST_ARGS=	tests/test_matplotlib_import.py \
		tests/unit_tests/mesh_to_vtk/test.py \
		tests/unit_tests/test_bounding_box.py \
		tests/unit_tests/test_config.py \
		tests/unit_tests/test_data_dose.py \
		tests/unit_tests/test_data_mass_attenuation.py \
		tests/unit_tests/test_deplete_atom_number.py \
		tests/unit_tests/test_deplete_continue.py \
		tests/unit_tests/test_deplete_cram.py \
		tests/unit_tests/test_deplete_decay.py \
		tests/unit_tests/test_deplete_nuclide.py \
		tests/unit_tests/test_deplete_operator.py \
		tests/unit_tests/test_deplete_reaction.py \
		tests/unit_tests/test_deplete_resultslist.py \
		tests/unit_tests/test_deplete_restart.py \
		tests/unit_tests/test_filter_reaction.py \
		tests/unit_tests/test_lattice.py \
		tests/unit_tests/test_lattice_discretization.py \
		tests/unit_tests/test_mcpl_stat_sum.py \
		tests/unit_tests/test_mesh_from_domain.py \
		tests/unit_tests/test_mesh_from_lattice.py \
		tests/unit_tests/test_mg_inverse_velocity.py \
		tests/unit_tests/test_mgxs_convert_flux.py \
		tests/unit_tests/test_model_triso.py \
		tests/unit_tests/test_particle_type.py \
		tests/unit_tests/test_pathlike_simple.py \
		tests/unit_tests/test_pin.py \
		tests/unit_tests/test_plots.py \
		tests/unit_tests/test_polynomials.py \
		tests/unit_tests/test_slice_voxel_plots.py \
		tests/unit_tests/test_surface.py \
		tests/unit_tests/test_surface_composite.py \
		tests/unit_tests/test_temp_interp.py \
		tests/unit_tests/test_transfer_volumes.py \
		tests/unit_tests/test_vectfit.py \
		tests/unit_tests/test_waste_classification.py

# tests as of 0.16.0: 325 passed, 1 skipped, 27 warnings in 39.09s

.include <bsd.port.mk>
