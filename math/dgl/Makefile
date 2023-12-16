PORTNAME=	dgl
DISTVERSION=	1.1.1
CATEGORIES=	math # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep Graph Library
WWW=		https://www.dgl.ai/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${BACKEND_DEPENDS} \
		bash:shells/bash \
		gmake:devel/gmake

USES=		cmake:testing compiler:c++17-lang localbase:ldflags python:build shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_TUPLE=	apache:tvm:b2e418c:tvm/third_party/tvm \
		dmlc:dlpack:e2bdd3b:dlpack/third_party/dlpack \
		dmlc:dmlc-core:bfad207:dmlc_core/third_party/dmlc-core \
		greg7mdp:parallel-hashmap:25293ce:phmap/third_party/phmap \
		herumi:xbyak:757e406:xbyak/third_party/xbyak \
		imneme:pcg-cpp:428802d:pcg/third_party/pcg \
		jlblancoc:nanoflann:4c47ca2:nanoflann/third_party/nanoflann \
		KarypisLab:METIS:1060348:metis/third_party/METIS \
			KarypisLab:GKlib:62de20c:metis_GKlib/third_party/METIS/GKlib \
		pytorch:tensorpipe:6042f1a:tensorpipe/third_party/tensorpipe \
			libuv:libuv:1dff88e:tensorpipe_libuv/third_party/tensorpipe/third_party/libuv \
			google:libnop:aa95422:tensorpipe_libnop/third_party/tensorpipe/third_party/libnop \
		hfp:libxsmm:8009060:libxsmm/third_party/libxsmm \
		NVIDIA:thrust:02931a3:thrust/third_party/thrust \
		google:googletest:f71fb4f:googletest/third_party/googletest

SHEBANG_GLOB=	*.sh

MAKE_ENV=	PYTHON=${PYTHON_CMD}
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	BUILD_CPP_TEST # tests fail to compile, see https://github.com/dmlc/dgl/issues/5664

BINARY_ALIAS=	make=${GMAKE} python3=${PYTHON_CMD}

PLIST_FILES=	lib/libdgl_metis.so # workaround for https://github.com/dmlc/dgl/issues/5666

OPTIONS_RADIO=			BACKEND
OPTIONS_RADIO_BACKEND=		PYTORCH TENSORFLOW MXNET
OPTIONS_DEFAULT=		PYTORCH

PYTORCH_DESC=			Use PyTorch backend
PYTORCH_VARS=			BACKEND_DEPENDS=${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
PYTORCH_MAKE_ENV=		DGLBACKEND=pytorch

TENSORFLOW_DESC=		Use TensorFlow backend
TENSORFLOW_VARS=		BACKEND_DEPENDS=${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVOR}
TENSORFLOW_MAKE_ENV=		DGLBACKEND=tensorflow
TENSORFLOW_CMAKE_ON=		-DBUILD_SPARSE=OFF

MXNET_DESC=			Use MXNET backend
MXNET_VARS=			BACKEND_DEPENDS=${PYTHON_PKGNAMEPREFIX}mxnet>0:misc/py-mxnet@${PY_FLAVOR}
MXNET_MAKE_ENV=			DGLBACKEND=mxnet

post-install: # workaround for https://github.com/dmlc/dgl/issues/5666
	${INSTALL_LIB} ${BUILD_WRKSRC}/third_party/METIS/libmetis/libdgl_metis.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
