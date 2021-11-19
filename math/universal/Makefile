PORTNAME=	universal
DISTVERSIONPREFIX=	v
DISTVERSION=	3.47
CATEGORIES=	math
PKGNAMESUFFIX=	-fp-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ template library for universal number arithmetic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang # should be compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	stillwater-sc

CMAKE_OFF=	UNIVERSAL_ENABLE_TESTS BUILD_DEMONSTRATION BUILD_PLAYGROUND BUILD_EDUCATION BUILD_APPLICATIONS

OPTIONS_DEFINE=		TOOLS
OPTIONS_SUB=		yes

TOOLS_DESC=		Build command line tools
TOOLS_CMAKE_BOOL=	BUILD_CMD_LINE_TOOLS
TOOLS_VARS_OFF=		NO_ARCH=yes # header-only library w/out executables

do-test: # tests fail to compile: https://github.com/stillwater-sc/universal/issues/263
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_OFF:C/(.*)/-D\1=ON/} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
