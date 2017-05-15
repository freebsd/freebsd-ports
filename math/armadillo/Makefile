# $FreeBSD$

PORTNAME=	armadillo
PORTVERSION=	7.900.1
CATEGORIES=	math
MASTER_SITES=	SF/arma

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C++ linear algebra library

LICENSE=	MPL

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libopenblasp.so:math/openblas \
		libarpack.so:math/arpack \
		libhdf5.so:science/hdf5 \
		libsuperlu.so:math/superlu

USES=		blaslapack cmake compiler:c++11-lang pkgconfig tar:xz
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DPKG_CONFIG_DIR=${LOCALBASE}/libdata/pkgconfig/

BROKEN_powerpc64=	Does not build

.include <bsd.port.mk>
