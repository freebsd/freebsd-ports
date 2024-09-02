PORTNAME=	contourpy
PORTVERSION=	1.3.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python library for calculating contours of 2D quadrilateral grids
WWW=		https://github.com/contourpy/contourpy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pybind11:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meson-python>=0:devel/meson-python@${PY_FLAVOR} \
		meson:devel/meson
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}

USES=		localbase pkgconfig python
USE_PYTHON=	autoplist concurrent pep517 pytest

BINARY_ALIAS=	pybind11-config=pybind11-config-${PYTHON_VER}

.include <bsd.port.mk>
