# $FreeBSD$

PORTNAME=	ceres-solver
DISTVERSION=	1.14.0
PORTREVISION=	18
CATEGORIES=	math

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Nonlinear least squares minimizer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglog.so:devel/glog
RUN_DEPENDS:=	${BUILD_DEPENDS:Meigen*}

USES=		cmake compiler:${OPENMP}c++11-lib eigen:3 localbase shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	examples/slam/pose_graph_*/plot_results.py \
		scripts/make_docs.py
CMAKE_ON=	CXX11 BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_BENCHMARKS
LDFLAGS+=	-Wl,--as-needed # -lccolamd -lcholmod -lrt from suitesparse
PLIST_SUB=	VERSION=${DISTVERSION:C/rc.*//}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME:S/-solver//}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-solver//}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	CUSTOM_BLAS EXAMPLES DOCS GFLAGS LAPACK SCHUR TEST
OPTIONS_DEFAULT=CUSTOM_BLAS CXSPARSE OPENBLAS OPENMP SCHUR SUITESPARSE
OPTIONS_RADIO=	LAPACK THREADS
OPTIONS_RADIO_LAPACK=	ATLAS GOTOBLAS NETLIB OPENBLAS
OPTIONS_RADIO_THREADS=	OPENMP TBB
OPTIONS_GROUP=	SPARSE
OPTIONS_GROUP_SPARSE=	CXSPARSE EIGENSPARSE SUITESPARSE

CUSTOM_BLAS_DESC=	Handcoded BLAS routines instead of Eigen
CUSTOM_BLAS_CMAKE_BOOL=	CUSTOM_BLAS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_USES=		python:build
DOCS_CMAKE_BOOL=	BUILD_DOCUMENTATION

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES
EXAMPLES_IMPLIES=	GFLAGS

GFLAGS_DESC=		Google Flags support
GFLAGS_LIB_DEPENDS=	libgflags.so:devel/gflags
GFLAGS_CMAKE_BOOL=	GFLAGS

OPENMP_USES=		compiler:openmp
OPENMP_CMAKE_BOOL=	OPENMP
.if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support aarch64, armv6, armv7 yet
OPENMP_VARS=		OPENMP=gcc-
.endif

SCHUR_DESC=		Fixed-size schur specializations
SCHUR_CMAKE_BOOL=	SCHUR_SPECIALIZATIONS

TBB_DESC=		Intel threading building blocks
TBB_LIB_DEPENDS=	libtbb.so:devel/tbb
TBB_CMAKE_BOOL=		TBB

# XXX Unbundle googletest/googlemock
TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	test
TEST_IMPLIES=		GFLAGS

LAPACK_DESC=		Linear Algebra PACKage
LAPACK_CMAKE_BOOL=	LAPACK
# Avoid conflict with Ceres threading by using single-threaded BLAS library.
# BLASLIB from USES=blaslapack cannot be used as it's multi-threaded.
# https://github.com/xianyi/OpenBLAS/wiki/faq#multi-threaded
ATLAS_USES=		blaslapack:atlas
ATLAS_CMAKE_ON=		-DBLA_VENDOR:STRING="ATLAS" \
			-DBLAS_LIBRARIES:FILEPATH="${LOCALBASE}/lib/libcblas.so" \
			-DLAPACK_LIBRARIES:FILEPATH="${LOCALBASE}/lib/libalapack.so"
ATLAS_IMPLIES=		LAPACK
GOTOBLAS_DESC=		Goto blas implementation
GOTOBLAS_USES=		blaslapack:gotoblas
GOTOBLAS_CMAKE_ON=	-DBLA_VENDOR:STRING="Goto"
GOTOBLAS_IMPLIES=	LAPACK
NETLIB_USES=		blaslapack:netlib
NETLIB_CMAKE_ON=	-DBLA_VENDOR:STRING="Generic"
NETLIB_IMPLIES=		LAPACK
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CMAKE_ON=	-DBLA_VENDOR:STRING="OpenBLAS"
OPENBLAS_IMPLIES=	LAPACK

SPARSE_DESC=		Sparse linear algebra library
CXSPARSE_DESC=		CXSparse support
CXSPARSE_LIB_DEPENDS=	libcxsparse.so:math/suitesparse
CXSPARSE_CMAKE_ON=	-DCXSPARSE_INCLUDE_DIR:PATH="${LOCALBASE}/include/suitesparse"
CXSPARSE_CMAKE_BOOL=	CXSPARSE
EIGENSPARSE_DESC=	Simplicial Cholesky factorization in Eigen
EIGENSPARSE_CMAKE_BOOL=	EIGENSPARSE
EIGENSPARSE_VARS=	LICENSE+=LGPL21+ LICENSE_COMB=multi \
			LICENSE_FILE_BSD3CLAUSE="${LICENSE_FILE}"
SUITESPARSE_DESC=	SuiteSparse support
SUITESPARSE_LIB_DEPENDS=libspqr.so:math/suitesparse
SUITESPARSE_CMAKE_BOOL=	SUITESPARSE

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e 's,python,${PYTHON_CMD:T},' \
		${WRKSRC}/docs/source/CMakeLists.txt

pre-install-TEST-on: do-test

post-install-EXAMPLES-on:
# Copy examples (stripped), their source and sample data but not tests programs
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${EXAMPLESDIR})
	(cd ${BUILD_WRKSRC} && ${COPYTREE_SHARE} bin ${STAGEDIR}${EXAMPLESDIR})
	@${RM} -r ${STAGEDIR}${EXAMPLESDIR}/bin/*_test
	-@${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/bin/* # may fail for non-root

.include <bsd.port.mk>
