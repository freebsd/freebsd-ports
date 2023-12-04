PORTNAME=	libsockpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	net devel

MAINTAINER=	peter@flytrace.com
COMMENT=	Simple, modern, C++ socket library
WWW=		https://github.com/fpagliughi/sockpp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fpagliughi
GH_PROJECT=	sockpp

OPTIONS_DEFINE=		TEST

TEST_DESC=	Build unit tests (requires Catch2)

TEST_BUILD_DEPENDS=	catch2>0:devel/catch2
TEST_CMAKE_BOOL=	SOCKPP_BUILD_TESTS

CMAKE_ARGS=	-DSOCKPP_BUILD_STATIC=FALSE -DSOCKPP_BUILD_DOCUMENTATION=FALSE

post-patch:
	${REINPLACE_CMD} -e 's|#include "catch2/catch.hpp"|#include "catch2/catch_all.hpp"|' \
		${WRKSRC}/tests/unit/*.cpp

.include <bsd.port.mk>
