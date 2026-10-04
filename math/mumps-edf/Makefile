PORTNAME=	mumps
DISTVERSION=	5.1.2-aster7
PORTREVISION=	6
CATEGORIES=	math
PKGNAMESUFFIX=	-edf

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	MUltifrontal Massively Parallel sparse direct Solver for Code_Aster
WWW=		https://mumps-solver.org/

LICENSE=	CeCILL_C
LICENSE_NAME=	CeCILL-C
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libmetis.so:math/metis

USES=		blaslapack fortran

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
FORTRANLIBS=	-lgfortran
GCCLIBDIR=	${LDFLAGS}
USE_LDCONFIG=	yes
VEM=		${PORTVERSION:R:R:R}
MUMPSVERSION=	${PORTVERSION:R}
LIBS=	cmumps dmumps mumps_common pord smumps zmumps
PLIST_SUB=	VE=${VEM} MUMPSVERSION=${MUMPSVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES MPICH

MPICH_USES=		mpi:mpich
MPICH_LIB_DEPENDS_OFF=	libscotch.so:cad/scotch
MPICH_LIB_DEPENDS=	libparmetis.so:math/parmetis	\
			libptscotch.so:cad/scotch	\
			libscalapack.so:math/scalapack
MPICH_PLIST_SUB=	WITH_LIBSEQ="@comment "
MPICH_PLIST_SUB_OFF=	WITH_LIBSEQ=""
MPICH_LIBS_OFF=		mpiseq

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../french/aster/bsd.aster.mk"

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch in argument 's' at (1); passed INTEGER(4) to LOGICAL(4)
FCFLAGS+=	-fallow-argument-mismatch
.endif

.ifdef WITH_MPICH
PKGNAMESUFFIX+=		-mpich
.endif

.if ${FORTRAN_DEFAULT} == gfortran && ${GCC_DEFAULT} >= 10
FCFLAGS+=	-fallow-argument-mismatch
.endif

post-patch-MPICH-on:
	${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.FREEBSD10.PAR \
		${WRKSRC}/Makefile.inc

post-patch-MPICH-off:
	${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.FREEBSD10.SEQ \
		${WRKSRC}/Makefile.inc

pre-configure:
	${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
.for MF in Makefile Makefile.inc PORD/lib/Makefile libseq/Makefile src/Makefile
	${REINPLACE_CMD} -e 's+@CC@+${CC}+g ; s+@FC@+${FC}+g ; \
	s+/usr/local+${LOCALBASE}+; \
	s+@CFLAGS@+${CFLAGS} -fPIC+g; \
	s+@FCFLAGS@+${FCFLAGS} -fPIC+g; \
	s+@SOVER@+${VEM}+g; \
	s+@GCCLIBDIR@+${GCCLIBDIR}+g; \
	s+@FORTRANLIBS@+${FORTRANLIBS}+g; \
	s+@BLAS_LIBS@+${BLASLIB}+ ; \
	s+@LAPACK_LIBS@+${LAPACKLIB}+ ; \
	s+@LOCALBASE@+${LOCALBASE}+g;' \
		${WRKSRC}/${MF}
.endfor

pre-configure-MPICH-on:
	${REINPLACE_CMD} -e '/lptscotch/s|#LSCOTCH|LSCOTCH|'	\
		-e 's|^LMETIS|##LMETIS|;s|^#LMETIS|LMETIS|' ${WRKSRC}/Makefile.inc

pre-configure-MPICH-off:
	${REINPLACE_CMD} -e '/lscotch/s|#LSCOTCH|LSCOTCH|' ${WRKSRC}/Makefile.inc

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/lib*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/lib*.so.${VEM} ${STAGEDIR}${PREFIX}/lib
.for lib in ${LIBS}
	(cd ${STAGEDIR}${PREFIX}/lib &&	\
	${LN} -sf lib${lib}.so.${VEM} ${STAGEDIR}${PREFIX}/lib/lib${lib}.so)
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/userguide_${MUMPSVERSION}.pdf ${STAGEDIR}${DOCSDIR}
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
	${INSTALL_LIB} ${WRKSRC}/libseq/libmpiseq*.so.${VEM} ${STAGEDIR}${PREFIX}/lib
.for lib in ${LIBS}
. for ext in a so so.${VEM}
	(cd ${STAGEDIR}${PREFIX}/lib &&	\
	${LN} -sf lib${lib}.${ext} ${STAGEDIR}${PREFIX}/lib/lib${lib}_seq.${ext})
. endfor
.endfor

test:	install
.if defined (WITH_MPICH) && defined(MAINTAINER_MODE)
.  if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
.  endif
	(cd ${WRKSRC}/examples &&	\
	${LOCALBASE}/bin/mpirun -np 2 ./ssimpletest < input_simpletest_real ;	\
	${LOCALBASE}/bin/mpirun -np 2 ./dsimpletest < input_simpletest_real ;	\
	${LOCALBASE}/bin/mpirun -np 2 ./csimpletest < input_simpletest_cmplx ;	\
	${LOCALBASE}/bin/mpirun -np 2 ./zsimpletest < input_simpletest_cmplx ;	\
	${ECHO_MSG} "The solution should be (1,2,3,4,5)" ;	\
	${LOCALBASE}/bin/mpirun -np 3 ./c_example ;	\
	${ECHO_MSG} "The solution should be (1,2)")
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
