# New ports collection makefile for:	Spooles
# Date created:         26 Jan 2002
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	spooles
PORTVERSION=	2.2
CATEGORIES=	math
MASTER_SITES=	http://www.netlib.org/linalg/spooles/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz
.if !defined(NOPORTDOCS)
DISTFILES+=     ${DISTNAME}${EXTRACT_SUFX} AllInOne.ps.gz Eigen.ps.gz \
	 	Install.ps.gz LinSol.ps.gz Ordering.ps.gz \
		PP99.ps.gz ReferenceManual.ps.gz
.endif
DIST_SUBDIR=    spooles
EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SParse Object Oriented Linear Equations Solver

USE_GMAKE=	yes	#BSD make gives problems here
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	global

.if !defined(USE_MPI)
PLIST_SUB+=     MPI="@comment "
.else
PLIST_SUB+=     MPI=""
.endif

post-patch:

.if defined(USE_MPI)
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' ${WRKSRC}/Make.inc
.endif

post-build:
.if defined(USE_MPI)
	@(cd ${WRKSRC}/MPI/src; $(MAKE) -f makeGlobalLib)
.else
	@(cd ${WRKSRC}/MT/src; $(MAKE) -f makeGlobalLib)
.endif

do-install:
	${INSTALL} ${WRKSRC}/spooles.a ${PREFIX}/lib/libspooles.a
	${MKDIR} ${PREFIX}/include/spooles
.if defined(USE_MPI)
	${MKDIR} ${PREFIX}/include/spooles/MPI
	${INSTALL_DATA} ${WRKSRC}/MPI/*.h ${PREFIX}/include/spooles/MPI
.endif
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/spooles/
	${MKDIR} ${PREFIX}/include/spooles/A2
	${INSTALL_DATA} ${WRKSRC}/A2/*.h ${PREFIX}/include/spooles/A2
	${MKDIR} ${PREFIX}/include/spooles/BPG
	${INSTALL_DATA} ${WRKSRC}/BPG/*.h ${PREFIX}/include/spooles/BPG
	${MKDIR} ${PREFIX}/include/spooles/Chv
	${INSTALL_DATA} ${WRKSRC}/Chv/*.h ${PREFIX}/include/spooles/Chv
	${MKDIR} ${PREFIX}/include/spooles/ChvList
	${INSTALL_DATA} ${WRKSRC}/ChvList/*.h ${PREFIX}/include/spooles/ChvList
	${MKDIR} ${PREFIX}/include/spooles/ChvManager
	${INSTALL_DATA} ${WRKSRC}/ChvManager/*.h ${PREFIX}/include/spooles/ChvManager
	${MKDIR} ${PREFIX}/include/spooles/Coords
	${INSTALL_DATA} ${WRKSRC}/Coords/*.h ${PREFIX}/include/spooles/Coords
	${MKDIR} ${PREFIX}/include/spooles/DenseMtx
	${INSTALL_DATA} ${WRKSRC}/DenseMtx/*.h ${PREFIX}/include/spooles/DenseMtx
	${MKDIR} ${PREFIX}/include/spooles/DSTree
	${INSTALL_DATA} ${WRKSRC}/DSTree/*.h ${PREFIX}/include/spooles/DSTree
	${MKDIR} ${PREFIX}/include/spooles/Drand
	${INSTALL_DATA} ${WRKSRC}/Drand/*.h ${PREFIX}/include/spooles/Drand
	${MKDIR} ${PREFIX}/include/spooles/DV
	${INSTALL_DATA} ${WRKSRC}/DV/*.h ${PREFIX}/include/spooles/DV
	${MKDIR} ${PREFIX}/include/spooles/ETree
	${INSTALL_DATA} ${WRKSRC}/ETree/*.h ${PREFIX}/include/spooles/ETree
	${MKDIR} ${PREFIX}/include/spooles/FrontMtx
	${INSTALL_DATA} ${WRKSRC}/FrontMtx/*.h ${PREFIX}/include/spooles/FrontMtx
	${MKDIR} ${PREFIX}/include/spooles/GPart
	${INSTALL_DATA} ${WRKSRC}/GPart/*.h ${PREFIX}/include/spooles/GPart
	${MKDIR} ${PREFIX}/include/spooles/Graph
	${INSTALL_DATA} ${WRKSRC}/Graph/*.h ${PREFIX}/include/spooles/Graph
	${MKDIR} ${PREFIX}/include/spooles/I2Ohash
	${INSTALL_DATA} ${WRKSRC}/I2Ohash/*.h ${PREFIX}/include/spooles/I2Ohash
	${MKDIR} ${PREFIX}/include/spooles/IIheap
	${INSTALL_DATA} ${WRKSRC}/IIheap/*.h ${PREFIX}/include/spooles/IIheap
	${MKDIR} ${PREFIX}/include/spooles/IV
	${INSTALL_DATA} ${WRKSRC}/IV/*.h ${PREFIX}/include/spooles/IV
	${MKDIR} ${PREFIX}/include/spooles/IVL
	${INSTALL_DATA} ${WRKSRC}/IVL/*.h ${PREFIX}/include/spooles/IVL
	${MKDIR} ${PREFIX}/include/spooles/Ideq
	${INSTALL_DATA} ${WRKSRC}/Ideq/*.h ${PREFIX}/include/spooles/Ideq
	${MKDIR} ${PREFIX}/include/spooles/InpMtx
	${INSTALL_DATA} ${WRKSRC}/InpMtx/*.h ${PREFIX}/include/spooles/InpMtx
	${MKDIR} ${PREFIX}/include/spooles/Lock
	${INSTALL_DATA} ${WRKSRC}/Lock/*.h ${PREFIX}/include/spooles/Lock
	${MKDIR} ${PREFIX}/include/spooles/MSMD
	${INSTALL_DATA} ${WRKSRC}/MSMD/*.h ${PREFIX}/include/spooles/MSMD
	${MKDIR} ${PREFIX}/include/spooles/MT
	${INSTALL_DATA} ${WRKSRC}/MT/*.h ${PREFIX}/include/spooles/MT
	${MKDIR} ${PREFIX}/include/spooles/PatchAndGoInfo
	${INSTALL_DATA} ${WRKSRC}/PatchAndGoInfo/*.h ${PREFIX}/include/spooles/PatchAndGoInfo
	${MKDIR} ${PREFIX}/include/spooles/Pencil
	${INSTALL_DATA} ${WRKSRC}/Pencil/*.h ${PREFIX}/include/spooles/Pencil
	${MKDIR} ${PREFIX}/include/spooles/SolveMap
	${INSTALL_DATA} ${WRKSRC}/SolveMap/*.h ${PREFIX}/include/spooles/SolveMap
	${MKDIR} ${PREFIX}/include/spooles/SubMtx
	${INSTALL_DATA} ${WRKSRC}/SubMtx/*.h ${PREFIX}/include/spooles/SubMtx
	${MKDIR} ${PREFIX}/include/spooles/SubMtxList
	${INSTALL_DATA} ${WRKSRC}/SubMtxList/*.h ${PREFIX}/include/spooles/SubMtxList
	${MKDIR} ${PREFIX}/include/spooles/SubMtxManager
	${INSTALL_DATA} ${WRKSRC}/SubMtxManager/*.h ${PREFIX}/include/spooles/SubMtxManager
	${MKDIR} ${PREFIX}/include/spooles/SymbFac
	${INSTALL_DATA} ${WRKSRC}/SymbFac/*.h ${PREFIX}/include/spooles/SymbFac
	${MKDIR} ${PREFIX}/include/spooles/Tree
	${INSTALL_DATA} ${WRKSRC}/Tree/*.h ${PREFIX}/include/spooles/Tree
	${MKDIR} ${PREFIX}/include/spooles/Utilities
	${INSTALL_DATA} ${WRKSRC}/Utilities/*.h ${PREFIX}/include/spooles/Utilities
	${MKDIR} ${PREFIX}/include/spooles/ZV/
	${INSTALL_DATA} ${WRKSRC}/ZV/*.h ${PREFIX}/include/spooles/ZV
	${MKDIR} ${PREFIX}/include/spooles/misc
	${INSTALL_DATA} ${WRKSRC}/misc/*.h ${PREFIX}/include/spooles/misc
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
