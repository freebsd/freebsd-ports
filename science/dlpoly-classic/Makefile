############################################################################
# New ports collection Makefile for:   dlpoly-classic
# Date created:        21 Jan 2010
# Whom:                Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#
############################################################################

PORTNAME=	dlpoly
PORTVERSION=	1.8
CATEGORIES=	science java
MASTER_SITES=	http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/
PKGNAMESUFFIX=	classic
DISTNAME=	dl_class_${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Molecular dynamics simulation package

BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:${PORTSDIR}/net/openmpi
RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi

OPTIONS=	GUI	"Install Java GUI"		on

USE_GMAKE=	yes
USE_FORTRAN=	yes

SUB_FILES=	dlpoly-gui

BUILD_WRKSRC=	${WRKSRC}/source

MPIF90=		${LOCALBASE}/mpi/openmpi/bin/mpif90

.include <bsd.port.options.mk>

.if defined(WITH_GUI)
USE_JAVA=	yes
PLIST_FILES+=	bin/dlpoly-gui \
		${DATADIR_REL}/GUI.jar
PLIST_DIRS+=	${DATADIR_REL}
.endif

post-patch:
	${CP} ${WRKSRC}/build/MakePAR ${WRKSRC}/build/MakeSEQ ${BUILD_WRKSRC}
	${REINPLACE_CMD} 's|gfortran|${FC}|g' ${BUILD_WRKSRC}/MakeSEQ
	${REINPLACE_CMD} 's|DLPOLY\.X|dlpoly-classic|g' ${BUILD_WRKSRC}/MakeSEQ
	${REINPLACE_CMD} 's|mpif90|${MPIF90}|g' \
		${BUILD_WRKSRC}/MakePAR
	${REINPLACE_CMD} 's|DLPOLY\.X|dlpoly-classic-mpi|g' \
		${BUILD_WRKSRC}/MakePAR

do-build:
	(cd ${BUILD_WRKSRC} && \
		${CP} -f MakeSEQ Makefile && \
		${MAKE} ${FC})
	(cd ${BUILD_WRKSRC} && \
		${MAKE} clean && \
		${CP} -f MakePAR Makefile && \
		${MAKE} gfortran)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic-mpi ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/* ${DOCSDIR}
.endif
.ifndef(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/execute ${EXAMPLESDIR}
	${RM} ${EXAMPLESDIR}/execute/dlpoly*
.endif
.if defined(WITH_GUI)
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/java/GUI.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/dlpoly-gui ${PREFIX}/bin
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
