# Created by: Maho Nakata <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	suitesparse
DISTVERSION=	5.2.0
CATEGORIES=	math
MASTER_SITES=	http://faculty.cse.tamu.edu/davis/SuiteSparse/
DISTNAME=	SuiteSparse-${PORTVERSION}

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	SuiteSparse is a set of packages for sparse matrices calculation

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libmetis.so:math/metis \
		liblapack.so:math/lapack

USES=		compiler:openmp fortran gmake
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/SuiteSparse
WRKSRC_SHARED=	${WRKSRC}_shared

OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	OPENBLAS NETLIB ATLAS
OPTIONS_DEFAULT=	OPENBLAS

OPENBLAS_USES=	blaslapack:openblas
NETLIB_USES=	blaslapack:netlib
ATLAS_USES=	blaslapack:atlas

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

METIS=		${LOCALBASE}/lib/libmetis.a
METIS_PATH=	${LOCALBASE}/include/metis
CHOLMOD_CONFIG=
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS+=	MY_METIS_LIB="-L${LOCALBASE}/lib -lmetis $(LDFLAGS)"

post-patch:
	@${RM} -r ${WRKSRC}/metis-5.1.0
	@${FIND} -X ${WRKSRC} -type f -name 'Makefile' -or -name '*.mk' | ${XARGS} \
		${REINPLACE_CMD} \
			-e '\|^AR =|s|ar|${AR}|' \
			-e '\|^ *BLAS =|s|=.*|= ${LDFLAGS} ${BLASLIB}|' \
			-e '\|^CC =|d' \
			-e '\|^CFLAGS =|{s|-O[1-9]\{0,1\}||g;s|=|= ${CFLAGS} $${PICFLAG} |;}' \
			-e '\|^CHOLMOD_CONFIG =|s|=.*|= ${CHOLMOD_CONFIG}|' \
			-e '\|^CPLUSPLUS =|s|=.*|= ${CXX}|' \
			-e '\|^F77 =|d' \
			-e '\|^F77FLAGS =|s|=.*|= ${FFLAGS} $${PICFLAG}|' \
			-e '\|^LAPACK =|s|=.*|= ${LDFLAGS} ${LAPACKLIB}|' \
			-e '\|^METIS =|s|=.*|= ${METIS}|' \
			-e '\|^METIS_PATH =|s|=.*|= ${METIS_PATH}|' \
			-e 's|-I\$$(METIS_PATH)/Lib|-I${METIS_PATH}|' \
			-e '\|^RANLIB =|s|ranlib|${RANLIB}|' \
			-e '\|^SPQR_CONFIG =|s|=.*|= ${CHOLMOD_CONFIG}|' \
			-e 's|# MAKE = gmake|MAKE = gmake|g' \
			-e 's|/usr/local|${LOCALBASE}|g'
	@${CP} -r ${WRKSRC} ${WRKSRC_SHARED}
	@${FIND} -X ${WRKSRC_SHARED} -type f -name 'Makefile' -or -name '*.mk' | ${XARGS} \
		${REINPLACE_CMD} -e 's|$$(CFLAGS)|$$(CFLAGS) $$(PICFLAG)|g'

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PICFLAG= \
		LD_LIBRARY_PATH=${WRKDIR}/SuiteSparse/lib ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS}
	@cd ${WRKSRC_SHARED} && ${SETENV} ${MAKE_ENV} PICFLAG=${PICFLAG} \
		LD_LIBRARY_PATH=${WRKDIR}/SuiteSparse/lib ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/suitesparse
	@cd ${STAGEDIR}${PREFIX}/include && ${LN} -s suitesparse ufsparse
.for d in AMD BTF CAMD CCOLAMD CHOLMOD COLAMD CSparse CXSparse KLU SPQR UMFPACK # CSparse: shared lib bot built
	${INSTALL_DATA} ${WRKSRC}/${d}/Include/*.h ${STAGEDIR}${PREFIX}/include/suitesparse
.endfor
	${INSTALL_DATA} ${WRKSRC}/SuiteSparse_config/SuiteSparse_config.h ${STAGEDIR}${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/UMFPACK/Source/umf_config.h ${STAGEDIR}${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/SPQR/Include/*.hpp ${STAGEDIR}${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC_SHARED}/lib/*.so* ${STAGEDIR}${PREFIX}/lib/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so*

.include <bsd.port.mk>
