PORTNAME=	llama-cpp
DISTVERSIONPREFIX=	b
DISTVERSION=	3503
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Facebook's LLaMA model in C/C++ # '
WWW=		https://github.com/ggerganov/llama.cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=278810

USES=		cmake:testing compiler:c++11-lang python:run shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ggerganov
GH_PROJECT=	llama.cpp
GH_TUPLE=	nomic-ai:kompute:4565194:kompute/kompute

SHEBANG_GLOB=	*.py

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	LLAMA_BUILD_TESTS
CMAKE_TESTING_ON=	LLAMA_BUILD_TESTS

LDFLAGS+=	-pthread

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_SUB=		yes

EXAMPLES_CMAKE_BOOL=	LLAMA_BUILD_EXAMPLES

BINARY_ALIAS=	git=false

# 1 test fails due to a missing model file (stories260K.gguf)

.include <bsd.port.mk>
