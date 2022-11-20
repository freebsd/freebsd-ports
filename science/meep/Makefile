PORTNAME=	meep
DISTVERSIONPREFIX=	v
DISTVERSION=	1.25.0
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
TEST_TARGET=	check

BINARY_ALIAS=	make=${GMAKE}

OPTIONS_DEFINE=			PYTHON
OPTIONS_DEFAULT=		PYTHON
OPTIONS_SUB=			yes

PYTHON_CONFIGURE_WITH=		python
PYTHON_CONFIGURE_ENABLE=	maintainer-mode
PYTHON_USES=			python
PYTHON_BUILD_DEPENDS=		swig:devel/swig

.include <bsd.port.mk>
