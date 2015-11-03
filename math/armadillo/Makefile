# $FreeBSD$

PORTNAME=	armadillo
PORTVERSION=	6.200.2
CATEGORIES=	math
MASTER_SITES=	SF/arma

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C++ linear algebra library

LICENSE=	MPL

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		libarpack.so:${PORTSDIR}/math/arpack \
		libhdf5.so:${PORTSDIR}/science/hdf5 \
		libsuperlu.so:${PORTSDIR}/math/superlu

USES=		cmake blaslapack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
