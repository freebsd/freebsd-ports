# $FreeBSD$

PORTNAME=	mnn
DISTVERSION=	0.2.2.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight deep neural network inference engine

LICENSE=	APACHE20

BROKEN_i386=	always_inline function '_mm_set1_ps' requires target feature 'sse', but would be inlined into function 'Vec4' that is compiled without support for 'sse'

BUILD_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++11-lang shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	alibaba
GH_PROJECT=	MNN
SHEBANG_GLOB=	*.sh
USE_LDCONFIG=	yes

CXXFLAGS+=	-pthread
LDFLAGS+=	-pthread

CFLAGS+=	-fPIC # workaround for https://github.com/alibaba/MNN/issues/553
CXXFLAGS+=	-fPIC

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DMNN_USE_AVX:BOOL=OFF \
		-DMNN_USE_SSE:BOOL=OFF
.endif

pre-build: # https://github.com/alibaba/MNN/issues/648
	@cd ${WRKSRC}/schema && ./generate.sh

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DMNN_BUILD_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		cd ${BUILD_WRKSRC} && ./run_test.out

.include <bsd.port.post.mk>
