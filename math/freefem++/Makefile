# New ports collection makefile for:	FreeFem++
# Date created:        17 October 2003
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	freefem++
DISTVERSION=	1.45-6
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Gamma/freefem/	\
		http://mule.ann.jussieu.fr/~hecht/ftp/freefem/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of a language dedicated to the finite element method

LIB_DEPENDS=	atlas.1:${PORTSDIR}/math/atlas				\
		f2c.2:${PORTSDIR}/lang/f2c				\
		gsl.7:${PORTSDIR}/math/gsl				\
		lapack.3:${PORTSDIR}/math/lapack			\
		fltk.1:${PORTSDIR}/x11-toolkits/fltk-threads
BUILD_DEPENDS=	${LOCALBASE}/lib/libumfpack.a:${PORTSDIR}/math/umfpack	\
		${LOCALBASE}/lib/libarpack.a:${PORTSDIR}/math/arpack	\
		dvips:${PORTSDIR}/print/dvipsk-tetex			\
		pdflatex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	dvips:${PORTSDIR}/print/dvipsk-tetex			\
		pdflatex:${PORTSDIR}/print/teTeX-base

RESTRICTED=	No resale or commercial use

USE_GL=			yes
USE_GCC=		3.4
USE_GMAKE=		yes
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--disable-download					\
			--with-blas="${LIBBLAS}"				\
			--with-amd="-lamd"					\
			--with-umfpack="-lumfpack"				\
			--with-arpack="${LIBARPACK}"
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"	\
			LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

LIBBLAS=	-lf2c -lf77blas -latlas -lgslcblas
LIBARPACK=	-larpack -lalapack ${LIBBLAS}

DOCS=		AUTHORS BUGS COPYING HISTORY README TODO DOC/manual-full.pdf
BADSAMPLES=	load/myfunction.o tutorial/Makefile.in.orig

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
PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g"		\
		-e "s|mpiCC|${LOCALBASE}/mpich/bin/mpiCC|"		\
		-e "s|/usr/X11R6|${X11BASE}|g"				\
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e "s|mpiCC|${LOCALBASE}/mpich/bin/mpiCC|"	\
		${WRKSRC}/src/mpi/Makefile.in

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/FreeFem++ ${PREFIX}/bin/FreeFem++-nw
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
. for direx in "" -bug -eigen -load -mpi -other -tutorial
	@${MKDIR} ${EXAMPLESDIR}/${direx:S/-//}
	@for sample in `${LS} ${WRKSRC}/examples++${direx}` ; do	\
		${INSTALL_DATA} ${WRKSRC}/examples++${direx}/$$sample	\
			${EXAMPLESDIR}/${direx:S/-//} ;			\
	done
	@(cd ${EXAMPLESDIR}/${direx:S/-//} &&				\
	${RM} Makefile.am Makefile.in Makefile)
. endfor
. for sample in ${BADSAMPLES}
	@${RM} ${EXAMPLESDIR}/${sample}
. endfor
	@${ECHO_MSG} "===>  Examples installed in ${EXAMPLESDIR}."
.endif

.if defined(MAINTAINER_MODE)
test:	install
	# Gnuplot needed! Click on the picture to end a set.
.for direx in - -eigen -tutorial
	(cd ${EXAMPLESDIR}/${direx:S/-//} ;	\
	${PREFIX}/bin/FreeFem++ all.edp)
.endfor
.endif

.include <bsd.port.post.mk>
