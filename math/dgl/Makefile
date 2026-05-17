PORTNAME=	dgl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
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
GH_TUPLE=	axboe:liburing:f7dcc1ea60819475dffd3a45059e16f04381bee7:liburing/third_party/liburing \
		dmlc:dlpack:e2bdd3bee8cb6501558042633fa59144cc8b7f5f:dlpack/third_party/dlpack \
		dmlc:dmlc-core:bfad207b448480783a1f428ae3d93d87032d8349:dmlc_core/third_party/dmlc-core \
		google:googletest:f8d7d77c06936315286eb55f8de22cd23c188571:googletest/third_party/googletest \
		hfp:libxsmm:80090603e43f6ddc870cc42e1403dd0af07744cc:libxsmm/third_party/libxsmm \
		imneme:pcg-cpp:428802d1a5634f96bcd0705fab379ff0113bcf13:pcg/third_party/pcg \
		jlblancoc:nanoflann:4c47ca200209550c5628c89803591f8a753c8181:nanoflann/third_party/nanoflann \
		KarypisLab:GKlib:8bd6bad750b2b0d90800c632cf18e8ee93ad72d7:gklib/third_party/GKlib \
		KarypisLab:METIS:e0f1b88b8efcb24ffa0ec55eabb78fbe61e58ae7:metis/third_party/METIS \
		NVIDIA:cccl:c67b1c3257be5115253f06d45a2d607b54234db4:cccl/third_party/cccl \
		NVIDIA:cuCollections:6c0d7ee190a167c6976af0f7c628a43d13b78f38:cuco/third_party/cuco \
		taskflow:taskflow:7d9e85b6b2e9bf501021f857f2f3cbe43bc37c85:taskflow/third_party/taskflow \
		Tessil:robin-map:1115dad3ffa0994e3f43b693d9b9cc99944c64c1:tsl_robin_map/third_party/tsl_robin_map

SHEBANG_GLOB=	*.sh

MAKE_ENV=	PYTHON=${PYTHON_CMD}
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_GRAPHBOLT \
		BUILD_CPP_TEST \
		USE_LIBXSMM

BINARY_ALIAS=	make=${GMAKE} python3=${PYTHON_CMD}

PLIST_FILES=	lib/libGKlib.so \
		lib/libdgl_metis.so # workaround for https://github.com/dmlc/dgl/issues/5666

OPTIONS_RADIO=			BACKEND
OPTIONS_RADIO_BACKEND=		PYTORCH TENSORFLOW
OPTIONS_DEFAULT=		PYTORCH

PYTORCH_DESC=			Use PyTorch backend
PYTORCH_VARS=			BACKEND_DEPENDS=${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
PYTORCH_MAKE_ENV=		DGLBACKEND=pytorch

TENSORFLOW_DESC=		Use TensorFlow backend
TENSORFLOW_VARS=		BACKEND_DEPENDS=${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVOR}
TENSORFLOW_MAKE_ENV=		DGLBACKEND=tensorflow
TENSORFLOW_CMAKE_ON=		-DBUILD_SPARSE=OFF

post-install: # workaround for https://github.com/dmlc/dgl/issues/5666
	${INSTALL_LIB} ${BUILD_WRKSRC}/libGKlib.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${BUILD_WRKSRC}/third_party/METIS/libmetis/libdgl_metis.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
