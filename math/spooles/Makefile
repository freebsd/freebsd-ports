# New ports collection makefile for:	Spooles
# Date created:         26 Jan 2002
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	spooles
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.netlib.org/linalg/spooles/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz
.ifndef NOPORTDOCS
DISTFILES+=     ${DISTNAME}${EXTRACT_SUFX} AllInOne.ps.gz Eigen.ps.gz \
	 	Install.ps.gz LinSol.ps.gz Ordering.ps.gz \
		PP99.ps.gz ReferenceManual.ps.gz
.endif
DIST_SUBDIR=    spooles
EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SParse Object Oriented Linear Equations Solver

.if defined(USE_MPI)
BUILD_DEPENDS=	${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich
.endif

USE_GMAKE=	yes	#BSD make gives problems here
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	global

.if defined(USE_THREADS)
PLIST_SUB+=     MT=""
CFLAGS+= ${PTHREAD_CFLAGS}
.else
PLIST_SUB+=     MT="@comment "
.endif
.if defined(USE_MPI)
PLIST_SUB+=     MPI=""
.else
PLIST_SUB+=     MPI="@comment "
.endif

.SILENT:

pre-everything::
.if !defined(USE_THREADS)
	${ECHO_MSG} "make USE_THREADS=yes for threaded version"
.endif
.if !defined(USE_MPI)
	${ECHO_MSG} "make USE_MPI=yes for mpich version"
.endif

.if defined (USE_THREADS) && (USE_MPI)
BROKEN= mpich is *NOT* threadsafe at the moment
.endif

post-patch:
.if defined(USE_THREADS)
	@${REINPLACE_CMD} -e 's+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g;' ${WRKSRC}/Make.inc
.else
	@${REINPLACE_CMD} -e 's+%%PTHREAD_LIBS%%++g;' ${WRKSRC}/Make.inc
	@${REINPLACE_CMD} -e 's+THREAD_TYPE TT_POSIX+THREAD_TYPE TT_NONE+;' ${WRKSRC}/Lock/Lock.h
.endif
.if defined(USE_MPI)
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' ${WRKSRC}/Make.inc
.endif

post-build:
.if defined(USE_THREADS)
	@(cd ${WRKSRC}/MT/src; $(GMAKE) -f makeGlobalLib)
.endif
.if defined(USE_MPI)
	@(cd ${WRKSRC}/MPI/src; $(GMAKE) -f makeGlobalLib)
.endif

do-install:
	${MKDIR} ${PREFIX}/include/spooles
	${INSTALL} ${WRKSRC}/spooles.a ${PREFIX}/lib/libspooles.a
.if defined(USE_THREADS)
	${MKDIR} ${PREFIX}/include/spooles/MT
	${INSTALL_DATA} ${WRKSRC}/MT/*.h ${PREFIX}/include/spooles/MT
.endif
.if defined(USE_MPI)
	${MKDIR} ${PREFIX}/include/spooles/MPI
	${INSTALL_DATA} ${WRKSRC}/MPI/*.h ${PREFIX}/include/spooles/MPI
.endif
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/spooles/
.for i in A2 BPG Chv ChvList ChvManager Coords DenseMtx DSTree Drand \
	DV ETree FrontMtx GPart Graph I2Ohash IIheap IV IVL Ideq InpMtx \
	Lock MSMD PatchAndGoInfo Pencil SolveMap SubMtx SubMtxList SubMtxManager \
	SymbFac Tree Utilities ZV misc
	${MKDIR} ${PREFIX}/include/spooles/${i}
	${INSTALL_DATA} ${WRKSRC}/${i}/*.h ${PREFIX}/include/spooles/${i}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/AllInOne.ps.gz	${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Eigen.ps.gz		${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Install.ps.gz		${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/LinSol.ps.gz		${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Ordering.ps.gz	${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/PP99.ps.gz		${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/ReferenceManual.ps.gz	${DOCSDIR}
.endif

.include <bsd.port.mk>
