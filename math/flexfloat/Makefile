# $FreeBSD$

PORTNAME=	flexfloat
DISTVERSION=	g20190814
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for the emulation of reduced-precision floating point types

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	oprecomp
GH_TAGNAME=	6db869087a12d763a94d53e9b0a9d52def270865
USE_LDCONFIG=	yes
USE_GCC=	any # clang doesn't support __float128

CMAKE_OFF=	BUILD_TESTS BUILD_EXAMPLES

PLIST_FILES=	include/flexfloat/flexfloat.h \
		include/flexfloat/flexfloat.hpp \
		include/flexfloat/flexfloat_config.h \
		lib/libflexfloat.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/flexfloat
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${WRKSRC}/include/*.hpp ${STAGEDIR}${PREFIX}/include/flexfloat
	${INSTALL_LIB} ${BUILD_WRKSRC}/libflexfloat.so ${STAGEDIR}${PREFIX}/lib

do-test: # one test, value_representation_half, fails: https://github.com/oprecomp/flexfloat/issues/9
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
