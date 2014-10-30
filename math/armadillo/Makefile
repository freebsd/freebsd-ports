# $FreeBSD$

PORTNAME=	armadillo
PORTVERSION=	4.500.0
CATEGORIES=	math
MASTER_SITES=	SF/arma

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C++ linear algebra library

LICENSE=	MPL

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		liblapack.so:${PORTSDIR}/math/lapack \
		libhdf5.so:${PORTSDIR}/science/hdf5

USES=		cmake
USE_LDCONFIG=	yes

.include <bsd.port.mk>
