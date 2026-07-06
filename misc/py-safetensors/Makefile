PORTNAME=	safetensors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	0
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple, safe way to store and distribute tensors
WWW=		https://huggingface.co/docs/safetensors/index \
		https://github.com/huggingface/safetensors

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}maturin>0:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=1.10:misc/py-pytorch@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=3.7.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.12.1:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=6.70.2:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=4.0.0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	huggingface

WRKSRC_SUBDIR=	bindings/python

CARGO_CRATES=	allocator-api2-0.2.21 \
		anyhow-1.0.102 \
		bitflags-2.13.0 \
		block2-0.6.2 \
		cfg-if-1.0.4 \
		dispatch2-0.3.1 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		fastrand-2.4.1 \
		foldhash-0.1.5 \
		foldhash-0.2.0 \
		getrandom-0.4.2 \
		hashbrown-0.15.5 \
		hashbrown-0.16.1 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		id-arena-2.3.0 \
		indexmap-2.14.0 \
		itoa-1.0.18 \
		leb128fmt-0.1.0 \
		libc-0.2.186 \
		linux-raw-sys-0.12.1 \
		log-0.4.32 \
		memchr-2.8.1 \
		memmap2-0.9.10 \
		objc2-0.6.4 \
		objc2-core-foundation-0.3.2 \
		objc2-encode-4.1.0 \
		objc2-foundation-0.3.2 \
		objc2-metal-0.3.2 \
		once_cell-1.21.4 \
		portable-atomic-1.13.1 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.106 \
		pyo3-0.28.3 \
		pyo3-build-config-0.28.3 \
		pyo3-ffi-0.28.3 \
		pyo3-macros-0.28.3 \
		pyo3-macros-backend-0.28.3 \
		quote-1.0.45 \
		r-efi-6.0.0 \
		rustix-1.1.4 \
		semver-1.0.28 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.150 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		tempfile-3.27.0 \
		unicode-ident-1.0.24 \
		unicode-xid-0.2.6 \
		wasip2-1.0.3+wasi-0.2.9 \
		wasip3-0.4.0+wasi-0.3.0-rc-2026-01-06 \
		wasm-encoder-0.244.0 \
		wasm-metadata-0.244.0 \
		wasmparser-0.244.0 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		wit-bindgen-0.51.0 \
		wit-bindgen-0.57.1 \
		wit-bindgen-core-0.51.0 \
		wit-bindgen-rust-0.51.0 \
		wit-bindgen-rust-macro-0.51.0 \
		wit-component-0.244.0 \
		wit-parser-0.244.0 \
		zmij-1.0.21

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${BUILD_WRKDIR}

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
