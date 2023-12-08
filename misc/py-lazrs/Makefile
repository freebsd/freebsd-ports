PORTNAME=	lazrs
DISTVERSION=	0.5.3
PORTREVISION=	2
CATEGORIES=	misc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for laz-rs
WWW=		https://github.com/pola-rs/polars

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	laz-rs
GH_PROJECT=	laz-rs-python

CARGO_CRATES=	autocfg-1.1.0 \
		bitflags-1.3.2 \
		byteorder-1.5.0 \
		cfg-if-1.0.0 \
		crossbeam-deque-0.8.3 \
		crossbeam-epoch-0.9.15 \
		crossbeam-utils-0.8.16 \
		either-1.9.0 \
		heck-0.4.1 \
		indoc-2.0.4 \
		laz-0.8.3 \
		libc-0.2.149 \
		lock_api-0.4.11 \
		memoffset-0.9.0 \
		num-traits-0.2.17 \
		once_cell-1.18.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		proc-macro2-1.0.69 \
		pyo3-0.20.0 \
		pyo3-build-config-0.20.0 \
		pyo3-ffi-0.20.0 \
		pyo3-macros-0.20.0 \
		pyo3-macros-backend-0.20.0 \
		quote-1.0.33 \
		rayon-1.8.0 \
		rayon-core-1.12.0 \
		redox_syscall-0.4.1 \
		scopeguard-1.2.0 \
		smallvec-1.11.1 \
		syn-2.0.38 \
		target-lexicon-0.12.12 \
		unicode-ident-1.0.12 \
		unindent-0.2.3 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lazrs/lazrs${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
