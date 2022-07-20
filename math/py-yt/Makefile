PORTNAME=	yt
DISTVERSION=	4.0.4
CATEGORIES=	math astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analysis and visualization toolkit for volumetric data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BROKEN_i386=	call to 'countOnes' is ambiguous, see https://github.com/yt-project/yt/issues/3477

# dependencies are in setup.cfg
BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	\
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cmyt>=0.2.2:math/py-cmyt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=1.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=8.4:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.2:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=0.4.0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=3.4.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unyt>=2.8.0:math/py-unyt@${PY_FLAVOR}

USES=		dos2unix localbase python:3.7+
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
