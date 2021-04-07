PORTNAME=	restbed
DISTVERSION=	4.7
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous RESTful functionality to C++11 applications

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Corvusoft
GH_TUPLE=	Corvusoft:asio-dependency:22afb86:a/dependency/asio \
		Corvusoft:catch-dependency:d10b9bd:c/dependency/catch
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED
CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING=lib

do-test: # tests only pass when net.inet6.ip6.v6only=0, see pkg-message
	@if [ $$(sysctl -n net.inet6.ip6.v6only) == 1 ]; then \
		${ECHO} "tests only pass when net.inet6.ip6.v6only=0"; \
		return 1; \
	fi
	@${ECHO_MSG} "===>    Configuring tests in ${PKGNAME}"
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH}
	@${ECHO_MSG} "===>    Building tests in ${PKGNAME}"
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}
	@${ECHO_MSG} "===>    Running tests in ${PKGNAME}"
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
