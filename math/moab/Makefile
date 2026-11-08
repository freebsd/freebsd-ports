PORTNAME=	moab
DISTVERSION=	5.6.0
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Component for representing and evaluating mesh data
WWW=		https://sigma.mcs.anl.gov/moab-library/ \
		https://bitbucket.org/fathomteam/moab/src/master/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libopenblas.so:math/openblas

USES=		cmake:testing eigen:3 fortran
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DLAPACK_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DFREEBSD_STAGEDIR:STRING=${STAGEDIR}
CMAKE_OFF=		ENABLE_TESTING
CMAKE_TESTING_ON=	ENABLE_TESTING

BB_ACCOUNT=	fathomteam
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	3fa8ae9e8025

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

OPTIONS_DEFINE=		MPI
OPTIONS_DEFAULT=	MPI
OPTIONS_SUB=		yes

MPI_CMAKE_BOOL=		ENABLE_MPI
MPI_LIB_DEPENDS=	libmpi_cxx.so:net/openmpi4
MPI_VARS=		CXX=${LOCALBASE}/mpi/openmpi/bin/mpic++ CC=${LOCALBASE}/mpi/openmpi/bin/mpicc
MPI_VARS+=		CONFLICTS_BUILD=mpich # otherwise bin/hexmodops gets linked with libmpi.so:net/mpich
MPI_VARS_OFF=		USES+=compiler:c++11-lang

post-install:
	# docs are just readmes
	@${RM} -r ${STAGEDIR}${DOCSDIR}
	# examples are installed into a wrong location, maybe fix them later?
	@${RM} -r ${STAGEDIR}${PREFIX}/share/examples

# tests as of 5.6.0: 98% tests passed, 1 tests failed out of 52 (the bitnucket issues page says that they will disappear soon, which is weird, so we coundn't report the test failure)

.include <bsd.port.mk>
