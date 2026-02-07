PORTNAME=	hypre
DISTVERSIONPREFIX=	v
DISTVERSION=	2.33.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable Linear Solvers and Multigrid Methods
WWW=		https://computing.llnl.gov/projects/hypre-scalable-linear-solvers-multigrid-methods \
		https://github.com/hypre-space/hypre

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/../LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/../LICENSE-MIT

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

LIB_DEPENDS=	libsuperlu.so:math/superlu

USES=		blaslapack:openblas cmake:testing fortran localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	hypre-space

WRKSRC_SUBDIR=	src

CMAKE_ON=	BUILD_SHARED_LIBS HYPRE_ENABLE_OPENMP HYPRE_ENABLE_SUPERLU
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
NOMPI_CMAKE_ON=		-DHYPRE_ENABLE_MPI=OFF

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DHYPRE_ENABLE_MPI=ON

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DHYPRE_ENABLE_MPI=ON
OPENMPI_BROKEN=		doesn't switch to openmpi in cmake build, see https://github.com/hypre-space/hypre/issues/720

PORTDOCS=	*

xpost-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libHYPRE.so	\
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libHYPRE.so.0	\
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} usr-manual ${STAGEDIR}${DOCSDIR}

post-test: # run tests; unclear how to to run tests, see https://github.com/hypre-space/hypre/issues/502
.for t in ij ij_assembly ij_mv maxwell_unscaled
	@cd ${WRKSRC}/test && \
		${ECHO} "==> running test ${t}" && \
		${BUILD_WRKSRC}/test/${t}
.endfor

# the test ij_mv fails, see https://github.com/hypre-space/hypre/issues/1161

.include <bsd.port.mk>
