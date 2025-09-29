PORTNAME=	aider_chat
DISTVERSION=	0.86.1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	aider_chat-${PORTVERSION}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	AI pair programming in your terminal
WWW=		https://aider.chat/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.44:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>=1.3:devel/py-arrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SoundFile>=0.12:audio/py-SoundFile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiosqlite>0:databases/py-aiosqlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backoff>=2.2:devel/py-backoff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.12:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.8:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=5.5:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>=1.5:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diff-match-patch>=0:textproc/py-diff-match-patch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diskcache>=5.6.0:devel/py-diskcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=7.1.1:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1.30:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=3.0.3:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grep-ast>=0.3.2:textproc/py-grep-ast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.24.6:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}json5>=0.9.11:devel/py-json5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.23.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}litellm>=1.44.7:misc/py-litellm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mixpanel>=4.10:misc/py-mixpanel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=3.3:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy<2.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=1.43.1:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslex>=0.1.3:devel/py-oslex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.12.1:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=4.9.0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.4.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}posthog>=4.0.1:misc/py-posthog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.47:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.8.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydub>=0.25:audio/py-pydub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypandoc>=1.5:textproc/py-pypandoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.7.0:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml-include>=1.2:devel/py-pyyaml-include@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.8:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11,1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shtab>0:devel/py-shtab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}socksio>=1<2:net/py-socksio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sounddevice>=0.5.0:audio/py-sounddevice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}streamlit>=1.38:www/py-streamlit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.7.0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>=0.20.0:textproc/py-tokenizers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter>=0.20,<0.22.2:devel/py-tree-sitter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchfiles>=0:devel/py-watchfiles@${PY_FLAVOR}
# missing dependencies
# playwright its a chromium browser automation library
# watchdog is pulled in by streamlit
# google-generativeai is not a popular aider dependency

USES=		python:3.10+ shebangfix
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_FILES=	aider/coders/base_coder.py aider/coders/search_replace.py

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
