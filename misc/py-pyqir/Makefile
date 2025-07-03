PORTNAME=	pyqir
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.7
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
CARGO_CRATES=	aho-corasick-1.1.2 \
		autocfg-1.1.0 \
		bitvec-1.0.1 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		cmake-0.1.50 \
		const-str-0.5.6 \
		error-chain-0.10.0 \
		funty-2.0.0 \
		heck-0.5.0 \
		indoc-2.0.5 \
		lazy_static-1.4.0 \
		libc-0.2.153 \
		llvm-sys-110.0.4 \
		llvm-sys-120.3.2 \
		llvm-sys-130.1.2 \
		llvm-sys-140.1.3 \
		llvm-sys-150.2.1 \
		log-0.4.20 \
		memchr-2.7.1 \
		memoffset-0.9.0 \
		mut_static-5.0.0 \
		normalize-line-endings-0.3.0 \
		once_cell-1.19.0 \
		pest-2.7.6 \
		portable-atomic-1.10.0 \
		proc-macro2-1.0.92 \
		pyo3-0.23.4 \
		pyo3-build-config-0.23.4 \
		pyo3-ffi-0.23.4 \
		pyo3-macros-0.23.4 \
		pyo3-macros-backend-0.23.4 \
		quote-1.0.35 \
		radium-0.7.0 \
		regex-1.10.3 \
		regex-automata-0.4.5 \
		regex-syntax-0.8.2 \
		semver-0.11.0 \
		semver-1.0.21 \
		semver-parser-0.10.2 \
		syn-2.0.95 \
		tap-1.0.1 \
		target-lexicon-0.12.16 \
		thiserror-1.0.56 \
		thiserror-impl-1.0.56 \
		ucd-trie-0.1.6 \
		unicode-ident-1.0.12 \
		unindent-0.2.3 \
		wyz-0.5.1

MAKE_ENV=	LLVM_SYS_140_PREFIX=${LLVM_PREFIX}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_LIB} ${WRKDIR}/target/release/libpyqir.so ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_native.abi3.so
	${INSTALL_DATA} ${WRKSRC}/pyqir/pyqir/*.py ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}

# tests as of 0.10.7: test result: ok. 51 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.01s

.include <bsd.port.mk>
