PORTNAME=	faiss
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.1
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for efficient similarity search & clustering of dense vectors
WWW=		https://github.com/facebookresearch/faiss

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BROKEN_i386=	clang crashes, see bug#261580

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
BUILD_DEPENDS=	swig:devel/swig \
		${PY_DEPENDS}
LIB_DEPENDS=	libfaiss.so:math/faiss
RUN_DEPENDS=	${PY_DEPENDS}

USES=		cmake compiler:c++11-lang localbase python
USE_PYTHON=	flavors pytest # tests fail to run, see https://github.com/facebookresearch/faiss/issues/3914

USE_GITHUB=	yes
GH_ACCOUNT=	facebookresearch

WRKSRC_SUBDIR=	faiss/python

CMAKE_ARGS=	-DPython_EXECUTABLE:STRING=${PYTHON_CMD}

TEST_WRKSRC=	${WRKSRC}/../../tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-patch: # remove GPU testcases
	@${RM} -r ${WRKSRC}/../../faiss/gpu

do-install: # see https://github.com/facebookresearch/faiss/issues/2194
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_LIB} ${BUILD_WRKSRC}/_swigfaiss.so ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
.for f in __init__.py array_conversions.py class_wrappers.py extra_wrappers.py gpu_wrappers.py loader.py swigfaiss.py
	${INSTALL_DATA} ${BUILD_WRKSRC}/${f} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
.endfor
	cd ${BUILD_WRKSRC} && ${COPYTREE_SHARE} contrib ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

# tests are broken, see https://github.com/facebookresearch/faiss/issues/4317

.include <bsd.port.mk>
