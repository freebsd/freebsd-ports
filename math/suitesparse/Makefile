# Created by: Maho Nakata <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	suitesparse
PORTVERSION=	4.0.2
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/SuiteSparse/
DISTNAME=	SuiteSparse-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SuiteSparse is a set of packages for sparse matrices calculation

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USES=		fortran gmake

OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	OPENBLAS NETLIB ATLAS
OPTIONS_DEFAULT=	OPENBLAS

OPENBLAS_USES=	blaslapack:openblas
NETLIB_USES=	blaslapack:netlib
ATLAS_USES=	blaslapack:atlas

.if defined (WITH_METIS)
LIB_DEPENDS=	libmetis.so:math/metis4

RESTRICTED=	GPL and METIS licenses are contradictory
.endif

CONFLICTS=	umfpack-*

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

USE_LDCONFIG=	yes
WRKSRC=${WRKDIR}/SuiteSparse
WRKSRC_SHARED=${WRKSRC}_shared
SVERSION=1

.if defined (WITH_METIS)
METIS=${LOCALBASE}/lib/libmetis.a
METIS_PATH=${LOCALBASE}/include/metis
CHOLMOD_CONFIG=
.else
CHOLMOD_CONFIG=		-DNPARTITION
.endif

post-patch:
	@${FIND} -X ${WRKSRC} -type f -name 'Makefile' -or -name '*.mk' | ${XARGS} \
	${REINPLACE_CMD} -e '\|^AR =|s|ar|${AR}|' \
			-e '\|^BLAS =|s|=.*|= ${LDFLAGS} ${BLASLIB}|' \
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
	@cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} PICFLAG= \
		${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS}
	@cd ${WRKSRC_SHARED} ; ${SETENV} ${MAKE_ENV} PICFLAG=${PICFLAG} \
		${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS}

post-build:
	@for i in `find ${WRKSRC_SHARED} -type f -name '*.a'` ; do \
		j=$${i##*/} ; ${LD} -Bshareable -o $${i%.a}.so.${SVERSION} -x \
		-soname $${j%.a}.so.${SVERSION} --whole-archive $${i} ; \
	done

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/suitesparse
	@${LN} -sf ${PREFIX}/include/suitesparse ${STAGEDIR}${PREFIX}/include/ufsparse
.for d in AMD BTF CAMD CCOLAMD CHOLMOD COLAMD CXSparse KLU SPQR UMFPACK
	@${INSTALL_DATA} ${WRKSRC}/${d}/Include/*.h ${STAGEDIR}${PREFIX}/include/suitesparse
.endfor
	@${INSTALL_DATA} ${WRKSRC}/SuiteSparse_config/SuiteSparse_config.h ${STAGEDIR}${PREFIX}/include/suitesparse
	@${INSTALL_DATA} ${WRKSRC}/UMFPACK/Source/umf_config.h ${STAGEDIR}${PREFIX}/include/suitesparse
	@${INSTALL_DATA} ${WRKSRC}/SPQR/Include/*.hpp ${STAGEDIR}${PREFIX}/include/suitesparse
	@for i in `find ${WRKSRC_SHARED} -type f -name '*.a'` ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i##${WRKSRC_SHARED}/} \
		$${i%.a}.so.${SVERSION} ${STAGEDIR}${PREFIX}/lib ; \
		j=$${i##*/} ;  ${LN} -sf $${j%.a}.so.${SVERSION} ${STAGEDIR}${PREFIX}/lib/$${j%.a}.so ; \
	done

.include <bsd.port.mk>
