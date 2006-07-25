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
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis
MAKE_ENV+=	ORDERINGSF=-Dmetis
.endif

PLIST_SUB+=	MUMPSVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/mpich2/bin/mpicc) && !defined(WITHOUT_MPI)
WITH_MPI=	yes
.endif
.ifdef WITH_MPI
PKGNAMESUFFIX+=		-mpich
BUILD_DEPENDS+=	${LOCALBASE}/mpich2/include/mpif.h:${PORTSDIR}/net/mpich2 \
		${LOCALBASE}/lib/libblacs.a:${PORTSDIR}/math/blacs \
		${LOCALBASE}/lib/libscalapack.a:${PORTSDIR}/math/scalapack
# Note: -l?mumps still requires to be linked with -lblacs + -lscalapack
RUN_DEPENDS+=	${LOCALBASE}/mpich2/bin/mpirun:${PORTSDIR}/net/mpich2 \
		${LOCALBASE}/lib/libblacs.a:${PORTSDIR}/math/blacs \
		${LOCALBASE}/lib/libscalapack.a:${PORTSDIR}/math/scalapack
CONFLICTS=	mumps-4*
.else
CONFLICTS=	mumps-mpich-4*
.endif

.ifndef WITH_MPI
PLIST_SUB+=	WITH_LIBSEQ=""
.else
PLIST_SUB+=	WITH_LIBSEQ="@comment "
.endif

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

.if defined(MAINTAINER_MODE)
regression-test:
. if defined (WITH_MPI)
.  if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
.  endif
	${LOCALBASE}/mpich2/bin/mpd &
	(cd ${WRKSRC}/test &&	\
	${LOCALBASE}/mpich2/bin/mpirun -np 2 ./ssimpletest < input_simpletest_real ;	\
	${LOCALBASE}/mpich2/bin/mpirun -np 2 ./dsimpletest < input_simpletest_real ;	\
	${LOCALBASE}/mpich2/bin/mpirun -np 2 ./csimpletest < input_simpletest_cmplx ;	\
	${LOCALBASE}/mpich2/bin/mpirun -np 2 ./zsimpletest < input_simpletest_cmplx ;	\
	${ECHO_MSG} "The solution should be (1,2,3,4,5)" ;	\
	${LOCALBASE}/mpich2/bin/mpirun -np 3 ./c_example ;	\
	${ECHO_MSG} "The solution should be (1,2)")
	${LOCALBASE}/mpich2/bin/mpdallexit
. else
	(cd ${WRKSRC}/test &&	\
	./ssimpletest < input_simpletest_real ;			\
	./dsimpletest < input_simpletest_real ;			\
	./csimpletest < input_simpletest_cmplx ;		\
	./zsimpletest < input_simpletest_cmplx ;		\
	${ECHO_MSG} "The solution should be (1,2,3,4,5)" ;	\
	./c_example ;						\
	${ECHO_MSG} "The solution should be (1,2)")
. endif
.endif

.include <bsd.port.post.mk>
