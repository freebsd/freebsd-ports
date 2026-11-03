PORTNAME=	crewai-cli
PORTVERSION=	1.15.34
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
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crewai-core==1.15.34:misc/py-crewai-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=42.0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.14.2:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11.9:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.15.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.2.2:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual>=7.5.0:textproc/py-textual@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=1.1.0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=2.0.2:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv>=0.13.4:devel/py-uv@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crewai>=1.15.27:misc/py-crewai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subprocess>=0:devel/py-pytest-subprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

# Template files contain Jinja syntax and cannot be byte-compiled.
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --no-compile-bytecode \
			--destdir ${STAGEDIR} --prefix ${PREFIX} \
			${BUILD_WRKSRC}/dist/${PORTNAME:C|[-_]+|_|g}-${DISTVERSION}*.whl

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_subprocess.fixtures \
		-p pytest_asyncio.plugin \
		-p pytest_timeout
TEST_ARGS+=	--ignore=experimental/test_eval_crew.py # EMLINK when exporting through symlinks on FreeBSD
TEST_ARGS+=	--ignore=test_click_compatibility.py # needs monorepo lib/* pyproject.toml files absent from PyPI sdist
TEST_ARGS+=	--ignore=test_create_unified.py # create command fails with --no-project in isolated test environment
TEST_ARGS+=	--deselect='tests/test_cli.py::test_commands_that_need_a_login_exit_1_when_logged_out[args5]' # create tool --no-project error in isolated env
TEST_ARGS+=	--deselect=tests/test_cli.py::test_create_skip_provider_flag # create command --no-project error in isolated env
TEST_ARGS+=	--deselect=tests/test_cli.py::test_create_skip_provider_snake_case_alias_warns # create command --no-project error in isolated env
TEST_ARGS+=	--deselect=tests/test_cli.py::test_create_crew_in_dmn_mode_skips_provider_prompts # create command --no-project error in isolated env
TEST_ARGS+=	--deselect=tests/test_cli.py::test_create_flow_declarative_uses_declarative_scaffold # create command --no-project error in isolated env
TEST_ARGS+=	--deselect=tests/test_cli.py::test_create_crew_rejects_declarative_flag # create command --no-project error in isolated env
TEST_ARGS+=	--deselect='tests/test_create_crew.py::test_create_initializes_git_repo_when_git_is_available[args0-git_crew]' # requires a project parent not present in isolated test env
TEST_ARGS+=	--deselect='tests/test_create_crew.py::test_create_initializes_git_repo_when_git_is_available[args1-git_flow]' # requires a project parent not present in isolated test env
TEST_ARGS+=	--deselect=tests/test_create_crew.py::test_agents_md_imports_resolve # references crewai_files imports not available in sdist
TEST_ARGS+=	--deselect=tests/test_create_crew.py::test_agents_md_docs_paths_exist # references files not available in sdist
TEST_ARGS+=	--deselect=tests/test_crew_run_tui.py::test_tracing_asked_for_reads_the_declaration_but_keeps_the_other_guards # TUI tests need an interactive terminal
TEST_ARGS+=	--deselect=tests/test_crew_run_tui.py::test_pressing_evaluate_on_an_untraced_run_counts_the_press_and_nothing_else # TUI tests need an interactive terminal
TEST_ARGS+=	--deselect=tests/test_run_declarative_flow.py::test_run_declarative_flow_still_runs_a_disabled_conversational_flow # output formatting differs in test environment
TEST_ARGS+=	--deselect=tests/skills/test_cli_commands.py::TestSkillGroupIsTopLevel::test_skill_group_not_gated_by_experimental_env # default in_project value changed upstream
TEST_ARGS+=	--deselect=tests/test_plus_api.py::TestPlusAPI::test_get_tool_with_org_uuid # needs CREWAI_PLUS_URL environment variable
TEST_ARGS+=	--deselect=tests/test_plus_api.py::TestPlusAPI::test_login_to_tool_repository_with_org_uuid # needs CREWAI_PLUS_URL environment variable
TEST_ARGS+=	--deselect=tests/test_plus_api.py::TestPlusAPI::test_publish_tool_with_org_uuid # needs CREWAI_PLUS_URL environment variable

# tests as of 1.15.34: 1169 passed, 17 deselected, 5 warnings, 13 subtests passed

.include <bsd.port.mk>
