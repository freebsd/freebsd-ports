PORTNAME=	armadillo
PORTVERSION=	10.8.2
CATEGORIES=	math
MASTER_SITES=	SF/arma

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ linear algebra library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libarpack.so:math/arpack-ng \
		liblapack.so:math/lapack \
		libhdf5.so:science/hdf5 \
		libsuperlu.so:math/superlu \
		libsz.so:science/szip

USES=		blaslapack:openblas cmake compiler:c++11-lang pkgconfig tar:xz

USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DPKG_CONFIG_DIR=${LOCALBASE}/libdata/pkgconfig/

.include <bsd.port.mk>
