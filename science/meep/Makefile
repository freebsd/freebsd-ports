PORTNAME=	meep
DISTVERSIONPREFIX=	v
DISTVERSION=	1.24.0
CATEGORIES=	science cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finite-difference time-domain software for electromagnetic simulations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libharminv.a:science/harminv
LIB_DEPENDS=	libblas.so:math/blas \
		libctlgeom.so:science/libctl \
		libfftw3.so:math/fftw3 \
		libhdf5.so:science/hdf5 \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas

USES=		autoreconf compiler:c++11-lang fortran gmake libtool localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	NanoComp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-scheme \
		--without-python

CXXFLAGS_i386=	-msse2 # to fix this error: '_mm_getcsr' needs target feature sse

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

BINARY_ALIAS=	make=${GMAKE}

.include <bsd.port.mk>
