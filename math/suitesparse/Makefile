# New ports collection makefile for:	ufspace
# Date created:		4 July 2006
# Whom:			Maho Nakata <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	suitesparse
PORTVERSION=	2.4.0
CATEGORIES=	math
MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/SuiteSparse/
DISTNAME=	SuiteSparse-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SuiteSparse is a set of packages for sparse matrices calculation

LIB_DEPENDS=	 metis:${PORTSDIR}/math/metis

CONFLICTS=	umfpack-*

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-L${LOCALBASE}/lib -lf77blas -latlas -lcblas
LAPACK=		-L${LOCALBASE}/lib -lalapack
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-L${LOCALBASE}/lib -lblas
LAPACK=		-L${LOCALBASE}/lib -llapack
.endif

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

USE_LDCONFIG=	yes
USE_GMAKE=	yes
WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
WRKSRC=${WRKDIR}/SuiteSparse
WRKSRC_SHARED=${WRKSRC}_shared
CFLAGS_SHARED=${CFLAGS} ${FPIC}
FFLAGS_SHARED=${CFLAGS} ${FPIC}
SVERSION=1

post-patch:
	${CP} -r ${WRKSRC} ${WRKSRC_SHARED}
	@${REINPLACE_CMD} -e 's,%%CC%%,${CC},g' \
			  -e 's,%%CFLAGS%%,${CFLAGS},g' \
			  -e 's,%%F77%%,${F77},g' \
			  -e 's,%%FC%%,${FC},g' \
			  -e 's,%%FFLAGS%%,${FFLAGS},g' \
			  -e 's,%%BLAS%%,${BLAS},g' \
			  -e 's,%%LAPACK%%,${LAPACK},g' \
			  -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
				 ${WRKSRC}/UFconfig/UFconfig.mk
	@${REINPLACE_CMD} -e 's,%%CC%%,${CC},g' \
			  -e 's,%%CFLAGS%%,${CFLAGS},g' \
				${WRKSRC}/CSparse/Source/Makefile \
				${WRKSRC}/CXSparse/Source/Makefile

	@${REINPLACE_CMD} -e 's,%%CC%%,${CC},g' \
			  -e 's,%%CFLAGS%%,${CFLAGS_SHARED},g' \
			  -e 's,%%F77%%,${F77},g' \
			  -e 's,%%FC%%,${FC},g' \
			  -e 's,%%FFLAGS%%,${FFLAGS_SHARED},g' \
			  -e 's,%%BLAS%%,${BLAS},g' \
			  -e 's,%%LAPACK%%,${LAPACK},g' \
			  -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
				 ${WRKSRC_SHARED}/UFconfig/UFconfig.mk
	@${REINPLACE_CMD} -e 's,%%CC%%,${CC},g' \
			  -e 's,%%CFLAGS%%,${CFLAGS_SHARED},g' \
				${WRKSRC_SHARED}/CSparse/Source/Makefile \
				${WRKSRC_SHARED}/CXSparse/Source/Makefile

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
	${INSTALL_DATA} ${WRKSRC}/CCOLAMD/*.h   	                     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CHOLMOD/Include/*.h                 	     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/COLAMD/*.h    	                     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CXSparse/Source/*.h 	                     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/KLU/Include/*.h                            ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CAMD/Include/*.h		             ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKDIR}/tmp_static/*.a                                        ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/tmp_shared/*.so.${SVERSION}                    ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/tmp_shared/*.so                    ${PREFIX}/lib

.include <bsd.port.post.mk>
