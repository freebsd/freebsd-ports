# Created by: Maho Nakata <maho@FreeBSD.org>
#
# Common elements used by the SuiteSparse modules

PKGNAMEPREFIX=	suitesparse-
SSPNAME=	suitesparse
SSPVERSION=	7.11.0
DISTVERSIONPREFIX=	v

MAINTAINER=	fortran@FreeBSD.org

#USE_GITHUB=	yes # Does not work with different versions for modules
GH_ACCOUNT=	DrTimothyAldenDavis
GH_PROJECT=	SuiteSparse
GH_TAGNAME=	${SSPVERSION}
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/refs/tags/
DISTNAME=	${DISTVERSIONPREFIX}${SSPVERSION}
DIST_SUBDIR=	${SSPNAME}
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${SSPVERSION}

.if ${MPORTNAME} != config
CONFIGURE_WRKSRC=${WRKSRC}/${MPORTNAME}
.else
CONFIGURE_WRKSRC=${WRKSRC}/SuiteSparse_config
.endif
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
CMAKE_SOURCE_PATH=	${CONFIGURE_WRKSRC}
CMAKE_ARGS+=	-DBLAS_LIBRARIES:STRING="${BLASLIB}"	\
		-DLAPACK_LIBRARIES:STRING="${LAPACKLIB}"

.if ${MPORTNAME} != config &&	\
	${MPORTNAME} != CSparse &&	\
	${MPORTNAME} != ssget
LIB_DEPENDS+=	libsuitesparseconfig.so:math/suitesparse-config
.endif
.if ${MPORTNAME} != config &&	\
	${MPORTNAME} != BTF &&	\
	${MPORTNAME} != Example &&	\
	${MPORTNAME} != ssget
OPTIONS_DEFINE+=DEMOS
.endif

USES+=		cmake:insource fortran pathfix

DOCSDIR=	${PREFIX}/share/doc/${SSPNAME}
MAKE_ENV=	JOBS="${MAKE_JOBS_NUMBER}" \
		CMAKE_OPTIONS='${CMAKE_ARGS}' \
		INSTALL="${STAGEDIR}${PREFIX}" \
		INSTALL_DOC="${STAGEDIR}${DOCSDIR}" \
		INSTALL_INCLUDE="${STAGEDIR}${PREFIX}/include/${SSPNAME}"
LDFLAGS+=	-L${WRKSRC}/lib # prevent linking with shared libs from the preinstalled older versions

INSTALL_TARGET=	install # skip USES=cmake
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_SUB+=	VER=${PORTVERSION}

# FIXME: wont work if .CURDIR contains spaces
DISTINFO_FILE=	${.CURDIR}/../../math/suitesparse/distinfo

OPTIONS_DEFINE+=	DOCS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT+=	OPTIMIZED_CFLAGS

.if ${MPORTNAME} == config ||	\
	${MPORTNAME} == CHOLMOD ||	\
	${MPORTNAME} == ParU ||	\
	${MPORTNAME} == SPQR ||	\
	${MPORTNAME} == UMFPACK
OPTIONS_RADIO+=		BLAS
OPTIONS_RADIO_BLAS+=	ATLAS BLIS NETLIB OPENBLAS
OPTIONS_DEFAULT+=	OPENBLAS
BLIS_DESC=		BLAS implemntation from FLAME

ATLAS_USES=		blaslapack:atlas
BLIS_USES=		blaslapack:blis
NETLIB_USES=		blaslapack:netlib
OPENBLAS_USES=		blaslapack:openblas
.endif

OPTIONS_DEFINE+=	OPENMP
OPTIONS_EXCLUDE_aarch64=	OPENMP
OPTIONS_EXCLUDE_armv7=	OPENMP
OPTIONS_EXCLUDE_powerpc=	OPENMP
OPTIONS_DEFAULT+=	OPENMP

OPENMP_MAKE_ENV_OFF=	CFOPENMP=
. if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support armv6, armv7 yet
OPENMP_VARS=		OPENMP=gcc-
. endif
OPENMP_CMAKE_BOOL=	OPENMP
OPENMP_CMAKE_BOOL_OFF=	NOPENMP

DEMOS_DESC=		Build the demonstrations
DEMOS_CMAKE_BOOL=	SUITESPARSE_DEMOS

.if !defined(WITH_DEBUG)
OPTIMIZED_CFLAGS_CFLAGS=	-O3
OPTIMIZED_CFLAGS_CXXFLAGS=	-O3
LDFLAGS+=	-s
.endif

post-install:
.if ! ${MPORTNAME} == config
	 @${RM} ${STAGEDIR}${DOCSDIR}/SUITESPARSECONFIG_README.txt	\
		${STAGEDIR}${PREFIX}/include/suitesparse/SuiteSparse_config.h
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# See PR 230888 : Missing 64 bit atomic functions for i386
USE_GCC=	yes
LDFLAGS+=	-latomic
.else
USES+=	compiler:c++11-lib
.endif
