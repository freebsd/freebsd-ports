# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	mumps4
PORTVERSION=	4.10.0	# Please do not upgrade to 5+: use math/mumps
PORTREVISION=	3
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

USES=		fortran

MAKE_JOBS_UNSAFE=yes

FFLAGS+=	-ffast-math
FORTRANLIBS=	-lgfortran
GCCLIBDIR=	${LDFLAGS}
USE_LDCONFIG=	yes
VEM=		${PORTVERSION:R:R}
LIBS=		cmumps dmumps mumps_common pord smumps zmumps

CONFLICTS+=	mumps-mpich-4*

OPTIONS_DEFINE=	DOCS EXAMPLES

LIBS+=		mpiseq

PLIST_SUB+=	MUMPSVERSION=${PORTVERSION} MUMPSV=${VEM}

#-----------------------------------------------------------------------
# WARNING: Non-serviceable parts inside, can break other ports
# You may define these options/knobs:
#
# FFLAGS: Fortran compiler flags for gfortran
# BLASLIB: specify other version of BLAS
# WITH_ATLAS: Use ATLAS instead of the regular BLAS
#-----------------------------------------------------------------------

.include <bsd.port.pre.mk>

# This is like blaslapack, except we don't use lapack at all
.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	libatlas.so:math/atlas
BLASLIB=	-lf77blas
#LAPACKLIB=	-lalapack -lcblas
.else
LIB_DEPENDS+=	libblas.so:math/blas
BLASLIB=	-lblas
#LAPACKLIB=	-llapack
.endif

pre-configure:
	${INSTALL_DATA} ${WRKSRC}/Make.inc/Makefile.inc.generic.SEQ \
		${WRKSRC}/Makefile.inc
	${REINPLACE_CMD} -e 's+LIBPAR+LIBSEQ+' ${WRKSRC}/src/Makefile

pre-build:
	${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
.for MF in Makefile Makefile.inc PORD/lib/Makefile libseq/Makefile src/Makefile
	${REINPLACE_CMD} -e 's+@CC@+${CC}+g ; s+@FC@+${FC}+g ; \
	s+@CFLAGS@+${CFLAGS} -fPIC+g; \
	s+@FCFLAGS@+${FCFLAGS} -fPIC+g; \
	s+@SOVER@+${VEM}+g; \
	s+@GCCLIBDIR@+${GCCLIBDIR}+g; \
	s+@FORTRANLIBS@+${FORTRANLIBS}+g; \
	s+@BLAS_LIBS@+${BLASLIB}+ ; \
	s+@LOCALBASE@+${LOCALBASE}+g;' \
		${WRKSRC}/${MF}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/lib*.a ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/lib/lib*.so.${VEM} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libseq/libmpiseq.a ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/libseq/libmpiseq*.so.${VEM} ${STAGEDIR}${PREFIX}/lib
.for lib in ${LIBS}
	(cd ${STAGEDIR}${PREFIX}/lib &&	\
		${LN} -sf lib${lib}.so.${VEM} ${STAGEDIR}${PREFIX}/lib/lib${lib}4.so)
. endfor
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

regression-test:	install
	(cd ${WRKSRC}/examples &&	\
	./ssimpletest < input_simpletest_real ;			\
	./dsimpletest < input_simpletest_real ;			\
	./csimpletest < input_simpletest_cmplx ;		\
	./zsimpletest < input_simpletest_cmplx ;		\
	${ECHO_MSG} "The solution should be (1,2,3,4,5)" ;	\
	./c_example ;						\
	${ECHO_MSG} "The solution should be (1,2)")

.include <bsd.port.post.mk>
