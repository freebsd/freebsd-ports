# $FreeBSD$

PORTNAME=	armadillo
PORTVERSION=	4.300.8
CATEGORIES=	math
MASTER_SITES=	SF/arma/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ linear algebra library

LICENSE=	MPL

LIB_DEPENDS=	liblapack.so:${PORTSDIR}/math/lapack	\
		libboost_date_time.so:${PORTSDIR}/devel/boost-libs

USES=		cmake
USE_LDCONFIG=	yes

.include <bsd.port.mk>
