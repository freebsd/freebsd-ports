PORTNAME=	caffe
DISTVERSION=	1.0-136
DISTVERSIONSUFFIX=	-g9b891540
PORTREVISION=	20
CATEGORIES=	misc # machine-learning

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	7f503bd9a19758a173064e299ab9d4cac65ed60f.patch:-p1 # opencv4 fix
PATCHFILES+=	1b317bab3f6413a1b5d87c9d3a300d785a4173f9.patch:-p1 # protobuf3 fix

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast open framework for deep learning
WWW=		https://caffe.berkeleyvision.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		${PYNUMPY}
LIB_DEPENDS=	libsnappy.so:archivers/snappy \
		libleveldb.so:databases/leveldb \
		liblmdb.so:databases/lmdb \
		libboost_system.so:devel/boost-libs \
		${PY_BOOST} \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf \
		libopencv_highgui.so:graphics/opencv \
		libopenblas.so:math/openblas \
		libhdf5.so:science/hdf5
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydot>0:graphics/py-pydot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydotplus>0:graphics/py-pydotplus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>0:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang fortran localbase:ldflags pkgconfig python
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	BVLC

CMAKE_ARGS=	-DBLAS=Open \
		-DPYTHON_EXECUTABLE=${PYTHON_CMD} \
		-DFREEBSD_PYTHONPREFIX_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR}
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT
LDFLAGS+=	-lpython${PYTHON_VER}

PORTSCOUT=	limit:^[0-9].*[0-9]$$ # should begin and end with a digit to prevent tags like rcnn-release and rc5

.include <bsd.port.mk>
