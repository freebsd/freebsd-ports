# New ports collection makefile for:	OpenFOAM
# Date created:		Sat 17 dec 2005
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	${REALNAME:L}
PORTVERSION=	1.2
CATEGORIES=	science math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	foam
DISTNAME=	${REALNAME}-${PORTVERSION}.General
EXTRACT_SUFX=	.gtgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open Field Operation and Manipulation - CFD Simulation Toolbox

BUILD_DEPENDS=	micod:${PORTSDIR}/devel/mico						\
		cmake:${PORTSDIR}/devel/cmake						\
		${X11BASE}/lib/libode.a:${PORTSDIR}/devel/ode				\
		${PARAVIEW_LIB}/ParaViewConfig.cmake:${PORTSDIR}/science/paraview	\
		${LOCALBASE}/share/java/java3d/jar/j3dutils.jar:${PORTSDIR}/java/java3d	\
		${LOCALBASE}/include/vtk/vtkDataSetSource.h:${PORTSDIR}/math/vtk-headers
RUN_DEPENDS=	micod:${PORTSDIR}/devel/mico						\
		dx:${PORTSDIR}/graphics/opendx						\
		${LOCALBASE}/share/java/java3d/jar/j3dutils.jar:${PORTSDIR}/java/java3d	\
		paraview:${PORTSDIR}/science/paraview

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen	\
		dot:${PORTSDIR}/graphics/graphviz
.endif

USE_GCC=	3.4+
USE_JAVA=	1.4+
USE_GL=		yes
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${REALNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	REALNAME=${REALNAME} VER=${PORTVERSION}
PLIST_SUB=	${SUB_LIST}

#MAKE_SHELL=	${CSH}
MAKE_ENV=	WM_PROJECT_DIR=${BUILD_WRKSRC} WM_ARCH=${OPSYS}			\
		WM_PROJECT_INST_DIR=${PREFIX}/${REALNAME} WM_COMPILER=""	\
		WM_COMPILER_ARCH=${ARCH} WM_COMPILER_LIB_ARCH=${ARCH}		\
		WM_PROJECT_VERSION=${PORTVERSION} WM_PROJECT=${REALNAME}	\
		LD_LIBRARY_PATH="" WM_JAVAC_OPTION=Opt WM_COMPILE_OPTION=Opt	\
		WM_PROJECT_USER_DIR=${HOME}/${REALNAME}				\
		MICO_VERSION=${MICO_VER} MICO_ARCH_PATH=${LOCALBASE}

CSH=		/bin/csh
REALNAME=	OpenFOAM
PARAVIEW_VER=	2.4.1
PARAVIEW_LIB=	${LOCALBASE}/lib/paraview-${PARAVIEW_VER:R}
GCC_VER=	${_GCCVERSION:S/0/-/:S/0/./g}

BATCHRC=	.bashrc .cshrc
SHELLRC=	bashrc cshrc
DIR2CLEAN=	.${REALNAME}-${PORTVERSION} bin wmake applications
DIR2INST=	.${REALNAME}-${PORTVERSION} bin lib wmake
APP2INST=	solvers test utilities
ZLIB2FIX=	std/std_zfstream.H c++2/zfstream2.H
THRD2FIX=	c++ mplibLAM
VER2FIX=	applications/utilities/mesh/manipulation/patchTool/C++/PatchToolServer/Make/omniOptions	\
		applications/utilities/mesh/manipulation/patchTool/C++/FoamXServer/Make/omniOptions	\
		applications/utilities/preProcessing/FoamX/C++/FoamXLib/Make/omniOptions
GL2FIX=		applications/utilities/miscellaneous/foamDebugSwitches/Make/options
PARARC=		bashrc cshrc
PS2FIX=		runFoamXHB patchTool foamJob killFoamX foamEndJob
DIR2PRUNE=	applications/utilities/mesh/manipulation/setSet/readline-5.0/platforms

DOCS=		README ReleaseNotes-${PORTVERSION} doc/Guides-a4 doc/Guides-usletter

.if defined(WITH_LAM)
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/lam7
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:${PORTSDIR}/net/lam7
MAKE_ENV+=	WM_MPLIB=LAM LAM_ARCH_PATH=${LOCALBASE}
MPICH_VER=	1.2.6
LAM_VER=	`${GREP} LAM_VERSION ${LOCALBASE}/include/lam_config.h | ${AWK} '{print $$3}'`
MPI_LIB=	LAM
PLIST_SUB+=	MPI="@comment " LAM="" LAM_VER=7.1.1
IGNORE=		does not run with lam7 at the moment
.else
BUILD_DEPENDS+=	${LOCALBASE}/mpich/bin/mpicc:${PORTSDIR}/net/mpich
RUN_DEPENDS+=	${LOCALBASE}/mpich/bin/mpirun:${PORTSDIR}/net/mpich
MAKE_ENV+=	WM_MPLIB=MPICH MPICH_ARCH_PATH=${LOCALBASE}/mpich
MPICH_VER=	`${LOCALBASE}/mpich/bin/mpichversion | ${HEAD} -1 | ${AWK} '{print $$3}'`
LAM_VER=	7.1.1
MPI_LIB=	MPICH
PLIST_SUB+=	MPI="" LAM="@comment " MPICH_VER=1.2.6
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not compile with gcc-2.95
.endif

.if ${OSVERSION} <= 504103
EXTRACT_DEPENDS+=	bsdtar:${PORTSDIR}/archivers/bsdtar
TAR=		${LOCALBASE}/bin/bsdtar
.endif

.if exists(${LOCALBASE}/bin/mico-config)
MICO_VER=	`${LOCALBASE}/bin/mico-config --version`
.else
MICO_VER=	2.3.11
.endif

OSVERMAJ=	${OSREL:R}

post-extract:
	${CP} -Rp ${WRKSRC}/wmake/rules/linux ${WRKSRC}/wmake/rules/${OPSYS}
	${RM} ${WRKSRC}/wmake/rules/${OPSYS}/dirToString

pre-configure:
	${FIND} ${DIR2CLEAN:S|^|${WRKSRC}/|} -name "*.orig" -delete
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|"		\
		-e "s|#!/bin/bash|#!${LOCALBASE}/bin/bash|"	\
		-e "s|%%MPILIB%%|${MPI_LIB}|"			\
		${SHELLRC:S|^|${WRKSRC}/.${REALNAME}-${PORTVERSION}/|}
	${REINPLACE_CMD} -e "s|%%JAVA_HOME%%|${JAVA_HOME}|"			\
		-e "s|^#!/bin/bash|#! ${LOCALBASE}/bin/bash|"			\
		-e "s|gcc-3.4.3|gcc${GCC_VER}|"					\
		-e "s|2\.3\.11|${MICO_VER}|"					\
		-e "s|\$$MICO_PATH/platforms/\$$WM_OPTIONS|${LOCALBASE}|"	\
		-e "s|1\.2\.4|${MPICH_VER}|"					\
		-e "s|\$$MPICH_PATH/platforms/\$$WM_OPTIONS|${LOCALBASE}/mpich|"\
		-e "s|7\.1\.1|${LAM_VER}|"					\
		-e "s|\$$LAMHOME/platforms/\$$WM_OPTIONS|${LOCALBASE}|"		\
		-e "s|^SOURCE |source |"					\
		${BATCHRC:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e "s|-lGL|-L${X11BASE}/lib -lGL|"	\
		${GL2FIX:S|^|${WRKSRC}/|}
.for f in ${THRD2FIX}
	${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|"	\
		-e "s|-lpthread|${PTHREAD_LIBS}|"		\
		${WRKSRC}/wmake/rules/${OPSYS}/${f}
.endfor
.for f in ${ZLIB2FIX}
	# Use system zlib
	${REINPLACE_CMD} -e 's|"zlib.h"|<zlib.h>|'		\
		${WRKSRC}/src/OpenFOAM/db/IOstreams/zfstream/${f}
.endfor
	${REINPLACE_CMD} -e "s|/usr/X11R6|${X11BASE}|"		\
		${WRKSRC}/wmake/rules/${OPSYS}/X
.for f in ${VER2FIX}
	${REINPLACE_CMD} -e "s|%%ARCH%%|${ARCH}|"	\
		-e "s|%%OSVERMAJ%%|${OSVERMAJ}|"	\
		-e "s|-lpthread|${PTHREAD_LIBS}|"	\
		${WRKSRC}/${f}
.endfor
.for f in ${PS2FIX}
	${REINPLACE_CMD} -e "s|ps -u|ps -U|" ${WRKSRC}/bin/${f}
.endfor
.for f in ${PARARC}
	${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|"		\
		-e "s|#!/bin/bash|#!${LOCALBASE}/bin/bash|"		\
		-e "s|2.2.0|${PARAVIEW_VER}|"				\
		-e "s|paraview-2.2|paraview-${PARAVIEW_VER:R}|"		\
		${WRKSRC}/.${REALNAME}-${PORTVERSION}/apps/paraview/${f}
.endfor

do-build:
	(cd ${BUILD_WRKSRC};			\
	${SETENV} ${MAKE_ENV} ./Allwmake)

.if !defined(NOPORTDOCS)
post-build:
	@${ECHO_MSG} "===>  Building documentation."
	(cd ${BUILD_WRKSRC};			\
	${SETENV} ${MAKE_ENV} ./Allwmake doc)
.endif

do-install:
	${MKDIR} ${PREFIX}/${REALNAME}/applications
	${CP} -R ${BATCHRC:S|^|${WRKSRC}/|} ${PREFIX}/${REALNAME}
	${CP} -R ${DIR2INST:S|^|${WRKSRC}/|} ${PREFIX}/${REALNAME}
	${CP} -R ${APP2INST:S|^|${WRKSRC}/applications/|} ${PREFIX}/${REALNAME}/applications
	${FIND} ${PREFIX}/${REALNAME}/applications -type d			\
		\( -name ${OPSYS}Opt -o -name linuxDebug -o -name linuxOpt \)	\
		-exec ${RM} -rf {} \; 2>/dev/null || ${TRUE}
	${MKDIR} ${PREFIX}/${REALNAME}/applications/bin/${OPSYS}Opt
	cd ${WRKSRC}/applications/bin/${OPSYS}Opt			\
	&& ${FIND} . -type f -exec ${INSTALL_PROGRAM} {}		\
		${PREFIX}/${REALNAME}/applications/bin/${OPSYS}Opt/{} \;
	@${RMDIR} ${DIR2PRUNE:S|^|${PREFIX}/${REALNAME}/|}
.if !defined(NOPORTDOCS)
	${CP} -R ${DOCS:S|^|${WRKSRC}/|} ${PREFIX}/${REALNAME}
	${CP} -R ${WRKSRC}/tutorials ${PREFIX}/${REALNAME}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
