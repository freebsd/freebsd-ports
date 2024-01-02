PORTNAME=	astc-encoder
DISTVERSION=	4.6.1
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
CMAKE_OFF=	ASTCENC_UNITTEST
CMAKE_TESTING_ON=	ASTCENC_UNITTEST

LDFLAGS+=	-pthread

PLIST_FILES=	bin/astcenc-native

.include <bsd.port.mk>
