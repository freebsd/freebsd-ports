# $FreeBSD$

PORTNAME=	hmat-oss
DISTVERSION=	1.5.0-348
DISTVERSIONSUFFIX=	-g76beaf3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hierarchical matrix C/C++ library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libcblas.so:math/cblas \
		libomp.so:devel/openmp \
		libopenblas.so:math/openblas

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	jeromerobert
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DLAPACK_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DCBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libcblas.so

post-configure: # fix the error in math/openturns: /usr/local/lib/libhmat-oss.so.1: undefined reference to `openblas_set_num_threads(int)'
	@${REINPLACE_CMD} "s|#define OPENBLAS_DISABLE_THREADS|\/\/&|" ${BUILD_WRKSRC}/config.h # OPENBLAS_DISABLE_THREADS enables openblas_set_num_threads(int) here

.include <bsd.port.mk>
