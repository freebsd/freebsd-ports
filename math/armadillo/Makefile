PORTNAME=	armadillo
PORTVERSION=	14.6.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/arma

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ linear algebra library
WWW=		https://arma.sourceforge.net/ \
		https://gitlab.com/conradsnicta/armadillo-code

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libsuperlu.so:math/superlu

USES=		blaslapack:openblas cmake:testing compiler:c++11-lang pathfix pkgconfig tar:xz

CMAKE_OFF=	ALLOW_BLAS_LAPACK_MACOS \
		ALLOW_FLEXIBLAS_LINUX \
		ALLOW_OPENBLAS_MACOS \
		BUILD_SMOKE_TEST \
		HEADER_ONLY
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	BUILD_SMOKE_TEST
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	OPENBLAS_LAPACK
OPENBLAS_LAPACK_DESC=	Use LAPACK function from OpenBLAS

OPENBLAS_LAPACK_CMAKE_BOOL=	OPENBLAS_PROVIDES_LAPACK
OPENBLAS_LAPACK_LIB_DEPENDS_OFF=liblapack.so:math/lapack

.include <bsd.port.mk>
