PORTNAME=	flexfloat
DISTVERSION=	g20220606
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for the emulation of reduced-precision floating point types

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	unknown type name '__float128'; did you mean '_Float128'?
BROKEN_armv7=	unknown type name '__float128'; did you mean '_Float128'?

USES=		cmake compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	oprecomp
GH_TAGNAME=	ac67200de13ed9584500832a2d38a29c79331c1c

CFLAGS_powerpc64le=	-mfloat128
CFLAGS_powerpc64=	-mfloat128 -mvsx
CFLAGS_powerpc=	-mfloat128 -mvsx
CMAKE_OFF=	BUILD_TESTS BUILD_EXAMPLES

PLIST_FILES=	include/flexfloat/flexfloat.h \
		include/flexfloat/flexfloat.hpp \
		include/flexfloat/flexfloat_config.h \
		lib/libflexfloat.so

do-install: # https://github.com/oprecomp/flexfloat/issues/15
	${MKDIR} ${STAGEDIR}${PREFIX}/include/flexfloat
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${WRKSRC}/include/*.hpp ${STAGEDIR}${PREFIX}/include/flexfloat
	${INSTALL_LIB} ${BUILD_WRKSRC}/libflexfloat.so ${STAGEDIR}${PREFIX}/lib

do-test: # one test, value_representation_half, fails: https://github.com/oprecomp/flexfloat/issues/9
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
