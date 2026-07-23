PORTNAME=	OpenFermion
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.1
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronic structure package for quantum computers
WWW=		https://github.com/quantumlib/OpenFermion

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cirq-core>=1.6.0:science/py-cirq-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cirq-google>=0.15.0:science/py-cirq-google@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecation>0:devel/py-deprecation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PubChemPy>0:science/py-PubChemPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 tests fails, see https://github.com/quantumlib/OpenFermion/issues/879

USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib

NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD} # only for tests

# tests hang wihout these ignores/deselects:
TEST_ARGS=	--ignore=src/openfermion/testing/performance_benchmarks_test.py \
		--ignore=src/openfermion/testing/lih_integration_test.py \
		--ignore=src/openfermion/linalg/davidson_test.py \
		--ignore=src/openfermion/linalg/linear_qubit_operator_test.py \
		--ignore=src/openfermion/hamiltonians/jellium_test.py \
		--ignore=src/openfermion/hamiltonians/plane_wave_hamiltonian_test.py \
		--ignore=src/openfermion/chem/pubchem_test.py \
		--deselect=src/openfermion/ops/representations/doci_hamiltonian_test.py::IntegralTransformsTest::test_fermionic_hamiltonian_from_integrals \
		--deselect=src/openfermion/transforms/opconversions/remove_symmetry_qubits_test.py::ReduceSymmetryQubitsTest::test_energy_reduce_symmetry_qubits \
		--deselect=src/openfermion/transforms/opconversions/verstraete_cirac_test.py::VerstraeteCirac2dSquareGroundStateTest::test_ground_energy

# tests as of 1.8.1: 2112 passed, 60 skipped, 3 deselected, 17 warnings in 1499.31s (0:24:59)

.include <bsd.port.mk>
