# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	yt
DISTVERSION=	3.5.0
PORTREVISION=	5
CATEGORIES=	math astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analysis and visualization toolkit for volumetric data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libomp.so:devel/openmp
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>=1.0:math/py-sympy@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython5>=1.0:devel/ipython5@${PY_FLAVOR}

USES=		dos2unix localbase python
USE_PYTHON=	distutils cython autoplist concurrent

OPTIONS_DEFINE=	EMBREE
#OPTIONS_DEFAULT=	EMBREE
EMBREE_DESC=	Embree ray-tracing engine support

EMBREE_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyembree>0:graphics/py-pyembree@${PY_FLAVOR}
EMBREE_LIB_DEPENDS=	libembree.so:graphics/embree
EMBREE_RUN_DEPENDS=	${EMBREE_BUILD_DEPENDS}

post-patch-EMBREE-on:
	@${REINPLACE_CMD} -e "s|check_for_pyembree() is not None|True|" \
		${WRKSRC}/setup.py

post-patch-EMBREE-off:
	@${REINPLACE_CMD} -e "s|check_for_pyembree() is not None|False|" \
		${WRKSRC}/setup.py

post-patch:
	@${REINPLACE_CMD} -e "s|check_for_openmp() is True|True|" \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|\['-fopenmp', filename\]|['-I${LOCALBASE}/include', '-L${LOCALBASE}/lib', '-lm', '-fopenmp', filename]|" \
		${WRKSRC}/setupext.py

post-install:
	@${STRIP_CMD} $$(${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so")

.include <bsd.port.mk>
