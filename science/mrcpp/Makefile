PORTNAME=	mrcpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MultiResolution Computation Program Package
WWW=		https://github.com/MRChemSoft/mrcpp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++14-lang eigen:3
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	MRChemSoft
GH_TAGNAME=	e865a7e

CMAKE_OFF=	ENABLE_TESTS
CMAKE_TESTING_ON=	ENABLE_TESTS

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		ARCH_FLAGS
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH # should be same default as in science/mrchem

ARCH_FLAGS_DESC=	Enable architecture-specific compiler flags
ARCH_FLAGS_CMAKE_BOOL=	ENABLE_ARCH_FLAGS

NOMPI_DESC=		Build without parallel processing support

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DENABLE_MPI=ON

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DENABLE_MPI=ON

.include <bsd.port.mk>
