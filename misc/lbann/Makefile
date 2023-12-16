PORTNAME=	lbann
DISTVERSIONPREFIX=	v
DISTVERSION=	0.102-254
DISTVERSIONSUFFIX=	-g2e3012a9a
PORTREVISION=	4
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Livermore Big Artificial Neural Network toolkit
WWW=		https://github.com/LLNL/lbann

LICENSE=	APACHE20

BUILD_DEPENDS=	cereal>0:devel/cereal \
		dihydrogen>0:math/dihydrogen \
		zstr>0:archivers/zstr
LIB_DEPENDS=	libconduit.so:science/conduit \
		libhdf5.so:science/hdf5 \
		libHydrogen_CXX.so:math/hydrogen \
		libopenblas.so:math/openblas \
		libprotobuf.so:devel/protobuf \
		libsiloh5.so:science/silo

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TUPLE=	KIwabuchi:havoqgt:100f63b:havoqgt/applications/graph/node2vec/havoqgt \
		samadejacobs:moses:28932ce:moses/applications/ATOM/moses \
		snap-stanford:snap:58a1e6a:snap/applications/graph/node2vec/snap \
		catchorg:Clara:2bfd8b2:clara

CMAKE_ARGS=	-DCLARA_INCLUDE_PATH=${WRKSRC_clara}/include
CMAKE_OFF=	LBANN_WITH_CNPY \
		LBANN_WITH_CUDNN \
		LBANN_WITH_HWLOC \
		LBANN_WITH_PYTHON_FRONTEND \
		LBANN_WITH_EMBEDDED_PYTHON \
		LBANN_WITH_VISION \
		LBANN_WITH_TBINF
CMAKE_ON=	LBANN_USE_PROTOBUF_MODULE
CMAKE_TESTING_ON=	LBANN_WITH_UNIT_TESTING # requires MPI cluster

LDFLAGS+=	-labsl_hash -labsl_log_internal_message -labsl_log_internal_nullguard -labsl_spinlock_wait -lexecinfo
USE_CXXSTD=	c++17

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH # should be same as in conduit, hydrogen, dihydrogen

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

post-install: # remove unnecessary files
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
