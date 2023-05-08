PORTNAME=	pytorch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://github.com/pytorch/pytorch/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: Tensors and dynamic neural networks in Python
WWW=		https://pytorch.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		gmake:devel/gmake \
		pybind11>0:devel/pybind11 \
		${LOCALBASE}/include/fxdiv.h:devel/fxdiv \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libopenblas.so:math/openblas \
		libmpi.so:net/openmpi \
		libonnx.so:misc/onnx \
		libpthreadpool.so:devel/pthreadpool \
		libprotobuf.so:devel/protobuf \
		libsleef.so:math/sleef
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dill>0:devel/py-dill@${PY_FLAVOR} # optional dependency

USES=		compiler:c++14-lang localbase:ldflags python
USE_PYTHON=	distutils autoplist

MAKE_ENV=	USE_NINJA=no # ninja breaks for some reason
MAKE_ENV+=	BUILD_TEST=0 # ninja breaks for some reason
LDFLAGS+=	-lexecinfo

BINARY_ALIAS=	make=${GMAKE}

POST_PLIST=	fix-plist

post-install: # strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torch/bin/torch_shm_manager \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torch/_C${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torch/_C_flatbuffer${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/functorch/_C${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torch/lib/lib*.so

fix-plist: # remove the stray %%PYTHON_SITELIBDIR%%/caffe2 file
	@${REINPLACE_CMD} -e "s|.*/caffe2$$||" ${TMPPLIST}

.include <bsd.port.mk>
