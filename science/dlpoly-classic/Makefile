# $FreeBSD$

PORTNAME=	dlpoly
PORTVERSION=	1.8
PORTREVISION=	19
CATEGORIES=	science java
MASTER_SITES=	# gone as of 20201014: http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/
PKGNAMESUFFIX=	classic
DISTNAME=	dl_class_${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Molecular dynamics simulation package

# Later versions use 2 clause
LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.pdf

DEPRECATED=	MASTERSITE gone; possibly replaced by https://gitlab.com/DL_POLY_Classic/dl_poly?
EXPIRATION_DATE=	2021-01-14

LIB_DEPENDS=	libmpi.so:net/openmpi3

USES=		fortran gmake

OPTIONS_DEFINE=		GUI DOCS EXAMPLES
OPTIONS_DEFAULT=	GUI
GUI_DESC=		Install Java GUI

SUB_FILES=	dlpoly-gui

BUILD_WRKSRC=	${WRKSRC}/source

MPIF90=		${LOCALBASE}/mpi/openmpi3/bin/mpif90

GUI_USE=		JAVA=yes
GUI_PLIST_FILES=	bin/dlpoly-gui \
			${DATADIR_REL}/GUI.jar

.include <bsd.port.options.mk>

.if ${GCC_DEFAULT} >= 10
BROKEN=		fails to build with GCC 10: Type mismatch between actual argument at (1) and actual argument at (2) (INTEGER(4)/REAL(4)).
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
