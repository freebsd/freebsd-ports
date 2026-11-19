PORTNAME=	tvm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.0
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep learning compiler stack for cpu, gpu and specialized accelerators
WWW=		https://tvm.ai \
		https://github.com/apache/tvm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	comilation fails: error: expected identifier before '__is_convertible'

BUILD_DEPENDS=	dlpack>0:misc/dlpack \
		dmlc-core>0:devel/dmlc-core \
		rang>0:devel/rang
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang localbase
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	apache
GH_PROJECT=	tvm
GH_TUPLE=	NVIDIA:cutlass:b2dd65dc864e09688245b316ac46c4a6cd07e15c:cutlass/3rdparty/cutlass \
		KhronosGroup:OpenCL-Headers:b590a6bfe034ea3a418b7b523e3490956bcb367a:OpenCL_Headers/3rdparty/OpenCL-Headers \
		tlc-pack:cutlass_fpA_intB_gemm:96b48221df9d010c2d5b7f65d1664f198c664d28:cutlass_fpA_intB_gemm/3rdparty/cutlass_fpA_intB_gemm \
		tlc-pack:libflash_attn:07ba35bae96900e51b4d63ef3487ba24850da870:libflash_attn/3rdparty/libflash_attn \
		apache:tvm-ffi:daf594da8e6950fdc02ae35fcf4e0ab2e59a4979:tvm_ffi/3rdparty/tvm-ffi

CMAKE_ON=	INSTALL_DEV # Install compiler infrastructure (as opposed to runtime-only)
CMAKE_ARGS=	-DDMLC_PATH=${LOCALBASE}/include -DRANG_PATH=${LOCALBASE}/include
CMAKE_TESTING_TARGET=	cpptest

LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=		LLVM
OPTIONS_DEFAULT=	LLVM

LLVM_VERSION=		${LLVM_DEFAULT}
LLVM_DESC=		With LLVM support for model compilation
LLVM_CMAKE_ON=		-DUSE_LLVM=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}
LLVM_BUILD_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
LLVM_RUN_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
CMAKE_ARGS+=	-DUSE_RPC:BOOL=OFF
.endif

post-test: # 1 test fails, see https://github.com/apache/tvm/issues/13131
	@cd ${TEST_WRKSRC} && ./cpptest

# tests as of 0.27.0:
# [----------] Global test environment tear-down
# [==========] 137 tests from 29 test suites ran. (127 ms total)
# [  PASSED  ] 137 tests.

.include <bsd.port.mk>
