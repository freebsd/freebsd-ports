PORTNAME=	pytorch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://github.com/pytorch/pytorch/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: Tensors and dynamic neural networks in Python
WWW=		https://pytorch.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	build fails: CMake Error at third_party/QNNPACK/CMakeLists.txt:47 (MESSAGE): Unrecognized CMAKE_SYSTEM_NAME = FreeBSD
BROKEN_i386=	build fails: DispatchStub.cpp:162:29: [0m[0;1;31merror: [0m[1muse of undeclared identifier 'AVX2'[0m

BUILD_DEPENDS=	cmake:devel/cmake-core \
		gmake:devel/gmake \
		pybind11>0:devel/pybind11 \
		${PYNUMPY} \
		${LOCALBASE}/include/fxdiv.h:devel/fxdiv \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libblis.so:math/blis \
		libmpi.so:net/openmpi \
		libonnx.so:misc/onnx \
		libopenblas.so:math/openblas \
		libpthreadpool.so:devel/pthreadpool \
		libprotobuf.so:devel/protobuf \
		libsleef.so:math/sleef
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dill>0:devel/py-dill@${PY_FLAVOR} # optional dependency

USES=		compiler:c++17-lang localbase:ldflags python
USE_PYTHON=	distutils autoplist

MAKE_ENV=	USE_NINJA=no # ninja breaks for some reason
MAKE_ENV+=	BUILD_TEST=0 # ninja breaks for some reason
MAKE_ENV+=	USE_MKLDNN=0 # disable MKLDNN that doesn't exist, see https://github.com/pytorch/pytorch/issues/100957
MAKE_ENV+=	USE_CUDNN=0
LDFLAGS+=	-lexecinfo

BINARY_ALIAS=	make=${GMAKE}

POST_PLIST=	fix-plist

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
USES+=	llvm:max=15
.endif

post-install: # strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torch/bin/torch_shm_manager \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torch/_C${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/functorch/_C${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torch/lib/lib*.so

fix-plist: # remove the stray %%PYTHON_SITELIBDIR%%/caffe2 file
	@${REINPLACE_CMD} -e "s|.*/caffe2$$||" ${TMPPLIST}

.include <bsd.port.mk>
