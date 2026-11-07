PORTNAME=	rtoml
DISTVERSION=	0.14.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	rtoml-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	TOML library for Python implemented in Rust
WWW=		https://github.com/samuelcolvin/rtoml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1<2:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python:3.10+
USE_PYTHON=	autoplist concurrent pep517

CARGO_CRATES=	equivalent-1.0.2 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		indexmap-2.14.2 \
		libc-0.2.168 \
		once_cell-1.21.3 \
		portable-atomic-1.10.0 \
		proc-macro2-1.0.92 \
		pyo3-0.29.3 \
		pyo3-build-config-0.29.3 \
		pyo3-ffi-0.29.3 \
		pyo3-macros-0.29.3 \
		pyo3-macros-backend-0.29.3 \
		quote-1.0.37 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_spanned-1.1.2 \
		syn-2.0.90 \
		target-lexicon-0.13.3 \
		toml-1.1.8+spec-1.1.0 \
		toml_datetime-1.1.2+spec-1.1.0 \
		toml_parser-1.1.5+spec-1.1.0 \
		toml_writer-1.1.3+spec-1.1.0 \
		unicode-ident-1.0.14 \
		winnow-1.0.4

BINARY_ALIAS=	python3=${PYTHON_CMD}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

.include <bsd.port.mk>
