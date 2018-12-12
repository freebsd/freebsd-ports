# $FreeBSD$

PORTNAME=	erkale
DISTVERSION=	g20181009
PORTREVISION=	2
CATEGORIES=	science
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry program to solve the electronic structure of atoms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	armadillo>0:math/armadillo
LIB_DEPENDS=	libderiv.so:science/libint \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libint.so:science/libint \
		libopenblas.so:math/openblas \
		libsz.so:science/szip \
		libxc.so:science/libxc

USES=		cmake:outsource,noninja fortran localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_TAGNAME=	f1e1ebc
USE_LDCONFIG=	yes

TEST_TARGET=	test # some tests fail: https://github.com/susilehtola/erkale/issues/29

CMAKE_ARGS=	-DLAPACK_LIBRARIES=-lopenblas -DBLAS_LIBRARIES=-lopenblasp
CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_BROKEN=		cmake can't fine OpenMP, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678

.include <bsd.port.mk>
