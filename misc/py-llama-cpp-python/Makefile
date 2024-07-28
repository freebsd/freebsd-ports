PORTNAME=	llama-cpp-python
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.84
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for the llama.cpp library
WWW=		https://llama-cpp-python.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		cmake:devel/cmake-core
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}diskcache>=5.6.1:devel/py-diskcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fastapi>=0.100.0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.0.1:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sse-starlette>=1.6.1:www/py-sse-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette-context>=0.3.6:www/py-starlette-context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.22.0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.24.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10:science/py-scipy@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	abetlen
GH_TUPLE=	ggerganov:llama.cpp:4730fac:cpp/vendor/llama.cpp

SHEBANG_GLOB=	*.py

.include <bsd.port.mk>
