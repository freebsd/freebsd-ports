PORTNAME=	pynwb
DISTVERSION=	3.1.3
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for working with Neurodata stored in the NWB format
WWW=		https://github.com/NeurodataWithoutBorders/pynwb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=3.2.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hdmf>=4.1.2:science/py-hdmf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.2.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=4.1.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist concurrent pytest

TEST_ENV=	${MAKE_ENV} PATH=${STAGEDIR}${PREFIX}/bin:${PATH} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	-o "testpaths=tests"
PYTEST_BROKEN_TESTS=	create_test_extension \
			test_custom_target_table \
			test_get_class \
			test_load_namespace_with_reftype_attribute_check_autoclass_const

NO_ARCH=	yes

post-extract:
	@${RM} -r ${WRKSRC}/tests/read_dandi

# tests as of 3.1.3: 729 passed, 11 skipped, 4 deselected in 73.65s

.include <bsd.port.mk>
