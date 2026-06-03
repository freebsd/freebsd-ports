PORTNAME=	oterm
DISTVERSION=	0.14.7
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Text-based terminal client for Ollama
WWW=		https://github.com/ggozad/oterm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.25.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosql>=10.1:databases/py-aiosql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiosqlite>=0.19.0:databases/py-aiosqlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authlib>=1.6.6:security/py-authlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}exceptiongroup>=1.3.1:devel/py-exceptiongroup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastmcp>=2.12.1:misc/py-fastmcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0.3.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}linkify-it-py>=2.0.3:textproc/py-linkify-it-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mdit-py-plugins>=0.4.1:textproc/py-mdit-py-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ollama>=0.4.7:misc/py-ollama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10.1:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.7.0:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.0.1:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich-pixels>=3.0.1:graphics/py-rich-pixels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual-image>=0.8.4:textproc/py-textual-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual-speedups>=0.2.1:textproc/py-textual-speedups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual0>=0.85.2:textproc/py-textual0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textualeffects>=0.1.3:devel/py-textualeffects@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12.3:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uc-micro-py>=1.0.3:textproc/py-uc-micro-py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}
NO_ARCH=	yes

.include <bsd.port.mk>
