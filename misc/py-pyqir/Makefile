PORTNAME=	pyqir
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.4
PORTREVISION=	0
CATEGORIES=	misc python # quantum-computing
#MASTER_SITES=	PYPI # no tarballs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyQIR parses, generates, evaluates Quantum Intermediate Representation
WWW=		https://www.qir-alliance.org/pyqir/ \
		https://github.com/qir-alliance/pyqir

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo gnome llvm:20 localbase:ldflags python
USE_PYTHON=	pep517 pytest
USE_GNOME=	libxml2

WRKSRC_SUBSIR=	pyqir

USE_GITHUB=	yes
GH_ACCOUNT=	qir-alliance

CARGO_FEATURES=	llvm20-1
CARGO_CRATES=	anyhow-1.0.98 \
		autocfg-1.4.0 \
		cc-1.2.48 \
		cmake-0.1.54 \
		const-str-0.6.2 \
		find-msvc-tools-0.1.5 \
		heck-0.5.0 \
		indoc-2.0.6 \
		lazy_static-1.5.0 \
		libc-0.2.171 \
		llvm-sys-181.2.0 \
		llvm-sys-191.0.0 \
		llvm-sys-201.0.1 \
		memoffset-0.9.1 \
		normalize-line-endings-0.3.0 \
		once_cell-1.21.3 \
		portable-atomic-1.11.0 \
		proc-macro2-1.0.94 \
		pyo3-0.27.2 \
		pyo3-build-config-0.27.2 \
		pyo3-ffi-0.27.2 \
		pyo3-macros-0.27.2 \
		pyo3-macros-backend-0.27.2 \
		quote-1.0.40 \
		regex-lite-0.1.7 \
		semver-1.0.26 \
		shlex-1.3.0 \
		syn-2.0.100 \
		target-lexicon-0.13.2 \
		unicode-ident-1.0.18 \
		unindent-0.2.4

MAKE_ENV=	LLVM_SYS_201_PREFIX=${LLVM_PREFIX}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_LIB} ${WRKDIR}/target/release/libpyqir.so ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_native.abi3.so
	${INSTALL_DATA} ${WRKSRC}/pyqir/pyqir/*.py ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}

# tests as of 0.10.7: test result: ok. 51 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.01s

.include <bsd.port.mk>
