# Created by: gahr
# $FreeBSD$

PORTNAME=	vtk
PORTVERSION=	6.0.0
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${VTK_SHORT_VER}/
PKGNAMESUFFIX=	6

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The Visualization Toolkit

LICENSE=	BSD3CLAUSE

#
# TODO
# * Python wrap
# * VTK Groups

CONFLICTS=	vtk-4*
USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/lib/vtk-${VTK_SHORT_VER}
USES=		cmake:outsource
CXXFLAGS+=	-I${LOCALBASE}/include

VTK_SHORT_VER=	${PORTVERSION:R}
PLIST_SUB+=	VER2=${VTK_SHORT_VER}

WRKSRC=		${WRKDIR}/VTK${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/vtk-${VTK_SHORT_VER}

#VTK_GROUPS=	Imaging MPI Qt Rendering StandAlone Views
VTK_GROUPS=	MPI Qt
VTK_WRAPS=	Java TclTk # Python
OPTIONS_GROUP=	Groups Wrapping
OPTIONS_GROUP_Groups=${VTK_GROUPS}
OPTIONS_GROUP_Wrapping=${VTK_WRAPS}
OPTIONS_DEFINE=	Designer DOCS
#OPTIONS_DEFAULT=MPI Qt Java Python TclTk Designer

.for g in ${VTK_GROUPS}
$g_DESC=	Build the $g group
.endfor
.for w in ${VTK_WRAPS}
$w_DESC=	$w wrapping
.endfor

Designer_DESC=	Build the Qt Designer plugin

CMAKE_ARGS+=	-DVTK_INSTALL_LIBRARY_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_ARCHIVE_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_NO_DOCUMENTATION=ON \
		-DVTK_INSTALL_QT_DIR=/${QT_LIBDIR_REL}/plugins/designer \
		-DSTAGEDIR=${STAGEDIR}

.include <bsd.port.options.mk>

.for g in ${VTK_GROUPS}
.  if ${PORT_OPTIONS:M${g}}
CMAKE_ARGS+=	-DVTK_Group_${g}:BOOL=ON
.  else
CMAKE_ARGS+=	-DVTK_Group_${g}:BOOL=OFF
.  endif
.endfor

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION:BOOL=ON
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=ON
.endif

.if ${PORT_OPTIONS:MMPI}
LIB_DEPENDS+=	libmpi.so:${PORTSDIR}/net/openmpi
CMAKE_ARGS+=	-DMPIEXEC=${LOCALBASE}/mpi/openmpi/bin/mpiexec
PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

.if ${PORT_OPTIONS:MQt}
USE_QT4=	gui_build gui_run network_build network_run sql_build sql_run \
		moc_build uic_build qmake_build rcc_build opengl webkit_build \
		webkit_run
PLIST_SUB+=	QT=""
.else
PLIST_SUB+=	QT="@comment "
.endif

.if ${PORT_OPTIONS:MDesigner}
USE_QT4=	gui_build gui_run network_build network_run sql_build sql_run \
		moc_build uic_build designer_build designer_run qmake_build \
		rcc_build opengl webkit_build webkit_run
PLIST_SUB+=	DESIGNER=""
CMAKE_ARGS+=	-DQT_DESIGNER_PLUGIN:BOOL=ON
.else
PLIST_SUB+=	DESIGNER="@comment "
CMAKE_ARGS+=	-DQT_DESIGNER_PLUGIN:BOOL=OFF
.endif

# Wrapping
.if ${PORT_OPTIONS:MJava}
CATEGORIES+=	java
USE_JAVA=	yes
CMAKE_ARGS+=	-DVTK_WRAP_JAVA:BOOL=ON \
    		-DJAVA_INCLUDE_PATH:PATH=${JAVA_HOME}/include \
		-DJAVA_AWT_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ARCH}/libjawt.so \
		-DJAVA_JVM_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ATCH}/libjava.so
PLIST_SUB+=	JAVA=""
.else
CMAKE_ARGS+=	-DVTK_WRAP_JAVA:BOOL=OFF \
    		-DModule_vtkWrappingJava:BOOL=OFF
PLIST_SUB+=	JAVA="@comment "
.endif

.if ${PORT_OPTIONS:MPython}
USE_PYTHON=	yes
CMAKE_ARGS+=	-DVTK_WRAP_PYTHON:BOOL=ON
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DVTK_WRAP_PYTHON:BOOL=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MTclTk}
USES+=		tk
CMAKE_ARGS+=	-DVTK_WRAP_TCL:BOOL=ON \
    		-DVTK_Group_Tk:BOOL=ON \
		-DTCL_INCLUDE_PATH:PATH=${TCL_INCLUDEDIR} \
		-DTK_INCLUDE_PATH:PATH=${TK_INCLUDEDIR}
PLIST_SUB+=	TCLTK=""
.else
CMAKE_ARGS+=	-DVTK_WRAP_TCL:BOOL=OFF \
    		-DVTK_Group_Tk:BOOL=OFF
PLIST_SUB+=	TCLTK="@comment "
.endif

.if ${PORT_OPTIONS:MJava} || ${PORT_OPTIONS:MPython} || ${PORT_OPTIONS:MTclTk}
PLIST_SUB+=	WRAP=""
.else
PLIST_SUB+=	WRAP="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION:BOOL=ON
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION:BOOL=OFF
.endif

.include <bsd.port.mk>
