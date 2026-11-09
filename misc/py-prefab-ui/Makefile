PORTNAME=	prefab-ui
DISTVERSION=	0.21.1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generative UI framework that even humans can use
WWW=		https://prefab.prefect.io \
		https://github.com/PrefectHQ/prefab

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>=0.7.0:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cyclopts>=4.0.0:devel/py-cyclopts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.0.0:textproc/py-rich@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.2.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.4.0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

MAKE_ENV+=	UV_DYNAMIC_VERSIONING_BYPASS=${DISTVERSION}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
		#PYTEST_PLUGINS=pytest_asyncio
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio -p pytest_asyncio.plugin \
		-o asyncio_default_fixture_loop_scope=function \
		-p pytest_timeout -p xdist

NO_ARCH=	yes

# tests as of 0.21.1: 1453 passed, 36 skipped in 4.03s

.include <bsd.port.mk>
