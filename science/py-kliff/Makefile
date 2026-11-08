PORTNAME=	kliff
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1-45
DISTVERSIONSUFFIX=	-gdf2d4de
CATEGORIES=	science python # chemistry
#MASTER_SITES=	PYPI # release 1.0.1 is faulty: it has the numpy<2 requirement
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	KIM-based Learning-Integrated Fitting Framework
WWW=		https://kliff.readthedocs.io/en/latest/ \
		https://github.com/openkim/kliff

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}loguru>0:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>0:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}
RUN_DEPENDS_torch=	\
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch-lightning>0:misc/py-pytorch-lightning@${PY_FLAVOR}
		# missing: torch_geometric, torch_scatter, tensorboard, tensorboardx
RUN_DEPENDS+=	${RUN_DEPENDS_torch}
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}emcee>0:math/py-emcee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kimpy>0:science/py-kimpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}
		# libdescriptor is missing
		# also need 'torch' dependency

USES=		compiler:c++11-lang python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/openkim/kliff/issues/81, and https://github.com/openkim/kliff/issues/197

USE_GITHUB=	yes
GH_ACCOUNT=	openkim

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

test-quick:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py

# tests as of 0.4.4: 17 failed, 29 passed, 16 errors in 14.58s, see https://github.com/openkim/kliff/issues/210

.include <bsd.port.mk>
