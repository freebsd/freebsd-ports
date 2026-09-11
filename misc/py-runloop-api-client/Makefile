PORTNAME=	runloop-api-client
#DISTVERSIONPREFIX=	v
DISTVERSION=	1.32.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Official Python library for the runloop API
WWW=		https://github.com/runloopai/api-client-python

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.26.3:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.5.05:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.7.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.23.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>0:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uuid-utils>=0.11.0:misc/py-uuid-utils@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dirty-equals>=0.6.0:devel/py-dirty-equals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=6.7.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=1.17:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyright>=1.1.399:devel/py-pyright@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=7.0.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-frontmatter>=1.0.0:textproc/py-python-frontmatter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}respx>=0:www/py-respx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}time-machine>=0:devel/py-time-machine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uuid-utils>=0.11.0:misc/py-uuid-utils@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin -p pytest_cov.plugin -p pytest_timeout -p xdist -p respx.plugin
TEST_ARGS+=	-W ignore::ResourceWarning # prevent Python 3.12 socket/loop cleanup warnings from triggering failures when filterwarnings = ["error"] is enabled in pyproject.toml
TEST_ARGS+=	--ignore=tests/api_resources # skip tests targeting external Prism mock servers
TEST_ARGS+=	--ignore=tests/smoketests # skip live API key tests

# tests as of 1.32.0: 1077 passed, 2 skipped in 14s

.include <bsd.port.mk>
