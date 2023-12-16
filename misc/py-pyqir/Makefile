PORTNAME=	pyqir
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	misc python # quantum-computing
#MASTER_SITES=	PYPI # no tarballs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyQIR parses, generates, evaluates Quantum Intermediate Representation
WWW=		https://www.qir-alliance.org/pyqir/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo gnome llvm:14 localbase:ldflags python
USE_PYTHON=	pep517 pytest
USE_GNOME=	libxml2

WRKSRC_SUBSIR=	pyqir

USE_GITHUB=	yes
GH_ACCOUNT=	qir-alliance

CARGO_FEATURES=	llvm14-0
CARGO_CRATES=	aho-corasick-0.7.19 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitvec-1.0.1 \
		cc-1.0.76 \
		cfg-if-1.0.0 \
		cmake-0.1.49 \
		const-str-0.5.3 \
		dashmap-5.4.0 \
		error-chain-0.10.0 \
		funty-2.0.0 \
		futures-0.3.25 \
		futures-channel-0.3.25 \
		futures-core-0.3.25 \
		futures-executor-0.3.25 \
		futures-io-0.3.25 \
		futures-sink-0.3.25 \
		futures-task-0.3.25 \
		futures-util-0.3.25 \
		hashbrown-0.12.3 \
		indoc-1.0.7 \
		lazy_static-1.4.0 \
		libc-0.2.137 \
		llvm-sys-110.0.4 \
		llvm-sys-120.2.5 \
		llvm-sys-130.0.5 \
		llvm-sys-140.0.3 \
		lock_api-0.4.9 \
		log-0.4.17 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		mut_static-5.0.0 \
		normalize-line-endings-0.3.0 \
		once_cell-1.16.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.4 \
		pest-2.4.1 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.47 \
		pyo3-0.17.3 \
		pyo3-build-config-0.17.3 \
		pyo3-ffi-0.17.3 \
		pyo3-macros-0.17.3 \
		pyo3-macros-backend-0.17.3 \
		quote-1.0.21 \
		radium-0.7.0 \
		redox_syscall-0.2.16 \
		regex-1.7.0 \
		regex-syntax-0.6.28 \
		scopeguard-1.1.0 \
		semver-0.11.0 \
		semver-1.0.14 \
		semver-parser-0.10.2 \
		serial_test-0.9.0 \
		serial_test_derive-0.9.0 \
		slab-0.4.7 \
		smallvec-1.10.0 \
		syn-1.0.103 \
		tap-1.0.1 \
		target-lexicon-0.12.5 \
		thiserror-1.0.37 \
		thiserror-impl-1.0.37 \
		ucd-trie-0.1.5 \
		unicode-ident-1.0.5 \
		unindent-0.1.10 \
		version_check-0.9.4 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0 \
		wyz-0.5.0

MAKE_ENV=	LLVM_SYS_140_PREFIX=${LLVM_PREFIX}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_LIB} ${WRKDIR}/target/*-unknown-freebsd/release/libpyqir.so ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_native.abi3.so
	${INSTALL_DATA} ${WRKSRC}/pyqir/pyqir/*.py ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}

.include <bsd.port.mk>
