PORTNAME=	pymatgen
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.6.14
PORTREVISION=	1
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
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bibtexparser>=1.4.0:textproc/py-bibtexparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=1:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.8:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>=2025.1.9:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.7:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.10:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}palettable>=3.3.3:misc/py-palettable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=5.0.0:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybtex>=0.24.0:textproc/py-pybtex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17.0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.13.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>=2.5:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.3:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.9:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.60:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>=3.1.4:math/py-uncertainties@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ase>=3.23.0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=3.11.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonopy>=2.33.3:science/py-phonopy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seekpath>=2.0.1:science/py-seekpath@${PY_FLAVOR} # optional dependencies
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybtex>0:textproc/py-pybtex@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 cython concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	materialsproject

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PMG_TEST_FILES_DIR=${WRKSRC}/tests/files \
		DISPLAY=${DISPLAY} \
		XAUTHORITY=${XAUTHORITY}
TEST_WRKSRC=	${WRKSRC}/tests

post-install: # strip binaries
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} && ${STRIP_CMD} \
		optimization/linear_assignment*.so \
		optimization/neighbors*.so \
		util/coord_cython*.so

# tests as of 2025.2.18: 56 failed, 2912 passed, 149 skipped, 1980 warnings in 11080.55s (3:04:40), see https://github.com/materialsproject/pymatgen/issues/4264
# tests as of 2025.5.28: 56 failed, 3015 passed, 161 skipped, 131 warnings, 7 errors in 5700.13s (1:35:00)

.include <bsd.port.mk>
