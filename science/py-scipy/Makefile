PORTNAME=	scipy
DISTVERSION=	1.17.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	science python
MASTER_SITES=	https://docs.scipy.org/doc/${PORTNAME}-1.17.0/:doc \
		PYPI:source \
		SF:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		scipy-html-1.17.0.zip:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Scientific tools for Python
WWW=		https://www.scipy.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>=0.15.0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.13.2:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pythran>=0.14.0:devel/py-pythran@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy1>=1.26.4:math/py-numpy1@${PY_FLAVOR} \
		boost-libs>=1.89.0:devel/boost-libs
LIB_DEPENDS=	libqhull_r.so:math/qhull
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy1>=1.26.4:math/py-numpy1@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asv>0:benchmarks/py-asv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gmpy2>0:math/py-gmpy2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}threadpoolctl>0:devel/py-threadpoolctl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-umfpack>0:math/py-scikit-umfpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pooch>0:devel/py-pooch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=6.30:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}array-api-strict>=2.3.1:devel/py-array-api-strict@${PY_FLAVOR}

USES=		compiler:c++17-lang cpe fortran pkgconfig python:3.11+ shebangfix
USE_PYTHON=	autoplist concurrent cython pep517 pytest

PEP517_BUILD_CONFIG_SETTING=	-Csetup-args=-Duse-system-libraries=all -Cbuild-dir=_build

TEST_WRKSRC=	${WRKDIR}
TEST_ARGS=	--pyargs scipy
PYTEST_BROKEN_TESTS=	test_threading

BINARY_ALIAS=	cython=cython-${PYTHON_VER} \
		pybind11-config=pybind11-config-${PYTHON_VER} \
		pythran=pythran-${PYTHON_VER}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	BLASLIB
OPTIONS_SINGLE_BLASLIB=	BLIS FLEXIBLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS
BLIS_DESC=	BLIS BLAS-like implementation
FLEXIBLAS_DESC=	FlexiBLAS BLAS implementation

BLIS_USES=	blaslapack:blis
BLIS_VARS=	PEP517_BUILD_CONFIG_SETTING+="-Csetup-args=-Dblas=blis -Csetup-args=-Dlapack=flame"
BLIS_BROKEN=	math/libflame does not provide a pkg-config file
FLEXIBLAS_USES=	blaslapack:flexiblas
FLEXIBLAS_VARS=	PEP517_BUILD_CONFIG_SETTING+="-Csetup-args=-Dblas=flexiblas -Csetup-args=-Dlapack=flexiblas"
NETLIB_USES=	blaslapack:netlib
NETLIB_VARS=	PEP517_BUILD_CONFIG_SETTING+="-Csetup-args=-Dblas=blas -Csetup-args=-Dlapack=lapack"
OPENBLAS_USES=	blaslapack:openblas
OPENBLAS_VARS=	PEP517_BUILD_CONFIG_SETTING+="-Csetup-args=-Dblas=openblas -Csetup-args=-Dlapack=openblas"

post-patch:
	@${REINPLACE_CMD} -e 's|pythran>=0.14.0,<0.19.0|pythran>=0.14.0|' \
		-e 's|Cython>=3.0.8,<3.3.0|Cython>=3.0.8|' \
		-e 's|numpy>=2.0.0|numpy>=1.26.4|g' \
		${WRKSRC}/pyproject.toml
	@${REINPLACE_CMD} -e "s|'boost', version : '1.89.0'|'boost'|g" \
		${WRKSRC}/meson.build

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${UNZIP_NATIVE_CMD} -d ${STAGEDIR}${DOCSDIR} ${DISTDIR}/scipy-html-1.17.0.zip
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

.include <bsd.port.mk>
