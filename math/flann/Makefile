# $FreeBSD$

PORTNAME=	flann
DISTVERSION=	1.8.4
DISTVERSIONSUFFIX=	-src
CATEGORIES=	math
MASTER_SITES=	http://people.cs.ubc.ca/~mariusm/uploads/FLANN/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for fast nearest neighbor searches in high dimensional spaces

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/szip

USES=		cmake:outsource zip
CMAKE_ARGS=	-DBUILD_PYTHON_BINDINGS:BOOL=OFF \
		-DBUILD_MATLAB_BINDINGS:BOOL=OFF \
		-DEXAMPLES_SUBDIR:STRING="share/examples/flann" \
		-DUSE_OPENMP:BOOL=OFF  # OpenMP search is broken in cmake: https://gitlab.kitware.com/cmake/cmake/issues/17474
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
PLIST_SUB=	SHL3=${DISTVERSION} SHL2=${DISTVERSION:R}

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

.include <bsd.port.mk>
