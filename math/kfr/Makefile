PORTNAME=	kfr
DISTVERSION=	6.2.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ DSP framework, FFT, Sample Rate Conversion, FIR/IIR/Biquad Filters
WWW=		https://github.com/kfrlib/kfr

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	architecture mismatch in cmake, see https://github.com/kfrlib/kfr/issues/222
ONLY_FOR_ARCHS=		aarch64 amd64 armv7 i386
ONLY_FOR_ARCHS_REASON=	only x86, x86_64, ARM (ARMv7+ hf) and AArch64 (aka ARM64) are supported, see https://github.com/kfrlib/kfr/issues/158#issuecomment-1204723324

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	kfrlib

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	ENABLE_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET}

#CXXFLAGS_armv6=	-march=native # to fix: ARM builds require NEON support. Add -march=native for native build or skip the check with CMT_FORCE_GENERIC_CPU=1
CMAKE_ARGS_armv6=	-DCMT_FORCE_GENERIC_CPU=1 # to fix: ARM builds require NEON support. Add -march=native for native build or skip the check with CMT_FORCE_GENERIC_CPU=1

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_FILES=	lib/libkfr_dft_avx.so \
		lib/libkfr_dft_avx2.so \
		lib/libkfr_dft_avx512.so \
		lib/libkfr_dft_sse2.so \
		lib/libkfr_dft_sse41.so \
		lib/libkfr_dsp_avx.so \
		lib/libkfr_dsp_avx2.so \
		lib/libkfr_dsp_avx512.so \
		lib/libkfr_dsp_sse2.so \
		lib/libkfr_dsp_sse41.so
.endif

post-test: # see https://github.com/kfrlib/kfr/issues/164
	@cd ${BUILD_WRKSRC} && \
		${BUILD_WRKSRC}/bin/all_tests

# tests as of 6.2.0: [--SUCCESS--] 199/199 tests 2810450/2810450 checks

.include <bsd.port.mk>
