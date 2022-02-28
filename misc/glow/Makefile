PORTNAME=	glow
DISTVERSION=	g20200721
PORTREVISION=	4
CATEGORIES=	misc # machine-learning
PKGNAMESUFFIX=	-nn-compiler

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Machine learning compiler and execution engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	non-constant-expression cannot be narrowed from type 'dim_t', see https://github.com/pytorch/glow/issues/4024
BROKEN=		does not link: undefined reference to typeinfo for snappy::Source

LIB_DEPENDS=	libLLVM-${LLVM_VER:R}.so:devel/llvm${LLVM_VER:S/.//} \
		libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfolly.so:devel/folly \
		libglog.so:devel/glog \
		libpng.so:graphics/png \
		libprotobuf.so:devel/protobuf \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium

USES=		cmake compiler:c++14-lang python:build
USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_TAGNAME=	f24d960e3cc80db95ac0bc17b1900dbf60ca044a
GH_TUPLE=	\
		google:benchmark:090faec:googlebenchmark/tests/googlebenchmark \
		houseroad:foxi:8015abb:foxi/thirdparty/foxi \
		Maratyszcza:FP16:34d4bf0:fp16/thirdparty/fp16 \
		onnx:onnx:50dc186:onnx/thirdparty/onnx \
		stp:OutputCheck:eab62a5:OutputCheck/tests/OutputCheck

CMAKE_ARGS=	-DFREEBSD_LLVM_VERSION:STRING=${LLVM_VER} -DGIT_SHA1:STRING="\"${GH_TAGNAME}\"" -DGIT_DATE:STRING="\"${DISTVERSION:S/g//}\""
#CMAKE_ON=	BUILD_SHARED_LIBS # this causes build failure: undefined reference to llvm::cfg::Update<llvm::BasicBlock*>::dump() const
CMAKE_OFF=	GLOW_BUILD_EXAMPLES GLOW_BUILD_TESTS

BINARY_ALIAS=	python=${PYTHON_CMD}
BINARY_ALIAS+=	c++=${LOCALBASE}/bin/clang++${LLVM_VER:S/.//} # workaround for the llvm version mixup: https://github.com/pytorch/glow/issues/4910

LLVM_VER=	${LLVM_DEFAULT:C/(.)(.)/\1.\2/}

post-configure: # not sure what causes -lgflags_shared to appear in build.ninja
	@${REINPLACE_CMD} -e 's|-lgflags_shared|-L${LOCALBASE}/lib -lgflags|g' ${BUILD_WRKSRC}/build.ninja

do-install: # https://github.com/pytorch/glow/issues/3461
		cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}
		cd ${BUILD_WRKSRC} && ${COPYTREE_SHARE} glow ${STAGEDIR}${PREFIX}/include
		cd ${WRKSRC}/thirdparty/foxi/foxi && ${MKDIR} ${STAGEDIR}${PREFIX}/include/foxi && (for f in `${LS} *.h`; do ${INSTALL_DATA} $$f ${STAGEDIR}${PREFIX}/include/foxi; done;)
		(for lib in `${FIND} ${BUILD_WRKSRC} -name "*.a"`; do ${INSTALL_DATA} $$lib ${STAGEDIR}${PREFIX}/lib/; done;)

.include <bsd.port.mk>
