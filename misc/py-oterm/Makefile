PORTNAME=	oterm
DISTVERSION=	0.2.10
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Text-based terminal client for Ollama
WWW=		https://github.com/ggozad/oterm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.9.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosql>=10.1:databases/py-aiosql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiosqlite>=0.19.0:databases/py-aiosqlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}linkify-it-py>=2.0.3:textproc/py-linkify-it-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mdit-py-plugins>=0.4.1:textproc/py-mdit-py-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ollama>=0.2.0:devel/py-ollama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.7.0:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.0.1:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich-pixels>=3.0.1:graphics/py-rich-pixels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual>=0.59.0:textproc/py-textual@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12.3:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uc-micro-py>=1.0.3:textproc/py-uc-micro-py@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
