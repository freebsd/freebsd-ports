PORTNAME=	astc-encoder
DISTVERSION=	5.3.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Texture compressor for Adaptive Scalable Texture Compression format
WWW=		https://github.com/ARM-software/astc-encoder \
		https://developer.arm.com/Gaming%20Graphics%20and%20VR

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_riscv64=	ld: error: lto.tmp: cannot link object files with different floating-point ABI

USES=		cmake:testing compiler:c++14-lang python:test

USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_TUPLE=	google:googletest:e2239ee:googletest/Source/GoogleTest

CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD} # only for tests
CMAKE_OFF=	ASTCENC_UNITTEST
CMAKE_TESTING_ON=	ASTCENC_UNITTEST

LDFLAGS+=	-pthread

PLIST_FILES=	bin/astcenc-native

# tests as of 5.3.0: 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
