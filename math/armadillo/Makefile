PORTNAME=	armadillo
DISTVERSION=	11.2.3
CATEGORIES=	math
MASTER_SITES=	SF/arma

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	C++ linear algebra library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libboost_date_time.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		liblapack.so:math/lapack \
		libsuperlu.so:math/superlu \
		libsz.so:science/libaec

USES=		blaslapack:openblas cmake:testing compiler:c++11-lang pkgconfig tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DPKG_CONFIG_DIR=${LOCALBASE}/libdata/pkgconfig/
CMAKE_OFF=	BUILD_SMOKE_TEST
CMAKE_TESTING_ON=	BUILD_SMOKE_TEST

.include <bsd.port.mk>
