PORTNAME=	pymatgen-core
DISTVERSIONPREFIX=	v
DISTVERSION=	2026.9.23
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Materials Genomics core data structures and algorithms
WWW=		https://pymatgen.org/ \
		https://github.com/materialsproject/pymatgen-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.1.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bibtexparser>=1:textproc/py-bibtexparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=1.3.2:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=6.1.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.8:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>=2026.7.16:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.7:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.25.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.10:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}palettable>=3.3.3:misc/py-palettable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=5.0:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.13.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>=2.5.0:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.3:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.9.0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.67.3:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>=3.1:math/py-uncertainties@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 cython concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	materialsproject
GH_PROJECT=	pymatgen-core

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		ETS_TOOLKIT=null \
		QT_QPA_PLATFORM=offscreen \
		PMG_TEST_FILES_DIR=${WRKSRC}/test-files \
		MPLBACKEND=Agg
TEST_ARGS=	--disable-plugin-autoload \
		--deselect=tests/core/test_graphs.py::TestMoleculeGraph::test_construction \
		--deselect=tests/io/qchem/test_outputs.py::TestQCOutput::test_structural_change \
		--deselect=tests/io/test_cif.py::TestCifIO::test_cif_parser \
		--deselect=tests/io/test_cif.py::TestMagCif::test_bibtex \
		--deselect=tests/util/test_provenance.py::TestStructureNL::test_authors \
		--deselect=tests/util/test_provenance.py::TestStructureNL::test_references \
		--deselect=tests/util/test_provenance.py::TestStructureNL::test_eq \
		--deselect=tests/util/test_provenance.py::TestStructureNL::test_as_from_dict
MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools>=77.0.0|setuptools|' \
		-e 's|license = "MIT"|license = { text = "MIT" }|' \
		-e '/^license-files = /d' \
		${WRKSRC}/pyproject.toml
	@${REINPLACE_CMD} -e 's|np.linalg.det(scale_matrix)|round(float(np.linalg.det(scale_matrix)))|' \
		${WRKSRC}/src/pymatgen/core/structure.py

# tests as of 2026.9.23: 2899 passed, 334 skipped, 10 deselected, 4 xfailed, 63 warnings in 581.35s (0:09:41)

.include <bsd.port.mk>
