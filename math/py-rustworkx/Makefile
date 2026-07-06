PORTNAME=	rustworkx
DISTVERSION=	0.18.0
CATEGORIES=	math python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High performance Python graph library implemented in Rust
WWW=		https://github.com/Qiskit/rustworkx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.9:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=5.4:graphics/py-pillow@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

CARGO_CRATES=	adler2-2.0.1 \
		aho-corasick-1.1.4 \
		allocator-api2-0.2.21 \
		anyhow-1.0.102 \
		approx-0.5.1 \
		arbitrary-1.4.2 \
		autocfg-1.5.0 \
		bitflags-2.11.1 \
		block-buffer-0.10.4 \
		bytemuck-1.25.0 \
		cc-1.2.62 \
		cfg-if-1.0.4 \
		chacha20-0.10.0 \
		cpufeatures-0.2.17 \
		cpufeatures-0.3.0 \
		crc32fast-1.5.0 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crypto-common-0.1.7 \
		derive_arbitrary-1.4.2 \
		digest-0.10.7 \
		either-1.15.0 \
		env_filter-1.0.1 \
		env_logger-0.11.10 \
		equivalent-1.0.2 \
		find-msvc-tools-0.1.9 \
		fixedbitset-0.5.7 \
		flate2-1.1.9 \
		foldhash-0.1.5 \
		foldhash-0.2.0 \
		generic-array-0.14.7 \
		getrandom-0.2.17 \
		getrandom-0.3.4 \
		getrandom-0.4.2 \
		hashbrown-0.15.5 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		hermit-abi-0.5.2 \
		id-arena-2.3.0 \
		indexmap-2.14.0 \
		itertools-0.13.0 \
		itertools-0.14.0 \
		itoa-1.0.18 \
		jobserver-0.1.34 \
		leb128fmt-0.1.0 \
		libc-0.2.186 \
		libfuzzer-sys-0.4.13 \
		libm-0.2.16 \
		log-0.4.29 \
		matrixmultiply-0.3.10 \
		memchr-2.8.0 \
		miniz_oxide-0.8.9 \
		nalgebra-0.33.3 \
		nalgebra-macros-0.2.2 \
		nalgebra-sparse-0.10.0 \
		ndarray-0.17.2 \
		ndarray-stats-0.7.0 \
		noisy_float-0.2.1 \
		num-bigint-0.4.6 \
		num-complex-0.4.6 \
		num-integer-0.1.46 \
		num-rational-0.4.2 \
		num-traits-0.2.19 \
		num_cpus-1.17.0 \
		numpy-0.29.0 \
		once_cell-1.21.4 \
		paste-1.0.15 \
		pest-2.8.6 \
		pest_derive-2.8.6 \
		pest_generator-2.8.6 \
		pest_meta-2.8.6 \
		petgraph-0.8.3 \
		portable-atomic-1.13.1 \
		portable-atomic-util-0.2.7 \
		ppv-lite86-0.2.21 \
		prettyplease-0.2.37 \
		priority-queue-2.7.0 \
		proc-macro2-1.0.106 \
		pyo3-0.29.0 \
		pyo3-build-config-0.29.0 \
		pyo3-ffi-0.29.0 \
		pyo3-macros-0.29.0 \
		pyo3-macros-backend-0.29.0 \
		quick-xml-0.37.5 \
		quickcheck-1.1.0 \
		quickcheck_macros-1.2.0 \
		quote-1.0.45 \
		r-efi-5.3.0 \
		r-efi-6.0.0 \
		rand-0.8.6 \
		rand-0.10.1 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rand_core-0.10.1 \
		rand_distr-0.6.0 \
		rand_pcg-0.10.2 \
		rawpointer-0.2.1 \
		rayon-1.12.0 \
		rayon-cond-0.4.0 \
		rayon-core-1.13.0 \
		regex-1.12.3 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.10 \
		rustc-hash-2.1.2 \
		safe_arch-0.7.4 \
		semver-1.0.28 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		sha2-0.10.9 \
		shlex-1.3.0 \
		simba-0.9.1 \
		simd-adler32-0.3.9 \
		smallvec-1.15.2 \
		sprs-0.11.4 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		typenum-1.20.0 \
		ucd-trie-0.1.7 \
		unicode-ident-1.0.24 \
		unicode-xid-0.2.6 \
		version_check-0.9.5 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasip2-1.0.1+wasi-0.2.4 \
		wasip3-0.4.0+wasi-0.3.0-rc-2026-01-06 \
		wasm-encoder-0.244.0 \
		wasm-metadata-0.244.0 \
		wasmparser-0.244.0 \
		wide-0.7.33 \
		wit-bindgen-0.46.0 \
		wit-bindgen-0.51.0 \
		wit-bindgen-core-0.51.0 \
		wit-bindgen-rust-0.51.0 \
		wit-bindgen-rust-macro-0.51.0 \
		wit-component-0.244.0 \
		wit-parser-0.244.0 \
		zerocopy-0.8.48 \
		zerocopy-derive-0.8.48 \
		zmij-1.0.21

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${BUILD_WRKDIR}

BINARY_ALIAS=	python3=${PYTHON_CMD}

# The upstream Cargo.lock has pyo3 resolved to hashbrown 0.15.5,
# but cargo update re-resolves it to 0.17.1 causing type mismatches.
# Preserve the upstream Cargo.lock to avoid this issue.
post-extract:
	@${CP} ${CARGO_CARGOLOCK} ${CARGO_CARGOLOCK}.orig

post-configure:
	@${CP} ${CARGO_CARGOLOCK}.orig ${CARGO_CARGOLOCK}

.include <bsd.port.mk>
