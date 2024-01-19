PORTNAME=	superlu-dist
DISTVERSIONPREFIX=	v
DISTVERSION=	8.2.1
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed memory, MPI based SuperLU
WWW=		https://portal.nersc.gov/project/sparse/superlu/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake:testing fortran pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	xiaoyeli
GH_PROJECT=	superlu_dist

CMAKE_ON=	USE_XSDK_DEFAULTS BUILD_SHARED_LIBS
CMAKE_OFF=	enable_tests enable_examples TPL_ENABLE_PARMETISLIB
CMAKE_TESTING_ON=	enable_tests # many tests fail, see https://github.com/xiaoyeli/superlu_dist/issues/113

OPTIONS_DEFINE=		DOCS FORTRAN
OPTIONS_SINGLE=		BLAS MPI
OPTIONS_SINGLE_BLAS=	ATLAS OPENBLAS REFERENCE
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	FORTRAN MPICH REFERENCE
OPTIONS_SUB=		yes

# all BLAS-related options
ATLAS_USES=		blaslapack:atlas
ATLAS_CMAKE_ON=		-DBLA_VENDOR:STRING="ATLAS"
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CMAKE_ON=	-DBLA_VENDOR:STRING="OpenBLAS"
REFERENCE_DESC=		Reference blas implementation
REFERENCE_USES=		blaslapack
REFERENCE_CMAKE_ON=	-DBLA_VENDOR:STRING="Generic"

# other options
FORTRAN_CMAKE_BOOL=	XSDK_ENABLE_Fortran
MPICH_USES=		mpi:mpich
OPENMPI_USES=		mpi:openmpi

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/DOC && ${COPYTREE_SHARE} "ug.pdf" ${STAGEDIR}${DOCSDIR}

post-install-FORTRAN-on:
	# workaround for https://github.com/xiaoyeli/superlu_dist/issues/112
	@${RM} -r ${STAGEDIR}${PREFIX}/include/FORTRAN/CMakeFiles
	# move .mod files to a proper location
	@cd ${STAGEDIR}${PREFIX}/include && \
		${MV} FORTRAN/* . && \
		${RMDIR} FORTRAN

.include <bsd.port.mk>
