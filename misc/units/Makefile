PORTNAME=	units
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1-24
DISTVERSIONSUFFIX=	-g0e7f8ea
CATEGORIES=	misc
PKGNAMESUFFIX=	-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for working with units of measurement
WWW=		https://units.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL

CMAKE_ON=	UNITS_BUILD_OBJECT_LIBRARY \
		UNITS_BUILD_SHARED_LIBRARY
CMAKE_OFF=	UNITS_ENABLE_TESTS
CMAKE_TESTING_ON=	UNITS_ENABLE_TESTS # tests expect the googletest source tree, see https://github.com/LLNL/units/issues/340

.include <bsd.port.mk>
