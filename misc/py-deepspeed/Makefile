PORTNAME=	deepspeed
DISTVERSION=	0.20.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DeepSpeed library for ChatGPT-like model training
WWW=		http://www.deepspeed.ai/ \
		https://github.com/deepspeedai/DeepSpeed

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}einops>0:misc/py-einops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hjson>0:textproc/py-hjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ninja>0:devel/py-ninja@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-cpuinfo2>0:sysutils/py-py-cpuinfo2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.0.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		bash:shells/bash
		# many extras exist in setup.py

USES=		python shebangfix
USE_PYTHON=	distutils autoplist pytest # some tests fail, tests consume gigabytes of disk space

SHEBANG_FILES=	bin/ds_ssh

# importing torch fails with 'No space available for static Thread Local Storage' unless libc10 is preloaded
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_PRELOAD=${PYTHON_SITELIBDIR}/torch/lib/libc10.so
TEST_ARGS=	--disable-plugin-autoload

PYTEST_BROKEN_TESTS=	test_llm_layers_replaced_with_distributed_attention \
		test_multimodal_model_wraps_both_branches # see https://github.com/deepspeedai/DeepSpeed/issues/8554

NO_ARCH=	yes

# tests as of 0.20.0: 44 passed, 2 deselected, 2 warnings in 2.75s

.include <bsd.port.mk>
