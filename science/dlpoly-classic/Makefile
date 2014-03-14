# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	dlpoly
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	science java
MASTER_SITES=	http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/
PKGNAMESUFFIX=	classic
DISTNAME=	dl_class_${PORTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Molecular dynamics simulation package

BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:${PORTSDIR}/net/openmpi
RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi

OPTIONS_DEFINE=	GUI DOCS EXAMPLES
OPTIONS_DEFAULT=	GUI
GUI_DESC=	Install Java GUI

USES=		fortran gmake

SUB_FILES=	dlpoly-gui

BUILD_WRKSRC=	${WRKSRC}/source

MPIF90=		${LOCALBASE}/mpi/openmpi/bin/mpif90

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/execute ${EXAMPLESDIR}
	${RM} ${EXAMPLESDIR}/execute/dlpoly*
.endif
.if ${PORT_OPTIONS:MGUI}
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/java/GUI.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/dlpoly-gui ${PREFIX}/bin
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
