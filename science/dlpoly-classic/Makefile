# $FreeBSD$

PORTNAME=	dlpoly
PORTVERSION=	1.8
PORTREVISION=	16
CATEGORIES=	science java
MASTER_SITES=	http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/
PKGNAMESUFFIX=	classic
DISTNAME=	dl_class_${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Molecular dynamics simulation package

BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:net/openmpi
RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpirun:net/openmpi

OPTIONS_DEFINE=	GUI DOCS EXAMPLES
OPTIONS_DEFAULT=	GUI
GUI_DESC=	Install Java GUI

USES=		fortran gmake

SUB_FILES=	dlpoly-gui

BUILD_WRKSRC=	${WRKSRC}/source

MPIF90=		${LOCALBASE}/mpi/openmpi/bin/mpif90

GUI_USE=		JAVA=yes
GUI_PLIST_FILES=	bin/dlpoly-gui \
			${DATADIR_REL}/GUI.jar

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

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic-mpi ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/execute ${STAGEDIR}${EXAMPLESDIR}
	${RM} ${STAGEDIR}${EXAMPLESDIR}/execute/dlpoly*
.if ${PORT_OPTIONS:MGUI}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/java/GUI.jar ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/dlpoly-gui ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
