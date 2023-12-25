PORTNAME=	scorec-core
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.8
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parallel finite element unstructured meshes
WWW=		https://github.com/SCOREC/core

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	\
		libepoll-shim.so:devel/libepoll-shim \
		libfabric.so:net/libfabric \
		libhwloc.so:devel/hwloc2 \
		libjson-c.so:devel/json-c \
		libze_loader.so:devel/level-zero

USES=		cmake:testing compiler:c++11-lang pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SCOREC
GH_PROJECT=	core
GH_TUPLE=	SCOREC:pumi-meshes:7b84de7:meshes/pumi-meshes

CFLAGS+=	${MPI_CFLAGS}
CXXFLAGS+=	${MPI_CFLAGS}
LDFLAGS+=	${MPI_LIBS}

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	IS_TESTING # some tests fail possibly because they need a larger MPI cluster

OPTIONS_DEFINE=		FORTRAN
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	FORTRAN MPICH
OPTIONS_SUB=		yes

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	PUMI_FORTRAN_INTERFACE

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

PORTSCOUT=	limit:^.*[0-9]\.[0-9].* # prevent tags like remove_viz

# 3 tests fail, see https://github.com/SCOREC/core/issues/410

.include <bsd.port.mk>
