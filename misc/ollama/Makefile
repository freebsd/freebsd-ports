PORTNAME=	ollama
DISTVERSIONPREFIX=	v
DISTVERSION=	0.22.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Run Llama 2, Mistral, and other large language models
WWW=		https://ollama.com \
		https://github.com/ollama/ollama

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to compile: x/mlxrunner/mlx/memory.go:40:11: 1 << (4 * 10) (untyped int constant 1099511627776) overflows int

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/include/miniaudio/miniaudio.h:audio/miniaudio \
		${LOCALBASE}/include/nlohmann/json_fwd.hpp:devel/nlohmann-json \
		${LOCALBASE}/include/stb/stb_image.h:devel/stb \
		patchelf:sysutils/patchelf

USES=		cmake:indirect go:1.24+,modules localbase pkgconfig
USE_RC_SUBR=	ollama

GO_MODULE=	github.com/yurivict/${PORTNAME} # fork with FreeBSD patches
GO_TARGET=	.
GO_ENV+=	CGO_CXXFLAGS="${CXXFLAGS}"

MLX_CORE_VERSION=	0.31.1
MLX_C_VERSION=		0.6.0
JSON_VERSION=		3.11.3

PLIST_FILES=	bin/${PORTNAME} \
		bin/ollama-limit-gpu-layers

XARCH!=		uname -p

OPTIONS_GROUP=		BACKENDS
OPTIONS_GROUP_BACKENDS=	CPU VULKAN MLX
OPTIONS_DEFAULT=	CPU VULKAN MLX

CPU_DESC=		Build CPU backend shared libraries for various SIMD instruction sets
CPU_PLIST_FILES=	lib/ollama/libggml-base.so \
			lib/ollama/libggml-base.so.0
.if ${XARCH} == "amd64" || ${XARCH} == "i386"
CPU_PLIST_FILES+=	lib/ollama/libggml-cpu-alderlake.so \
			lib/ollama/libggml-cpu-haswell.so \
			lib/ollama/libggml-cpu-icelake.so \
			lib/ollama/libggml-cpu-sandybridge.so \
			lib/ollama/libggml-cpu-skylakex.so \
			lib/ollama/libggml-cpu-sse42.so \
			lib/ollama/libggml-cpu-x64.so
.endif

VULKAN_DESC=		Build Vulkan GPU backend shared library
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_PLIST_FILES=	lib/ollama/vulkan/libggml-vulkan.so

MLX_DESC=		Build MLX backend for image generation (CPU)
MLX_BUILD_DEPENDS=	${LOCALBASE}/lib/cmake/fmt/fmt-config.cmake:devel/libfmt
MLX_LIB_DEPENDS=	libopenblas.so:math/openblas
MLX_PLIST_FILES=	lib/ollama/libmlx.so \
			lib/ollama/libmlxc.so
_CMAKE_FLAGS=	-DCMAKE_BUILD_TYPE=Release -DGGML_BACKEND_DL=ON -DGGML_BACKEND_DIR=${PREFIX}/lib/ollama

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMLX}
GO_BUILDFLAGS+=	-tags mlx
DISTFILES+=	v${MLX_CORE_VERSION}.tar.gz:mlxsrc \
		v${MLX_C_VERSION}.tar.gz:mlxcsrc \
		json.tar.xz:jsonsrc
MASTER_SITES+=	https://github.com/ml-explore/mlx/archive/refs/tags/:mlxsrc \
		https://github.com/ml-explore/mlx-c/archive/refs/tags/:mlxcsrc \
		https://github.com/nlohmann/json/releases/download/v${JSON_VERSION}/:jsonsrc
.endif

CONFLICTS_BUILD=	ggml

post-patch:
	# update version in go.mod and version.go
	@${REINPLACE_CMD} -e 's|var Version string = "0.0.0"|var Version string = "${PORTVERSION}"|g' \
		${WRKSRC}/go.mod ${WRKSRC}/version/version.go

pre-build-CPU-on:
	@${MKDIR} ${WRKSRC}/build && \
		cd ${WRKSRC}/build && \
		${CMAKE_BIN} ${_CMAKE_FLAGS} .. && \
		${MAKE_CMD} ggml-base && \
		${MAKE_CMD} ggml-cpu

pre-build-VULKAN-on:
.if !${PORT_OPTIONS:MCPU} && !${PORT_OPTIONS:MMLX}
	@${MKDIR} ${WRKSRC}/build && \
		cd ${WRKSRC}/build && \
		${CMAKE_BIN} ${_CMAKE_FLAGS} ..
.endif
	@cd ${WRKSRC}/build && \
		${MAKE_CMD} ggml-vulkan

post-patch-MLX-on:
	# FreeBSD compatibility fix: netinet/in.h (defines IPPROTO_TCP) is not
	# pulled in transitively by netinet/tcp.h on FreeBSD as it is on Linux.
	@${AWK} '/^#include <netinet\/tcp.h>/{print "#include <netinet/in.h>";print;next}1' \
		${WRKDIR}/mlx-${MLX_CORE_VERSION}/mlx/distributed/ring/ring.cpp > \
		${WRKDIR}/mlx-${MLX_CORE_VERSION}/mlx/distributed/ring/ring.cpp.new && \
		${MV} ${WRKDIR}/mlx-${MLX_CORE_VERSION}/mlx/distributed/ring/ring.cpp.new \
		${WRKDIR}/mlx-${MLX_CORE_VERSION}/mlx/distributed/ring/ring.cpp
	# FreeBSD memory size fix: add hw.physmem sysctl query so MLX sets its
	# memory_limit from actual RAM instead of using the 8 GB hardcoded fallback.
	${INSTALL_DATA} ${FILESDIR}/freebsd_memory.h \
		${WRKDIR}/mlx-${MLX_CORE_VERSION}/mlx/backend/no_gpu/freebsd_memory.h
	@${AWK} '/^#elif defined\(__linux__\)/{print "#elif defined(__FreeBSD__)";print "#include \"mlx/backend/no_gpu/freebsd_memory.h\"";print;next}1' \
		${WRKDIR}/mlx-${MLX_CORE_VERSION}/mlx/backend/no_gpu/allocator.cpp > \
		${WRKDIR}/mlx-${MLX_CORE_VERSION}/mlx/backend/no_gpu/allocator.cpp.new && \
		${MV} ${WRKDIR}/mlx-${MLX_CORE_VERSION}/mlx/backend/no_gpu/allocator.cpp.new \
		${WRKDIR}/mlx-${MLX_CORE_VERSION}/mlx/backend/no_gpu/allocator.cpp

pre-build-MLX-on:
	@${MKDIR} ${WRKSRC}/build && \
		cd ${WRKSRC}/build && \
		OLLAMA_MLX_SOURCE=${WRKDIR}/mlx-${MLX_CORE_VERSION} \
		OLLAMA_MLX_C_SOURCE=${WRKDIR}/mlx-c-${MLX_C_VERSION} \
		${CMAKE_BIN} ${_CMAKE_FLAGS} \
		-DMLX_ENGINE:BOOL=ON \
		-DFETCHCONTENT_FULLY_DISCONNECTED:BOOL=ON \
		-DFETCHCONTENT_SOURCE_DIR_JSON:PATH=${WRKDIR}/json \
		-DUSE_SYSTEM_FMT:BOOL=ON \
		-DMLX_BUILD_TESTS:BOOL=OFF \
		-DMLX_BUILD_EXAMPLES:BOOL=OFF \
		..
	@cd ${WRKSRC}/build && \
		${MAKE_CMD} mlx mlxc

post-install: # pending https://github.com/ollama/ollama/issues/6407
	${INSTALL_SCRIPT} ${FILESDIR}/ollama-limit-gpu-layers ${STAGEDIR}${PREFIX}/bin

post-install-CPU-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ollama
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libggml-base.so \
		${STAGEDIR}${PREFIX}/lib/ollama/
	# Create the SONAME symlink so that libggml-vulkan.so and libggml-cpu-*.so
	# can resolve their NEEDED libggml-base.so.0 dependency via dlopen
	${LN} -sf libggml-base.so ${STAGEDIR}${PREFIX}/lib/ollama/libggml-base.so.0
	@for f in ${WRKSRC}/build/lib/ollama/libggml-cpu*.so; do \
		${INSTALL_LIB} $$f ${STAGEDIR}${PREFIX}/lib/ollama/; \
	done

post-install-VULKAN-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ollama/vulkan
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libggml-vulkan.so \
		${STAGEDIR}${PREFIX}/lib/ollama/vulkan/

post-install-MLX-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ollama
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libmlx.so \
		${STAGEDIR}${PREFIX}/lib/ollama/
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libmlxc.so \
		${STAGEDIR}${PREFIX}/lib/ollama/
	patchelf --set-rpath '$$ORIGIN' ${STAGEDIR}${PREFIX}/lib/ollama/libmlx.so
	patchelf --set-rpath '$$ORIGIN' ${STAGEDIR}${PREFIX}/lib/ollama/libmlxc.so

do-test:
	@cd ${WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ./...

.include <bsd.port.mk>
