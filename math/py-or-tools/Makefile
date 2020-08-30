# $FreeBSD$

PORTNAME=	or-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	7.7
PORTREVISION=	2
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google's Operations Research tools (Python binding)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-2.0.txt

BROKEN_i386=	SWIG wrapped code invalid in 32 bit architecture, regenerate code using -DSWIGWORDSIZE32 # see https://github.com/google/or-tools/issues/2130

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR} \
		swig:devel/swig
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libOsiClp.so:math/clp \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	${PY_DEPENDS}

USES=		blaslapack cmake compiler:c++11-lang pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_PYTHON=	flavors

CMAKE_OFF=	BUILD_DEPS INSTALL_BUILD_DEPS BUILD_EXAMPLES
CMAKE_ON=	BUILD_PYTHON
CMAKE_ARGS=	-DSWIG_EXECUTABLE=${LOCALBASE}/bin/swig -DFREEBSD_PYTHON_VER=${PYTHON_VER}
CONFIGURE_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}
BUILD_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}

post-configure: # https://github.com/google/or-tools/issues/2109
	@${REINPLACE_CMD} -e 's|protobuf::protoc|protoc -I${LOCALBASE}/include| ; s|protobuf$$:$$:protoc||' ${BUILD_WRKSRC}/build.ninja

do-install: # by default cmake installs the whole or-tools project without the python part, so extract the wheel and install python files manually here
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && \
		unzip ${BUILD_WRKSRC}/python/dist/ortools-${DISTVERSION}*.whl && \
		${RM} -rf ortools-*.dist-info
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name "*.so" -o -name "*.so.*" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
