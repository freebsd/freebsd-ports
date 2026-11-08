PORTNAME=	mumps
PORTVERSION=	5.9.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://mumps-solver.org/
DISTNAME=	MUMPS_${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	MUltifrontal Massively Parallel sparse direct Solver
WWW=		https://mumps-solver.org/

LICENSE=	CeCILL_C
LICENSE_NAME=	CeCILL-C
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libmetis.so:math/metis

USES=		blaslapack:openblas fortran gmake
BINARY_ALIAS=	make=${GMAKE}

CONFLICTS+=	mumps-edf

ALL_TARGET=	all allshared
FORTRANLIBS=	-L${LOCALBASE}/lib/gcc${_GCC_VER} -lgfortran
FCFLAGS+=	-O2
# workaround for Type mismatch in argument 's' at (1); passed INTEGER(4) to LOGICAL(4)
FCFLAGS+=	-fallow-argument-mismatch
GCCLIBDIR=	${LDFLAGS}
USE_LDCONFIG=	yes
VEM=		${PORTVERSION:R:R:R}
MUMPSVERSION=	${PORTVERSION:R:R}
LIBRS=		cmumps dmumps mumps_common pord smumps zmumps
PLIST_SUB=	VE=${MUMPSVERSION} MUMPSVERSION=${DISTVERSION}

# TODO: flavorize with MPICH / OMPI / NOMPI
OPTIONS_DEFINE=	DOCS EXAMPLES MPICH
OPTIONS_DEFAULT=MPICH

MPICH_USES=		mpi:mpich
MPICH_LIB_DEPENDS_OFF=	libscotch.so:cad/scotch
MPICH_LIB_DEPENDS=	libblacs.so:math/blacs	\
			libptscotch.so:cad/scotch	\
			libscalapack.so:math/scalapack
MPICH_PLIST_SUB=	WITH_LIBSEQ="@comment "
MPICH_PLIST_SUB_OFF=	WITH_LIBSEQ=""
MPICH_VARS_OFF=		LIBRS+=mpiseq

MAKE_JOBS_UNSAFE=yes

pre-configure:
	${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
.for MF in Makefile PORD/lib/Makefile libseq/Makefile src/Makefile	\
	Make.inc/Makefile.FREEBSD10.PAR Make.inc/Makefile.FREEBSD10.SEQ
	${REINPLACE_CMD} -e 's+/usr/local+${LOCALBASE}+; \
	s+@CFLAGS@+${CFLAGS} -fPIC+g; \
	s+@FCFLAGS@+${FCFLAGS} -fPIC+g; \
	s+@SOVER@+${VEM}+g; \
	s+@GCCLIBDIR@+${GCCLIBDIR}+g; \
	s+@FORTRANLIBS@+${FORTRANLIBS}+g; \
	s+@BLASLIB@+${BLASLIB}+ ; \
	s+@LAPACKLIB@+${LAPACKLIB}+ ; \
	s+@MPI_CFLAGS@+${MPI_CFLAGS}+ ; \
	s+@MPI_LIBS@+${MPI_LIBS}+ ; \
	s+@LOCALBASE@+${LOCALBASE}+g;' \
		${WRKSRC}/${MF}
.endfor

pre-configure-MPICH-on:
	${REINPLACE_CMD} -e 's+@CC@+${MPICC}+g ; s+@FC@+${MPIF90}+'	\
		${WRKSRC}/Make.inc/Makefile.FREEBSD10.PAR
	${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.FREEBSD10.PAR \
		${WRKSRC}/Makefile.inc

pre-configure-MPICH-off:
	${REINPLACE_CMD} -e 's+@CC@+${CC}+g ; s+@FC@+${FC}+'	\
		${WRKSRC}/Make.inc/Makefile.FREEBSD10.SEQ
	${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.FREEBSD10.SEQ \
		${WRKSRC}/Makefile.inc

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/lib*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/lib*.so ${STAGEDIR}${PREFIX}/lib
.for lib in ${LIBRS}
	(cd ${STAGEDIR}${PREFIX}/lib &&	\
	${LN} -sf lib${lib}.so ${STAGEDIR}${PREFIX}/lib/lib${lib}.so.${VEM})
.endfor

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/userguide_${DISTVERSION}.pdf ${STAGEDIR}${DOCSDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ex in Makefile README *.c *.F input_simpletest_*
	${INSTALL_DATA} ${WRKSRC}/examples/${ex} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for ex in c_example *simpletest
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${ex} ${STAGEDIR}${EXAMPLESDIR}
.endfor

do-install-MPICH-off:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/mumps_seq
	${INSTALL_DATA} ${WRKSRC}/libseq/mpi.h ${STAGEDIR}${PREFIX}/include/mumps_seq/mpi.h
	${INSTALL_DATA} ${WRKSRC}/libseq/libmpiseq.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libseq/libmpiseq*.so ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib &&	\
	${LN} -sf libmpiseq.so ${STAGEDIR}${PREFIX}/lib/libmpiseq.so.5)
.for lib in ${LIBRS} mpiseq
. for ext in a so so.5
	(cd ${STAGEDIR}${PREFIX}/lib &&	\
	${LN} -sf lib${lib}.${ext} ${STAGEDIR}${PREFIX}/lib/lib${lib}_seq.${ext})
. endfor
.endfor

.if defined(MAINTAINER_MODE)
do-test:	install
	(cd ${WRKSRC}/examples &&	\
	./ssimpletest < input_simpletest_real ;			\
	./dsimpletest < input_simpletest_real ;			\
	./csimpletest < input_simpletest_cmplx ;		\
	./zsimpletest < input_simpletest_cmplx ;		\
	${ECHO_MSG} "The solution should be (1,2,3,4,5)" ;	\
	./c_example ;						\
	${ECHO_MSG} "The solution should be (1,2)")
.endif

.include <bsd.port.mk>
