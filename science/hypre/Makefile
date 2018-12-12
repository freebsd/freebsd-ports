# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	hypre
DISTVERSIONPREFIX=	v
DISTVERSION=	2.15.1
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable Linear Solvers and Multigrid Methods

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../COPYING.LESSER

BROKEN_powerpc64=	fails to compile: ./DistributedMatrixPilutSolver.h:97:20: expected ')' before '->' token

USES=		blaslapack fortran gmake localbase # gmake is only for the 'test' target
USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	src

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas --with-blas-lib=${BLASLIB} \
		--with-lapack --with-lapack-lib=${LAPACKLIB} \
		--enable-shared

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH

NOMPI_DESC=		Build without parallel processing support
NOMPI_CONFIGURE_ON=	--without-MPI

MPICH_DESC=		Parallel processing support via MPICH
MPICH_LIB_DEPENDS=	libmpich.so:net/mpich
MPICH_CONFIGURE_ENV=	CC=${LOCALBASE}/bin/mpicc CXX=${LOCALBASE}/bin/mpicxx
MPICH_CONFIGURE_WITH=	MPI-include=${LOCALBASE}/include \
			MPI-lib-dirs=${LOCALBASE}/lib
OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi
OPENMPI_CONFIGURE_ENV=	CC=${LOCALBASE}/mpi/openmpi/bin/mpicc \
			CXX=${LOCALBASE}/mpi/openmpi/bin/mpicxx
OPENMPI_CONFIGURE_WITH=	MPI-include=${LOCALBASE}/mpi/openmpi/include \
			MPI-lib-dirs=${LOCALBASE}/mpi/openmpi/lib

TEST_TARGET=	check

SHL3=	${PORTVERSION}
SHL2=	${SHL3:R}
SHL1=	${SHL2:R}

do-install:
	${INSTALL_DATA} ${WRKSRC}/hypre/include/* ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/hypre/lib/libHYPRE-${SHL3}.so	\
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so.${SHL2}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libHYPRE.so.${SHL2} \
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so.${SHL1}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libHYPRE.so.${SHL2} \
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../docs/*.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
