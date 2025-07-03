PORTNAME=	rustworkx
DISTVERSION=	0.16.0
PORTREVISION=	2
CATEGORIES=	math python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High performance Python graph library implemented in Rust
WWW=		https://github.com/Qiskit/rustworkx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=5.4:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist distutils pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

CARGO_CRATES=	adler2-2.0.0 \
		ahash-0.8.11 \
		allocator-api2-0.2.21 \
		autocfg-1.4.0 \
		byteorder-1.5.0 \
		cfg-if-1.0.0 \
		crc32fast-1.4.2 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		either-1.13.0 \
		equivalent-1.0.1 \
		fixedbitset-0.5.7 \
		flate2-1.0.35 \
		foldhash-0.1.4 \
		getrandom-0.2.15 \
		hashbrown-0.15.2 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		indexmap-2.7.0 \
		indoc-2.0.5 \
		itertools-0.11.0 \
		itertools-0.13.0 \
		itoa-1.0.14 \
		libc-0.2.169 \
		matrixmultiply-0.3.9 \
		memchr-2.7.4 \
		memoffset-0.9.1 \
		miniz_oxide-0.8.3 \
		ndarray-0.16.1 \
		ndarray-stats-0.6.0 \
		noisy_float-0.2.0 \
		num-bigint-0.4.6 \
		num-complex-0.4.6 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		num_cpus-1.16.0 \
		numpy-0.23.0 \
		once_cell-1.20.2 \
		petgraph-0.7.1 \
		portable-atomic-1.10.0 \
		portable-atomic-util-0.2.4 \
		ppv-lite86-0.2.20 \
		priority-queue-2.1.1 \
		proc-macro2-1.0.93 \
		pyo3-0.23.4 \
		pyo3-build-config-0.23.4 \
		pyo3-ffi-0.23.4 \
		pyo3-macros-0.23.4 \
		pyo3-macros-backend-0.23.4 \
		quick-xml-0.37.2 \
		quote-1.0.38 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rand_pcg-0.3.1 \
		rawpointer-0.2.1 \
		rayon-1.10.0 \
		rayon-cond-0.3.0 \
		rayon-core-1.12.1 \
		rustc-hash-2.1.0 \
		ryu-1.0.18 \
		serde-1.0.217 \
		serde_derive-1.0.217 \
		serde_json-1.0.135 \
		smallvec-1.13.2 \
		sprs-0.11.2 \
		syn-2.0.96 \
		target-lexicon-0.12.16 \
		unicode-ident-1.0.14 \
		unindent-0.2.3 \
		version_check-0.9.5 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${BUILD_WRKDIR}

PLIST_FILES=	${PYTHON_SITELIBDIR}/rustworkx/rustworkx${PYTHON_TAG}.so # workaround for https://github.com/Qiskit/rustworkx/issues/654

BINARY_ALIAS=	python3=${PYTHON_CMD}

#do-test: # this runs tests in the fixed venv
#	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} tox -epy

.include <bsd.port.mk>
