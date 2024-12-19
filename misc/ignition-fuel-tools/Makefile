PORTNAME=	ignition-fuel-tools
DISTVERSION=	1.2.0
PORTREVISION=	9
CATEGORIES=	misc
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classes and tools for interacting with Ignition Fuel
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ignition-cmake==2:devel/ignition-cmake
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libignition-common3.so:devel/ignition-common \
		libjsoncpp.so:devel/jsoncpp \
		libuuid.so:misc/libuuid \
		libyaml.so:textproc/libyaml \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++17-lang pkgconfig
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-fuel-tools
BB_COMMIT=	0ffbf3a2c836

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

PLIST_SUB+=	FUEL_TOOLS_IGN_VER=fuel_tools${DISTVERSION:R:R}

TESTING_UNSAFE=	4 tests are known to fail: https://bitbucket.org/ignitionrobotics/ign-fuel-tools/issues/48/4-unit-tests-fail-unit_fuelclient_test

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
