PORTNAME=	numpy
DISTVERSION=	2.4.6
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI \
		https://numpy.org/doc/${DISTVERSION:R}/:doc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-html.zip:doc
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION:R}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fundamental package for array computing in Python
WWW=		https://www.numpy.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>=0.18.0,1:devel/meson-python@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=5.3.0:devel/py-hypothesis@${PY_FLAVOR}

USES=		compiler:c++17-lang cpe fortran pkgconfig python:3.11+ shebangfix
USE_PYTHON=	autoplist concurrent cython pep517 pytest

PEP517_BUILD_CONFIG_SETTING=	-Csetup-args=-Dallow-noblas=false

WITHOUT_FBSD10_FIX=	yes
SHEBANG_GLOB=	*.py
BINARY_ALIAS=	cython=cython-${PYTHON_VER}
PORTDOCS=	*

CONFLICTS_INSTALL=	py*-numpy1

TEST_WRKSRC=	${WRKDIR}
TEST_ARGS=	--pyargs numpy

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		BLASLIB
OPTIONS_SINGLE_BLASLIB=	BLIS FLEXIBLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS

BLIS_DESC=		BLIS BLAS-like implementation
FLEXIBLAS_DESC=		FlexiBLAS BLAS implementation

BLIS_USES=		blaslapack:blis
BLIS_VARS=		PEP517_BUILD_CONFIG_SETTING+="-Csetup-args=-Dblas=blis -Csetup-args=-Dlapack=flame"
BLIS_BROKEN=		math/libflame does not provide a pkg-config file
FLEXIBLAS_USES=		blaslapack:flexiblas
FLEXIBLAS_VARS=		PEP517_BUILD_CONFIG_SETTING+="-Csetup-args=-Dblas=flexiblas -Csetup-args=-Dlapack=flexiblas"
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas
NETLIB_USES=		blaslapack:netlib
NETLIB_VARS=		PEP517_BUILD_CONFIG_SETTING+="-Csetup-args=-Dblas=blas -Csetup-args=-Dlapack=lapack"
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_VARS=		PEP517_BUILD_CONFIG_SETTING+="-Csetup-args=-Dblas=openblas -Csetup-args=-Dlapack=openblas"

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${UNZIP_NATIVE_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/numpy-html.zip -d ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

.include <bsd.port.mk>
