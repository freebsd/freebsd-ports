# New ports collection makefile for:	OpenFOAM
# Date created:		Sat 17 dec 2005
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	${REALNAME:L}
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	science math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	foam
DISTNAME=	${REALNAME}-${PORTVERSION}.General
EXTRACT_SUFX=	.gtgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open Field Operation and Manipulation - CFD Simulation Toolbox

BUILD_DEPENDS=	micod:${PORTSDIR}/devel/mico						\
		bash:${PORTSDIR}/shells/bash						\
		cmake:${PORTSDIR}/devel/cmake						\
		${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode				\
		${PARAVIEW_LIB}/ParaViewConfig.cmake:${PORTSDIR}/science/paraview	\
		${LOCALBASE}/share/java/java3d/jar/j3dutils.jar:${PORTSDIR}/java/java3d	\
		${LOCALBASE}/include/libiberty/demangle.h:${PORTSDIR}/devel/gnulibiberty\
		${LOCALBASE}/include/vtk/vtkDataSetSource.h:${PORTSDIR}/math/vtk-headers\
		${LOCALBASE}/lib/X11/fonts/freefont-ttf/FreeSans.ttf:${PORTSDIR}/x11-fonts/freefont-ttf
#		${LOCALBASE}/lib/parmetis/libmetis.a:${PORTSDIR}/math/parmetis
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo	\
		readline.6:${PORTSDIR}/devel/readline
# OpenFOAM requires metis-5.0, not yet in the ports tree
#		metis.1:${PORTSDIR}/math/metis
#		CGAL.0:${PORTSDIR}/math/cgal
RUN_DEPENDS=	micod:${PORTSDIR}/devel/mico						\
		dx:${PORTSDIR}/graphics/opendx						\
		${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/gnulibiberty		\
		${LOCALBASE}/share/java/java3d/jar/j3dutils.jar:${PORTSDIR}/java/java3d	\
		paraview:${PORTSDIR}/science/paraview

BROKEN=		bad depobj for java3d

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen	\
		dot:${PORTSDIR}/graphics/graphviz
.endif

USE_GCC=	3.4+	# Required to define GCC_VER
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_GL=		yes
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${REALNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	REALNAME=${REALNAME} VER=${PORTVERSION} APPSUBDIR=${APPSUBDIR}
PLIST_SUB=	${SUB_LIST}

#MAKE_SHELL=	${CSH}
MAKE_ENV=	WM_PROJECT_DIR=${BUILD_WRKSRC} WM_ARCH=${OPSYS}			\
		WM_PROJECT_INST_DIR=${PREFIX}/${REALNAME} WM_COMPILER=""	\
		WM_COMPILER_ARCH=${ARCH} WM_COMPILER_LIB_ARCH=${ARCH}		\
		WM_PROJECT_VERSION=${PORTVERSION} WM_PROJECT=${REALNAME}	\
		LD_LIBRARY_PATH="" WM_JAVAC_OPTION=${COMPOPT}			\
		WM_PROJECT_USER_DIR=${HOME}/${REALNAME}				\
		MICO_VERSION=${MICO_VER} MICO_ARCH_PATH=${LOCALBASE}		\
		WM_PRECISION_OPTION=${PRECISION} WM_COMPILE_OPTION=${COMPOPT}	\
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

CSH=		/bin/csh
REALNAME=	OpenFOAM
PRECISION?=	DP
COMPOPT?=	Opt
PARAVIEW_VER?=	2.4.4
PARAVIEW_LIB=	${LOCALBASE}/lib/paraview-${PARAVIEW_VER:R}
GCC_VER=	${_GCCVERSION:S/0/-/:S/0/./g}

BATCHRC=	.bashrc .cshrc
SHELLRC=	bashrc cshrc
DIR2CLEAN=	.${REALNAME}-${PORTVERSION} bin wmake applications
DIR2INST=	.${REALNAME}-${PORTVERSION} bin lib wmake
APP2INST=	solvers test utilities
THRD2FIX=	c++ mplibLAM
VER2FIX=	applications/utilities/mesh/manipulation/patchTool/C++/PatchToolServer/Make/omniOptions	\
		applications/utilities/mesh/manipulation/patchTool/C++/FoamXServer/Make/omniOptions	\
		applications/utilities/preProcessing/FoamX/C++/FoamXLib/Make/omniOptions
GL2FIX=		applications/utilities/miscellaneous/foamDebugSwitches/Make/options
PARARC=		bashrc cshrc
PS2FIX=		runFoamXHB patchTool foamJob killFoamX foamEndJob
BASH2FIX=	.OpenFOAM-${PORTVERSION}/apps/ensightFoam/bashrc
MALLOC2FIX=	src/MGridGenGamgAgglomeration/ParMGridGen-1.0/MGridGen/IMlib/IMlib.h	\
		src/MGridGenGamgAgglomeration/ParMGridGen-1.0/MGridGen/Lib/mgridgen.h	\
		applications/utilities/parallelProcessing/decompositionMethods/metis-5.0pre2/libmetis/stdheaders.h\
		applications/utilities/parallelProcessing/decompositionMethods/parMetisDecomp/ParMetis-3.1/METISLib/stdheaders.h\
		applications/utilities/parallelProcessing/decompositionMethods/parMetisDecomp/ParMetis-3.1/ParMETISLib/stdheaders.h
LOCAL2FIX=	wmake/rules/General/CGAL wmake/rules/${OPSYS}/general			\
		applications/utilities/parallelProcessing/decomposePar/Make/options	\
		applications/utilities/parallelProcessing/redistributeMeshPar/Make/options\
		applications/utilities/parallelProcessing/decompositionMethods/parMetisDecomp/Make/options
APPSUBDIR=	${OPSYS}${PRECISION}${COMPOPT}
APPDIR=		applications/bin/${APPSUBDIR}

DOCS=		README doc/Guides-a4 doc/Guides-usletter

.if defined(WITH_LAM)
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/lam
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:${PORTSDIR}/net/lam
MAKE_ENV+=	WM_MPLIB=LAM LAM_ARCH_PATH=${LOCALBASE}
OMPI_VER=	1.2.5
MPICH_VER=	1.0.7
LAM_VER=	`${LOCALBASE}/bin/laminfo -version lam full | ${AWK} '{print $$2}'`
MPI_LIB=	LAM
PLIST_SUB+=	MPI="lam" MPI_VER=${LAM_VERSION}
.elif defined(WITH_MPICH)
BUILD_DEPENDS+=	${LOCALBASE}/mpich2/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/mpich2/bin/mpirun:${PORTSDIR}/net/mpich2
MAKE_ENV+=	WM_MPLIB=MPICH MPICH_ARCH_PATH=${LOCALBASE}/mpich2
MPI_LIBPATH=	${LOCALBASE}/mpich2/lib
OMPI_VER=	1.2.5
MPICH_VER=	`${LOCALBASE}/mpich2/bin/mpich2version --version`
LAM_VER=	7.1.4
MPI_LIB=	MPICH
PLIST_SUB+=	MPI="mpich" MPI_VER=${MPICH_VERSION}
.else
LIB_DEPENDS=	mpi.0:${PORTSDIR}/net/openmpi
MAKE_ENV+=	WM_MPLIB=OPENMPI OPENMPI_ARCH_PATH=${LOCALBASE}/mpi/openmpi
OMPI_VER=	`${LOCALBASE}/mpi/openmpi/bin/ompi_info --version ompi full --parsable | ${GREP} ompi:version:full | ${CUT} -d: -f4-`
LAM_VER=	7.1.4
MPICH_VER=	1.0.7
MPI_LIBPATH=	${LOCALBASE}/mpi/openmpi/lib
MPI_LIB=	OPENMPI
PLIST_SUB+=	MPI="openmpi" MPI_VER=${OMPI_VERSION}
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/mico-config)
MICO_VER=	`${LOCALBASE}/bin/mico-config --version`
.else
MICO_VER=	2.3.12
.endif

# OpenMPI is the default, unless another MPI exists
.if exists(${LOCALBASE}/mpi/openmpi/bin/ompi_info)
WITH_OMPI=	yes
.endif
.if !defined(WITH_OMPI)
. if exists(${LOCALBASE}/mpich2/bin/mpich2version)
WITH_MPICH=	yes
. elif  exists(${LOCALBASE}/bin/laminfo)
WITH_LAM=	yes
. endif
.endif

.if defined(WITH_LAM)
. if exists(${LOCALBASE}/bin/laminfo)
LAM_VERSION!=	${LOCALBASE}/bin/laminfo -version lam full | ${AWK} '{print $$2}'
. else
LAM_VERSION=	${LAM_VER}
. endif
.elif defined(WITH_MPICH)
. if exists(${LOCALBASE}/mpich2/bin/mpich2version)
MPICH_VERSION!=	${LOCALBASE}/mpich2/bin/mpich2version --version
. else
MPICH_VERSION=	${MPICH_VER}
. endif
.else
. if exists(${LOCALBASE}/mpi/openmpi/bin/ompi_info)
OMPI_VERSION!=	${LOCALBASE}/mpi/openmpi/bin/ompi_info --version ompi full --parsable | ${GREP} ompi:version:full | ${CUT} -d: -f4-
. else
OMPI_VERSION=	1.2.5
. endif
.endif

OSVERMAJ=	${OSREL:R}

post-extract:
	${CP} -Rp ${WRKSRC}/wmake/rules/linuxGcc ${WRKSRC}/wmake/rules/${OPSYS}
	${RM} ${WRKSRC}/wmake/rules/${OPSYS}/dirToString
	${RM} -rf ${WRKSRC}/applications/utilities/mesh/manipulation/setSet/readline-5.0/platforms
	${FIND} ${WRKSRC}/applications/utilities/mesh/conversion/ccm26ToFoam/libccmio	\
		-name "\.#*" -delete

pre-configure:
	${FIND} ${DIR2CLEAN:S|^|${WRKSRC}/|} -name "*.orig" -delete
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|"		\
		-e "s|#!/bin/bash|#!${LOCALBASE}/bin/bash|"	\
		-e "s|%%MPILIB%%|${MPI_LIB}|"			\
		${SHELLRC:S|^|${WRKSRC}/.${REALNAME}-${PORTVERSION}/|}
	${REINPLACE_CMD} -e "s|%%JAVA_HOME%%|${JAVA_HOME}|"			\
		-e "s|^#!/bin/bash|#! ${LOCALBASE}/bin/bash|"			\
		-e "s|2\.3\.12|${MICO_VER}|"					\
		-e "s|\$$MICO_PATH/platforms/\$$WM_OPTIONS|${LOCALBASE}|"	\
		-e "s|1\.2\.3|${OMPI_VER}|"					\
		-e "s|\$$OPENMPI_HOME/platforms/\$$WM_OPTIONS|${LOCALBASE}/mpi/openmpi|"		\
		-e "s|1\.2\.4|${MPICH_VER}|"					\
		-e "s|\$$MPICH_PATH/platforms/\$$WM_OPTIONS|${LOCALBASE}/mpich2|"\
		-e "s|7\.1\.2|${LAM_VER}|"					\
		-e "s|\$$LAMHOME/platforms/\$$WM_OPTIONS|${LOCALBASE}|"		\
		-e "s|^SOURCE |source |"					\
		${BATCHRC:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e "s|-lGL|-L${LOCALBASE}/lib -lGL|"	\
		${GL2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e "s|GCC_VERSION=4.1.1|GCC_VERSION=${GCC_VER:S/_//}|"	\
		-e "s|JAVA_VERSION=1.4.2+|JAVA_VERSION=${JAVA_PORT_VERSION}|"	\
		${WRKSRC}/bin/foamInstallationTest
	${REINPLACE_CMD} -e "s|#!/bin/bash|#! ${LOCALBASE}/bin/bash|"	\
		${BASH2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|"	\
		${MALLOC2FIX:S|^|${WRKSRC}/|}
#	${REINPLACE_CMD} -e 's|-lmetis|-L${LOCALBASE}/lib -lmetis|'		\
#		-e 's|../metis-5.0pre2/include|${LOCALBASE}/include/metis|'	\
#		${WRKSRC}/applications/utilities/parallelProcessing/decompositionMethods/decompositionMethods/Make/options
.for f in ${THRD2FIX}
	${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|"	\
		-e "s|-lpthread|${PTHREAD_LIBS}|"		\
		${WRKSRC}/wmake/rules/${OPSYS}/${f}
.endfor
	${REINPLACE_CMD} -e "s|/usr/X11R6|${LOCALBASE}|"		\
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
		-e "s|2.4.4|${PARAVIEW_VER}|"				\
		-e "s|paraview-2.4|paraview-${PARAVIEW_VER:R}|"		\
		${WRKSRC}/.${REALNAME}-${PORTVERSION}/apps/paraview/${f}
.endfor
.for f in ${LOCAL2FIX}
	${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|"	\
		${WRKSRC}/${f}
.endfor
	${REINPLACE_CMD} -e	\
		's|/usr/include/readline/readline.h|${LOCALBASE}/include/readline/readline.h|'	\
		${WRKSRC}/applications/utilities/mesh/manipulation/Optional/Allwmake
.if defined(MPI_LIBPATH)
	${REINPLACE_CMD} -e	\
	'/LINKEXE/s|OPTIONS_DIR)|OPTIONS_DIR) -L${MPI_LIBPATH} -rpath-link ${MPI_LIBPATH}|'\
		${WRKSRC}/wmake/Makefile
.endif

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
		\( -name ${APPSUBDIR} -o -name linuxDebug -o -name linuxOpt \)	\
		-exec ${RM} -rf {} \; 2>/dev/null || ${TRUE}
	${MKDIR} ${PREFIX}/${REALNAME}/${APPDIR} ${PREFIX}/${REALNAME}/jobControl
	cd ${WRKSRC}/${APPDIR}					\
	&& ${FIND} . -type f -exec ${INSTALL_PROGRAM} {}	\
		${PREFIX}/${REALNAME}/${APPDIR}/{} \;
	${TOUCH} ${PREFIX}/${REALNAME}/jobControl/.keepme
	@${RM} -f ${PREFIX}/${REALNAME}/applications/utilities/mesh/conversion/ccm26ToFoam/libccmio/libadf/wmkdep.core
.if !defined(NOPORTDOCS)
	${CP} -R ${DOCS:S|^|${WRKSRC}/|} ${PREFIX}/${REALNAME}
	${CP} -R ${WRKSRC}/tutorials ${PREFIX}/${REALNAME}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
