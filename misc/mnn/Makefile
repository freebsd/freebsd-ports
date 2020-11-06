# $FreeBSD$

PORTNAME=	mnn
DISTVERSION=	1.1.0
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight deep neural network inference engine

LICENSE=	APACHE20

BROKEN_i386=	always_inline function '_mm_set1_ps' requires target feature 'sse', but would be inlined into function 'Vec4' that is compiled without support for 'sse'

BUILD_DEPENDS=	bash:shells/bash \
		flatc:devel/flatbuffers

USES=		cmake compiler:c++11-lang localbase shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	alibaba
GH_PROJECT=	MNN
SHEBANG_GLOB=	*.sh
USE_LDCONFIG=	yes

CXXFLAGS+=	-pthread
LDFLAGS+=	-pthread

CFLAGS+=	-fPIC # workaround for https://github.com/alibaba/MNN/issues/553
CXXFLAGS+=	-fPIC

OPTIONS_DEFINE=		APPS CONVERTER HARD_FP
OPTIONS_DEFAULT=	CONVERTER HARD_FP
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

pre-build: # https://github.com/alibaba/MNN/issues/648
	@cd ${WRKSRC}/schema && FREEBSD_FLATC=${LOCALBASE}/bin/flatc ./generate.sh

do-install-APPS-on:
.for f in	MNNConvert MNNV2Basic.out mobilenetTest.out backendTest.out testModel.out testModelWithDescrisbe.out getPerformance.out checkInvalidValue.out timeProfile.out quantized.out \
		transformer.out train.out rawDataTransform.out dataTransformer.out runTrainDemo.out
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-CONVERTER-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/MNNConvert ${STAGEDIR}${PREFIX}/bin

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DMNN_BUILD_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		cd ${BUILD_WRKSRC} && ./run_test.out

.include <bsd.port.post.mk>
