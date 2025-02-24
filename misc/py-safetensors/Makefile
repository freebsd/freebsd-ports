PORTNAME=	safetensors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
PORTREVISION=	1
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

CARGO_CRATES=	autocfg-1.4.0 \
		cfg-if-1.0.0 \
		heck-0.5.0 \
		indoc-2.0.5 \
		itoa-1.0.14 \
		libc-0.2.169 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		memoffset-0.9.1 \
		once_cell-1.20.2 \
		portable-atomic-1.10.0 \
		proc-macro2-1.0.92 \
		pyo3-0.23.3 \
		pyo3-build-config-0.23.3 \
		pyo3-ffi-0.23.3 \
		pyo3-macros-0.23.3 \
		pyo3-macros-backend-0.23.3 \
		quote-1.0.38 \
		ryu-1.0.18 \
		serde-1.0.217 \
		serde_derive-1.0.217 \
		serde_json-1.0.135 \
		syn-2.0.95 \
		target-lexicon-0.12.16 \
		unicode-ident-1.0.14 \
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
