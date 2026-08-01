PORTNAME=	python-geohash
DISTVERSION=	0.9.2
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_geohash-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, accurate python geohashing library
WWW=		https://github.com/hkwi/python-geohash

LICENSE=	APACHE20 MIT BSD3CLAUSE
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>=1.8:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist distutils

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

PLIST_FILES=	${PYTHON_SITELIBDIR}/_geohash.abi3.so

CARGO_CRATES=	heck-0.5.0 \
		libc-0.2.186 \
		once_cell-1.21.4 \
		portable-atomic-1.13.1 \
		proc-macro2-1.0.106 \
		pyo3-0.28.3 \
		pyo3-build-config-0.28.3 \
		pyo3-ffi-0.28.3 \
		pyo3-macros-0.28.3 \
		pyo3-macros-backend-0.28.3 \
		quote-1.0.45 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		unicode-ident-1.0.24

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/_geohash*.so

.include <bsd.port.mk>
