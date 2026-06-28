PORTNAME=	mistral-common
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.5
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI # tests are broken in PYPI tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common utilities for Mistral AI models
WWW=		https://github.com/mistralai/mistral-common

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.21.1:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.25:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.7:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-extra-types>=2.10.5:devel/py-pydantic-extra-types@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.7.0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.11.0:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}click>=8.1.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.118.3:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>=1.0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llguidance>=1.3.0:textproc/py-llguidance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opencv-python-headless>=4.0.0:graphics/py-opencv-python-headless@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.9.1:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentencepiece>=0.2.0:textproc/py-sentencepiece@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soundfile>=0.12.1:audio/py-SoundFile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soxr>=0.5.0:audio/py-soxr@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=7.4.4:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diff-cover>=8.0.3:devel/py-diff-cover@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy-protobuf>=3.5.0:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=1.8.0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=1.84.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7.4.4:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.2.2:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-jsonschema>=4.21.0.20240118:devel/py-types-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-protobuf>=4.24.0.20240129:devel/py-types-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-requests>=2.32:devel/py-types-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	mistralai

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--import-mode=importlib

# tests as of 1.11.5: 1382 passed, 17 skipped, 14 warnings in 69.80s (0:01:09)

.include <bsd.port.mk>
