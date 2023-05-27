PORTNAME=	vxl
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.2
PORTREVISION=	1
CATEGORIES=	misc science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ libraries for computer vision and image understanding
WWW=		https://vxl.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/core/vxl_copyright.h

LIB_DEPENDS=	libgeotiff.so:graphics/libgeotiff \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang jpeg
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CONFLICTS_BUILD=	openjpeg15

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

CONFLICTS_BUILD=	dcmtk # because it is bundled

do-test: # 1 test fails, see https://github.com/vxl/vxl/issues/920
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
PLIST_SUB+=	X86=""
CMAKE_ON+=	VIL_CONFIG_ENABLE_SSE2_ROUNDING # the automatic SSE2 test fails on i386: Performing Try-Run Test VXL_HAS_SSE2_HARDWARE_SUPPORT - Test Compilation Failed
.elif ${ARCH} == "i386"
CFLAGS+=	-msse2 # sse2 is not enabled on i386 by default as it is enabled on amd64, see https://github.com/vxl/vxl/issues/795
CXXFLAGS+=	-msse2
PLIST_SUB+=	X86=""
CMAKE_ON+=	VIL_CONFIG_ENABLE_SSE2_ROUNDING # the automatic SSE2 test fails on i386: Performing Try-Run Test VXL_HAS_SSE2_HARDWARE_SUPPORT - Test Compilation Failed
.else
PLIST_SUB+=	X86="@comment "
CMAKE_OFF+=	VIL_CONFIG_ENABLE_SSE2_ROUNDING
.endif

.include <bsd.port.post.mk>
