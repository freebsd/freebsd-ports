PORTNAME=	blake3
DISTVERSION=	1.0.9
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for the BLAKE3 cryptographic hash function
WWW=		https://github.com/oconnor663/blake3-py

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}maturin>0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

CARGO_CRATES=	arrayref-0.3.9 \
		arrayvec-0.7.7 \
		blake3-1.8.5 \
		cc-1.2.65 \
		cfg-if-1.0.4 \
		constant_time_eq-0.4.2 \
		cpufeatures-0.3.0 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		either-1.16.0 \
		find-msvc-tools-0.1.9 \
		heck-0.5.0 \
		hex-0.4.3 \
		libc-0.2.186 \
		memmap2-0.9.11 \
		once_cell-1.21.4 \
		portable-atomic-1.13.1 \
		proc-macro2-1.0.106 \
		pyo3-0.29.0 \
		pyo3-build-config-0.29.0 \
		pyo3-ffi-0.29.0 \
		pyo3-macros-0.29.0 \
		pyo3-macros-backend-0.29.0 \
		quote-1.0.46 \
		rayon-1.12.0 \
		rayon-core-1.13.0 \
		shlex-2.0.1 \
		syn-2.0.118 \
		target-lexicon-0.13.5 \
		unicode-ident-1.0.24

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	test_blake3.py

# tests as of 1.0.8:
# Results (1.40s):
#         81 passed
#          1 warning

.include <bsd.port.mk>
