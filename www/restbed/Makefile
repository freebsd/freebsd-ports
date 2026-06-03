PORTNAME=	restbed
DISTVERSION=	5.0.0
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous RESTful functionality to C++11 applications
WWW=		https://github.com/Corvusoft/restbed

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asio>0:net/asio
RUN_DEPENDS=	asio>0:net/asio

USES=		cmake:testing compiler:c++14-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Corvusoft

CMAKE_ON=	BUILD_SHARED
CMAKE_OFF=	BUILD_TESTS
CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING=lib
CMAKE_TESTING_ON=	BUILD_TESTS

pre-test: # tests only pass when net.inet6.ip6.v6only=0, see pkg-message
	@if [ $$(sysctl -n net.inet6.ip6.v6only) == 1 ]; then \
		${ECHO} "tests only pass when net.inet6.ip6.v6only=0"; \
		return 1; \
	fi

# tests as of 5.0.0: fails to find Catch2, see https://github.com/Corvusoft/restbed/issues/556

.include <bsd.port.mk>
