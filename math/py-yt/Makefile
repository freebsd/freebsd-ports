PORTNAME=	yt
DISTVERSION=	4.4.2
CATEGORIES=	math astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analysis and visualization toolkit for volumetric data
WWW=		https://yt-project.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ewah-bool-utils>=1.2.0:devel/py-ewah-bool-utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cmyt>=1.1.2:math/py-cmyt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ewah-bool-utils>=1.2.0:devel/py-ewah-bool-utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.5:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=8.4:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21.3:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.3.2:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=1.2.3:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=0.4.0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=3.4.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.4.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unyt>=2.9.2:math/py-unyt@${PY_FLAVOR}

USES=		dos2unix localbase python
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	@${STRIP_CMD} $$(${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so")

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		MPLBACKEND=Agg \
		PYTEST_ADDOPTS="-p no:black -p no:ruff -p no:mypy -p no:flake8 -p no:cov -p no:benchmark -p no:inline-snapshot -p no:xdist -p no:randomly"

do-test:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && \
		${SETENV} ${TEST_ENV} pytest yt/tests \
		--deselect=yt/data_objects/tests/test_data_containers.py::TestDataContainers::test_to_astropy_table

# tests as of 4.4.2: 53 passed, 10 skipped, 1 xfailed in 9.87s
# Additional tests are excluded because they depend on nose (broken on Python 3.12)
# or on data files/network access.

.include <bsd.port.mk>
