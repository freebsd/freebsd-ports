# New ports collection makefile for:	FreeFem++
# Date created:        17 October 2003
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	freefem++
PORTVERSION=	1.37
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Gamma/freefem/	\
		http://mule.ann.jussieu.fr/~hecht/ftp/freefem/
DISTNAME=	FreeFem++v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of a language dedicated to the finite element method

LIB_DEPENDS=	atlas.1:${PORTSDIR}/math/atlas
BUILD_DEPENDS=	${LOCALBASE}/include/ARPACK++:${PORTSDIR}/math/arpack++

RESTRICTED=	No resale or commercial use

USE_XLIB=	yes
USE_GMAKE=	yes

MAKE_ENV=	CXX=${CXX} HOSTTYPE=${HOSTTYPE}

DOCS=		BUGS COPYRIGHT HISTORY README DOC/manual.pdf

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501103
USE_GCC=	3.2
.endif

HOSTTYPE!=	${UNAME} -s

post-patch:
	@${MV} ${WRKSRC}/src/Makefile-linux ${WRKSRC}/src/Makefile-${HOSTTYPE}
	@${MV} ${WRKSRC}/src/Makefile-linux.orig ${WRKSRC}/src/Makefile-linux

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/FreeFem++ ${PREFIX}/bin/FreeFem++-nw
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
.for direx in "" -bug -eigen -load -mpi -tutorial
	@${MKDIR} ${EXAMPLESDIR}/${direx:S/-//}
	@for sample in `${LS} ${WRKSRC}/examples++${direx}` ; do	\
		${INSTALL_DATA} ${WRKSRC}/examples++${direx}/$$sample	\
			${EXAMPLESDIR}/${direx:S/-//} ;			\
	done
.endfor
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
