# $FreeBSD$

PORTNAME=	onednn
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7
PORTREVISION=	2
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

CMAKE_OFF=	BUILD_TESTING

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP SIMD_DEFAULT
OPTIONS_SINGLE=		SIMD
OPTIONS_SINGLE_SIMD=	SIMD_DEFAULT SIMD_NATIVE

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_BROKEN_OFF=	still requires omp.h, see https://github.com/intel/mkl-dnn/issues/581

SIMD_DEFAULT_DESC=	Default, no non-default SIMD instructions are used

SIMD_NATIVE_DESC=	Optimize for this CPU
SIMD_NATIVE_CXXFLAGS=	-march=native

SIMD_SSE41_DESC=	Use SSE4.1 instructions
SIMD_SSE41_CXXFLAGS=	-msse4.1

ARCH_LOCAL!=	/usr/bin/uname -p # because OPTIONS_SINGLE_SIMD doesn't support per-ARCH values OPTIONS_SINGLE_SIMD_{arch}, like OPTIONS_DEFINE_{arch}

.if ${ARCH_LOCAL} == i386 || ${ARCH_LOCAL} == amd64
OPTIONS_SINGLE_SIMD+=	SIMD_SSE41
.endif

CXXFLAGS:=	${CXXFLAGS:S/-O2/-O3/} # clang writes wrong binary code when -O2 optimization is used and one testcase is failing, see https://github.com/oneapi-src/oneDNN/issues/873#issuecomment-722778910

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

do-test: # some tests are known to fail: https://github.com/intel/mkl-dnn/issues/350 (the upstream failed to reproduce it and closed the report)
	@${REINPLACE_CMD} 's| /bin/bash | ${LOCALBASE}/bin/bash |' ${WRKSRC}/tests/CMakeLists.txt
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
