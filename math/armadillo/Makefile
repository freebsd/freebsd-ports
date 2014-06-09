# $FreeBSD$

PORTNAME=	armadillo
PORTVERSION=	3.800.1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/arma/

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	C++ linear algebra library

LICENSE=	MPL

LIB_DEPENDS=	liblapack.so:${PORTSDIR}/math/lapack	\
		libboost_date_time.so:${PORTSDIR}/devel/boost-libs

USES=		cmake
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
