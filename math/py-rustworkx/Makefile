PORTNAME=	rustworkx
DISTVERSION=	0.12.1
CATEGORIES=	math python
#MASTER_SITES=	CHEESESHOP
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

USES=		cargo python:3.7+
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

CARGO_CRATES=	ahash-0.7.6 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		either-1.6.1 \
		fixedbitset-0.4.2 \
		getrandom-0.2.6 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		indexmap-1.7.0 \
		indoc-1.0.6 \
		instant-0.1.12 \
		itoa-1.0.2 \
		lazy_static-1.4.0 \
		libc-0.2.126 \
		lock_api-0.4.7 \
		matrixmultiply-0.2.4 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		ndarray-0.13.1 \
		num-bigint-0.4.3 \
		num-complex-0.2.4 \
		num-complex-0.4.1 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		numpy-0.17.2 \
		once_cell-1.12.0 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		petgraph-0.6.2 \
		ppv-lite86-0.2.16 \
		priority-queue-1.2.0 \
		proc-macro2-1.0.39 \
		pyo3-0.17.3 \
		pyo3-build-config-0.17.3 \
		pyo3-ffi-0.17.3 \
		pyo3-macros-0.17.3 \
		pyo3-macros-backend-0.17.3 \
		quick-xml-0.22.0 \
		quote-1.0.18 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_pcg-0.3.1 \
		rawpointer-0.2.1 \
		rayon-1.5.3 \
		rayon-core-1.9.3 \
		redox_syscall-0.2.13 \
		ryu-1.0.10 \
		scopeguard-1.1.0 \
		serde-1.0.145 \
		serde_derive-1.0.145 \
		serde_json-1.0.89 \
		smallvec-1.8.0 \
		syn-1.0.96 \
		target-lexicon-0.12.4 \
		unicode-ident-1.0.0 \
		unindent-0.1.9 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${BUILD_WRKDIR}

PLIST_FILES=	${PYTHON_SITELIBDIR}/rustworkx/rustworkx${PYTHON_EXT_SUFFIX}.so # workaround for https://github.com/Qiskit/rustworkx/issues/654

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rustworkx/rustworkx.cpython-${PYTHON_SUFFIX}.so

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} tox -epy

.include <bsd.port.mk>
