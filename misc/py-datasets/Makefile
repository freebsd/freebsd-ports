PORTNAME=	datasets
DISTVERSION=	4.8.5
PORTREVISION=	1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HuggingFace community-driven open-source library of datasets
WWW=		https://huggingface.co/docs/datasets/index \
		https://github.com/huggingface/datasets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyproject-hooks>0:devel/py-pyproject-hooks@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>0.3.0:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=2023.1.0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.25.0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multiprocess>0:devel/py-multiprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=21.0.0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.66.3:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>0:devel/py-xxhash@${PY_FLAVOR}
RUN_DEPENDS_AUDIO=	${PYTHON_PKGNAMEPREFIX}torchcodec>=0.6.0:multimedia/py-torchcodec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.8.0:misc/py-pytorch@${PY_FLAVOR}
RUN_DEPENDS_VISION=	${PY_PILLOW}
RUN_DEPENDS+=	${RUN_DEPENDS_AUDIO} \
		${RUN_DEPENDS_VISION}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}absl-py>=0:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch>0:textproc/py-elasticsearch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}faiss>=1.6.4:math/py-faiss@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jax>=0.3.14:math/py-jax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jiwer>0:misc/py-jiwer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=1.3.0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lz4>=0:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polars>=0.20.0:misc/py-polars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.0.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-datadir>=0:devel/py-pytest-datadir@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.0.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rarfile>=4.0:archivers/py-rarfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}s3fs>=2021.11.1:filesystems/py-s3fs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.1:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0:archivers/py-zstandard@${PY_FLAVOR}
# missing TEST_DEPENDS: jaxlib, joblibspark, py7zr, pyspark, tensorflow, transformers

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		DATASETS_TEST_SKIP_TF=yes
PYTEST_ARGS=	tests/

NO_ARCH=	yes

pre-patch:
	@${MKDIR} ${WRKSRC}/tests/fixtures
	@${TOUCH} ${WRKSRC}/tests/__init__.py ${WRKSRC}/tests/fixtures/__init__.py

pre-test: # skip tests requiring unavailable dependencies/data
	@${RM} ${WRKSRC}/tests/test_fingerprint_tokenizer_stability.py
	@${RM} ${WRKSRC}/tests/test_formatting.py
	@${RM} ${WRKSRC}/tests/test_load.py
	@${RM} ${WRKSRC}/tests/test_distributed.py
	@${RM} ${WRKSRC}/tests/test_search.py
	@${RM} ${WRKSRC}/tests/test_table.py
	@${RM} ${WRKSRC}/tests/test_builder.py
	@${RM} ${WRKSRC}/tests/test_parallel.py
	@${RM} ${WRKSRC}/tests/test_iterable_dataset.py
	@${RM} ${WRKSRC}/tests/test_upstream_hub.py
	@${RM} ${WRKSRC}/tests/test_fingerprint.py

.include <bsd.port.mk>
