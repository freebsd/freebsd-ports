PORTNAME=	crewai-cli
PORTVERSION=	1.15.7
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	crewai_cli-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CrewAI: CLI
WWW=		https://crewai.com \
		https://docs.crewai.com \
		https://github.com/crewAIInc/crewAI

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.4:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crewai-core>=1.15.7:misc/py-crewai-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=42.0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.14.2:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11.9:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.13.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.2.2:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual>=7.5.0:textproc/py-textual@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=1.1.0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=2.0.2:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv>=0.11.6:devel/py-uv@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}crewai>=1.5.0:misc/py-crewai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subprocess>=0:devel/py-pytest-subprocess@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

# Template files contain Jinja syntax and cannot be byte-compiled.
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --no-compile-bytecode \
			--destdir ${STAGEDIR} --prefix ${PREFIX} \
			${BUILD_WRKSRC}/dist/${PORTNAME:C|[-_]+|_|g}-${DISTVERSION}*.whl

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
# ignore failing tests, see https://github.com/crewAIInc/crewAI/issues/6643
TEST_ARGS=	--ignore=test_click_compatibility.py \
		--ignore=test_create_crew.py \
		--ignore=test_plus_api.py \
		--ignore=test_run_crew.py \
		--ignore=test_run_declarative_flow.py \
		--ignore=skills/test_cli_commands.py \
		--ignore=tools/test_main.py \
		--deselect=tests/test_crew_run_tui.py::test_crew_done_keeps_memory_save_subscription_until_completion

# tests as of 1.15.7: 523 passed, 1 deselected, 5 warnings in 9.56s

.include <bsd.port.mk>
