# $FreeBSD$

PORTNAME=	ngraph
DISTVERSIONPREFIX=	v
DISTVERSION=	0.29.0-rc.0-345
DISTVERSIONSUFFIX=	-g58b649aa6
PORTREVISION=	1
CATEGORIES=	misc # machine-learning
PKGNAMESUFFIX=	-machine-learning-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library, compiler and runtime for Deep Learning

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	onednn>0:math/onednn
LIB_DEPENDS=	libtbb.so:devel/tbb

USES=		cmake eigen:3 localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	NervanaSystems
USE_LDCONFIG=	yes

CMAKE_OFF=	NGRAPH_UNIT_TEST_ENABLE NGRAPH_TEST_UTIL_ENABLE NGRAPH_TBB_ENABLE NGRAPH_JSON_ENABLE NGRAPH_MLIR_ENABLE NGRAPH_CODEGEN_ENABLE
CMAKE_ON=	NGRAPH_USE_PREBUILT_LLVM
CMAKE_ARGS=	-DClang_DIR=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/clang \
		-DTBB_ROOT=${LOCALBASE}

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3
BINARY_ALIAS=	git=/usr/bin/true

# ngraph uses clang from ports in a c++14 mode
BUILD_DEPENDS+=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
RUN_DEPENDS+=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

OPTIONS_DEFINE=		NATIVE

NATIVE_DESC=		Build with native optimizations (-march=native)
NATIVE_CMAKE_BOOL=	NGRAPH_NATIVE_ARCH_ENABLE

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} -r licenses && \
		${RM} LICENSE VERSION && \
		${MV} cmake lib/ && \
		${RM} -r include/ngraph/frontend/ATen

.include <bsd.port.mk>
