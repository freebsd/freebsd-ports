# $FreeBSD$

PORTNAME=	mxnet
DISTVERSION=	1.6.0
DISTVERSIONSUFFIX=	.rc0
PORTREVISION=	5
CATEGORIES=	misc # machine-learning

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	cbd43cab6eef8362bcb1cc91e59b49045c90444c.patch:-p1 \
		89c180d47b407913f0a9948d6e7f55daa523e7aa.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Apache MXNet: Ultra-scalable deep learning framework

LICENSE=	APACHE20

BUILD_DEPENDS=	googletest>0:devel/googletest \
		${LOCALBASE}/include/dnnl.h:math/mkl-dnn
LIB_DEPENDS=	libdmlc.so:devel/dmlc-core \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	incubator-mxnet
GH_TUPLE=	apache:incubator-tvm:5d66e7a:tvm/3rdparty/tvm \
		dmlc:dlpack:b90e939:dlpack/3rdparty/dlpack
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
OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv-core \
			libopencv_videoio.so:graphics/opencv

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_OFF+=	USE_SSE
.endif

post-patch:
.for lib in mkldnn.h mkldnn_types.h
	@${RM} ${WRKSRC}/include/mkldnn/${lib}
	@${LN} -s ${LOCALBASE}/include/dnnl.h ${WRKSRC}/include/mkldnn/${lib}
.endfor

post-install-CPP-on: # https://github.com/apache/incubator-mxnet/issues/17080
	@cd ${STAGEDIR}${PREFIX} && ${RM} include/mxnet-cpp/.gitignore include/mxnet-cpp/CPPLINT.cfg

.include <bsd.port.post.mk>
