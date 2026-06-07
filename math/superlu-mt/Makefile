PORTNAME=	superlu-mt
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.2
PORTREVISION=	1
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	b121cf0fcafbd10a1ca18c8d062d54cd68bbae9d.patch:-p1 # add THREAD_API cmake option

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of routines for performing sparse factorization
WWW=		https://portal.nersc.gov/project/sparse/superlu/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	xiaoyeli
GH_PROJECT=	superlu_mt

CMAKE_ON=	BUILD_SHARED_LIBS USE_XSDK_DEFAULTS
CMAKE_OFF=	enable_fortran \
		enable_tests \
		enable_examples
CMAKE_ARGS=	-DTHREAD_API=BOTH

LDFLAGS+=	-lpthread \
		-lm \
		${LAPACKLIB} \
		${BLASLIB}

OPTIONS_DEFAULT=	REFERENCE
OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS OPENBLAS REFERENCE

REFERENCE_DESC=		Reference BLAS implementation

ATLAS_USES=		blaslapack:atlas
ATLAS_CMAKE_ON=		-DBLA_VENDOR:STRING="ATLAS"
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CMAKE_ON=	-DBLA_VENDOR:STRING="OpenBLAS"
REFERENCE_USES=		blaslapack
REFERENCE_CMAKE_ON=	-DBLA_VENDOR:STRING="Generic"

post-patch:
	@${RM} ${WRKSRC}/SRC/sp_coletree.c.orig
	@${CP} ${FILESDIR}/xerbla.c ${WRKSRC}/TESTING/MATGEN/

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
		-Denable_tests:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

# tests as of 4.0.2: 100% tests passed, 0 tests failed out of 48

.include <bsd.port.mk>
