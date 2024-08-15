PORTNAME=	shell-gpt
DISTVERSION=	1.4.4
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Command-line productivity tool powered by large language models
WWW=		https://github.com/TheR1D/shell_gpt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openai>=1.34.0<2.0.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.7.0<1.0.0:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.1.1<9.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.1.0<14.0.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.8.0<2.0.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}instructor>=0.4.5<1.0.0:misc/py-instructor@${PY_FLAVOR} \
		curl:ftp/curl
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests-mock>=1.10.0<2.0.0:www/py-requests-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

BINARY_ALIAS=	python=${PYTHON_CMD}
NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS LITELLM

LITELLM_DESC=		Support various LLMs via LiteLLM
LITELLM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}litellm>=1.24.5<2.0.0:misc/py-litellm@${PY_FLAVOR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
