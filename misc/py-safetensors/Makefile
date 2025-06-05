PORTNAME=	safetensors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.3
PORTREVISION=	2
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple, safe way to store and distribute tensors
WWW=		https://huggingface.co/docs/safetensors/index

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}maturin>0:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=1.10:misc/py-pytorch@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=3.7.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface_hub>=0.12.1:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=6.70.2:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=4.0.0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	huggingface

WRKSRC_SUBDIR=	bindings/python

CARGO_CRATES=	autocfg-1.4.0 \
		cfg-if-1.0.0 \
		heck-0.5.0 \
		indoc-2.0.5 \
		itoa-1.0.14 \
		libc-0.2.170 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		memoffset-0.9.1 \
		once_cell-1.20.3 \
		portable-atomic-1.11.0 \
		proc-macro2-1.0.93 \
		pyo3-0.23.5 \
		pyo3-build-config-0.23.5 \
		pyo3-ffi-0.23.5 \
		pyo3-macros-0.23.5 \
		pyo3-macros-backend-0.23.5 \
		quote-1.0.38 \
		ryu-1.0.19 \
		serde-1.0.218 \
		serde_derive-1.0.218 \
		serde_json-1.0.139 \
		syn-2.0.98 \
		target-lexicon-0.12.16 \
		unicode-ident-1.0.17 \
		unindent-0.2.3

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${BUILD_WRKDIR}

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
