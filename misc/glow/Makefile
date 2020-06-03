# $FreeBSD$

PORTNAME=	glow
DISTVERSION=	g20200115
PORTREVISION=	3
CATEGORIES=	misc # machine-learning
PKGNAMESUFFIX=	-nn-compiler

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Machine learning compiler and execution engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	non-constant-expression cannot be narrowed from type 'dim_t', see https://github.com/pytorch/glow/issues/4024

LIB_DEPENDS=	libLLVM-${LLVM_VER:R}.so:devel/llvm${LLVM_VER:S/.//} \
		libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++14-lang python:build
USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_TAGNAME=	97f84e830404183375380842de914e07c0961f7f
GH_TUPLE=	\
		google:benchmark:090faec:googlebenchmark/tests/googlebenchmark \
		google:googletest:0c799d0:googletest/tests/googletest \
		houseroad:foxi:8015abb:foxi/thirdparty/foxi \
		Maratyszcza:FP16:34d4bf0:fp16/thirdparty/fp16 \
		onnx:onnx:50dc186:onnx/thirdparty/onnx \
		stp:OutputCheck:eab62a5:OutputCheck/tests/OutputCheck

CMAKE_ARGS=	-DFREEBSD_LLVM_VERSION:STRING=${LLVM_VER} -DGIT_SHA1:STRING="\"${GH_TAGNAME}\"" -DGIT_DATE:STRING="\"${DISTVERSION:S/g//}\""
CMAKE_OFF=	GLOW_BUILD_EXAMPLES GLOW_BUILD_TESTS

BINARY_ALIAS=	python=${PYTHON_CMD}

LLVM_VER=	${LLVM_DEFAULT:C/(.)(.)/\1.\2/}

do-install: # https://github.com/pytorch/glow/issues/3461
		cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}
		cd ${BUILD_WRKSRC} && ${COPYTREE_SHARE} glow ${STAGEDIR}${PREFIX}/include
		cd ${WRKSRC}/thirdparty/foxi/foxi && ${MKDIR} ${STAGEDIR}${PREFIX}/include/foxi && (for f in `${LS} *.h`; do ${INSTALL_DATA} $$f ${STAGEDIR}${PREFIX}/include/foxi; done;)
		(for lib in `${FIND} ${BUILD_WRKSRC} -name "*.a"`; do ${INSTALL_DATA} $$lib ${STAGEDIR}${PREFIX}/lib/; done;)

.include <bsd.port.mk>
