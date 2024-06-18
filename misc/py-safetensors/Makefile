PORTNAME=	safetensors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
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
RUN_DEPENDS=	${PYNUMPY}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	huggingface

WRKSRC_SUBDIR=	bindings/python

CARGO_CRATES=	autocfg-1.2.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		heck-0.4.1 \
		indoc-2.0.5 \
		itoa-1.0.11 \
		libc-0.2.153 \
		lock_api-0.4.11 \
		memmap2-0.9.4 \
		memoffset-0.9.1 \
		once_cell-1.19.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		portable-atomic-1.6.0 \
		proc-macro2-1.0.80 \
		pyo3-0.21.1 \
		pyo3-build-config-0.21.1 \
		pyo3-ffi-0.21.1 \
		pyo3-macros-0.21.1 \
		pyo3-macros-backend-0.21.1 \
		quote-1.0.36 \
		redox_syscall-0.4.1 \
		ryu-1.0.17 \
		scopeguard-1.2.0 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		serde_json-1.0.115 \
		smallvec-1.13.2 \
		syn-2.0.59 \
		target-lexicon-0.12.14 \
		unicode-ident-1.0.12 \
		unindent-0.2.3 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${BUILD_WRKDIR}

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/safetensors/_safetensors_rust${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
