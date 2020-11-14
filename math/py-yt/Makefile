# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	yt
DISTVERSION=	3.6.1
CATEGORIES=	math astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analysis and visualization toolkit for volumetric data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>=1.0:math/py-sympy@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython5>=1.0:devel/ipython5@${PY_FLAVOR}

USES=		dos2unix localbase python:3.5+
USE_PYTHON=	distutils cython autoplist concurrent

post-patch:
	@${REINPLACE_CMD} -e "s|check_for_pyembree() is not None|False|" \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|check_for_openmp() is True|True|" \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|\['-fopenmp', filename\]|['-I${LOCALBASE}/include', '-L${LOCALBASE}/lib', '-lm', '-fopenmp', filename]|" \
		${WRKSRC}/setupext.py

post-install:
	@${STRIP_CMD} $$(${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so")

.include <bsd.port.mk>
