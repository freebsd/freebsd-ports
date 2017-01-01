# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	yt
PORTVERSION=	3.3.3
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
		libomp.so:devel/openmp

USES=		dos2unix localbase python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e "s|\['-fopenmp', filename\]|['-I${LOCALBASE}/include', '-L${LOCALBASE}/lib', '-lm', '-fopenmp', filename]|" \
		${WRKSRC}/setupext.py

post-install:
	# workaround for the bug https://bitbucket.org/yt_analysis/yt/issues/1296
	@${ECHO} "${PYTHON_SITELIBDIR}/yt/__hg_version__.py" >> ${_PYTHONPKGLIST}
	@${ECHO} "${PYTHON_SITELIBDIR}/yt/__hg_version__.pyc" >> ${_PYTHONPKGLIST}
	@${ECHO} "${PYTHON_SITELIBDIR}/yt/__hg_version__.pyo" >> ${_PYTHONPKGLIST}

.include <bsd.port.mk>
