# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	mumps
DISTVERSION=	5.1.1-aster2
PORTREVISION=	2
CATEGORIES=	math
PKGNAMESUFFIX=	-edf

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	MUltifrontal Massively Parallel sparse direct Solver for Code_Aster

LICENSE=	CeCILL_C
LICENSE_NAME=	CeCILL-C
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libblas.so:math/blas		\
		liblapack.so:math/lapack	\
		libmetis.so:math/metis

USES=		fortran

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
BLAS_LIBS=	-lblas
LAPACK_LIBS=	-llapack
FORTRANLIBS=	-lgfortran
GCCLIBDIR=	${LDFLAGS}
USE_LDCONFIG=	yes
VEM=		${PORTVERSION:R:R:R}
MUMPSVERSION=	${PORTVERSION:R}
LIBS=		cmumps dmumps mumps_common pord smumps zmumps
PLIST_SUB=	VE=${VEM} MUMPSVERSION=${MUMPSVERSION}

CONFLICTS=	mumps-4* mumps-mpich-4*

OPTIONS_DEFINE=	DOCS EXAMPLES

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../french/aster/bsd.aster.mk"

.ifdef WITH_MPI
PKGNAMESUFFIX+=		-mpich
BUILD_DEPENDS+=	${LOCALBASE}/include/mpif.h:net/mpich2		\
		${LOCALBASE}/lib/libblacs.a:math/blacs		\
		${LOCALBASE}/lib/libptscotch.a:cad/scotch	\
		${LOCALBASE}/lib/libscalapack.a:math/scalapack	\
		${LOCALBASE}/lib/parmetis/libmetis.a:math/parmetis
LIB_DEPENDS+=	liblapack.so:math/lapack
# Note: -l?mumps still requires to be linked with -lblacs + -lscalapack
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:net/mpich2	\
		${LOCALBASE}/lib/libblacs.a:math/blacs	\
		${LOCALBASE}/lib/libscalapack.a:math/scalapack
PLIST_SUB+=	WITH_LIBSEQ="@comment "
CONFLICTS+=	mumps-5*
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libscotch.a:cad/scotch
PLIST_SUB+=	WITH_LIBSEQ=""
LIBS+=		mpiseq
CONFLICTS+=	mumps-mpich-5*
.endif

pre-configure:
.ifdef WITH_MPI
	${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.FREEBSD10.PAR \
		${WRKSRC}/Makefile.inc
.else
	${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.FREEBSD10.SEQ \
		${WRKSRC}/Makefile.inc
.endif
	${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
.for MF in Makefile Makefile.inc PORD/lib/Makefile libseq/Makefile src/Makefile
	${REINPLACE_CMD} -e 's+@CC@+${CC}+g ; s+@FC@+${FC}+g ; \
	s+/usr/local+${LOCALBASE}+; \
	s+@CFLAGS@+${CFLAGS} -fPIC+g; \
	s+@FCFLAGS@+${FCFLAGS} -fPIC+g; \
	s+@SOVER@+${VEM}+g; \
	s+@GCCLIBDIR@+${GCCLIBDIR}+g; \
	s+@FORTRANLIBS@+${FORTRANLIBS}+g; \
	s+@BLAS_LIBS@+${BLAS_LIBS}+ ; \
	s+@LAPACK_LIBS@+${LAPACK_LIBS}+ ; \
	s+@LOCALBASE@+${LOCALBASE}+g;' \
		${WRKSRC}/${MF}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/lib*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/lib*.so.${VEM} ${STAGEDIR}${PREFIX}/lib
.ifndef WITH_MPI
	${INSTALL_DATA} ${WRKSRC}/libseq/libmpiseq.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libseq/libmpiseq*.so.${VEM} ${STAGEDIR}${PREFIX}/lib
.endif
.for lib in ${LIBS}
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf lib${lib}.so.${VEM} ${STAGEDIR}${PREFIX}/lib/lib${lib}.so)
. endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/userguide_${MUMPSVERSION}.pdf ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
. for ex in Makefile README *.c *.F input_simpletest_*
	${INSTALL_DATA} ${WRKSRC}/examples/${ex} ${STAGEDIR}${EXAMPLESDIR}
. endfor
. for ex in c_example *simpletest
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${ex} ${STAGEDIR}${EXAMPLESDIR}
. endfor

regression-test:	install
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
