PORTNAME=	xformers
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.36
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Transformers building blocks, supporting a composable construction
WWW=		https://facebookresearch.github.io/xformers/ \
		https://github.com/facebookresearch/xformers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mslk>0:misc/py-mslk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.10:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	facebookresearch
# The PyPI sdist for xformers 0.0.36 is incomplete:
# it is missing tests/__init__.py, tests/utils.py, tests/multiprocessing_utils.py, and the entire xformers/components/ tree, so
# pytest cannot collect the test suite. I switched the port to the GitHub source tarball, which includes those files.

TEST_ARGS=	--disable-plugin-autoload \
		--ignore=tests/test_mem_eff_attention.py \
		--ignore=tests/test_multiprocessing_utils.py \
		--deselect tests/test_mslk_compat.py::test_reexports_exist_in_mslk[xformers.ops.fmha._triton.splitk_kernels]
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKDIR=	${WRKSRC}/tests

NO_ARCH=	yes

# tests as of 0.0.36: 257 passed, 1035 skipped, 1 deselected, 51 warnings in 7.83s

.include <bsd.port.mk>
