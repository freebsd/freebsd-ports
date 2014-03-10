# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	mumps
PORTVERSION=	4.8.4
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://mumps.enseeiht.fr/		\
		http://graal.ens-lyon.fr/MUMPS/		\
		http://www.enseeiht.fr/apo/MUMPS/	\
		http://www.enseeiht.fr/irit/apo/MUMPS/
DISTNAME=	MUMPS_${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	MUltifrontal Massively Parallel sparse direct Solver

#-----------------------------------------------------------------------

# WARNING: Non-serviceable parts inside, can break other ports
NO_STAGE=	yes
# You may define these options/knobs:
#
# FFLAGS: Fortran compiler flags for gfortran
# WITH_OPTIMIZED_FLAGS:Try to use agressive (non-CPU) FFLAGS
# BLAS_LIBS: specify other version of BLAS
# WITH_ATLAS: Use ATLAS instead of the regular BLAS
# WITH_METIS: Add METIS ordering
# WITH_MPI: Use mpich for the parallel version
#-----------------------------------------------------------------------

SLAVEDIRS=	math/mumps-mpich

USES=		fortran

FORTRANLIBS=	-lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math
.endif

.ifdef WITH_METIS
BUILD_DEPENDS+=	${LOCALBASE}/bin/oemetis:${PORTSDIR}/math/metis4
MAKE_ENV+=	ORDERINGSF=-Dmetis
.endif

PLIST_SUB+=	MUMPSVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS_LIBS=	-lf77blas
LAPACK_LIBS=	-lalapack -lcblas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS_LIBS=	-lblas
LAPACK_LIBS=	-llapack
.endif

.ifdef WITH_MPI
PKGNAMESUFFIX+=		-mpich
BUILD_DEPENDS+=	${LOCALBASE}/include/mpif.h:${PORTSDIR}/net/mpich2 \
		${LOCALBASE}/lib/libblacs.a:${PORTSDIR}/math/blacs \
		${LOCALBASE}/lib/libscalapack.a:${PORTSDIR}/math/scalapack
LIB_DEPENDS+=	lapack:${PORTSDIR}/math/lapack
# Note: -l?mumps still requires to be linked with -lblacs + -lscalapack
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:${PORTSDIR}/net/mpich2 \
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
	${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	${REINPLACE_CMD} -e 's+@CC@+${CC}+g ; s+@FC@+${FC}+g ; \
	s+@CFLAGS@+${CFLAGS}+g; \
	s+@FCFLAGS@+${FCFLAGS}+g; \
	s+@GCCLIBDIR@+${GCCLIBDIR}+g; \
	s+@FORTRANLIBS@+${FORTRANLIBS}+g; \
	s+@PTHREAD_LIBS@+${PTHREAD_LIBS}+g; \
	s+@BLAS_LIBS@+${BLAS_LIBS}+ ; \
	s+../PORD+${WRKSRC}/PORD+; \
	s+@LOCALBASE@+${LOCALBASE}+g;' \
		${WRKSRC}/Makefile.inc
.ifdef WITH_MPI
	${REINPLACE_CMD} -e 's+@LAPACK_LIBS@+${LAPACK_LIBS}+g;' ${WRKSRC}/Makefile.inc
.endif
.ifdef WITH_METIS
	${REINPLACE_CMD} -e 's+#LMETIS+LMETIS+' ${WRKSRC}/Makefile.inc
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
.ifndef NOPORTEXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
. for ex in Makefile README *.c *.F input_simpletest_*
	${INSTALL_DATA} ${WRKSRC}/examples/${ex} ${EXAMPLESDIR}
. endfor
. for ex in c_example *simpletest
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${ex} ${EXAMPLESDIR}
. endfor
.endif

regression-test:
.if defined (WITH_MPI) && defined(MAINTAINER_MODE)
.  if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
.  endif
	${LOCALBASE}/bin/mpd &
	(cd ${WRKSRC}/examples &&	\
	${LOCALBASE}/bin/mpirun -np 2 ./ssimpletest < input_simpletest_real ;	\
	${LOCALBASE}/bin/mpirun -np 2 ./dsimpletest < input_simpletest_real ;	\
	${LOCALBASE}/bin/mpirun -np 2 ./csimpletest < input_simpletest_cmplx ;	\
	${LOCALBASE}/bin/mpirun -np 2 ./zsimpletest < input_simpletest_cmplx ;	\
	${ECHO_MSG} "The solution should be (1,2,3,4,5)" ;	\
	${LOCALBASE}/bin/mpirun -np 3 ./c_example ;	\
	${ECHO_MSG} "The solution should be (1,2)")
	${LOCALBASE}/bin/mpdallexit
.else
	(cd ${WRKSRC}/examples &&	\
	./ssimpletest < input_simpletest_real ;			\
	./dsimpletest < input_simpletest_real ;			\
	./csimpletest < input_simpletest_cmplx ;		\
	./zsimpletest < input_simpletest_cmplx ;		\
	${ECHO_MSG} "The solution should be (1,2,3,4,5)" ;	\
	./c_example ;						\
	${ECHO_MSG} "The solution should be (1,2)")
.endif

.include <bsd.port.post.mk>
