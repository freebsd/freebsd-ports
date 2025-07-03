PORTNAME=	pytorch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.1
PORTREVISION=	10
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://github.com/pytorch/pytorch/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tensors and dynamic neural networks in Python (C++ library)
WWW=		https://pytorch.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: error: use of undeclared identifier 'AVX2'

BUILD_DEPENDS=	gmake:devel/gmake \
		${LOCALBASE}/include/fxdiv.h:devel/fxdiv \
		${PY_SETUPTOOLS}
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libblis.so:math/blis \
		libopenblas.so:math/openblas \
		libmpi_cxx.so:net/openmpi4 \
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
CMAKE_ON+=	ONNX_USE_LITE_PROTO # workaround for the protobuf-related failure described here: https://github.com/onnx/optimizer/issues/38
CMAKE_ARGS=	-DPSIMD_SOURCE_DIR=${WRKSRC}/third_party/psimd \
		-DPYTHON_EXECUTABLE=${PYTHON_CMD}

MAKE_ENV=	USE_NINJA=no # ninja breaks for some reason
LDFLAGS+=	-lexecinfo \
		-pthread

BINARY_ALIAS=	make=${GMAKE} git=true

OPTIONS_DEFINE=		PYTHON # PYTHON only provides python support for the py-PyTorch port - it's not a python binding
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_PY_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
PYTHON_BUILD_DEPENDS=	${PYTHON_PY_DEPENDS} \
			${PY_SETUPTOOLS} \
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
	# remove bundled fmt
	@${RM} -r ${WRKSRC}/third_party/fmt

post-install:
	# functorch.so is installed back into the source directory, see https://github.com/pytorch/pytorch/issues/91524
	@${RM} $$(${FIND} ${STAGEDIR} -name functorch.so)
	# https://github.com/pytorch/pytorch/issues/24417
	@${FIND} ${STAGEDIR} -type d -empty -delete

.include <bsd.port.post.mk>
