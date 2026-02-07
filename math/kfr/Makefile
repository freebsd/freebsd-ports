PORTNAME=	kfr
DISTVERSION=	6.3.1
CATEGORIES=	math

PATCH_SITES=	https://github.com/kfrlib/kfr/commit/
PATCHFILES=	eb615703f5f15eb7794d6ec3f20d83130d9f5274.patch:-p1 \
		6056e7d24723531e10484d63f6a9a5c58f976daa.patch:-p1

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

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_EXAMPLES
CMAKE_TESTING_ON=	ENABLE_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET}

#CXXFLAGS_armv6=	-march=native # to fix: ARM builds require NEON support. Add -march=native for native build or skip the check with CMT_FORCE_GENERIC_CPU=1
CMAKE_ARGS_armv6=	-DCMT_FORCE_GENERIC_CPU=1 # to fix: ARM builds require NEON support. Add -march=native for native build or skip the check with CMT_FORCE_GENERIC_CPU=1

.include <bsd.port.options.mk>

.ifndef CPUTYPE && (${ARCH} == amd64 || ${ARCH} == i386)
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
.else
CMAKE_OFF=	KFR_ENABLE_MULTIARCH
PLIST_FILES=	lib/libkfr_dft.so \
		lib/libkfr_dsp.so
.endif

post-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/sample_rate_converter ${STAGEDIR}${PREFIX}/bin/kfr_src

post-test: # see https://github.com/kfrlib/kfr/issues/164
	@cd ${BUILD_WRKSRC} && \
		${BUILD_WRKSRC}/bin/all_tests

.include <bsd.port.mk>
