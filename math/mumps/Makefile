# New ports collection makefile for:	MUMPS
# Date created:		5 Mar 2006
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	mumps
PORTVERSION=	4.6.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.enseeiht.fr/apo/MUMPS/	\
		http://www.enseeiht.fr/irit/apo/MUMPS/	\
		http://graal.ens-lyon.fr/MUMPS/
DISTNAME=	MUMPS_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MUltifrontal Massively Parallel sparse direct Solver

BUILD_DEPENDS=	${FC}:${PORTSDIR}/lang/gfortran
.ifdef WITH_MPI
BUILD_DEPENDS+=	${LOCALBASE}/mpich/include/mpif.h:${PORTSDIR}/net/mpich \
		${LOCALBASE}/lib/libscalapack.a:${PORTSDIR}/math/scalapack	\
		${LOCALBASE}/lib/libblacs.a:${PORTSDIR}/math/blacs
.endif
.ifdef WITH_METIS
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis
.endif

#-----------------------------------------------------------------------

# WARNING: Non-serviceable parts inside, can break other ports
# You may define these options/knobs:
#
# FFLAGS: Fortran compiler flags for gfortran
# WITH_OPTIMIZED_FLAGS:Try to use agressive (non-CPU) FFLAGS
# BLAS_LIBS: specify other version of BLAS
# WITH_ATLAS: Use ATLAS instead of the regular BLAS
# WITH_GFC_BLAS: BLAS was generated with gfortran, not g77
# WITH_METIS: Add METIS ordering
# WITH_MPI: Use mpich for the parallel version
#-----------------------------------------------------------------------

USE_GCC=	4.1+
WITH_FORTRAN=	yes
FC=	${LOCALBASE}/bin/gfortran41

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math
.endif

.ifndef WITH_GFC_BLAS	# g77 compatibility
MAKE_ENV+=	CDEFS=-DAdd__
FCFLAGS=	-ff2c ${FFLAGS}
.else
FCFLAGS?=	${FFLAGS}
.endif

.ifdef WITH_ATLAS
LIB_DEPENDS+=	atlas.1:${PORTSDIR}/math/atlas
BLAS_LIBS=	-lptf77blas -latlas_r
.else
LIB_DEPENDS+=	blas.1:${PORTSDIR}/math/blas
BLAS_LIBS?=	-lblas
.endif

.ifdef WITH_METIS
MAKE_ENV+=	ORDERINGSF=-Dmetis
.endif

.ifndef WITH_MPI
PLIST_SUB+=	WITH_LIBSEQ=""
.else
PLIST_SUB+=	WITH_LIBSEQ="@comment "
.endif
PLIST_SUB+=	MUMPSVERSION=${PORTVERSION}

post-patch:
.ifdef WITH_MPI
	@${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.inc.generic \
		${WRKSRC}/Makefile.inc
.else
	@${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.inc.generic.SEQ \
		${WRKSRC}/Makefile.inc
.endif

pre-build:
	@${REINPLACE_CMD} -e 's+@CC@+${CC}+g ; s+@FC@+${FC}+g ; \
	s+@CFLAGS@+${CFLAGS}+g; \
	s+@FCFLAGS@+${FCFLAGS}+g; \
	s+@PTHREAD_LIBS@+${PTHREAD_LIBS}+g; \
	s+@BLAS_LIBS@+${BLAS_LIBS}+ ; \
	s+@LOCALBASE@+${LOCALBASE}+g;' \
		${WRKSRC}/Makefile.inc
.ifdef WITH_METIS
	@${REINPLACE_CMD} -e 's+#LMETIS+LMETIS+' ${WRKSRC}/Makefile.inc
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/lib*.a ${PREFIX}/lib
.ifndef WITH_MPI
	${INSTALL_DATA} ${WRKSRC}/libseq/libmpiseq.a ${PREFIX}/lib
.endif
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/userguide_${PORTVERSION}.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/userguide_${PORTVERSION}.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/userguide_${PORTVERSION}.ps
.endif

.include <bsd.port.mk>
