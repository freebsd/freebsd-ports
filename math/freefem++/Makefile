# New ports collection makefile for:	FreeFem++
# Date created:        17 October 2003
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	freefem++
PORTVERSION=	1.41
CATEGORIES=	math science
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Gamma/freefem/	\
		http://mule.ann.jussieu.fr/~hecht/ftp/freefem/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of a language dedicated to the finite element method

LIB_DEPENDS=	atlas.1:${PORTSDIR}/math/atlas	\
		f2c.2:${PORTSDIR}/lang/f2c	\
		gsl.6:${PORTSDIR}/math/gsl
BUILD_DEPENDS=	${LOCALBASE}/include/ARPACK++:${PORTSDIR}/math/arpack++

RESTRICTED=	No resale or commercial use

USE_GL=			yes
USE_GCC=		3.4
USE_GMAKE=		yes
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--disable-download
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"	\
			LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

DOCS=		AUTHORS BUGS COPYING HISTORY README TODO DOC/manual.pdf
BADSAMPLES=	load/load.link.orig load/myfunction.o tutorial/Makefile.in.orig

pre-configure:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g"			\
		-e "s|/usr/local|${LOCALBASE}|g;s|/usr/X11R6|${X11BASE}|g"	\
		${WRKSRC}/${CONFIGURE_SCRIPT}

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

.include <bsd.port.mk>
