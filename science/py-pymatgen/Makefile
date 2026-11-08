PORTNAME=	pymatgen
DISTVERSIONPREFIX=	v
DISTVERSION=	2026.10.24
CATEGORIES=	science python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Materials Genomics is a robust materials analysis code
WWW=		https://pymatgen.org/ \
		https://github.com/materialsproject/pymatgen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymatgen-core>=2026.9.23:science/py-pymatgen-core@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ase>=3.27.0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup4>0:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}f90nml>0:devel/py-f90nml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}galore>0:science/py-galore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jarvis-tools>=2020.7.14:science/py-jarvis-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=3.11.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonopy>=4.0.0:science/py-phonopy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzeo>0:science/py-pyzeo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seekpath>=2.0.1:science/py-seekpath@${PY_FLAVOR} # optional dependencies
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybtex>0:textproc/py-pybtex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbabel>0:science/py-openbabel@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 cython concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	materialsproject

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		ETS_TOOLKIT=null \
		QT_QPA_PLATFORM=offscreen \
		PMG_TEST_FILES_DIR=${WRKSRC}/test-files \
		MPLBACKEND=Agg
TEST_ARGS=	--disable-plugin-autoload
TEST_WRKSRC=	${WRKSRC}/tests

post-patch:
	# Remove files owned by py-pymatgen-core (both packages install these from shared namespace)
	@${RM} ${WRKSRC}/src/pymatgen/analysis/chempot_diagram.py \
		${WRKSRC}/src/pymatgen/analysis/phase_diagram.py \
		${WRKSRC}/src/pymatgen/analysis/reaction_calculator.py

# tests as of 2026.10.24: 1 failed, 607 passed, 53 skipped, 7 xfailed, 251 warnings in 185.40s (0:03:05), failure is due to this VTK issue: https://gitlab.kitware.com/vtk/vtk/-/work_items/19993

.include <bsd.port.mk>
