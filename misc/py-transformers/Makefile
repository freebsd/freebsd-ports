PORTNAME=	transformers
DISTVERSION=	4.55.4
PORTREVISION=	1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	State-of-the-art Machine Learning for JAX, PyTorch and TensorFlow
WWW=		https://huggingface.co/transformers \
		https://github.com/huggingface/transformers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.34.0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2019.12.17:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>=0.4.3:misc/py-safetensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>=0.21:textproc/py-tokenizers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.27:misc/py-tqdm@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytorch>=2.1:misc/py-pytorch@${PY_FLAVOR}
# vision
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR}
# speech/audio
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}librosa>0:audio/py-librosa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchaudio>0:audio/py-torchaudio@${PY_FLAVOR}
# serving
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fastapi>0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>0:www/py-uvicorn@${PY_FLAVOR}
# assorted
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}accelerate>=0.26.0:misc/py-accelerate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blobfile>=0:net/py-blobfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}codecarbon>=2.8.1:misc/py-codecarbon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ftfy>=0:textproc/py-ftfy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natten>=0.14.6:misc/py-natten@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}num2words>=0:devel/py-num2words@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}optuna>=0:misc/py-optuna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker>=2.31.0:misc/py-sagemaker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentencepiece>=0.1.91:textproc/py-sentencepiece@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timm>=1.0.19:misc/py-timm@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

NO_ARCH=	yes

.include <bsd.port.mk>
