PORTNAME=	vedo
DISTVERSION=	2024.5.3
PORTREVISION=	1
CATEGORIES=	science graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for scientific analysis and visualization of 3D objects
WWW=		https://vedo.embl.es/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		vtk${VTK_VER:R}>0:math/vtk${VTK_VER:R} \
		bash:shells/bash

USES=		python shebangfix
USE_PYTHON=	pep517 concurrent autoplist

SHEBANG_GLOB=	*.sh

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

do-test: # run some examples as tests
.for example in advanced/interpolate_scalar3.py advanced/spline_draw1.py advanced/warp6.py simulations/optics_main3.py
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${WRKSRC}/examples/${example}
.endfor

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
