PORTNAME=	scikit-umfpack
DISTVERSION=	0.4.2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to UMFPACK sparse direct solver
WWW=		https://scikit-umfpack.github.io/scikit-umfpack/ \
		https://github.com/scikit-umfpack/scikit-umfpack

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		swig:devel/swig
LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libcblas.so:math/cblas \
		libopenblas.so:math/openblas \
		libumfpack.so:math/suitesparse-umfpack
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		fortran localbase:ldflags python
USE_PYTHON=	pep517 cython3 autoplist pytest
PEP517_BUILD_CONFIG_SETTING=	"-Cbuild-dir=_build"

CFLAGS+=	-I/usr/local/include/suitesparse
CXXFLAGS+=	-I/usr/local/include/suitesparse

post-patch:
	${REINPLACE_CMD} \
		-e "s|swig_inc_args = \[\]|swig_inc_args = [\'-I${LOCALBASE}/include/suitesparse\']|" \
		${WRKSRC}/scikits/umfpack/meson.build

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/scikits/umfpack/__umfpack${PYTHON_SOABI}.so

pre-test:
	${CP} -a ${WRKSRC}/_build/ ${WRKSRC}

.include <bsd.port.mk>
