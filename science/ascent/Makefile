PORTNAME=	ascent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	science
PKGNAMESUFFIX=	-visualizer

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization and analysis runtime for multi-physics HPC simulations

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libconduit.so:science/conduit \
		libhdf5.so:science/hdf5 \
		libsiloh5.so:science/silo \
		libsysinfo.so:devel/libsysinfo \
		libsz.so:science/libaec

USES=		cmake:testing compiler:c++11-lang fortran localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	Alpine-DAV
GH_TUPLE=	Alpine-DAV:spack_configs:26ea412:spack_configs/../scripts/uberenv_configs/spack_configs \
		LLNL:blt:86a7d6b:blt/blt \
		llnl:uberenv:105e384:uberenv/../scripts/uberenv

CMAKE_OFF=	ENABLE_PYTHON ENABLE_DOCS ENABLE_TESTS ENABLE_EXAMPLES
CMAKE_OFF+=	ENABLE_UTILS # utils are installed into a non-standard path, see https://github.com/Alpine-DAV/ascent/issues/814
CMAKE_OFF+=	ENABLE_MPI # MPI fails to link, see https://github.com/Alpine-DAV/ascent/issues/813
CMAKE_ARGS=	-DCONDUIT_DIR=${LOCALBASE}
CMAKE_TESTING_ON=	ENABLE_TESTS # one testcase fails because conduit lacks HDF5, see https://github.com/LLNL/conduit/issues/840

LDFLAGS+=	-lsysinfo

WRKSRC_SUBDIR=	src

.include <bsd.port.mk>
