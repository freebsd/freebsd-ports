# Created by: gahr
# $FreeBSD$

PORTNAME=	vtk
PORTVERSION=	6.2.0
PORTREVISION=	14
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${VTK_SHORT_VER}/
PKGNAMESUFFIX=	6
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Visualization toolkit

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2

#
# TODO
# * VTK Groups

CONFLICTS=	vtk8 vtk9
USES=		alias cmake jpeg localbase xorg
USE_LDCONFIG=	${PREFIX}/lib/vtk-${VTK_SHORT_VER}
USE_XORG=	xt sm ice x11 xext
VTK_SHORT_VER=	${PORTVERSION:R}
PLIST_SUB+=	VER2=${VTK_SHORT_VER}

DOCSDIR=	${PREFIX}/share/doc/vtk-${VTK_SHORT_VER}
DATADIR=	${PREFIX}/share/vtk-${VTK_SHORT_VER}

# Options
OPTIONS_DEFINE=	DESIGNER DOCS OSMESA EXAMPLES SHARED QT5
OPTIONS_DEFAULT=SHARED
#OPTIONS_DEFAULT=MPI Qt JAVA TCLTK DESIGNER
OSMESA_DESC=	Use Mesa for off-screen rendering
DESIGNER_DESC=	Build the Qt Designer plugin
OPTIONS_SUB=	yes

# Options groups
#VTK_GROUPS=	Imaging MPI Qt Rendering StandAlone Views
VTK_GROUPS=	MPI
VTK_WRAPS=	JAVA TCLTK
OPTIONS_GROUP=	GROUPS WRAPPING
OPTIONS_GROUP_GROUPS=${VTK_GROUPS}
OPTIONS_GROUP_WRAPPING=${VTK_WRAPS}
GROUPS_DESC=	Groups
WRAPPING_DESC=	Wrapping
.for g in ${VTK_GROUPS}
$g_DESC=	Build the $g group
.endfor
.for w in ${VTK_WRAPS}
$w_DESC=	$w wrapping
.endfor

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
		-DModule_vtkTestingRendering:BOOL=ON \
		-DVTK_WRAP_PYTHON:BOOL=OFF

SHARED_CMAKE_ON=	-DBUILD_SHARED_LIBS:BOOL=ON
SHARED_CMAKE_OFF=	-DBUILD_SHARED_LIBS:BOOL=OFF

# Mangling so that it will build when science/netcdf is installed.
post-patch:
	${MV} ${WRKSRC}/ThirdParty/netcdf/vtknetcdf/include/netcdf.h \
		${WRKSRC}/ThirdParty/netcdf/vtknetcdf/include/xxxnetcdf.h
	${FIND} ${WRKSRC}/ThirdParty/netcdf -type f | ${XARGS} ${REINPLACE_CMD} \
		-E 's/[[:<:]]netcdf\.h[[:>:]]/xxxnetcdf.h/'

.include <bsd.port.options.mk>

.for g in ${VTK_GROUPS}
.  if ${PORT_OPTIONS:M${g}}
CMAKE_ARGS+=	-DVTK_Group_${g}:BOOL=ON
.  else
CMAKE_ARGS+=	-DVTK_Group_${g}:BOOL=OFF
.  endif
.endfor

.if ${PORT_OPTIONS:MOSMESA}
LIB_DEPENDS+=	libOSMesa.so:graphics/libosmesa
CMAKE_ARGS+=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
		-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
		-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so \
		-DOPENGL_gl_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so \
		-DVTK_USE_X:BOOL=OFF
PLIST_SUB+=	X11="@comment " \
		OSMESA=""
.else
USES+=		gl
USE_GL=		gl glu
PLIST_SUB+=	X11="" \
		OSMESA="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=ON
.endif

.if ${PORT_OPTIONS:MMPI}
LIB_DEPENDS+=	libmpi.so:net/openmpi3
CMAKE_ARGS+=	-DMPIEXEC=${LOCALBASE}/mpi/openmpi3/bin/mpiexec
PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

.if ${PORT_OPTIONS:MQT5}
USES+=		qt:5
USE_QT=		gui_build gui_run network_build network_run sql_build sql_run \
		qmake_build opengl webkit_build buildtools webkit_run
CMAKE_ARGS+=	-DVTK_QT_VERSION:STRING="5" \
		-DCMAKE_PREFIX_PATH:STRING=${LOCALBASE}/lib/qt5
PLIST_SUB+=	QTV="qt5"
.endif

.if ${PORT_OPTIONS:MQT5}
CMAKE_ARGS+=	-DVTK_Group_Qt:BOOL=ON
PLIST_SUB+=	QT=""
.else
PLIST_SUB+=	QT="@comment "
CMAKE_ARGS+=	-DVTK_Group_Qt:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MDESIGNER}
.if ${PORT_OPTIONS:MQT5}
USE_QT+=	designer
.else
IGNORE=	designer requires QT5
.endif
PLIST_SUB+=	DESIGNER=""
CMAKE_ARGS+=	-DQT_DESIGNER_PLUGIN:BOOL=ON
.else
PLIST_SUB+=	DESIGNER="@comment "
CMAKE_ARGS+=	-DQT_DESIGNER_PLUGIN:BOOL=OFF
.endif

# Wrapping
.if ${PORT_OPTIONS:MJAVA}
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

.if ${PORT_OPTIONS:MTCLTK}
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

.if ${PORT_OPTIONS:MJAVA} || ${PORT_OPTIONS:MTCLTK}
PLIST_SUB+=	WRAP=""
.else
PLIST_SUB+=	WRAP="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION:BOOL=ON
BUILD_DEPENDS+=	doxygen:devel/doxygen
USES+=		perl5
USE_PERL5+=	build
.else
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION:BOOL=OFF
.endif

.include <bsd.port.pre.mk>

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv1
CXXFLAGS+=	-mminimal-toc
.endif

.include <bsd.port.post.mk>
