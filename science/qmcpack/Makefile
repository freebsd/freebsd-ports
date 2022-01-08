PORTNAME=	qmcpack
DISTVERSIONPREFIX=	v
DISTVERSION=	3.12.0-217 # 3.12.0 is broken: https://github.com/QMCPACK/qmcpack/issues/3698
DISTVERSIONSUFFIX=	-g0297e8705
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Many-body ab initio Quantum Monte Carlo code for quantum chemistry

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	undefined reference to `__atomic_load'

BUILD_DEPENDS=	catch>0:devel/catch
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libhdf5.so:science/hdf5 \
		libmpich.so:net/mpich \
		libopenblas.so:math/openblas \
		libsz.so:science/szip

USES=		cmake:testing compiler:c++11-lang fortran gnome localbase:ldflags pkgconfig python:build
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}

CMAKE_OFF=	BUILD_UNIT_TESTS
CMAKE_TESTING_ON=	BUILD_UNIT_TESTS # at least 3 testcases are known to fail

CXXFLAGS+=	-I${LOCALBASE}/include/catch2

PROGS=		convert4qmc convertpw4qmc qmc-check-affinity qmc-extract-eshdf-kvectors qmc-get-supercell qmcfinitesize qmcpack qmcpack.settings
PLIST_FILES=	${PROGS:C/^/bin\//}

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.mk>
