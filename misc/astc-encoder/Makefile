PORTNAME=	astc-encoder # due to bugs advanced instructions get into the sse2 binary despite the below options, see https://github.com/ARM-software/astc-encoder/issues/671
DISTVERSION=	5.7.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Texture compressor for Adaptive Scalable Texture Compression format
WWW=		https://github.com/ARM-software/astc-encoder

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_riscv64=	ld: error: lto.tmp: cannot link object files with different floating-point ABI

USES=		cmake:testing compiler:c++14-lang python:test

USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_TUPLE=	google:googletest:e2239ee:googletest/Source/GoogleTest

CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD} # only for tests
CMAKE_ON=	ASTCENC_ISA_SSE2
CMAKE_OFF=	ASTCENC_UNITTEST \
		ASTCENC_ISA_SSE41 \
		ASTCENC_ISA_SVE_256 \
		ASTCENC_ISA_SVE_128 \
		ASTCENC_X86_GATHERS \
		ASTCENC_ISA_NATIVE
CMAKE_TESTING_ON=	ASTCENC_UNITTEST

LDFLAGS+=	-pthread

PLIST_FILES=	bin/astcenc-sse2

# tests as of 5.7.0: 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
