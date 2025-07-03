PORTNAME=	lazrs
DISTVERSION=	0.6.2
PORTREVISION=	5
CATEGORIES=	misc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for laz-rs (Laszip compression, LAS format)
WWW=		https://github.com/laz-rs/laz-rs-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	laz-rs
GH_PROJECT=	laz-rs-python

CARGO_CRATES=	autocfg-1.4.0 \
		byteorder-1.5.0 \
		cfg-if-1.0.0 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		either-1.13.0 \
		heck-0.5.0 \
		indoc-2.0.5 \
		laz-0.9.2 \
		libc-0.2.168 \
		memoffset-0.9.1 \
		num-traits-0.2.19 \
		once_cell-1.20.2 \
		portable-atomic-1.10.0 \
		proc-macro2-1.0.92 \
		pyo3-0.22.6 \
		pyo3-build-config-0.22.6 \
		pyo3-ffi-0.22.6 \
		pyo3-macros-0.22.6 \
		pyo3-macros-backend-0.22.6 \
		quote-1.0.37 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		syn-2.0.90 \
		target-lexicon-0.12.16 \
		unicode-ident-1.0.14 \
		unindent-0.2.3

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

.include <bsd.port.mk>
