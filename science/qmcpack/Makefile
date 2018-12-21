# $FreeBSD$

PORTNAME=	qmcpack
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.0
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

USES=		cmake:outsource compiler:c++11-lang fortran gnome localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
USE_GNOME=	libxml2

PROGS=		convert4qmc qmc-check-affinity qmc-extract-eshdf-kvectors qmc-get-supercell qmcpack
PLIST_FILES=	${PROGS:C/^/bin\//}

do-install:
.for p in ${PROGS}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/${p} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
