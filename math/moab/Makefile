PORTNAME=	moab
DISTVERSION=	5.3.1
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Component for representing and evaluating mesh data
WWW=		https://press3.mcs.anl.gov/sigma/moab-library/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libopenblas.so:math/openblas

USES=		cmake eigen:3 fortran
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DLAPACK_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DFREEBSD_STAGEDIR:STRING=${STAGEDIR}

BB_ACCOUNT=	fathomteam
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	65880ffe833d

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

OPTIONS_DEFINE=		MPI
OPTIONS_DEFAULT=	MPI
OPTIONS_SUB=		yes

MPI_CMAKE_BOOL=		ENABLE_MPI
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi
MPI_VARS=		CXX=${LOCALBASE}/mpi/openmpi/bin/mpic++ CC=${LOCALBASE}/mpi/openmpi/bin/mpicc
MPI_VARS+=		CONFLICTS_BUILD=mpich # otherwise bin/hexmodops gets linked with libmpi.so:net/mpich
MPI_VARS_OFF=		USES=compiler:c++11-lang

post-install:
	# docs are just readmes
	@${RM} -r ${STAGEDIR}${DOCSDIR}
	# examples are installed into a wrong location, maybe fix them later?
	@${RM} -r ${STAGEDIR}${PREFIX}/share/examples

.include <bsd.port.mk>
