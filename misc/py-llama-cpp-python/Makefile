PORTNAME=	llama-cpp-python
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.29
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for the llama.cpp library
WWW=		https://llama-cpp-python.readthedocs.io/en/latest/ \
		https://github.com/abetlen/llama-cpp-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.9.2:devel/py-scikit-build-core@${PY_FLAVOR} \
		cmake:devel/cmake-core
LIB_DEPENDS=	libggml.so:misc/ggml
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}diskcache>=5.6.1:devel/py-diskcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.20.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fastapi>=0.100.0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.0.1:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sse-starlette>=1.6.1:www/py-sse-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette-context>=0.3.6:www/py-starlette-context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.22.0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.24.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.23.0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

USES=		python shebangfix ssl
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	abetlen
GH_TUPLE=	ggerganov:llama.cpp:f05cf46:cpp/vendor/llama.cpp

SHEBANG_GLOB=	*.py

CONFLICTS_BUILD=	llama-cpp

# tests as of 0.3.28: 66 passed in 364.39s (0:06:04)

.include <bsd.port.mk>
