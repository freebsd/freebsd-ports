# $FreeBSD$

PORTNAME=	armadillo
PORTVERSION=	7.500.2
PORTREVISION=	1
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

USES=		blaslapack cmake compiler:c++11-lang tar:xz
USE_LDCONFIG=	yes

BROKEN_powerpc64=	Does not build

.include <bsd.port.mk>
