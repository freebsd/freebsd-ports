PORTNAME=	phonors
DISTVERSION=	0.3.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust kernels for phonopy and phono3py
WWW=		https://github.com/phonopy/phonors

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.7<2:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist

# Workaround to keep the PyPI source tarball alongside the cargo crates.
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

CARGO_CRATES=	autocfg-1.5.1 \
		bitflags-2.13.0 \
		bytemuck-1.25.0 \
		bytemuck_derive-1.10.2 \
		byteorder-1.5.0 \
		cfg-if-1.0.4 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crunchy-0.2.4 \
		defer-0.2.1 \
		dyn-stack-0.13.2 \
		dyn-stack-macros-0.1.3 \
		either-1.16.0 \
		enum-as-inner-0.6.1 \
		equator-0.2.2 \
		equator-0.6.0 \
		equator-macro-0.2.1 \
		equator-macro-0.6.0 \
		faer-0.24.4 \
		faer-traits-0.24.0 \
		gemm-0.19.0 \
		gemm-c32-0.19.0 \
		gemm-c64-0.19.0 \
		gemm-common-0.19.0 \
		gemm-f16-0.19.0 \
		gemm-f32-0.19.0 \
		gemm-f64-0.19.0 \
		generativity-1.2.1 \
		half-2.7.1 \
		heck-0.5.0 \
		hermit-abi-0.5.2 \
		interpol-0.2.1 \
		libc-0.2.186 \
		libm-0.2.16 \
		matrixmultiply-0.3.10 \
		nano-gemm-0.2.2 \
		nano-gemm-c32-0.2.1 \
		nano-gemm-c64-0.2.1 \
		nano-gemm-codegen-0.2.1 \
		nano-gemm-core-0.2.1 \
		nano-gemm-f32-0.2.1 \
		nano-gemm-f64-0.2.1 \
		ndarray-0.17.2 \
		num-complex-0.4.6 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		num_cpus-1.17.0 \
		numpy-0.28.0 \
		once_cell-1.21.4 \
		paste-1.0.15 \
		portable-atomic-1.13.1 \
		portable-atomic-util-0.2.7 \
		private-gemm-x86-0.1.20 \
		proc-macro2-1.0.106 \
		pulp-0.22.3 \
		pulp-wasm-simd-flag-0.1.1 \
		pyo3-0.28.3 \
		pyo3-build-config-0.28.3 \
		pyo3-ffi-0.28.3 \
		pyo3-macros-0.28.3 \
		pyo3-macros-backend-0.28.3 \
		qd-0.8.0 \
		quote-1.0.46 \
		raw-cpuid-11.6.0 \
		rawpointer-0.2.1 \
		rayon-1.12.0 \
		rayon-core-1.13.0 \
		reborrow-0.5.5 \
		rustc-hash-2.1.2 \
		same-file-1.0.6 \
		seq-macro-0.3.6 \
		syn-1.0.109 \
		syn-2.0.118 \
		sysctl-0.6.0 \
		target-lexicon-0.13.5 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		unicode-ident-1.0.24 \
		version_check-0.9.5 \
		walkdir-2.5.0 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		zerocopy-0.8.52 \
		zerocopy-derive-0.8.52

.include <bsd.port.mk>
