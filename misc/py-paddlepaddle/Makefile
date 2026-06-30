# CAVEAT: it needs LD_LIBRARY_PATH=/usr/local/lib/python3.11/site-packages/paddle/libs for now in order for binaries to find the installed libs

PORTNAME=	paddlepaddle
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.1
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for PaddlePaddle deep learning framework
WWW=		https://www.paddlepaddle.org.cn/ \
		https://github.com/PaddlePaddle/Paddle

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git \
		gmake:devel/gmake \
		${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>=3.3.0:math/py-opt-einsum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.20.2:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11-stubgen>0:devel/py-pybind11-stubgen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>=0.6.0:misc/py-safetensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libopenblas.so:math/openblas \
		libsleef.so:math/sleef
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>=3.3.0:math/py-opt-einsum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.20.2:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>=0.6.0:misc/py-safetensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		gfortran${GCC_DEFAULT}:lang/gcc${GCC_DEFAULT}

USES=		cmake llvm:21 python
USE_PYTHON=	autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	PaddlePaddle
GH_PROJECT=	Paddle
GH_TUPLE=	\
		NVIDIA:cccl:1f6e4bcae0fbf1bbed87f88544d8d2161c490fc1:NVIDIA_cccl/third_party/cccl \
		weidai11:cryptopp:9dcc26c58213abb8351fbb1b2a7a1d2c667366e4:weidai11_cryptopp/third_party/cryptopp \
		noloader:cryptopp-cmake:6d0666c457fbbf6f81819fd2b80f0cb5b6646593:noloader_cryptopp_cmake/third_party/cryptopp-cmake \
		NVIDIA:cub:48b555897ee66bcd057a521ed39d62b7688c7d59:NVIDIA_cub/third_party/cub \
		NVIDIA:cutlass:eefa171318b79cbe2e78514d4cce5cd0fe919d0c:NVIDIA_cutlass/third_party/cutlass \
		dmlc:dlpack:84d107bf416c6bab9ae68ad285876600d230490d:dmlc_dlpack/third_party/dlpack \
		FlagOpen:FlagCX:7c469f4af991bf0f64b8f76d66f8e307a5eaea3f:FlagOpen_FlagCX/third_party/flagcx \
		PaddlePaddle:flash-attention:196115f865fc7f18a7ab55f32510415a788cb85d:PaddlePaddle_flash_attention/third_party/flashattn \
		gflags:gflags:e171aa2d15ed9eb17054558e0b3a6a413bb01067:gflags_gflags/third_party/gflags \
		google:glog:96a2f23dca4cc7180821ca5f32e526314395d26a:google_glog/third_party/glog \
		ziyoujiyi:gloo:8b6b61dfa0dca02b226a01262bfcf0484382048f:ziyoujiyi_gloo/third_party/gloo \
		google:googletest:2fe3bd994b3189899d93f1d5a881e725e046fdc2:google_googletest/third_party/gtest \
		NVIDIA:jitify:57de649139c866eb83acacfe50c92ad7c6278776:NVIDIA_jitify/third_party/jitify \
		libuv:libuv:2e7c07f4d10c1b391a7138471c49f4aae3c47d8d:libuv_libuv/third_party/libuv \
		nlohmann:json:199dea11b17c533721b26249e2dcaee6ca1d51d3:nlohmann_json/third_party/nlohmann_json \
		oneapi-src:oneDNN:28d696724426b943e2f4a0e607f90cdc19aedaf6:oneapi_src_oneDNN/third_party/onednn \
		xianyi:OpenBLAS:5f36f18148603facb6c3540e673610d6b24cbfbb:xianyi_OpenBLAS/third_party/openblas \
		openvinotoolkit:openvino:07ecdf07d2974410dc1d67d9fa2d3433dcab7865:openvinotoolkit_openvino/third_party/openvino \
		protocolbuffers:protobuf:f0dc78d7e6e331b8c6bb2d5283e06aa26883ca7c:protocolbuffers_protobuf/third_party/protobuf \
		pybind:pybind11:a2e59f0e7065404b44dfe92a28aca47ba1378dc4:pybind_pybind11/third_party/pybind \
		Thunderbrook:rocksdb:9e18bf0e273b081de54ef1227e6f1db9e02a472a:Thunderbrook_rocksdb/third_party/rocksdb \
		progschj:ThreadPool:9a42ec1329f259a5f4881a291db1dcb8f2ad9040:progschj_ThreadPool/third_party/threadpool \
		JuliaStrings:utf8proc:3203baa7374d67132384e2830b2183c92351bffc:JuliaStrings_utf8proc/third_party/utf8proc \
		baidu-research:warp-ctc:bdc2b4550453e0ef2d3b5190f9c6103a84eff184:baidu_research_warp_ctc/third_party/warpctc \
		PaddlePaddle:warp-transducer:7ea6bfe748779c245a0fcaa5dd9383826273eff2:PaddlePaddle_warp_transducer/third_party/warprnnt \
		herumi:xbyak:4ca0434b4e78c05e3f3e68bda70e8713668e87d3:herumi_xbyak/third_party/xbyak \
		Cyan4973:xxHash:7cc9639699f64b750c0b82333dced9ea77e8436e:Cyan4973_xxHash/third_party/xxhash \
		jbeder:yaml-cpp:1d8ca1f35eb3a9c9142462b28282a848e5d29a91:jbeder_yaml_cpp/third_party/yaml-cpp \
		madler:zlib:51b7f2abdade71cd9bb0e7a373ef2610ec6f9daf:madler_zlib/third_party/zlib
USE_GITLAB=	nodefault
GL_TUPLE=	\
		libeigen:eigen:f612df273689a19d25b45ca4f8269463207c4fee:libeigen_eigen/third_party/eigen3 \
		https://gitlab.mpcdf.mpg.de:mtr:pocketfft:ea778e37710c07723435b1be58235996d1d43a5a:mtr_pocketfft/third_party/pocketfft

CMAKE_ON=	WITH_PYTHON
# WITH_MKL includes MKLML (precompiled Linux binaries: libiomp5.so, libmklml_intel.so)
# that require libpthread.so.0, which does not exist on FreeBSD. Use OpenBLAS instead.
CMAKE_OFF=	WITH_MKL
# Point cmake to the system OpenBLAS in /usr/local so it finds cblas.h,
# lapacke.h, and openblas_config.h without building OpenBLAS from source.
CMAKE_ARGS+=	-DOPENBLAS_ROOT=${LOCALBASE}

# On clang 19 (poudriere), check_cxx_compiler_flag(-fPIC) fails so paddle's
# cmake/flags.cmake does not add -fPIC to CMAKE_CXX_FLAGS.  Force PIC globally
# via the cmake-native mechanism so all targets (shared and static) compile with
# position-independent code, which is required when static archives are later
# linked into libphi_core.so.
CMAKE_ARGS+=	-DCMAKE_POSITION_INDEPENDENT_CODE=ON

# cmake ExternalProject installs happen during the build phase. FreeBSD's
# ports system sets DESTDIR=${STAGEDIR} in MAKE_ENV (via ninja.mk) for
# staging, but cmake ExternalProject uses $ENV{DESTDIR} as prefix, causing
# third-party library installs to go to ${STAGEDIR}${INSTALL_DIR} instead of
# ${INSTALL_DIR}. Strip DESTDIR from the build environment so all ExternalProject
# installs land in the correct paths during the build phase.
DO_MAKE_BUILD=	${SETENVI} ${WRK_ENV} ${MAKE_ENV:NDESTDIR=*} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS:N${DESTDIRNAME}=*}

# PaddlePaddle's phi/common headers specialise std::is_pod, is_floating_point,
# is_signed, is_unsigned for custom numeric types (float16, bfloat16, float8,
# complex). Clang 17+ marks these standard traits _LIBCPP_NO_SPECIALIZATIONS
# which triggers -Winvalid-specialization as an error. Suppress globally.
CXXFLAGS+=	-Wno-invalid-specialization

CFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS
CXXFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS

WHEEL_TAG=	${:!uname -rm | sed -e 's/[.-]/_/g' -e 's/ /_/g' -e 's/^/freebsd_/' | tr '[:upper:]' '[:lower:]'!}
PLIST_SUB+=	WHEEL_TAG=${WHEEL_TAG}

#MAKE_JOBS_UNSAFE= 	yes

# The cmake build generates CMakeLists.txt files in the source tree (at configure
# time) that are listed as cmake RERUN_CMAKE dependencies. cmake uses
# copy-if-different when writing build.ninja, so build.ninja keeps its old mtime
# if its content hasn't changed. This causes ninja to see those generated files
# as newer than build.ninja and loop on cmake regeneration. Touch build.ninja
# after configure to ensure it is always the newest file.
post-configure:
	@${TOUCH} ${CONFIGURE_WRKSRC}/build.ninja

# The cmake build places Python modules under opt/paddle/share/wheels,
# but they need to be in Python site-packages. Run setup.py from the
# build directory to place Python modules into STAGEDIR.
post-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	cd ${BUILD_WRKSRC}/python && \
		${SETENV} ${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		${PYTHON_CMD} setup.py install \
		--root=${STAGEDIR} \
		--prefix=${PREFIX} \
		--single-version-externally-managed
	@${REINPLACE_CMD} -e '1s|#!/bin/bash|#!/usr/local/bin/bash|' \
		${STAGEDIR}${PREFIX}/bin/paddle
	@${RM} ${STAGEDIR}${PREFIX}/bin/paddle.bak

.include <bsd.port.mk>
