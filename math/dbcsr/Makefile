# $FreeBSD$

PORTNAME=	dbcsr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-rc.0-40
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gd9c0dd54
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed Block Compressed Sparse Row matrix library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fypp:devel/py-fypp@${PY_FLAVOR}

USES=		blaslapack:openblas cmake:noninja fortran python:build
USE_GITHUB=	yes
GH_ACCOUNT=	cp2k
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DBLA_VENDOR:STRING="OpenBLAS"

TEST_TARGET=	test # tests hang: https://github.com/cp2k/dbcsr/issues/72

OPTIONS_DEFINE=		MPI OPENMP C_API # libxsmm is supposed to be supported, but cmake build lacks the corresponding option: https://github.com/cp2k/dbcsr/issues/73
OPTIONS_DEFAULT=	MPI OPENMP C_API
OPTIONS_SUB=		yes

MPI_CMAKE_BOOL=		USE_MPI
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp

C_API_DESC=		Build the C API library
C_API_CMAKE_BOOL=	WITH_C_API

.include <bsd.port.mk>
