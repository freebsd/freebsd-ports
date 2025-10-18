PORTNAME=	ascent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.5
CATEGORIES=	science
PKGNAMESUFFIX=	-visualizer

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization and analysis runtime for multi-physics HPC simulations
WWW=		https://ascent.readthedocs.io/en/latest/ \
		https://github.com/Alpine-DAV/ascent

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_FreeBSD_15=	compilation fails with clang-19, see https://github.com/Alpine-DAV/ascent/issues/1422

LIB_DEPENDS=	libconduit.so:science/conduit \
		libhdf5.so:science/hdf5 \
		libsiloh5.so:science/silo \
		libsysinfo.so:devel/libsysinfo \
		libsz.so:science/libaec

USES=		cmake:testing compiler:c++11-lang fortran localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	Alpine-DAV
GH_TUPLE=	Alpine-DAV:spack_configs:26ea412:spack_configs/../scripts/uberenv_configs/spack_configs \
		LLNL:blt:9ff7734:blt/blt \
		llnl:uberenv:105e384:uberenv/../scripts/uberenv

CMAKE_OFF=	ENABLE_PYTHON ENABLE_DOCS ENABLE_TESTS ENABLE_EXAMPLES
CMAKE_OFF+=	ENABLE_UTILS # utils are installed into a non-standard path, see https://github.com/Alpine-DAV/ascent/issues/814
CMAKE_ARGS=	-DCONDUIT_DIR=${LOCALBASE}
CMAKE_TESTING_ON=	ENABLE_TESTS # one testcase fails because conduit lacks HDF5, see https://github.com/LLNL/conduit/issues/840

LDFLAGS+=	-lsysinfo

WRKSRC_SUBDIR=	src

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH
OPTIONS_SUB=		yes

NOMPI_DESC=		Build without parallel processing support
NOMPI_CMAKE_ON=		-DENABLE_MPI=OFF

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DENABLE_MPI=ON

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DENABLE_MPI=ON
OPENMPI_BROKEN=		still chooses mpich, see https://github.com/Alpine-DAV/ascent/issues/1091

# tests as of 0.9.5: 100% tests passed, 0 tests failed out of 97

.include <bsd.port.mk>
