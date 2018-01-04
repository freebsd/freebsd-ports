# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	yt
PORTVERSION=	3.4.0
CATEGORIES=	math astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Analysis and visualization toolkit for volumetric data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyembree>0:graphics/py-pyembree@${FLAVOR}
RUN_DEPENDS=	isympy:math/py-sympy@${FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyembree>0:graphics/py-pyembree@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.3:math/py-matplotlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=1.0:devel/ipython@${FLAVOR}
LIB_DEPENDS=	libembree.so:graphics/embree \
		libomp.so:devel/openmp

USES=		dos2unix localbase python:2.7
USE_PYTHON=	autoplist distutils cython

post-patch:
	@${REINPLACE_CMD} -e "s|check_for_pyembree() is not None|True|; s|check_for_openmp() is True|True|" \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|\['-fopenmp', filename\]|['-I${LOCALBASE}/include', '-L${LOCALBASE}/lib', '-lm', '-fopenmp', filename]|" \
		${WRKSRC}/setupext.py

post-install:
	@${STRIP_CMD} $$(${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so")

.include <bsd.port.mk>
