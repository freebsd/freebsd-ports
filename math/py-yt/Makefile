PORTNAME=	yt
DISTVERSION=	4.3.1
PORTREVISION=	2
CATEGORIES=	math astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analysis and visualization toolkit for volumetric data
WWW=		https://yt-project.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

# dependencies are in setup.cfg
BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ewah-bool-utils>=1.0.2:devel/py-ewah-bool-utils@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cmyt>=0.2.2:math/py-cmyt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ewah-bool-utils>=1.0.2:devel/py-ewah-bool-utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=1.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=8.4:devel/py-more-itertools@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.2:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.2:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=0.4.0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=3.4.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unyt>=2.8.0:math/py-unyt@${PY_FLAVOR}

USES=		dos2unix localbase python
USE_PYTHON=	autoplist concurrent cython3 distutils

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
