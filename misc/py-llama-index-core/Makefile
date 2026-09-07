PORTNAME=	llama-index-core
PORTVERSION=	0.14.24
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interface between LLMs and your data
WWW=		https://llamaindex.ai

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.6:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiosqlite>0:databases/py-aiosqlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}banks>=2.3.0:misc/py-banks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dataclasses-json>0:devel/py-dataclasses-json@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>=1.2.9.3:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dirtyjson>=1.0.8:textproc/py-dirtyjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eval-type-backport>=0.2.0:devel/py-eval-type-backport@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filetype>=1.2.0:devel/py-filetype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=2023.5.0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llama-index-workflows>=2.23.3:textproc/py-llama-index-workflows@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=1.5.8:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=3.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.9.3:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.8.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.4.49:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=8.2.0:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.7.0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinytag>=2.2.0:audio/py-tinytag@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.66.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-inspect>=0.8.0:devel/py-typing-inspect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>0:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/^license = "\([^"]*\)"/license = {text = "\1"}/' -e '/^license-files/d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
