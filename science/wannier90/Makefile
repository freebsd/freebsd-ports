PORTNAME=	wannier90
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Maximally-localized Wannier functions (MLWFs) and Wannier90
WWW=		http://www.wannier.org/ \
		https://github.com/wannier-developers/wannier90

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	gmake:devel/gmake

USES=		cmake:testing blaslapack:netlib fortran python:test shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wannier-developers

SHEBANG_FILES=	test-suite/run_tests test-suite/clean_tests
SHEBANG_GLOB=	*.py

CMAKE_OFF=		WANNIER90_TEST
CMAKE_TESTING_ON=	WANNIER90_TEST

OPTIONS_DEFINE=		WITH_C
OPTIONS_DEFAULT=	WITH_C
OPTIONS_RADIO=		BLAS_SIZE MPI
OPTIONS_RADIO_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT+=	NOMPI
OPTIONS_SUB=		yes

WITH_C_DESC=		Build C interface
WITH_C_CMAKE_BOOL=	WANNIER90_WITH_C
WITH_C_CFLAGS=		-I${LOCALBASE}/include/gcc${GCC_DEFAULT}

NOMPI_DESC=		MPI isn't used

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DWANNIER90_MPI=ON -DWANNIER90_MPIH=ON
BUILD_LIB_DEPENDS=	libmpich.so:net/mpich
MPICH_LIB_DEPENDS=	libmpich.so:net/mpich
MMPICH_BROKEN=		https://github.com/wannier-developers/wannier90/issues/662

OPENMPI_USES=		mpi:mpich
OPENMPI_CMAKE_ON=	-DWANNIER90_MPI=ON -DWANNIER90_MPIH=ON
OPENMPI_BUILD_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_RUN_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_BROKEN=		https://github.com/wannier-developers/wannier90/issues/662

# tests as of 4.0.1: 100% tests passed, 0 tests failed out of 93

.include <bsd.port.mk>
