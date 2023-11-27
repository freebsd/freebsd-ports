PORTNAME=	pytorch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://github.com/pytorch/pytorch/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tensors and dynamic neural networks in Python (C++ library)
WWW=		https://pytorch.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

#BROKEN_aarch64=	configure fails: CMake Error at third_party/XNNPACK/CMakeLists.txt:94 (MESSAGE): Unrecognized CMAKE_SYSTEM_NAME = FreeBSD
#BROKEN_i386=	compilation fails: error: use of undeclared identifier 'AVX2'
#BROKEN_FreeBSD_14=	fails to compile calling a private constructor of class

BUILD_DEPENDS=	gmake:devel/gmake \
		${LOCALBASE}/include/fxdiv.h:devel/fxdiv
LIB_DEPENDS=	libopenblas.so:math/openblas \
		libmpi.so:net/openmpi \
		libonnx.so:misc/onnx \
		libpthreadpool.so:devel/pthreadpool \
		libprotobuf.so:devel/protobuf \
		libsleef.so:math/sleef

USES=		compiler:c++17-lang cmake localbase:ldflags python # requires python even with PYTHON=off

CMAKE_OFF=	BUILD_CUSTOM_PROTOBUF USE_CUDA USE_ROCM  USE_NNPACK USE_QNNPACK USE_PYTORCH_QNNPACK \
		USE_FBGEMM # workaround recommended by the upstream here: https://github.com/pytorch/pytorch/issues/28337
CMAKE_ON=	USE_SYSTEM_PYBIND11 \
		USE_SYSTEM_SLEEF \
		USE_SYSTEM_ONNX # see other USE_SYSTEM_xx in CMakeLists.txt
CMAKE_ARGS=	-DPSIMD_SOURCE_DIR=${WRKSRC}/third_party/psimd \
		-DFREEBSD_PYTHON_VER=${PYTHON_VER}

MAKE_ENV=	USE_NINJA=no # ninja breaks for some reason
LDFLAGS+=	-lexecinfo

BINARY_ALIAS=	make=${GMAKE} git=true

OPTIONS_DEFINE=		PYTHON # PYTHON only provides python support for the py-PyTorch port - it's not a python binding
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_PY_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
PYTHON_BUILD_DEPENDS=	${PYTHON_PY_DEPENDS} \
			pybind11>0:devel/pybind11
PYTHON_RUN_DEPENDS=	${PYTHON_PY_DEPENDS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif

post-patch:
	# replace malloc.h -> stdlib.h in many places
	@cd ${WRKSRC} && for f in $$(${GREP} -rl "include <malloc\.h>" * | ${GREP} -E "\.(c|cpp|h|hpp)$$"); do \
	  ${REINPLACE_CMD} -i'' -E "s|include <malloc\.h>|include <stdlib.h>|" $$f; \
	done

post-install:
	# functorch.so is installed back into the source directory, see https://github.com/pytorch/pytorch/issues/91524
	@${RM} $$(${FIND} ${STAGEDIR} -name functorch.so)
	# https://github.com/pytorch/pytorch/issues/24417
	@${FIND} ${STAGEDIR} -type d -empty -delete

.include <bsd.port.post.mk>
