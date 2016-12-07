# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	mumps
PORTVERSION=	4.10.0
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	http://mumps.enseeiht.fr/		\
		http://graal.ens-lyon.fr/MUMPS/		\
		http://www.enseeiht.fr/apo/MUMPS/	\
		http://www.enseeiht.fr/irit/apo/MUMPS/
DISTNAME=	MUMPS_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MUltifrontal Massively Parallel sparse direct Solver

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

#-----------------------------------------------------------------------

# WARNING: Non-serviceable parts inside, can break other ports
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

MAKE_JOBS_UNSAFE=yes

FORTRANLIBS=	-lgfortran
GCCLIBDIR=	${LDFLAGS}

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math
.endif

.ifdef WITH_METIS
BUILD_DEPENDS+=	${LOCALBASE}/bin/oemetis:math/metis4
MAKE_ENV+=	ORDERINGSF=-Dmetis
.endif

PLIST_SUB+=	MUMPSVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS_LIBS=	-lf77blas
LAPACK_LIBS=	-lalapack -lcblas
.else
LIB_DEPENDS+=	libblas.so:math/blas
BLAS_LIBS=	-lblas
LAPACK_LIBS=	-llapack
.endif

.ifdef WITH_MPI
PKGNAMESUFFIX+=		-mpich
BUILD_DEPENDS+=	${LOCALBASE}/include/mpif.h:net/mpich2 \
		${LOCALBASE}/lib/libblacs.a:math/blacs \
		${LOCALBASE}/lib/libscalapack.a:math/scalapack
LIB_DEPENDS+=	liblapack.so:math/lapack
# Note: -l?mumps still requires to be linked with -lblacs + -lscalapack
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:net/mpich2 \
		${LOCALBASE}/lib/libblacs.a:math/blacs \
		${LOCALBASE}/lib/libscalapack.a:math/scalapack
CONFLICTS=	mumps-4*
.else
CONFLICTS=	mumps-mpich-4*
.endif

.ifndef WITH_MPI
PLIST_SUB+=	WITH_LIBSEQ=""
.else
PLIST_SUB+=	WITH_LIBSEQ="@comment "
.endif

pre-configure:
.ifdef WITH_MPI
	${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.inc.generic \
		${WRKSRC}/Makefile.inc
.else
	${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.inc.generic.SEQ \
		${WRKSRC}/Makefile.inc
.endif

pre-build:
	${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	${REINPLACE_CMD} -e 's+@CC@+${CC}+g ; s+@FC@+${FC}+g ; \
	s+@CFLAGS@+${CFLAGS}+g; \
	s+@FCFLAGS@+${FCFLAGS}+g; \
	s+@GCCLIBDIR@+${GCCLIBDIR}+g; \
	s+@FORTRANLIBS@+${FORTRANLIBS}+g; \
	s+@BLAS_LIBS@+${BLAS_LIBS}+ ; \
	s+@LOCALBASE@+${LOCALBASE}+g;' \
		${WRKSRC}/Makefile.inc
.ifdef WITH_MPI
	${REINPLACE_CMD} -e 's+@LAPACK_LIBS@+${LAPACK_LIBS}+g;' ${WRKSRC}/Makefile.inc
.endif
.ifdef WITH_METIS
	${REINPLACE_CMD} -e 's+#LMETIS+LMETIS+' ${WRKSRC}/Makefile.inc
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/lib*.a ${STAGEDIR}${PREFIX}/lib
.ifndef WITH_MPI
	${INSTALL_DATA} ${WRKSRC}/libseq/libmpiseq.a ${STAGEDIR}${PREFIX}/lib
.endif
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/userguide_${PORTVERSION}.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/userguide_${PORTVERSION}.ps ${STAGEDIR}${DOCSDIR}
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/userguide_${PORTVERSION}.ps
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
. for ex in Makefile README *.c *.F input_simpletest_*
	${INSTALL_DATA} ${WRKSRC}/examples/${ex} ${STAGEDIR}${EXAMPLESDIR}
. endfor
. for ex in c_example *simpletest
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${ex} ${STAGEDIR}${EXAMPLESDIR}
. endfor

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
