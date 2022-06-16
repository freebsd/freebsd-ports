PORTNAME=	armadillo
PORTVERSION=	11.2.0
PORTREVISION=	1
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

USES=		blaslapack:openblas cmake compiler:c++11-lang pkgconfig tar:xz

USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DPKG_CONFIG_DIR=${LOCALBASE}/libdata/pkgconfig/

.include <bsd.port.mk>
