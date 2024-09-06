PORTNAME=	safetensors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.5
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

CARGO_CRATES=	autocfg-1.3.0 \
		cfg-if-1.0.0 \
		heck-0.5.0 \
		indoc-2.0.5 \
		itoa-1.0.11 \
		libc-0.2.155 \
		memchr-2.7.4 \
		memmap2-0.9.4 \
		memoffset-0.9.1 \
		once_cell-1.19.0 \
		portable-atomic-1.7.0 \
		proc-macro2-1.0.86 \
		pyo3-0.22.2 \
		pyo3-build-config-0.22.2 \
		pyo3-ffi-0.22.2 \
		pyo3-macros-0.22.2 \
		pyo3-macros-backend-0.22.2 \
		quote-1.0.36 \
		ryu-1.0.18 \
		serde-1.0.204 \
		serde_derive-1.0.204 \
		serde_json-1.0.122 \
		syn-2.0.72 \
		target-lexicon-0.12.16 \
		unicode-ident-1.0.12 \
		unindent-0.2.3

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
