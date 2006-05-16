# New ports collection makefile for:	FreeFem++
# Date created:        17 October 2003
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	freefem++
DISTVERSION=	2.7-2
CATEGORIES=	math science
MASTER_SITES=	http://www.freefem.org/ff++/ftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of a language dedicated to the finite element method

LIB_DEPENDS=	atlas.1:${PORTSDIR}/math/atlas				\
		f2c.2:${PORTSDIR}/lang/f2c				\
		gsl.9:${PORTSDIR}/math/gsl				\
		lapack.3:${PORTSDIR}/math/lapack			\
		fltk.1:${PORTSDIR}/x11-toolkits/fltk-threads		\
		fftw3.4:${PORTSDIR}/math/fftw3
BUILD_DEPENDS=	${LOCALBASE}/lib/libumfpack.a:${PORTSDIR}/math/umfpack	\
		${LOCALBASE}/lib/libarpack.a:${PORTSDIR}/math/arpack	\
		convert:${PORTSDIR}/graphics/ImageMagick		\
		dvips:${PORTSDIR}/print/dvipsk-tetex			\
		pdflatex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	dvips:${PORTSDIR}/print/dvipsk-tetex			\
		pdflatex:${PORTSDIR}/print/teTeX-base			\
		bamg:${PORTSDIR}/math/bamg

RESTRICTED=	No resale or commercial use

USE_GL=			yes
USE_GCC=		3.4
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--disable-download					\
			--with-blas="${LIBBLAS}"				\
			--with-amd="-lamd"					\
			--with-umfpack="-lumfpack"				\
			--with-arpack="${LIBARPACK}"
CONFIGURE_ENV=		CPPFLAGS="${MPICFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"	\
			LDFLAGS="${MPILDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"

LIBBLAS=	-lf2c -lf77blas -latlas -lgslcblas
LIBARPACK=	-larpack -lalapack ${LIBBLAS}

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

.if exists(${LOCALBASE}/mpich/bin/mpiCC)
WITH_MPI=	yes
.endif
.if defined(WITH_MPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpich/bin/mpiCC:${PORTSDIR}/net/mpich
RUN_DEPENDS+=	${LOCALBASE}/mpich/bin/mpiCC:${PORTSDIR}/net/mpich
MPICFLAGS=	-I${LOCALBASE}/mpich/include
MPILDFLAGS=	-L${LOCALBASE}/mpich/lib
CONFIGURE_ENV+=	PATH="$$PATH:${LOCALBASE}/mpich/bin"
CONFIGURE_ARGS+=	--with-mpi=yes
PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g"		\
		-e "s|=mpiCC|=${LOCALBASE}/mpich/bin/mpiCC|"		\
		-e "s|/usr/X11R6|${X11BASE}|g"				\
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e "s|mpiCC|${LOCALBASE}/mpich/bin/mpiCC|"	\
		${WRKSRC}/src/mpi/Makefile.in

post-build:
.if !defined(NOPORTDOCS)
	(cd ${BUILD_WRKSRC}/DOC;	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${DOC_TARGET}; \
	${CP} ${DOC_TARGET} ${BUILD_WRKSRC})
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
. for direx in "" -bug -chapt3 -eigen -load -mpi -other -tutorial
	@cd ${WRKSRC}/examples++${direx} && ${FIND} . -type d	\
		-exec ${MKDIR} ${EXAMPLESDIR}/${direx:S/-//}/{} \;
	@cd ${WRKSRC}/examples++${direx} && ${FIND} -L . -type f	\
		-exec ${INSTALL_DATA} ${WRKSRC}/examples++${direx}/{}	\
			${EXAMPLESDIR}/${direx:S/-//} \;
. endfor
	@${FIND} ${EXAMPLESDIR} -name "Makefile*" -delete
	@${RMDIR} ${EXAMPLESDIR}/load/include
. for sample in ${BADSAMPLES}
	@${RM} ${EXAMPLESDIR}/${sample}
. endfor
	@${ECHO_MSG} "===>  Examples installed in ${EXAMPLESDIR}."
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
	# Gnuplot needed! Click on the picture to end a set.
.for direx in - -eigen -tutorial
	(cd ${EXAMPLESDIR}/${direx:S/-//} ;	\
	${PREFIX}/bin/FreeFem++ all.edp)
.endfor
.endif

.include <bsd.port.post.mk>
