# $FreeBSD$

PORTNAME=	openturns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Uncertainty treatment library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		flex:textproc/flex
LIB_DEPENDS=	libceres.so:math/ceres-solver \
		libcminpack.so:math/cminpack \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libnlopt.so:math/nlopt \
		libopt.so:math/optpp \
		libtbb.so:devel/tbb \
		libhmat-oss.so:math/hmat-oss

USES=		bison blaslapack:openblas cmake compiler:c++11-lang eigen:3 gnome localbase:ldflags pkgconfig
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBLAS_LIBRARIES=${LOCALBASE}/lib/libopenblas.so -DLAPACK_LIBRARIES=${LOCALBASE}/lib/libopenblas.so \
		-DOPENTURNS_EXAMPLE_PATH:STRING=share/examples/openturns \
		-DOPENTURNS_DOC_PATH:STRING=share/doc/openturns
CMAKE_OFF=	USE_DOXYGEN USE_SPHINX

OPTIONS_DEFINE=		PYTHON EXAMPLES
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_CMAKE_ON=	-DSWIG_EXECUTABLE=${LOCALBASE}/bin/swig3.0
PYTHON_BUILD_DEPENDS=	swig3.0:devel/swig30 \
			${PYTHON_RUN_DEPENDS}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

PORTEXAMPLES=		*

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
