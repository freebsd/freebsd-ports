PORTNAME=	litellm
DISTVERSION=	1.83.14
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Call all LLM APIs using the OpenAI format
WWW=		https://github.com/BerriAI/litellm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.10.7:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastuuid>=0.14.0:devel/py-fastuuid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=2.24.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.2.2:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.12.0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=8.5.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>=0.22.2:textproc/py-tokenizers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.13.4:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.12.5:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.23.0:devel/py-jsonschema@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

SHEBANG_FILES=	litellm/proxy/start.sh
bash_CMD=	${SH}

REINPLACE_ARGS=	-i ''
NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' \
		${WRKSRC}/litellm/proxy/start.sh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
