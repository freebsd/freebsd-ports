PORTNAME=	kfr
DISTVERSION=	4.2.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ DSP framework, FFT, Sample Rate Conversion, FIR/IIR/Biquad Filters

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_riscv64=	error: no member named 'neon' in 'kfr::cpu_t'

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	kfrlib

CMAKE_ON=	BUILD_SHARED_LIBS

#CXXFLAGS_armv6=	-march=native # to fix: ARM builds require NEON support. Add -march=native for native build or skip the check with CMT_FORCE_GENERIC_CPU=1
CMAKE_ARGS_armv6=	-DCMT_FORCE_GENERIC_CPU=1 # to fix: ARM builds require NEON support. Add -march=native for native build or skip the check with CMT_FORCE_GENERIC_CPU=1

do-test: # some tests fail: https://github.com/kfrlib/kfr/issues/132
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_SHARED_LIBS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/bin/all_tests

.include <bsd.port.mk>
