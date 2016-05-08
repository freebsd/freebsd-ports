# $FreeBSD$

PORTNAME=	armadillo
PORTVERSION=	6.700.6
CATEGORIES=	math
MASTER_SITES=	SF/arma

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C++ linear algebra library

LICENSE=	MPL

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libarpack.so:math/arpack \
		libhdf5.so:science/hdf5 \
		libsuperlu.so:math/superlu

USES=		cmake blaslapack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
