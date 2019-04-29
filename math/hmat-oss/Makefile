# $FreeBSD$

PORTNAME=	hmat-oss
DISTVERSION=	1.5.0-340
DISTVERSIONSUFFIX=	-g700d1fa
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hierarchical matrix C/C++ library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libcblas.so:math/cblas \
		libomp.so:devel/openmp \
		libopenblas.so:math/openblas

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	jeromerobert
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DLAPACK_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DCBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libcblas.so

.include <bsd.port.mk>
