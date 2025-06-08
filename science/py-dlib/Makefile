PORTNAME=	dlib
DISTVERSION=	20.0.0
PORTREVISION=	1
CATEGORIES=	science devel math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Machine learning framework written in C++ (python bindings)
WWW=		http://dlib.net

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/dlib/LICENSE.txt

LIB_DEPENDS=		${PY_BOOST} \
			libpng.so:graphics/png \
			libgif.so:graphics/giflib

USES=			cmake:indirect compiler:c++11-lang jpeg pkgconfig python \
			shebangfix sqlite xorg
USE_PYTHON=		autoplist distutils
USE_XORG=		ice sm x11 xext
SHEBANG_FILES=		python_examples/*.py

OPTIONS_DEFINE=		BLASLAPACK

BLASLAPACK_DESC=	Use OpenBLAS for matrix operations

BLASLAPACK_USES=	blaslapack:openblas
BLASLAPACK_VARS_OFF=	blaslapackargs="--no DLIB_USE_BLAS --no DLIB_USE_LAPACK"

PYDISTUTILS_BUILDARGS=	--set BOOST_PYTHON_SUFFIX:STRING=${PYTHON_SUFFIX} ${BLASLAPACKARGS}

post-extract:
	${FIND} ${WRKSRC}/dlib/external -d 1 -not -name pybind11 -exec rm -rf {} +

# due to a build system bug the code gets recompiled twice during "build" and "stage"
do-build:
	@${DO_NADA}

.include <bsd.port.mk>
