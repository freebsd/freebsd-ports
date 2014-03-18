# Created by: gahr
# $FreeBSD$

PORTNAME=	vtk
PORTVERSION=	6.1.0
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${VTK_SHORT_VER}/
PKGNAMESUFFIX=	6
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The Visualization Toolkit

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
    		libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2

#
# TODO
# * Python wrap
# * VTK Groups

UNIQUENAME=	${PKGBASE}

CONFLICTS=	vtk-4*
USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/lib/vtk-${VTK_SHORT_VER}
USE_XORG=	xt
USES=		cmake:outsource
CXXFLAGS+=	-I${LOCALBASE}/include

VTK_SHORT_VER=	${PORTVERSION:R}
PLIST_SUB+=	VER2=${VTK_SHORT_VER}

DOCSDIR=	${PREFIX}/share/doc/vtk-${VTK_SHORT_VER}
DATADIR=	${PREFIX}/share/vtk-${VTK_SHORT_VER}

#VTK_GROUPS=	Imaging MPI Qt Rendering StandAlone Views
VTK_GROUPS=	MPI
VTK_WRAPS=	Java TclTk # Python
OPTIONS_GROUP=	Groups Wrapping
OPTIONS_GROUP_Groups=${VTK_GROUPS}
OPTIONS_GROUP_Wrapping=${VTK_WRAPS}
OPTIONS_DEFINE=	Designer DOCS
OPTIONS_RADIO=	Qt
OPTIONS_RADIO_Qt=	Qt4 Qt5
Qt_DESC=	Qt GUI support
Qt4_DESC=	Qt 4 toolkit support
Qt5_DESC=	Qt 5 toolkit support
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
		-DVTK_USE_SYSTEM_EXPAT:BOOL=ON \
		-DVTK_USE_SYSTEM_TIFF:BOOL=ON \
		-DVTK_USE_SYSTEM_PNG:BOOL=ON \
		-DVTK_USE_SYSTEM_JPEG:BOOL=ON \
		-DVTK_USE_SYSTEM_FREETYPE:BOOL=ON \
		-DVTK_USE_SYSTEM_ZLIB:BOOL=ON \
		-DSTAGEDIR=${STAGEDIR} \
		-DModule_vtkTestingCore:BOOL=ON \
		-DModule_vtkTestingRendering:BOOL=ON

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

.if ${PORT_OPTIONS:MQt4}
USE_QT4=	gui_build gui_run network_build network_run sql_build sql_run \
		moc_build uic_build qmake_build rcc_build opengl webkit_build \
		webkit_run
CMAKE_ARGS+=	-DVTK_QT_VERSION:STRING="4"
.endif

.if ${PORT_OPTIONS:MQt5}
USE_QT5=	gui_build gui_run network_build network_run sql_build sql_run \
		qmake_build opengl webkit_build buildtools webkit_run
CMAKE_ARGS+=	-DVTK_QT_VERSION:STRING="5" \
		-DCMAKE_PREFIX_PATH:STRING=${LOCALBASE}/lib/qt5
.endif

.if ${PORT_OPTIONS:MQt4} || ${PORT_OPTIONS:MQt5}
CMAKE_ARGS+=	-DVTK_Group_Qt:BOOL=ON
PLIST_SUB+=	QT=""
.else
PLIST_SUB+=	QT="@comment "
CMAKE_ARGS+=	-DVTK_Group_Qt:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MDesigner}
.if ${PORT_OPTIONS:MQt5}
USE_QT5+=	designer
.elif ${PORT_OPTIONS:MQt4}
USE_QT4+=	designer
.else
IGNORE=	designer requires either Qt4 or Qt5
.endif
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
		-DTK_INCLUDE_PATH:PATH=${TK_INCLUDEDIR}  \
		-DVTK_INSTALL_TCL_DIR=lib/vtk-${VTK_SHORT_VER}
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
