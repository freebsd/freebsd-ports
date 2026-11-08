PORTNAME=	papermill
DISTVERSION=	2.7.0
CATEGORIES=	misc python
#MASTER_SITES=	PYPI using the latest revision
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parameterize, execute, and analyze notebooks
WWW=		https://papermill.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}entrypoints>0:devel/py-entrypoints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbclient>=0.2.0:devel/py-nbclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=5.2.0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=5.0.2:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.32.2:misc/py-tqdm@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-datalake-store>=0.0.30:devel/py-azure-datalake-store@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-identity>=1.3.1:devel/py-azure-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=12.1.0:devel/py-azure-storage-blob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gcsfs>=0.2:filesystems/py-gcsfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moto>=5.0.0:devel/py-moto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbclient>0:devel/py-nbclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.6.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-env>=0.6.2:devel/py-pytest-env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=1.10:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 autoplist pytest

SHEBANG_FILES=	${WRKSRC}/papermill/tests/test_cli.py

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PYTHONHASHSEED=0 AWS_ACCESS_KEY_ID=foobar_key \
		AWS_SECRET_ACCESS_KEY=foobar_secret
TEST_ARGS=	-p no:cov -p no:black -p no:mypy -p no:xdist -p no:randomly
PYTEST_IGNORED_TESTS=	test_create_adapter TestBrokenNotebook2

USE_GITHUB=	yes
GH_ACCOUNT=	nteract

NO_ARCH=	yes

PORTSCOUT=	limit:^.*[0-9]\.[0-9].*$$ # prevent tags like push

# tests as of 2.7.0: 545 passed, 2 deselected in 103.35s (0:01:43)
# - test_create_adapter is ignored because the packaged azure-datalake-store
#   no longer provides the auth attribute the upstream test mocks.
# - TestBrokenNotebook2 is ignored because the current nbclient/Jupyter kernel
#   emits an error output cell instead of display_data on this broken notebook.

.include <bsd.port.mk>
