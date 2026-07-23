PORTNAME=	ase
DISTVERSION=	3.29.0
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Atomic simulation environment
WWW=		https://ase-lib.org/ \
		https://gitlab.com/ase/ase

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.1.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR}
#		nwchem:science/nwchem
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=1.30.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asap3>0:science/py-asap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>0:science/py-netCDF4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>0:science/py-spglib@${PY_FLAVOR}
		# more test dependencies can be installed to enable more tests, see printout in the beginning of the test run
# optional dependencies: x11-toolkits/py-tkinter, www/py-flask (see https://wiki.fysik.dtu.dk/ase/install.html)

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

NO_ARCH=	yes

# ignore very slow or hanging tests (need to investigate why they hang)
TEST_ARGS=	--ignore=ase/test/atoms/test_atoms_get_positions.py \
		--ignore=ase/test/ase4/test_optimize.py \
		--ignore=ase/test/filter/test_cellfilter.py \
		--ignore=ase/test/neb/test_dynamic_neb.py \
		--ignore=ase/test/neb/test_autoneb.py \
		--ignore=ase/test/neb/test_COCu111.py \
		--ignore=ase/test/neb/test_COCu111_2.py \
		--ignore=ase/test/optimize/test_cellawarebfgs.py \
		--ignore=ase/test/precon/test_ff_and_precon_c60.py \
		--ignore=ase/test/precon/test_unitcellfilter.py \
		--deselect=ase/test/constraints/test_fix_symmetry.py::test_no_symmetrization[FrechetCellFilter] \
		--deselect=ase/test/constraints/test_fix_symmetry.py::test_no_sym_rotated[FrechetCellFilter] \
		--deselect=ase/test/constraints/test_fix_symmetry.py::test_sym_adj_cell[FrechetCellFilter] \
		--deselect=ase/test/constraints/test_fix_symmetry.py::test_sym_rot_adj_cell[FrechetCellFilter] \
		--ignore=ase/test/calculator/socketio/test_ipi_protocol_bfgs.py \
		--deselect=ase/test/calculator/socketio/test_python_interface.py::test_socketio_python \
		--deselect=ase/test/fio/test_eon_readwrite.py::test_eon_write_single \
		-k 'not GPMin'

# tests as of 3.29.0: 3371 passed, 481 skipped, 10 deselected, 5 xfailed, 1 xpassed, 1 warning in 1788.62s (0:29:48)

.include <bsd.port.mk>
