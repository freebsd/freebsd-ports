# $FreeBSD$

PORTNAME=	armadillo
PORTVERSION=	4.320.0
CATEGORIES=	math
MASTER_SITES=	SF/arma

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ linear algebra library

LICENSE=	MPL

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		liblapack.so:${PORTSDIR}/math/lapack \
		libhdf5.so:${PORTSDIR}/science/hdf5

USES=		cmake
USE_LDCONFIG=	yes

.include <bsd.port.mk>
