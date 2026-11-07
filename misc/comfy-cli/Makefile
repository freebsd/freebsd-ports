PORTNAME=	comfy-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.25.0
CATEGORIES=	misc python # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI for ComfyUI, a node-based workflow system for AI image generation
WWW=		https://docs.comfy.org/comfy-cli/getting-started \
		https://github.com/Comfy-Org/comfy-cli

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blake3>=1.0.9:security/py-blake3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2024.7.4:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cookiecutter>0:devel/py-cookiecutter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1.50:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio-ffmpeg>0:graphics/py-imageio-ffmpeg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mixpanel>0:misc/py-mixpanel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}posthog>=6:misc/py-posthog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=6:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}questionary>0:devel/py-questionary@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=3.0.2:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.13:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12.5:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.7:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv>=0.11.15:devel/py-uv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Comfy-Org

NO_ARCH=	yes

# deselected tests expect the 'comfy' executable, an unpatched 0.0.0 version, network access, 'uv pip install' into the system python or specific certificate bundle contents
TEST_ARGS=	--ignore=tests/e2e \
		--deselect tests/comfy_cli/command/test_command.py::test_version \
		--deselect tests/comfy_cli/agent/test_command.py::test_cli_permissions_lists_pending_and_names_approve_first \
		--deselect tests/comfy_cli/agent/test_command.py::test_permissions_grant_carries_a_non_default_data_dir \
		--deselect tests/comfy_cli/agent/test_command.py::test_permissions_grant_omits_the_data_dir_when_it_is_the_default \
		--deselect tests/comfy_cli/agent/test_command.py::test_permissions_grant_makes_a_relative_data_dir_absolute \
		--deselect tests/comfy_cli/command/github/test_pr.py::TestInstallExecuteWithLatest \
		--deselect tests/comfy_cli/command/test_node_deps.py::test_non_pep440_installed_version_is_unknown_not_a_crash \
		--deselect tests/comfy_cli/test_http.py::test_an_unloadable_supplement_falls_through_to_the_platform_roots

post-patch: # fix version in pyproject.toml
	@${REINPLACE_CMD} -e 's|version = "0.0.0"|version = "${DISTVERSION}"|' ${WRKSRC}/pyproject.toml

# tests as of 1.25.0: 11389 passed, 20 skipped, 10 deselected, 86 warnings

.include <bsd.port.mk>
