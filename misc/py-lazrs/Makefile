PORTNAME=	lazrs
DISTVERSION=	0.8.1
PORTREVISION=	1
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

CARGO_CRATES=	autocfg-1.5.0 \
		byteorder-1.5.0 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		either-1.15.0 \
		heck-0.5.0 \
		indoc-2.0.7 \
		laz-0.11.1 \
		libc-0.2.185 \
		memoffset-0.9.1 \
		num-traits-0.2.19 \
		once_cell-1.21.4 \
		portable-atomic-1.13.1 \
		proc-macro2-1.0.106 \
		pyo3-0.27.2 \
		pyo3-build-config-0.27.2 \
		pyo3-ffi-0.27.2 \
		pyo3-macros-0.27.2 \
		pyo3-macros-backend-0.27.2 \
		quote-1.0.45 \
		rayon-1.12.0 \
		rayon-core-1.13.0 \
		rustversion-1.0.22 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		unicode-ident-1.0.24 \
		unindent-0.2.4

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

.include <bsd.port.mk>
