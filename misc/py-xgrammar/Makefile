PORTNAME=	xgrammar
DISTVERSION=	0.2.9
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient, flexible and portable structured generation
WWW=		https://xgrammar.mlc.ai/ \
		https://github.com/mlc-ai/xgrammar

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apache-tvm-ffi>=0.1.11:misc/py-apache-tvm-ffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10.0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.1:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apache-tvm-ffi>=0.1.11:misc/py-apache-tvm-ffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=1.10.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.38.0:misc/py-transformers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.9.0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cohere-melody>=0.13.0:misc/py-cohere-melody@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-run-parallel>0:devel/py-pytest-run-parallel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentencepiece>0:textproc/py-sentencepiece@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>0:textproc/py-tiktoken@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	pep517 autoplist pytest

# LD_PRELOAD avoids 'No space available for static Thread Local Storage' when torch is imported after tvm_ffi
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_PRELOAD=${PYTHON_SITELIBDIR}/torch/lib/libc10.so
TEST_ARGS=	--disable-plugin-autoload -p pytest_run_parallel.plugin -m "not hf_token_required"
TEST_WRKSRC=	${WRKSRC}/tests

# tests as of 0.2.9: 4934 passed, 61 skipped, 860 deselected, 5 warnings in 69.28s (0:01:09)
# tests that require gated HF models (marker hf_token_required) are deselected, see https://github.com/mlc-ai/xgrammar/issues/584

.include <bsd.port.mk>
