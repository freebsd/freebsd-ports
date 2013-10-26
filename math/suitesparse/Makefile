# Created by: Maho Nakata <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	suitesparse
PORTVERSION=	4.0.2
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/SuiteSparse/
DISTNAME=	SuiteSparse-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SuiteSparse is a set of packages for sparse matrices calculation

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USES=		gmake

.if defined (WITH_METIS)
LIB_DEPENDS=	metis.1:${PORTSDIR}/math/metis4

RESTRICTED=	GPL and METIS licenses are contradictory
.endif

CONFLICTS=	umfpack-*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libopenblas.so)
WITH_BLAS?=	openblas
.elif exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${WITH_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == openblas
LIB_DEPENDS+=	openblas:${PORTSDIR}/math/openblas
BLAS=		-lopenblasp
LAPACK=		-lopenblasp
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	goto2:${PORTSDIR}/math/gotoblas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS =		-lgoto2p
LAPACK =	-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
LAPACK =	-lalapack -lptcblas
.endif

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

USE_LDCONFIG=	yes
USE_FORTRAN=	yes
WRKSRC=${WRKDIR}/SuiteSparse
WRKSRC_SHARED=${WRKSRC}_shared
SVERSION=1

.if defined (WITH_METIS)
METIS=${LOCALBASE}/lib/libmetis.a
METIS_PATH=${LOCALBASE}/include/metis
CHOLMOD_CONFIG =
.else
CHOLMOD_CONFIG =	-DNPARTITION
.endif

post-patch:
	@${FIND} -X ${WRKSRC} -type f -name 'Makefile' -or -name '*.mk' | ${XARGS} \
	${REINPLACE_CMD} -e '\|^AR =|s|ar|${AR}|' \
			-e '\|^BLAS =|s|=.*|= ${LDFLAGS} ${BLAS}|' \
			-e '\|^CC =|d' \
			-e '\|^CFLAGS =|{s|-O[1-9]\{0,1\}||g;s|=|= ${CFLAGS} $${PICFLAG} |;}' \
			-e '\|^CHOLMOD_CONFIG =|s|=.*|= ${CHOLMOD_CONFIG}|' \
			-e '\|^CPLUSPLUS =|s|=.*|= ${CXX}|' \
			-e '\|^F77 =|d' \
			-e '\|^F77FLAGS =|s|=.*|= ${FFLAGS} $${PICFLAG}|' \
			-e '\|^LAPACK =|s|=.*|= ${LDFLAGS} ${LAPACK}|' \
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
		${GMAKE} ${_MAKE_JOBS} ${MAKE_ARGS}
	@cd ${WRKSRC_SHARED} ; ${SETENV} ${MAKE_ENV} PICFLAG=${PICFLAG} \
		${GMAKE} ${_MAKE_JOBS} ${MAKE_ARGS}

post-build:
	@for i in `find ${WRKSRC_SHARED} -type f -name '*.a'` ; do \
		j=$${i##*/} ; ${LD} -Bshareable -o $${i%.a}.so.${SVERSION} -x \
		-soname $${j%.a}.so.${SVERSION} --whole-archive $${i} ; \
	done

do-install:
	@${MKDIR} ${PREFIX}/include/suitesparse
	@${LN} -sf ${PREFIX}/include/suitesparse ${PREFIX}/include/ufsparse
.for d in AMD BTF CAMD CCOLAMD CHOLMOD COLAMD CXSparse KLU SPQR UMFPACK
	@${INSTALL_DATA} ${WRKSRC}/${d}/Include/*.h ${PREFIX}/include/suitesparse
.endfor
	@${INSTALL_DATA} ${WRKSRC}/SuiteSparse_config/SuiteSparse_config.h ${PREFIX}/include/suitesparse
	@${INSTALL_DATA} ${WRKSRC}/UMFPACK/Source/umf_config.h ${PREFIX}/include/suitesparse
	@${INSTALL_DATA} ${WRKSRC}/SPQR/Include/*.hpp ${PREFIX}/include/suitesparse
	@for i in `find ${WRKSRC_SHARED} -type f -name '*.a'` ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i##${WRKSRC_SHARED}/} \
		$${i%.a}.so.${SVERSION} ${PREFIX}/lib ; \
		j=$${i##*/} ;  ${LN} -sf $${j%.a}.so.${SVERSION} ${PREFIX}/lib/$${j%.a}.so ; \
	done

.include <bsd.port.post.mk>
