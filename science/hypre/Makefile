PORTNAME=	hypre
DISTVERSIONPREFIX=	v
DISTVERSION=	2.31.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable Linear Solvers and Multigrid Methods
WWW=		https://computing.llnl.gov/projects/hypre-scalable-linear-solvers-multigrid-methods

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/../LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/../LICENSE-MIT

LIB_DEPENDS=	libsuperlu.so:math/superlu

USES=		blaslapack:openblas cmake:testing fortran localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	hypre-space

WRKSRC_SUBDIR=	src

CMAKE_ON=	HYPRE_ENABLE_SHARED HYPRE_WITH_OPENMP HYPRE_WITH_SUPERLU
CMAKE_OFF=	HYPRE_ENABLE_HYPRE_BLAS HYPRE_ENABLE_HYPRE_LAPACK
CMAKE_ARGS=	-DTPL_BLAS_LIBRARIES="${_BLASLIB}"	\
		-DTPL_SUPERLU_LIBRARIES="${LOCALBASE}/lib/libsuperlu.so"	\
		-DTPL_SUPERLU_INCLUDE_DIRS="${LOCALBASE}/include/superlu"
CMAKE_TESTING_ON=	HYPRE_BUILD_TESTS # tests are only built and not run, see https://github.com/hypre-space/hypre/issues/502

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH

NOMPI_DESC=		Build without parallel processing support
NOMPI_CMAKE_ON=		-DHYPRE_WITH_MPI=OFF

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DHYPRE_WITH_MPI=ON

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DHYPRE_WITH_MPI=ON
OPENMPI_BROKEN=		doesn't switch to openmpi in cmake build, see https://github.com/hypre-space/hypre/issues/720

PORTDOCS=	*

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libHYPRE.so	\
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libHYPRE.so.0	\
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} usr-manual ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
