# $FreeBSD$

PORTNAME=	qmcpack
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.0
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Many-body ab initio Quantum Monte Carlo code for quantum chemstry

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	undefined reference to `__atomic_load'

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libhdf5.so:science/hdf5 \
		libmpich.so:net/mpich \
		libomp.so:devel/openmp \
		libopenblas.so:math/openblas \
		libsz.so:science/szip

USES=		cmake compiler:c++11-lang fortran gnome localbase:ldflags pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
USE_GNOME=	libxml2

PROGS=		convert4qmc qmc-check-affinity qmc-extract-eshdf-kvectors qmc-get-supercell qmcpack
PLIST_FILES=	${PROGS:C/^/bin\//}

BINARY_ALIAS=	python=${PYTHON_CMD}

do-install:
.for p in ${PROGS}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/${p} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
