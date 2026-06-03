PORTNAME=	numpy
DISTVERSION=	1.26.4
PORTREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	PYPI \
		https://numpy.org/doc/${DISTVERSION:R}/:doc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-html.zip:doc
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION:R}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fundamental package for array computing in Python
WWW=		https://www.numpy.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>=0.15.0:devel/meson-python@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=6.24.1:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.2.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		compiler:c11 cpe fortran pkgconfig python shebangfix
USE_PYTHON=	autoplist concurrent cython pep517 pytest

PEP517_BUILD_CONFIG_SETTING=	-Csetup-args=-Dallow-noblas=false

WITHOUT_FBSD10_FIX=	yes
SHEBANG_GLOB=	*.py
PORTDOCS=	*

CONFLICTS_INSTALL=	py*-numpy

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

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31200
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|meson-python>=0.15.0,<0.16.0|meson-python>=0.15.0|' \
		-e 's|Cython>=0.29.34,<3.1|Cython>=0.29.34|' \
		${WRKSRC}/pyproject.toml

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${UNZIP_NATIVE_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/numpy-html.zip -d ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

.include <bsd.port.post.mk>
