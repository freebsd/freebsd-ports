PORTNAME=	restbed
DISTVERSION=	4.8
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous RESTful functionality to C++11 applications

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++14-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Corvusoft
GH_TUPLE=	Corvusoft:asio-dependency:a4d820d:a/dependency/asio \
		Corvusoft:catch-dependency:d10b9bd:c/dependency/catch

CMAKE_ON=	BUILD_SHARED
CMAKE_OFF=	BUILD_TESTS
CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING=lib
CMAKE_TESTING_ON=	BUILD_TESTS

pre-test: # tests only pass when net.inet6.ip6.v6only=0, see pkg-message
	@if [ $$(sysctl -n net.inet6.ip6.v6only) == 1 ]; then \
		${ECHO} "tests only pass when net.inet6.ip6.v6only=0"; \
		return 1; \
	fi

.include <bsd.port.mk>
