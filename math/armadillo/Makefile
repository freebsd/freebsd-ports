# $FreeBSD$

PORTNAME=	armadillo
PORTVERSION=	3.800.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/arma/

MAINTAINER=	giffunip@tutopia.com
COMMENT=	C++ linear algebra library

LICENSE=	MPL

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack	\
		boost_date_time:${PORTSDIR}/devel/boost-libs

USES=		cmake
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
