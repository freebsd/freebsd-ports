PORTNAME=	kfr
DISTVERSION=	6.0.2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ DSP framework, FFT, Sample Rate Conversion, FIR/IIR/Biquad Filters
WWW=		https://github.com/kfrlib/kfr

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

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

post-test: # see https://github.com/kfrlib/kfr/issues/164
	@cd ${BUILD_WRKSRC} && \
		${BUILD_WRKSRC}/bin/all_tests

.include <bsd.port.mk>
