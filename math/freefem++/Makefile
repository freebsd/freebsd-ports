# New ports collection makefile for:	FreeFem++
# Date created:        17 October 2003
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	freefem++
DISTVERSION=	3.0-5
PORTREVISION=	2
CATEGORIES=	math science
MASTER_SITES=	http://www.freefem.org/ff++/ftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of a language dedicated to the finite element method

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk-threads		\
		fftw3.5:${PORTSDIR}/math/fftw3				\
		umfpack.1:${PORTSDIR}/math/suitesparse			\
		arpack.1:${PORTSDIR}/math/arpack			\
		gsl.13:${PORTSDIR}/math/gsl
BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick		\
		dvips:${PORTSDIR}/print/dvipsk-tetex			\
		pdflatex:${PORTSDIR}/print/teTeX-base			\
		${LOCALBASE}/lib/libtet.a:${PORTSDIR}/math/tetgen
RUN_DEPENDS=	dvips:${PORTSDIR}/print/dvipsk-tetex			\
		pdflatex:${PORTSDIR}/print/teTeX-base			\
		bamg:${PORTSDIR}/math/bamg

RESTRICTED=	No resale or commercial use
DEPRECATED=	fails to compile with up-to-date compilers, nobody really interested
EXPIRATION_DATE=2009-08-20

USE_FORTRAN=		yes
FORTRANLIBDIR=		`${DIRNAME} \`${FC} -print-libgcc-file-name\``
FORTRANLIBDIR2=		`${DIRNAME} \`${FC} -print-libgcc-file-name\``/../../../
USE_BISON=		build
USE_GL=			glut
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-download					\
			--without-wget						\
			--without-cadna						\
			--with-blas="${BLAS}"					\
			--with-lapack="${LAPACK}"				\
			--with-amd="-lamd"					\
			--with-umfpack="-lumfpack"				\
			--with-arpack="${ARPACK}"
CONFIGURE_ENV=		CPPFLAGS="${MPICFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/suitesparse/include ${PTHREAD_CFLAGS}"	\
			LDFLAGS="${MPILDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

DOC_TARGET=	freefem++doc.pdf
PORTDOCS=	AUTHORS BUGS COPYING HISTORY HISTORY_BEFORE_2005 INNOVATION README TODO ${DOC_TARGET}
BADSAMPLES=	load/myfunction.o

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAKE_ARGS+=	"PIC=-fPIC"
.endif

.if ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--disable-optim
.endif

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lcblas -lf77blas -latlas -L${FORTRANLIBDIR} -L${FORTRANLIBDIR2} -lgfortranbegin -lgfortran
LAPACK=		-lalapack ${BLAS}
ARPACK=		-larpack
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack ${BLAS}
ARPACK=		-larpack
.endif

.if exists(${LOCALBASE}/mpich2/include/mpicxx.h) && !defined(WITHOUT_MPI)
WITH_MPI=	yes
.endif
.if defined(WITH_MPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpich2/bin/mpicxx:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/mpich2/bin/mpiexec:${PORTSDIR}/net/mpich2
MPICFLAGS=	-I${LOCALBASE}/mpich2/include -DMPICH_IGNORE_CXX_SEEK
MPILDFLAGS=	-L${LOCALBASE}/mpich2/lib
CONFIGURE_ENV+=	PATH="$$PATH:${LOCALBASE}/mpich2/bin"
CONFIGURE_ARGS+=	--with-mpi=${LOCALBASE}/mpich2/bin/mpicxx
PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
CONFIGURE_ARGS+=	--without-mpi
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g"		\
		-e "s|/usr/X11R6|${LOCALBASE}|g"				\
		${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e "s|mpicc|${LOCALBASE}/mpich2/bin/mpicxx|"	\
		${WRKSRC}/src/mpi/Makefile.in
.for sf in configure src/mpi/parallelempi.cpp
	${REINPLACE_CMD} -e 's|mpi++.h|mpicxx.h|' ${WRKSRC}/${sf}
.endfor
#	${FIND} ${WRKSRC} -name "*.edp" | ${XARGS} \
#		${REINPLACE_CMD} -e 's|exec("medit|// exec("medit|g'

post-build:
.if !defined(NOPORTDOCS)
	(cd ${BUILD_WRKSRC}/DOC;	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${DOC_TARGET}; \
	${CP} ${DOC_TARGET} ${BUILD_WRKSRC})
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
. for direx in "" -3d -bug -chapt3 -eigen -load -mpi -other -tutorial
	cd ${WRKSRC}/examples++${direx} && ${FIND} . -type d	\
		-exec ${MKDIR} ${EXAMPLESDIR}/${direx:S/-//}/{} \;
	cd ${WRKSRC}/examples++${direx} && ${FIND} -L . -type f	\
		-exec ${INSTALL_DATA} ${WRKSRC}/examples++${direx}/{}	\
			${EXAMPLESDIR}/${direx:S/-//} \;
. endfor
	${FIND} ${EXAMPLESDIR} -name "Makefile*" -delete
	${RMDIR} ${EXAMPLESDIR}/load/include
. for sample in ${BADSAMPLES}
	${RM} ${EXAMPLESDIR}/${sample}
. endfor
	@${ECHO_MSG} "===>  Examples installed in ${EXAMPLESDIR}."
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
	# Gnuplot and medit needed! Click on the picture to end a set.
	(cd ${WRKSRC}/examples++ &&	\
	${PREFIX}/bin/FreeFem++ regtests.edp)
.endif

.include <bsd.port.post.mk>
