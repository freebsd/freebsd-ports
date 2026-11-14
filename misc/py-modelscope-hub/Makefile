PORTNAME=	modelscope-hub
DISTVERSION=	0.7.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python client to connect with ModelScope Hub
WWW=		https://www.modelscope.cn/home \
		https://github.com/modelscope/modelscope

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=41:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.9:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.28:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.64.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0.20:devel/py-responses@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# sdist lacks test data/harness files, kernels needs network; test_matches_installed_modelscope_when_available
# imports torch via the installed modelscope, which can fail with 'No space available for static Thread Local Storage'
TEST_ARGS=	--disable-plugin-autoload -p pytest_mock \
		--ignore=tests/test_download_corruption.py \
		--ignore=tests/test_kernels.py \
		--ignore=tests/test_openapi_coverage.py \
		--deselect=tests/test_compat_constants_completeness.py::test_matches_installed_modelscope_when_available

# tests as of 0.7.1: 978 passed, 1 deselected in 24.93s

.include <bsd.port.mk>
