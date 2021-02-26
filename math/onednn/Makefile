# $FreeBSD$

PORTNAME=	onednn
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
CATEGORIES=	math # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel(R) Math Kernel Library for Deep Neural Networks

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: shift count >= width of type (and other errors), see https://github.com/intel/mkl-dnn/issues/315

TEST_DEPENDS=	bash:shells/bash \
		libsysinfo>0:devel/libsysinfo

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	oneapi-src
GH_PROJECT=	oneDNN
USE_LDCONFIG=	yes

CMAKE_OFF=	DNNL_BUILD_TESTS DNNL_BUILD_EXAMPLES

OPTIONS_DEFAULT=		SIMD_DEFAULT OPENMP
OPTIONS_SINGLE=			SIMD CPU_RUNTIME
OPTIONS_SINGLE_SIMD=		SIMD_DEFAULT SIMD_NATIVE
OPTIONS_SINGLE_CPU_RUNTIME=	OPENMP TBB SEQ THREADPOOL_STANDALONE THREADPOOL_EIGEN THREADPOOL_TBB
CPU_RUNTIME_DESC=		Threading runtime for CPU engines

OPENMP_CMAKE_ON=	-DDNNL_CPU_RUNTIME=OMP

SEQ_DESC=		Sequential (no parallelism)
SEQ_CMAKE_ON=		-DDNNL_CPU_RUNTIME=SEQ

SIMD_DEFAULT_DESC=	Default, no non-default SIMD instructions are used

SIMD_NATIVE_DESC=	Optimize for this CPU
SIMD_NATIVE_CXXFLAGS=	-march=native

SIMD_SSE41_DESC=	Use SSE4.1 instructions
SIMD_SSE41_CXXFLAGS=	-msse4.1

TBB_DESC=		Threading Building Blocks
TBB_CMAKE_ON=		-DDNNL_CPU_RUNTIME=TBB
TBB_BROKEN=		https://github.com/oneapi-src/oneDNN/issues/876

THREADPOOL_STANDALONE_DESC=	Threadpool based on the standalone implementation
THREADPOOL_STANDALONE_CMAKE_ON=	-DDNNL_CPU_RUNTIME=THREADPOOL -D_DNNL_TEST_THREADPOOL_IMPL=STANDALONE
THREADPOOL_STANDALONE_BROKEN=	https://github.com/oneapi-src/oneDNN/issues/877
THREADPOOL_EIGEN_DESC=		Threadpool based on the Eigen implementation
THREADPOOL_EIGEN_CMAKE_ON=	-DDNNL_CPU_RUNTIME=THREADPOOL -D_DNNL_TEST_THREADPOOL_IMPL=EIGEN
THREADPOOL_TBB_DESC=		Threadpool based on the TBB implementation
THREADPOOL_TBB_CMAKE_ON=	-DDNNL_CPU_RUNTIME=THREADPOOL -D_DNNL_TEST_THREADPOOL_IMPL=TBB
THREADPOOL_TBB_BROKEN=		https://github.com/oneapi-src/oneDNN/issues/876

ARCH_LOCAL!=	/usr/bin/uname -p # because OPTIONS_SINGLE_SIMD doesn't support per-ARCH values OPTIONS_SINGLE_SIMD_{arch}, like OPTIONS_DEFINE_{arch}

.if ${ARCH_LOCAL} == i386 || ${ARCH_LOCAL} == amd64
OPTIONS_SINGLE_SIMD+=	SIMD_SSE41
.endif

CXXFLAGS:=	${CXXFLAGS:S/-O2/-O3/} # clang writes wrong binary code when -O2 optimization is used and one testcase is failing, see https://bugs.llvm.org/show_bug.cgi?id=48104

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

do-test: # some tests are known to fail: https://github.com/intel/mkl-dnn/issues/350 (the upstream failed to reproduce it and closed the report)
	@${REINPLACE_CMD} 's| /bin/bash | ${LOCALBASE}/bin/bash |' ${WRKSRC}/tests/CMakeLists.txt
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DDNNL_BUILD_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
