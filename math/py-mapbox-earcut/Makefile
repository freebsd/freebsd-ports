PORTNAME=	mapbox-earcut
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
CATEGORIES=	math
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bindings for Pango for use with Manim
WWW=		https://manimpango.manim.community/en/latest/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	skogler
GH_PROJECT=	mapbox_earcut_python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/mapbox_earcut${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
