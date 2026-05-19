PORTNAME=	ignition-math
DISTVERSIONPREFIX=	gz-math9_
DISTVERSION=	9.0.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General purpose math library for robot applications
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ignition-cmake>=5:devel/ignition-cmake
LIB_DEPENDS=	libgz-utils.so:devel/ignition-utils

USES=		compiler:c++17-lang cmake eigen:3
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	SKIP_PYBIND11 SKIP_SWIG
CMAKE_OFF=	BUILD_TESTING

GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-math

PLIST_SUB+=	MATH_IGN_VER=math${DISTVERSION:R:R}

do-test: # one test is known to fail: https://bitbucket.org/ignitionrobotics/ign-math/issues/98
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
