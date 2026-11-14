PORTNAME=	python-calamine
DISTVERSION=	0.9.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Rust library for reading Excel and ODF files
WWW=		https://github.com/dimastbk/python-calamine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1:devel/py-maturin@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>0:textproc/py-xlrd@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		--deselect tests/test_pandas.py::test_xlsb_pyxlsb_pandas # needs pyxlsb

# tests as of 0.9.1: 54 passed, 1 deselected, 1 xfailed in 2.28s

.include <bsd.port.mk>
