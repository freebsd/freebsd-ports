PORTNAME=	safetensors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2
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

CARGO_CRATES=	autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		heck-0.4.1 \
		indoc-2.0.4 \
		itoa-1.0.10 \
		libc-0.2.152 \
		lock_api-0.4.11 \
		memmap2-0.5.10 \
		memoffset-0.9.0 \
		once_cell-1.19.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		proc-macro2-1.0.78 \
		pyo3-0.20.2 \
		pyo3-build-config-0.20.2 \
		pyo3-ffi-0.20.2 \
		pyo3-macros-0.20.2 \
		pyo3-macros-backend-0.20.2 \
		quote-1.0.35 \
		redox_syscall-0.4.1 \
		ryu-1.0.16 \
		scopeguard-1.2.0 \
		serde-1.0.195 \
		serde_derive-1.0.195 \
		serde_json-1.0.111 \
		smallvec-1.13.1 \
		syn-2.0.48 \
		target-lexicon-0.12.13 \
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
