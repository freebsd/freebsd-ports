# New ports collection makefile for:	Spooles
# Date created:         26 Jan 2002
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	spooles
PORTVERSION=	2.2
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	http://www.netlib.org/linalg/spooles/
.ifdef WITH_MPI
PKGNAMESUFFIX=	-mpich
.endif
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz
.ifndef NOPORTDOCS
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} AllInOne.ps.gz Eigen.ps.gz \
	 	Install.ps.gz LinSol.ps.gz Ordering.ps.gz \
		PP99.ps.gz ReferenceManual.ps.gz
.endif
DIST_SUBDIR=	spooles
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SParse Object Oriented Linear Equations Solver

.if defined(WITH_MPI)
BUILD_DEPENDS=	${LOCALBASE}/lib/libmpich.a:${PORTSDIR}/net/mpich2
.endif

USE_GMAKE=	yes	#BSD make gives problems here

.if defined(WITH_MPI)
PLIST_SUB+=	MPI=""
PLIST_SUB+=	MT="@comment "
CONFLICTS=	spooles-2*
.else
PLIST_SUB+=	MT=""
PLIST_SUB+=	MPI="@comment "
CONFLICTS=	spooles-mpich-2*
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

.SILENT:

pre-everything::
.if !defined(WITH_MPI)
	${ECHO_MSG} "make WITH_MPI=yes for mpich version"
.endif

do-extract:
	${MKDIR} ${WRKSRC} ; cd ${WRKSRC} ; ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

post-patch:
	${MKDIR} ${WRKSRC}_SHARED ; ${CP} -r ${WRKSRC}/* ${WRKSRC}_SHARED
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' -e 's+%%CFLAGS%%+${PTHREAD_CFLAGS} ${CFLAGS}+g;' -e 's+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g;' -e 's+%%CC%%+${CC}+g;' ${WRKSRC}/Make.inc
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' -e 's+%%CFLAGS%%+${CFLAGS} ${PTHREAD_CFLAGS} ${PICFLAG}+g;' -e 's+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g;' -e 's+%%CC%%+${CC}+g;' ${WRKSRC}_SHARED/Make.inc

do-build:
.if defined(WITH_MPI)
	@(cd ${WRKSRC}/MPI/src ; ${SETENV} ${MAKE_ENV} ${GMAKE} -f makeGlobalLib)
	@(cd ${WRKSRC}_SHARED/MPI/src; ${SETENV} ${MAKE_ENV} ${GMAKE} -f makeGlobalLib)
	@(cd ${WRKSRC}_SHARED ; ld -Bshareable -o libspooles.so.1 -x -soname libspooles.so.1 --whole-archive spooles.a )

.else
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} global -f makefile)
	@(cd ${WRKSRC}/MT/src; ${SETENV} ${MAKE_ENV} ${GMAKE} -f makeGlobalLib)
	@(cd ${WRKSRC}_SHARED; ${SETENV} ${MAKE_ENV} ${GMAKE} global -f makefile)
	@(cd ${WRKSRC}_SHARED/MT/src; ${SETENV} ${MAKE_ENV} ${GMAKE} -f makeGlobalLib)
	@(cd ${WRKSRC}_SHARED ; ld -Bshareable -o libspooles.so.1 -x -soname libspooles.so.1 --whole-archive spooles.a )
.endif

do-install:
	${MKDIR} ${PREFIX}/include/spooles
	${INSTALL_DATA} ${WRKSRC}/spooles.a ${PREFIX}/lib/libspooles.a
	${INSTALL_DATA} ${WRKSRC}_SHARED/libspooles.so.1 ${PREFIX}/lib
	${LN} -sf libspooles.so.1 ${PREFIX}/lib/libspooles.so

.if defined(WITH_MPI)
	${MKDIR} ${PREFIX}/include/spooles/MPI
	${INSTALL_DATA} ${WRKSRC}/MPI/*.h ${PREFIX}/include/spooles/MPI
.else
	${MKDIR} ${PREFIX}/include/spooles/MT
	${INSTALL_DATA} ${WRKSRC}/MT/*.h ${PREFIX}/include/spooles/MT
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

.include <bsd.port.post.mk>
