PORTNAME=	usd
DISTVERSIONPREFIX=	v
DISTVERSION=	25.11
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Scene Description is a scene description management system
WWW=		http://www.openusd.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	CMakeLists.txt fails for non-64-bit architectures: Compiler does not support 64-bit builds; also: pxr/base/arch/defines.h:69:2: error: "Unsupported architecture.  x86_64 or ARM64 required."

LIB_DEPENDS=	libtbb.so:devel/onetbb

USES=		cmake python:test
USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenUSD
USE_LDCONFIG=	yes

CMAKE_OFF=	PXR_BUILD_EXAMPLES PXR_BUILD_TESTS PXR_BUILD_TUTORIALS \
		PXR_ENABLE_PYTHON_SUPPORT

OPTIONS_DEFINE=		IMAGING MONOLITHIC TOOLS
OPTIONS_DEFAULT=	IMAGING MONOLITHIC TOOLS
OPTIONS_SUB=		yes

IMAGING_DESC=		Build imaging components
MONOLITHIC_DESC=	Build a monolithic library (required for blender)
TOOLS_DESC=		Build commandline tools

IMAGING_LIB_DEPENDS=	libosdCPU.so:graphics/opensubdiv \
			libosdGPU.so:graphics/opensubdiv
IMAGING_USES=		gl xorg
IMAGING_USE=		GL=gl XORG=ice,sm,x11,xext
IMAGING_CMAKE_BOOL=	PXR_BUILD_IMAGING
IMAGING_CMAKE_ON=	-DPTEX_INCLUDE_DIR=${LOCALBASE}/include

MONOLITHIC_CMAKE_BOOL=	PXR_BUILD_MONOLITHIC

TOOLS_CMAKE_BOOL=	PXR_BUILD_USD_TOOLS

do-test: # tests are expected to be installed, see https://github.com/PixarAnimationStudios/USD/issues/1707
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
			-DPXR_BUILD_TESTS=ON -DPYTHON_EXECUTABLE=${PYTHON_CMD} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} install && \
		${FIND} ${BUILD_WRKSRC} -name CTestTestfile.cmake -type f -exec \
			${REINPLACE_CMD} -e 's|${PREFIX}/tests|${STAGEDIR}${PREFIX}/tests|g' {} + && \
		ctest -C ${CMAKE_BUILD_TYPE} ${WRKSRC} --output-on-failure

.include <bsd.port.mk>
