PORTNAME=	qiskit-terra
DISTVERSION=	0.24.1
CATEGORIES=	science python # quantum-computing
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terra submodule of the Quiskit framework for quantum computing
WWW=		https://qiskit.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ply>=3.10:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rustworkx>=0.12.0:math/py-rustworkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.5:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.3:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>=0.3:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8.0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=3.0.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}symengine>=0.9:math/py-symengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tweedledum>=1.1:science/py-tweedledum@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ddt>0:devel/py-ddt@${PY_FLAVOR} # no test requirements are listed in setup.py, see https://github.com/Qiskit/qiskit-terra/issues/8498

USES=		cargo python:3.8+
USE_PYTHON=	distutils autoplist pytest # tests fail to run through pytest, see https://github.com/Qiskit/qiskit-terra/issues/8500

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

CARGO_CRATES=	ahash-0.7.6 \
		ahash-0.8.3 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.11 \
		crossbeam-utils-0.8.12 \
		either-1.8.0 \
		fixedbitset-0.4.2 \
		getrandom-0.2.8 \
		hashbrown-0.11.2 \
		hashbrown-0.12.0 \
		hashbrown-0.13.2 \
		hermit-abi-0.1.19 \
		indexmap-1.9.0 \
		indoc-1.0.7 \
		libc-0.2.137 \
		libm-0.2.5 \
		lock_api-0.4.9 \
		matrixmultiply-0.3.2 \
		memoffset-0.6.5 \
		memoffset-0.8.0 \
		ndarray-0.15.6 \
		num-bigint-0.4.3 \
		num-complex-0.4.2 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		numpy-0.18.0 \
		once_cell-1.16.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.4 \
		petgraph-0.6.2 \
		ppv-lite86-0.2.16 \
		priority-queue-1.2.0 \
		proc-macro2-1.0.47 \
		pyo3-0.18.3 \
		pyo3-build-config-0.18.3 \
		pyo3-ffi-0.18.3 \
		pyo3-macros-0.18.3 \
		pyo3-macros-backend-0.18.3 \
		quote-1.0.21 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rand_distr-0.4.3 \
		rand_pcg-0.3.1 \
		rawpointer-0.2.1 \
		rayon-1.7.0 \
		rayon-core-1.11.0 \
		redox_syscall-0.2.16 \
		rustc-hash-1.1.0 \
		rustworkx-core-0.12.1 \
		scopeguard-1.1.0 \
		smallvec-1.10.0 \
		syn-1.0.103 \
		target-lexicon-0.12.4 \
		unicode-ident-1.0.5 \
		unindent-0.1.10 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

PLIST_FILES=	${PYTHON_SITELIBDIR}/qiskit/_accelerate${PYTHON_EXT_SUFFIX}.so \
		${PYTHON_SITELIBDIR}/qiskit/_qasm2%%PYTHON_EXT_SUFFIX%%.so

post-patch: # project was renamed, see https://github.com/Qiskit/rustworkx/issues/656
	@${FIND} ${WRKSRC} -name "*.py" | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|retworkx|rustworkx|'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/qiskit/_accelerate.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
