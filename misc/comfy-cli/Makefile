PORTNAME=	comfy-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
CATEGORIES=	misc python # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI for ComfyUI, a node-based workflow system for AI image generation
WWW=		https://docs.comfy.org/comfy-cli/getting-started \
		https://github.com/Comfy-Org/comfy-cli

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cookiecutter>0:devel/py-cookiecutter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mixpanel>0:misc/py-mixpanel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}questionary>0:devel/py-questionary@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=3.0.2:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>0:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12.5:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.7:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv>=0.6.9:devel/py-uv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	Comfy-Org

NO_ARCH=	yes

post-patch: # fix version in pyproject.toml
	@${REINPLACE_CMD} -e 's|version = "0.0.0"|version = "${DISTVERSION}"|' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
