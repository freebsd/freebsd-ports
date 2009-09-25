# New ports collection makefile for:	ufspace
# Date created:		4 July 2006
# Whom:			Maho Nakata <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	suitesparse
PORTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/SuiteSparse/
DISTNAME=	SuiteSparse-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SuiteSparse is a set of packages for sparse matrices calculation

.if defined (WITH_METIS)
LIB_DEPENDS=	metis:${PORTSDIR}/math/metis
.endif

.if defined (WITH_METIS)
RESTRICTED=	GPL and METIS license contradicts
.endif

CONFLICTS=	umfpack-*

.include <bsd.port.pre.mk>

USE_BLAS?=	reference

.if exists(${LOCALBASE}/lib/libgoto.so)
USE_BLAS=     gotoblas
.elif exists(${LOCALBASE}/lib/libatlas_r.so)
USE_BLAS=     atlas
.endif

.if ${USE_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${USE_BLAS} == gotoblas
LIB_DEPENDS+=	goto:${PORTSDIR}/math/gotoblas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-pthread -lgotop
LAPACK=		-pthread -lgotop -llapack
.elif ${USE_BLAS} == atlas
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
BLAS=		-pthread -lptf77blas -lptcblas -latlas_r
LAPACK=		-pthread -lalapack_r
.endif

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_FORTRAN=	yes
WRKSRC=${WRKDIR}/SuiteSparse
WRKSRC_SHARED=${WRKSRC}_shared
CFLAGS_SHARED=${CFLAGS} ${FPIC}
FFLAGS_SHARED=${CFLAGS} ${FPIC}
SVERSION=1
FORTRANRUNTIME=-lgfortran -lgfortranbegin

.if defined (WITH_METIS)
METIS=${LOCALBASE}/lib/libmetis.a
METIS_PATH=${LOCALBASE}/include/metis
CHOLMOD_CONFIG =
.else
CHOLMOD_CONFIG = -DNPARTITION
.endif

post-patch:
	${CP} -r ${WRKSRC} ${WRKSRC_SHARED}
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' \
			  -e 's|%%CXX%%|${CXX}|g' \
			  -e 's|%%F77%%|${F77}|g' \
			  -e 's|%%BLAS%%|-L${LOCALBASE}/lib ${BLAS}|g' \
			  -e 's|%%FORTRANRUNTIME%%|${FORTRANRUNTIME}|g' \
			  -e 's|%%LAPACK%%|-L${LOCALBASE}/lib ${LAPACK}|g' \
			  -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			  -e 's|%%METIS_PATH%%|${METIS_PATH}|g' \
			  -e 's|%%METIS%%|${METIS}|g' \
			  -e 's|%%CHOLMOD_CONFIG%%|${CHOLMOD_CONFIG}|g' \
				 ${WRKSRC}/UFconfig/UFconfig.mk \
				 ${WRKSRC_SHARED}/UFconfig/UFconfig.mk\
				 ${WRKSRC}/CSparse/Lib/Makefile \
				 ${WRKSRC_SHARED}/CSparse/Lib/Makefile

	@${REINPLACE_CMD}  -e 's|%%CFLAGS%%|${CFLAGS}|g' \
			   -e 's|%%FFLAGS%%|${FFLAGS}|g' \
				 ${WRKSRC}/UFconfig/UFconfig.mk \
				 ${WRKSRC}/CSparse/Lib/Makefile

	@${REINPLACE_CMD}  -e 's|%%CFLAGS%%|${CFLAGS_SHARED}|g' \
			   -e 's|%%FFLAGS%%|${FFLAGS_SHARED}|g' \
				 ${WRKSRC_SHARED}/UFconfig/UFconfig.mk \
				 ${WRKSRC_SHARED}/CSparse/Lib/Makefile

do-build:
	cd ${WRKSRC} ; ${GMAKE}
	cd ${WRKSRC_SHARED} ; ${GMAKE}
	${RM} -rf ${WRKDIR}/tmp_static
	${MKDIR} ${WRKDIR}/tmp_static
	cd ${WRKDIR}/tmp_static
	${FIND} ${WRKSRC} -name "*\.a" -exec ${MV} {} ${WRKDIR}/tmp_static \;
	${RM} -rf ${WRKDIR}/tmp_shared
	${MKDIR} ${WRKDIR}/tmp_shared
	${FIND} ${WRKSRC_SHARED} -name "*\.a" -exec ${MV} {} ${WRKDIR}/tmp_shared \;
post-build:
	cd ${WRKDIR}/tmp_shared ; for i in `ls *.a | ${SED}  's/\.a//' `; do \
		ld -Bshareable -o $${i}.so.${SVERSION} -x -soname $${i}.so.${SVERSION} --whole-archive $${i}.a ;\
		${LN} -s $${i}.so.${SVERSION} $${i}.so ;\
	done

do-install:
	${MKDIR} ${PREFIX}/include/suitesparse
	${LN} -sf ${PREFIX}/include/suitesparse ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKSRC}/UFconfig/UFconfig.h                        ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/UMFPACK/Include/*.h                        ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/AMD/Include/*.h			     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/BTF/Include/*.h			     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CCOLAMD/Include/*.h   	             ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CHOLMOD/Include/*.h                 	     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/COLAMD/Include/*.h    	             ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CXSparse/Include/*.h 	                     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/KLU/Include/*.h                            ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CAMD/Include/*.h		             ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/SPQR/Include/*.h		             ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/SPQR/Include/*.hpp		             ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKDIR}/tmp_static/*.a                             ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/tmp_shared/*.so.${SVERSION}                    ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/tmp_shared/*.so                    ${PREFIX}/lib

.include <bsd.port.post.mk>
