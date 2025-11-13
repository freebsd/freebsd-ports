PORTNAME=	mpifx
DISTVERSION=	1.5
CATEGORIES=	net devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern Fortran wrappers around MPI routines
WWW=		https://github.com/dftbplus/mpifx

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fypp:devel/py-fypp@${PY_FLAVOR}

USES=		cmake:testing fortran mpi:mpich python:build

USE_GITHUB=	yes
GH_ACCOUNT=	dftbplus

CMAKE_ON=	BUILD_SHARED_LIBS

post-patch:
	${REINPLACE_CMD} -e '/include(CTest)/d' ${WRKSRC}/CMakeLists.txt

post-test: # run test programs # at least one test crashes, see https://github.com/dftbplus/mpifx/issues/35
.for f in test_allgather test_allgatherv test_allreduce test_bcast test_comm_split test_gather test_gatherv test_reduce test_scatter test_scatterv
	cd ${BUILD_WRKSRC}/test && ./${f}
.endfor

.include <bsd.port.pre.mk>

.if ${FORTRAN_DEFAULT} == gfortran && ${GCC_DEFAULT} >= 10
# workaround for Type mismatch in argument 'cc' at (1); passed COMPLEX(8) to REAL(8)
FFLAGS+=	-fallow-argument-mismatch
.endif

# tests fail to run: https://github.com/dftbplus/mpifx/issues/49

.include <bsd.port.post.mk>
