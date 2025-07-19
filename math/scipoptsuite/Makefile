PORTNAME=	scipoptsuite
DISTVERSION=	9.2.3
CATEGORIES=	math
MASTER_SITES=	https://scipopt.org/download/release/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SCIP Optimization Suite
WWW=		https://scipopt.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/variant.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libgsl.so:math/gsl \
		libipopt.so:math/ipopt \
		libmpfr.so:math/mpfr \
		libtbb.so:devel/onetbb

USES=		bison cmake compiler:c++14-lang mpi:openmpi pkgconfig readline tar:tgz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
