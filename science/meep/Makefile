PORTNAME=	meep
DISTVERSIONPREFIX=	v
DISTVERSION=	1.28.0
CATEGORIES=	science cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finite-difference time-domain software for electromagnetic simulations
WWW=		https://github.com/NanoComp/meep

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libharminv.a:science/harminv
LIB_DEPENDS=	libblas.so:math/blas \
		libctlgeom.so:science/libctl \
		libfftw3.so:math/fftw3 \
		libGDSII.so:cad/libgdsii \
		libhdf5.so:science/hdf5 \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas

USES=		autoreconf compiler:c++11-lang fortran gmake libtool localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	NanoComp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-scheme

CXXFLAGS_i386=	-msse2 # to fix this error: '_mm_getcsr' needs target feature sse

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # some python binding's tests fail due to bug#270105 (in needed dependency science/mpb) and https://github.com/NanoComp/meep/issues/2434

BINARY_ALIAS=	make=${GMAKE}

OPTIONS_DEFINE=			PYTHON
OPTIONS_DEFAULT=		PYTHON
OPTIONS_SUB=			yes

PYTHON_CONFIGURE_WITH=		python
PYTHON_CONFIGURE_ENABLE=	maintainer-mode
PYTHON_USES=			python
PYTHON_BUILD_DEPENDS=		swig:devel/swig
PYTHON_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}autograd>0:math/py-autograd@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}jax>0:math/py-jax@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
				${PYNUMPY} \
				${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

.include <bsd.port.mk>
