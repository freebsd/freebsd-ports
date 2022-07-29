PORTNAME=	mxnet
DISTVERSION=	1.9.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Apache MXNet: Ultra-scalable deep learning framework

LICENSE=	APACHE20

BROKEN_i386=	https://github.com/apache/incubator-mxnet/issues/20832
.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libdmlc.so:devel/dmlc-core \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	incubator-mxnet
GH_TUPLE=	apache:tvm:efdac94:tvm/3rdparty/tvm \
		dmlc:dlpack:3efc489:dlpack/3rdparty/dlpack \
		oneapi-src:oneDNN:f40443c:onednn/3rdparty/mkldnn # same as BUILD_DEPENDS=${LOCALBASE}/include/dnnl.h:math/onednn
USE_LDCONFIG=	yes

CMAKE_OFF=	USE_CUDA USE_CUDNN USE_MKLDNN USE_NCCL ENABLE_CUDA_RTC \
		BUILD_CPP_EXAMPLES USE_JEMALLOC USE_MKL_IF_AVAILABLE

LDFLAGS+=	-pthread -lexecinfo

OPTIONS_DEFINE=		CPP OPENCV
OPTIONS_DEFAULT=	CPP OPENCV
OPTIONS_SUB=		yes

CPP_DESC=		Install the C++ binding (cpp-package)
CPP_CMAKE_BOOL=		USE_CPP_PACKAGE
CPP_USES=		python:build
CPP_VARS=		BINARY_ALIAS=python=${PYTHON_CMD}

OPENCV_CMAKE_BOOL=	USE_OPENCV
OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv \
			libopencv_videoio.so:graphics/opencv

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_OFF+=	USE_SSE
.endif

xpost-patch:
	@${RM} ${WRKSRC}/include/mkldnn/*
.for h in dnnl.h dnnl.hpp mkldnn.h mkldnn.hpp mkldnn_dnnl_mangling.h mkldnn_types.h mkldnn_version.h
	@${LN} -s ${LOCALBASE}/include/${h} ${WRKSRC}/include/mkldnn/${h}
.endfor

post-install-CPP-on: # https://github.com/apache/incubator-mxnet/issues/17080
	@cd ${STAGEDIR}${PREFIX} && ${RM} include/mxnet-cpp/.gitignore include/mxnet-cpp/CPPLINT.cfg

.include <bsd.port.post.mk>
