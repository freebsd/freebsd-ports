PORTNAME=	pyqir
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.4
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
CARGO_CRATES=	aho-corasick-1.1.2 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitvec-1.0.1 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		cmake-0.1.50 \
		const-str-0.5.6 \
		error-chain-0.10.0 \
		funty-2.0.0 \
		indoc-1.0.9 \
		lazy_static-1.4.0 \
		libc-0.2.153 \
		llvm-sys-110.0.4 \
		llvm-sys-120.3.2 \
		llvm-sys-130.1.2 \
		llvm-sys-140.1.3 \
		lock_api-0.4.11 \
		log-0.4.20 \
		memchr-2.7.1 \
		memoffset-0.9.0 \
		mut_static-5.0.0 \
		normalize-line-endings-0.3.0 \
		once_cell-1.19.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		pest-2.7.6 \
		proc-macro2-1.0.78 \
		pyo3-0.19.2 \
		pyo3-build-config-0.19.2 \
		pyo3-ffi-0.19.2 \
		pyo3-macros-0.19.2 \
		pyo3-macros-backend-0.19.2 \
		quote-1.0.35 \
		radium-0.7.0 \
		redox_syscall-0.4.1 \
		regex-1.10.3 \
		regex-automata-0.4.5 \
		regex-syntax-0.8.2 \
		scopeguard-1.2.0 \
		semver-0.11.0 \
		semver-1.0.21 \
		semver-parser-0.10.2 \
		smallvec-1.13.1 \
		syn-1.0.109 \
		syn-2.0.48 \
		tap-1.0.1 \
		target-lexicon-0.12.13 \
		thiserror-1.0.56 \
		thiserror-impl-1.0.56 \
		ucd-trie-0.1.6 \
		unicode-ident-1.0.12 \
		unindent-0.1.11 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5 \
		wyz-0.5.1

MAKE_ENV=	LLVM_SYS_140_PREFIX=${LLVM_PREFIX}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_LIB} ${WRKDIR}/target/*-unknown-freebsd/release/libpyqir.so ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_native.abi3.so
	${INSTALL_DATA} ${WRKSRC}/pyqir/pyqir/*.py ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}

.include <bsd.port.mk>
