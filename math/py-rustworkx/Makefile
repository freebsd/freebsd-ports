PORTNAME=	rustworkx
DISTVERSION=	0.15.1
PORTREVISION=	1
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

CARGO_CRATES=	ahash-0.8.11 \
		alga-0.9.3 \
		allocator-api2-0.2.18 \
		approx-0.3.2 \
		autocfg-1.3.0 \
		bitflags-2.6.0 \
		cfg-if-1.0.0 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		either-1.13.0 \
		equivalent-1.0.1 \
		fixedbitset-0.4.2 \
		getrandom-0.2.15 \
		hashbrown-0.12.3 \
		hashbrown-0.14.5 \
		heck-0.4.1 \
		hermit-abi-0.3.9 \
		indexmap-1.9.3 \
		indexmap-2.2.6 \
		indoc-2.0.5 \
		itertools-0.10.5 \
		itertools-0.11.0 \
		itoa-1.0.11 \
		libc-0.2.155 \
		libm-0.2.8 \
		lock_api-0.4.12 \
		matrixmultiply-0.3.8 \
		memchr-2.7.4 \
		memoffset-0.9.1 \
		ndarray-0.15.6 \
		ndarray-stats-0.5.1 \
		noisy_float-0.2.0 \
		num-bigint-0.4.6 \
		num-complex-0.2.4 \
		num-complex-0.4.6 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		num_cpus-1.16.0 \
		numpy-0.21.0 \
		once_cell-1.19.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		petgraph-0.6.5 \
		portable-atomic-1.6.0 \
		ppv-lite86-0.2.17 \
		priority-queue-2.0.3 \
		proc-macro2-1.0.86 \
		pyo3-0.21.2 \
		pyo3-build-config-0.21.2 \
		pyo3-ffi-0.21.2 \
		pyo3-macros-0.21.2 \
		pyo3-macros-backend-0.21.2 \
		quick-xml-0.34.0 \
		quote-1.0.36 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rand_pcg-0.3.1 \
		rawpointer-0.2.1 \
		rayon-1.10.0 \
		rayon-cond-0.3.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.5.2 \
		rustc-hash-1.1.0 \
		ryu-1.0.18 \
		scopeguard-1.2.0 \
		serde-1.0.203 \
		serde_derive-1.0.203 \
		serde_json-1.0.118 \
		smallvec-1.13.2 \
		sprs-0.11.1 \
		syn-2.0.68 \
		target-lexicon-0.12.14 \
		unicode-ident-1.0.12 \
		unindent-0.2.3 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.52.5 \
		zerocopy-0.7.34 \
		zerocopy-derive-0.7.34

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
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rustworkx/rustworkx${PYTHON_EXT_SUFFIX}.so

#do-test: # this runs tests in the fixed venv
#	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} tox -epy

.include <bsd.port.mk>
