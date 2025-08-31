PORTNAME=	dgl
DISTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	math python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep Graph Library
WWW=		https://www.dgl.ai/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${BACKEND_DEPENDS}
LIB_DEPENDS=	libdgl.so:math/dgl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>=2.1:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.8.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${BACKEND_DEPENDS}

USES=		python localbase
USE_PYTHON=	distutils cython autoplist

WRKSRC_SUBDIR=	python

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc

MAKE_ENV=	DGL_LIBRARY_PATH=${LOCALBASE}/lib

POST_PLIST=	fix-plist

OPTIONS_RADIO=			BACKEND
OPTIONS_RADIO_BACKEND=		PYTORCH TENSORFLOW
OPTIONS_DEFAULT=		PYTORCH

PYTORCH_DESC=			Use PyTorch backend
PYTORCH_VARS=			BACKEND_DEPENDS=${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
PYTORCH_MAKE_ENV=		DGLBACKEND=pytorch

TENSORFLOW_DESC=		Use TensorFlow backend
TENSORFLOW_VARS=		BACKEND_DEPENDS=${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVOR}
TENSORFLOW_MAKE_ENV=		DGLBACKEND=tensorflow

post-install:
	# workaround for https://github.com/dmlc/dgl/issues/5665
	@${RM} ${STAGEDIR}${PREFIX}/dgl/libdgl.so
	# remove empty dirs
	@${RMDIR} \
		${STAGEDIR}${PREFIX}/dgl/tensoradapter/pytorch \
		${STAGEDIR}${PREFIX}/dgl/tensoradapter \
		${STAGEDIR}${PREFIX}/dgl/dgl_sparse \
		${STAGEDIR}${PREFIX}/dgl
	# strip binaries
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dgl/_ffi/_cy3/core${PYTHON_TAG}.so

fix-plist:
	# workaround for https://github.com/dmlc/dgl/issues/5665
	@${REINPLACE_CMD} ' \
		/dgl\/libdgl.so/d ; \
		' ${TMPPLIST}
	# remove empty dirs
	@${REINPLACE_CMD} ' \
		/dgl\/tensoradapter\/pytorch/d ; \
		/dgl\/dgl_sparse/d ; \
		' ${TMPPLIST}

.include <bsd.port.mk>
