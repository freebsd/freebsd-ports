PORTNAME=	mnn
DISTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight deep neural network inference engine
WWW=		https://github.com/alibaba/MNN

LICENSE=	APACHE20

BROKEN_i386=	always_inline function '_mm_set1_ps' requires target feature 'sse', but would be inlined into function 'Vec4' that is compiled without support for 'sse'

BUILD_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++11-lang localbase shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	alibaba
GH_PROJECT=	MNN

SHEBANG_GLOB=	*.sh

CMAKE_TESTING_ON=	MNN_BUILD_TEST
CMAKE_TESTING_TARGET=

CXXFLAGS+=	-pthread
LDFLAGS+=	-pthread

CFLAGS+=	-fPIC # workaround for https://github.com/alibaba/MNN/issues/553
CXXFLAGS+=	-fPIC

OPTIONS_DEFINE=		APPS CONVERTER HARD_FP
OPTIONS_DEFAULT=	APPS CONVERTER HARD_FP
OPTIONS_SUB=		yes

APPS_DESC=		Build ML training, quantization tools
APPS_CMAKE_BOOL=	MNN_BUILD_QUANTOOLS MNN_BUILD_TOOLS MNN_BUILD_TRAIN

CONVERTER_DESC=		Build the model converter tool
CONVERTER_CMAKE_BOOL=	MNN_BUILD_CONVERTER
CONVERTER_LIB_DEPENDS=	libprotobuf.so:devel/protobuf

HARD_FP_DESC=		Hard floating point numbers
HARD_FP_CMAKE_BOOL=	MNN_BUILD_HARD

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DMNN_USE_AVX:BOOL=OFF \
		-DMNN_USE_SSE:BOOL=OFF
.endif

do-install-APPS-on:
.for f in	MNNV2Basic.out mobilenetTest.out backendTest.out testModel.out getPerformance.out checkInvalidValue.out timeProfile.out quantized.out \
		transformer.out train.out rawDataTransform.out dataTransformer.out runTrainDemo.out
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-CONVERTER-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/MNNConvert ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/tools/converter/libMNNConvertDeps.so ${STAGEDIR}${PREFIX}/lib

post-test:
	@cd ${BUILD_WRKSRC} && \
		cd ${BUILD_WRKSRC} && ./run_test.out

# 5 tests fail, see https://github.com/alibaba/MNN/issues/2358

.include <bsd.port.post.mk>
