# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	yt
PORTVERSION=	3.3.5
PORTREVISION=	1
CATEGORIES=	math astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Analysis and visualization toolkit for volumetric data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	cython:lang/cython \
		${PYNUMPY}
RUN_DEPENDS=	isympy:math/py-sympy \
		${PYNUMPY}  \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython
LIB_DEPENDS=	libembree.so:graphics/embree \
		libomp.so.0:devel/openmp

USES=		dos2unix localbase python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e "s|\['-fopenmp', filename\]|['-I${LOCALBASE}/include', '-L${LOCALBASE}/lib', '-lm', '-fopenmp', filename]|" \
		${WRKSRC}/setupext.py

.include <bsd.port.mk>
