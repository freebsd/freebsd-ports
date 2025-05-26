PORTNAME=	primesieve
DISTVERSIONPREFIX=	v
DISTVERSION=	12.9
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast prime number generator
WWW=		https://github.com/kimwalisch/primesieve

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kimwalisch

CMAKE_OFF=	BUILD_STATIC_LIBS
CMAKE_TESTING_ON=	BUILD_TESTS

# tests as of 12.9: 100% tests passed, 0 tests failed out of 34

.include <bsd.port.mk>
