PORTNAME=	usd
DISTVERSIONPREFIX=	v
DISTVERSION=	21.11
PORTREVISION=	12
CATEGORIES=	misc

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	4942189cf7b1a45b23d62f4ae92a940721ec4009.patch:-p1 \
		445e3f8a473db9b1e0d1301e6ce4bf74c270f376.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Scene Description is a scene description management system
WWW=		http://www.openusd.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc powerpc64le # CMakeLists.txt fails for non-64-bit architectures: Compiler does not support 64-bit builds; also: pxr/base/arch/defines.h:69:2: error: "Unsupported architecture.  x86_64 or ARM64 required."

LIB_DEPENDS=	libtbb.so:devel/tbb

USES=		cmake python:test

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	${PORTNAME:tu}

CMAKE_OFF=	PXR_BUILD_TESTS PXR_BUILD_EXAMPLES PXR_BUILD_TUTORIALS PXR_ENABLE_PYTHON_SUPPORT

OPTIONS_DEFINE=		IMAGING TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes

IMAGING_DESC=		Build imaging components
IMAGING_CMAKE_BOOL=	PXR_BUILD_IMAGING
IMAGING_CMAKE_ON=	-DPTEX_INCLUDE_DIR=${LOCALBASE}/include
IMAGING_BROKEN=		see https://github.com/PixarAnimationStudios/USD/issues/1706

TOOLS_DESC=		Build commandline tools
TOOLS_CMAKE_BOOL=	PXR_BUILD_USD_TOOLS
TOOLS_LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

do-test: # tests are expected to be installed, see https://github.com/PixarAnimationStudios/USD/issues/1707
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DPXR_BUILD_TESTS=ON -DPYTHON_EXECUTABLE=${PYTHON_CMD} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} install && \
		ctest -C ${CMAKE_BUILD_TYPE} ${WRKSRC}

.include <bsd.port.mk>
