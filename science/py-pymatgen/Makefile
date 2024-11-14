PORTNAME=	pymatgen
DISTVERSIONPREFIX=	v
DISTVERSION=	2024.11.13
CATEGORIES=	science python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Materials Genomics is a robust materials analysis code
WWW=		https://pymatgen.org/ \
		https://github.com/materialsproject/pymatgen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=1:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.8:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>=2024.10.21:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.7:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}palettable>=3.3.3:misc/py-palettable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=4.5.0:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybtex>=0.24.0:textproc/py-pybtex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17.0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.13.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.14.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>=2.5.0:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.3:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.9:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.60:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>=3.1.4:math/py-uncertainties@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybtex>0:textproc/py-pybtex@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 cython concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	materialsproject

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install: # strip binaries
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} && ${STRIP_CMD} \
		optimization/linear_assignment*.so \
		optimization/neighbors*.so \
		util/coord_cython*.so

# tests fail to find some files: https://github.com/materialsproject/pymatgen/issues/4172
xpre-test:
	@cd ${TEST_WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build_ext --inplace

.include <bsd.port.mk>
