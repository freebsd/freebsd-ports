PORTNAME=	openturns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Uncertainty treatment library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		flex:textproc/flex \
		spectra>0:math/spectra
LIB_DEPENDS=	libbonmin.so:math/bonmin \
		libceres.so:math/ceres-solver \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libcminpack.so:math/cminpack \
		libCoinUtils.so:math/coinutils \
		libdlib.so:science/dlib-cpp \
		libgif.so:graphics/giflib \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libhdf5_cpp.so:science/hdf5 \
		libipopt.so:math/ipopt \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libnlopt.so:math/nlopt \
		libopt.so:math/optpp \
		libOsi.so:math/osi \
		libpng16.so:graphics/png \
		libsz.so:science/szip \
		libtbb.so:devel/onetbb

USES=		bison blaslapack:openblas cmake compiler:c++14-lang eigen:3 gnome jpeg localbase:ldflags pkgconfig sqlite xorg
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBLAS_LIBRARIES=${LOCALBASE}/lib/libopenblas.so -DLAPACK_LIBRARIES=${LOCALBASE}/lib/libopenblas.so \
		-DOPENTURNS_EXAMPLE_PATH:STRING=share/examples/openturns \
		-DOPENTURNS_DOC_PATH:STRING=share/doc/openturns
CMAKE_OFF=	USE_DOXYGEN USE_SPHINX
CMAKE_OFF+=	USE_HMAT # broken with hmat-oss-1.7.1: https://github.com/openturns/openturns/issues/1868

OPTIONS_DEFINE=		PYTHON EXAMPLES
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_CMAKE_ON=	-DSWIG_EXECUTABLE=${LOCALBASE}/bin/swig
PYTHON_PY_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}chaospy>0:math/py-chaospy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}dill>0:devel/py-dill@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
PYTHON_BUILD_DEPENDS=	swig:devel/swig \
			${PYTHON_PY_DEPENDS}
PYTHON_RUN_DEPENDS=	${PYTHON_PY_DEPENDS}

PORTEXAMPLES=		*

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
