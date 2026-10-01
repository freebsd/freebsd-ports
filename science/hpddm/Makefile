PORTNAME=	HPDDM
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Framework for high-performance domain decomposition methods
WWW=		https://github.com/hpddm/hpddm

LICENSE=	LGPL3

BUILD_DEPENDS=	${PY_DEPENDS}
LIB_DEPENDS=	libarpack.so:math/arpack-ng	\
		libscalapack.so:math/scalapack
RUN_DEPENDS=	bash:shells/bash	\
		${PY_DEPENDS}
PY_DEPENDS=	${MPI4PY}	\
		${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}

USES=		blaslapack:openblas fortran gmake mpi:openmpi python shebangfix
SHEBANG_FILES=	examples/payload.sh
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl}
GH_PROJECT=	${GH_ACCOUNT}

CXXFLAGS+=	-std=c++11 -fPIC
CFLAGS+=	-std=c99
USE_LDCONFIG=	yes

# Remark: set OMPI_FC for OpenMPI or MPICH_F90 for MPICH
MAKE_ENV=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR}	\
		PYTHON_LIBDIR=${PYTHON_LIBDIR}	\
		PYTHON_VER=${PYTHON_VER}	\
		BLASLIB=${BLASLIB}	\
		EIGENSOLVER=ARPACK	\
		MPICXX=${MPICXX}	\
		MPICC=${MPICC}		\
		MPIF90=${MPIF90}	\
		MPIRUN="${MPIRUN} -np"	\
		MPI_LIBS="${MPI_LIBS}"	\
		OMPI_FC=${FC}

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_RADIO=	SOLVER
OPTIONS_RADIO_SOLVER=	MUMPS SUITESPARSE
OPTIONS_DEFAULT=	MUMPS

MUMPS_DESC=	Use MUMPS as the direct solver
MUMPS_LIB_DEPENDS=	libcmumps.so:math/mumps
MUMPS_MAKE_ENV=	SOLVER=MUMPS SUBSOLVER=MUMPS

SUITESPARSE_DESC=	Prefer MFPACK of SuiteSparse
SUITESPARSE_LIB_DEPENDS=libumfpack.so:math/suitesparse-umfpack
SUITESPARSE_MAKE_ENV=	SOLVER=SUITESPARSE SUBSOLVER=SUITESPARSE

post-extract:
	${CP} -p ${WRKSRC}/Make.inc/Makefile.Linux	\
		${WRKSRC}/Make.inc/Makefile.${OPSYS}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/benchmark	\
		${STAGEDIR}${DATADIR}/interface		\
		${STAGEDIR}${PREFIX}/include/HPDDM
	${INSTALL_DATA} ${WRKSRC}/benchmark/*.cpp ${STAGEDIR}${DATADIR}/benchmark/
	${INSTALL_SCRIPT} ${WRKSRC}/benchmark/local_solver.py	\
		${STAGEDIR}${DATADIR}/benchmark
.for b in custom_operator_fortran schwarz_c schwarz_cpp
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${b} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/bin/*.mod ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include/HPDDM/
	(cd ${WRKSRC}/interface &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/interface)
.for l in libhpddm_c libhpddm_fortran libhpddm_python
	${INSTALL_LIB} ${WRKSRC}/lib/${l}.so ${STAGEDIR}${PREFIX}/lib/${l}.so.0
	(cd ${STAGEDIR}${PREFIX}/lib &&	\
		${LN} -sf ${l}.so.0 ${STAGEDIR}${PREFIX}/lib/${l}.so)
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${REINPLACE_CMD} -e 's|make|${GMAKE}|' ${WRKSRC}/examples/payload.sh
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
