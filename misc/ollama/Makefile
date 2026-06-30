PORTNAME=	ollama
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.0
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

USES=		cmake:indirect go:1.26+,modules localbase pkgconfig
USE_LDCONFIG=	${PREFIX}/lib/ollama ${PREFIX}/lib/ollama/vulkan
USE_RC_SUBR=	ollama

GO_MODULE=	github.com/yurivict/${PORTNAME} # fork with FreeBSD patches
GO_TARGET=	.
GO_ENV+=	CGO_CXXFLAGS="${CXXFLAGS}"

LLAMA_CPP_VERSION=	b9840 # from the LLAMA_CPP_VERSION file in the llama.cpp repo
GGML_SO_VERSION=	0.15.3	# tied to LLAMA_CPP_VERSION; update when llama.cpp changes
MLX_CORE_VERSION=	0.31.2
MLX_C_VERSION=		fba4470b89073180056c9ea46c443051375f7399
JSON_VERSION=		3.11.3

DISTFILES+=	${LLAMA_CPP_VERSION}.tar.gz:llamasrc \
		llama-${LLAMA_CPP_VERSION}-ui.tar.gz:llamasrc
MASTER_SITES+=	https://github.com/ggml-org/llama.cpp/archive/refs/tags/:llamasrc \
		https://github.com/ggml-org/llama.cpp/releases/download/${LLAMA_CPP_VERSION}/:llamasrc

PLIST_FILES=	bin/${PORTNAME} \
		bin/ollama-limit-gpu-layers

OPTIONS_GROUP=		BACKENDS
OPTIONS_GROUP_BACKENDS=	CPU VULKAN MLX
OPTIONS_DEFAULT=	CPU VULKAN MLX

CPU_DESC=		Build CPU backend shared libraries for various SIMD instruction sets
CPU_PLIST_FILES=	lib/ollama/llama-server \
			lib/ollama/llama-quantize \
			lib/ollama/libggml-base.so \
			lib/ollama/libggml-base.so.0 \
			lib/ollama/libggml-base.so.${GGML_SO_VERSION} \
			lib/ollama/libggml.so \
			lib/ollama/libggml.so.0 \
			lib/ollama/libggml.so.${GGML_SO_VERSION} \
			lib/ollama/libllama-common.so \
			lib/ollama/libllama-common.so.0 \
			lib/ollama/libllama-common.so.0.0.${LLAMA_CPP_VERSION:S/b//} \
			lib/ollama/libllama-quantize-impl.so \
			lib/ollama/libllama-server-impl.so \
			lib/ollama/libllama.so \
			lib/ollama/libllama.so.0 \
			lib/ollama/libllama.so.0.0.${LLAMA_CPP_VERSION:S/b//} \
			lib/ollama/libmtmd.so \
			lib/ollama/libmtmd.so.0 \
			lib/ollama/libmtmd.so.0.0.${LLAMA_CPP_VERSION:S/b//}
.if ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "i386"
CPU_PLIST_FILES+=	lib/ollama/libggml-cpu-alderlake.so \
			lib/ollama/libggml-cpu-cannonlake.so \
			lib/ollama/libggml-cpu-cascadelake.so \
			lib/ollama/libggml-cpu-cooperlake.so \
			lib/ollama/libggml-cpu-haswell.so \
			lib/ollama/libggml-cpu-icelake.so \
			lib/ollama/libggml-cpu-ivybridge.so \
			lib/ollama/libggml-cpu-piledriver.so \
			lib/ollama/libggml-cpu-sandybridge.so \
			lib/ollama/libggml-cpu-sapphirerapids.so \
			lib/ollama/libggml-cpu-skylakex.so \
			lib/ollama/libggml-cpu-sse42.so \
			lib/ollama/libggml-cpu-x64.so \
			lib/ollama/libggml-cpu-zen4.so
.endif

VULKAN_DESC=		Build Vulkan GPU backend shared library
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
			${LOCALBASE}/share/cmake/SPIRV-Headers/SPIRV-HeadersConfig.cmake:graphics/spirv-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_PLIST_FILES=	lib/ollama/vulkan/libggml-vulkan.so

MLX_DESC=		Build MLX backend for image generation (CPU)
MLX_BUILD_DEPENDS=	${LOCALBASE}/lib/cmake/fmt/fmt-config.cmake:devel/libfmt
MLX_LIB_DEPENDS=	libopenblas.so:math/openblas
MLX_PLIST_FILES=	lib/ollama/libmlx.so \
			lib/ollama/libmlxc.so

_CMAKE_FLAGS=	-DCMAKE_BUILD_TYPE=Release \
		-DGGML_BACKEND_DL=ON \
		-DGGML_BACKEND_DIR=${PREFIX}/lib/ollama \
		-DFETCHCONTENT_FULLY_DISCONNECTED=ON \
		-DFETCHCONTENT_SOURCE_DIR_LLAMA_CPP=${WRKDIR}/llama.cpp-${LLAMA_CPP_VERSION} \
		-DOLLAMA_LLAMA_CPP_SKIP_COMPAT_PATCH=ON \
		-DLLAMA_BUILD_NUMBER=${LLAMA_CPP_VERSION:S/b//}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVULKAN}
_CMAKE_FLAGS+=	-DOLLAMA_LLAMA_BACKENDS=vulkan
.endif

.if ${PORT_OPTIONS:MMLX}
GO_BUILDFLAGS+=	-tags mlx
DISTFILES+=	v${MLX_CORE_VERSION}.tar.gz:mlxsrc \
		${MLX_C_VERSION}.tar.gz:mlxcsrc \
		json.tar.xz:jsonsrc
MASTER_SITES+=	https://github.com/ml-explore/mlx/archive/refs/tags/:mlxsrc \
		https://github.com/ml-explore/mlx-c/archive/:mlxcsrc \
		https://github.com/nlohmann/json/releases/download/v${JSON_VERSION}/:jsonsrc
.endif

post-extract:
	# Copy pre-built UI assets into llama.cpp source tree so the build
	# can embed them without running npm or downloading from Hugging Face.
	@${MKDIR} ${WRKDIR}/llama.cpp-${LLAMA_CPP_VERSION}/tools/ui/dist && \
		${CP} -r ${WRKDIR}/llama-${LLAMA_CPP_VERSION}/* \
		${WRKDIR}/llama.cpp-${LLAMA_CPP_VERSION}/tools/ui/dist/

post-patch:
	# Apply llama.cpp laguna model patch (adds llama_model_laguna class)
	@${PATCH} -d ${WRKDIR}/llama.cpp-${LLAMA_CPP_VERSION} -p1 \
		< ${WRKSRC}/llama/compat/models/003-llama-cpp-laguna.patch
	# Apply Ollama llama.cpp compat hooks patch (vision model support)
	@${PATCH} -d ${WRKDIR}/llama.cpp-${LLAMA_CPP_VERSION} -p1 \
		< ${WRKSRC}/llama/compat/001-llama-cpp-hooks.patch
	# Fix llama-ui-embed crash when called without asset_dir argument
	@${REINPLACE_CMD} -e 's|const std::string asset_dir = argv\[3\];|const std::string asset_dir = (argc > 3) ? argv[3] : "";|g' \
		${WRKDIR}/llama.cpp-${LLAMA_CPP_VERSION}/tools/ui/embed.cpp
	# FreeBSD: copy llm/llm_freebsd.go for LlamaServerSysProcAttr
	@${CP} ${FILESDIR}/llm_freebsd.go ${WRKSRC}/llm/
	# update version in version.go
	@${REINPLACE_CMD} -e 's|var Version string = "0.0.0"|var Version string = "${PORTVERSION}"|g' \
		${WRKSRC}/version/version.go

pre-build-CPU-on:
	@${MKDIR} ${WRKSRC}/build && \
		cd ${WRKSRC}/build && \
		${CMAKE_BIN} ${_CMAKE_FLAGS} .. && \
		${MAKE_CMD} ollama-llama-server-local

pre-build-VULKAN-on:
.if !${PORT_OPTIONS:MCPU} && !${PORT_OPTIONS:MMLX}
	@${MKDIR} ${WRKSRC}/build && \
		cd ${WRKSRC}/build && \
		${CMAKE_BIN} ${_CMAKE_FLAGS} ..
.endif
	@cd ${WRKSRC}/build && \
		${MAKE_CMD} ollama-llama-server-vulkan

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
	@${MKDIR} ${WRKSRC}/build-mlx && \
		cd ${WRKSRC}/build-mlx && \
		OLLAMA_MLX_SOURCE=${WRKDIR}/mlx-${MLX_CORE_VERSION} \
		OLLAMA_MLX_C_SOURCE=${WRKDIR}/mlx-c-${MLX_C_VERSION} \
		${CMAKE_BIN} ${_CMAKE_FLAGS} \
		-DFETCHCONTENT_FULLY_DISCONNECTED:BOOL=ON \
		-DUSE_SYSTEM_FMT:BOOL=ON \
		-DFETCHCONTENT_SOURCE_DIR_JSON:PATH=${WRKDIR}/json \
		-DOLLAMA_SOURCE_DIR:PATH=${WRKSRC} \
		-S ${WRKSRC}/cmake/mlx \
		-B ${WRKSRC}/build-mlx
	@cd ${WRKSRC}/build-mlx && \
		${MAKE_CMD} mlx mlxc

post-install: # pending https://github.com/ollama/ollama/issues/6407
	${INSTALL_SCRIPT} ${FILESDIR}/ollama-limit-gpu-layers ${STAGEDIR}${PREFIX}/bin

post-install-CPU-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ollama
	# versioned libggml-base
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libggml-base.so.${GGML_SO_VERSION} \
		${STAGEDIR}${PREFIX}/lib/ollama/
	${LN} -sf libggml-base.so.${GGML_SO_VERSION} \
		${STAGEDIR}${PREFIX}/lib/ollama/libggml-base.so.0
	${LN} -sf libggml-base.so.0 \
		${STAGEDIR}${PREFIX}/lib/ollama/libggml-base.so
	# versioned libggml
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libggml.so.${GGML_SO_VERSION} \
		${STAGEDIR}${PREFIX}/lib/ollama/
	${LN} -sf libggml.so.${GGML_SO_VERSION} \
		${STAGEDIR}${PREFIX}/lib/ollama/libggml.so.0
	${LN} -sf libggml.so.0 \
		${STAGEDIR}${PREFIX}/lib/ollama/libggml.so
	# versioned libllama-common
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libllama-common.so.0.0.${LLAMA_CPP_VERSION:S/b//} \
		${STAGEDIR}${PREFIX}/lib/ollama/
	${LN} -sf libllama-common.so.0.0.${LLAMA_CPP_VERSION:S/b//} \
		${STAGEDIR}${PREFIX}/lib/ollama/libllama-common.so.0
	${LN} -sf libllama-common.so.0 \
		${STAGEDIR}${PREFIX}/lib/ollama/libllama-common.so
	# versioned libllama
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libllama.so.0.0.${LLAMA_CPP_VERSION:S/b//} \
		${STAGEDIR}${PREFIX}/lib/ollama/
	${LN} -sf libllama.so.0.0.${LLAMA_CPP_VERSION:S/b//} \
		${STAGEDIR}${PREFIX}/lib/ollama/libllama.so.0
	${LN} -sf libllama.so.0 \
		${STAGEDIR}${PREFIX}/lib/ollama/libllama.so
	# versioned libmtmd
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libmtmd.so.0.0.${LLAMA_CPP_VERSION:S/b//} \
		${STAGEDIR}${PREFIX}/lib/ollama/
	${LN} -sf libmtmd.so.0.0.${LLAMA_CPP_VERSION:S/b//} \
		${STAGEDIR}${PREFIX}/lib/ollama/libmtmd.so.0
	${LN} -sf libmtmd.so.0 \
		${STAGEDIR}${PREFIX}/lib/ollama/libmtmd.so
	# unversioned impl libs needed at runtime by llama-server and llama-quantize
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libllama-server-impl.so \
		${STAGEDIR}${PREFIX}/lib/ollama/
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libllama-quantize-impl.so \
		${STAGEDIR}${PREFIX}/lib/ollama/
	# binaries
	${INSTALL_PROGRAM} ${WRKSRC}/build/lib/ollama/llama-server \
		${STAGEDIR}${PREFIX}/lib/ollama/
	${INSTALL_PROGRAM} ${WRKSRC}/build/lib/ollama/llama-quantize \
		${STAGEDIR}${PREFIX}/lib/ollama/
	# cpu-variant SIMD backend DSOs
	@for f in ${WRKSRC}/build/lib/ollama/libggml-cpu*.so; do \
		${INSTALL_LIB} $$f ${STAGEDIR}${PREFIX}/lib/ollama/; \
	done

post-install-VULKAN-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ollama/vulkan
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/vulkan/libggml-vulkan.so \
		${STAGEDIR}${PREFIX}/lib/ollama/vulkan/
	# Fix RPATH: libggml-base.so.0 lives in the parent directory
	patchelf --set-rpath '$$ORIGIN:$$ORIGIN/..' \
		${STAGEDIR}${PREFIX}/lib/ollama/vulkan/libggml-vulkan.so

post-install-MLX-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ollama
	${INSTALL_LIB} ${WRKSRC}/build-mlx/lib/ollama/libmlx.so \
		${STAGEDIR}${PREFIX}/lib/ollama/
	${INSTALL_LIB} ${WRKSRC}/build-mlx/lib/ollama/libmlxc.so \
		${STAGEDIR}${PREFIX}/lib/ollama/
	patchelf --set-rpath '$$ORIGIN' ${STAGEDIR}${PREFIX}/lib/ollama/libmlx.so
	patchelf --set-rpath '$$ORIGIN' ${STAGEDIR}${PREFIX}/lib/ollama/libmlxc.so

do-test:
	@cd ${WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ./...

.include <bsd.port.mk>
