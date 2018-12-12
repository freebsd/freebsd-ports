# $FreeBSD$

PORTNAME=	vtk
DISTVERSION=	8.1.2
PORTREVISION=	3
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${VTK_SHORT_VER}/
PKGNAMESUFFIX=	8
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization toolkit

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2

CONFLICTS=	vtk5 vtk6

USES=		alias cmake:outsource compiler:c++11-lang gl jpeg localbase
USE_LDCONFIG=	${PREFIX}/lib/vtk-${VTK_SHORT_VER}
USE_XORG=	ice x11 xt xext sm

CMAKE_ON=	BUILD_SHARED_LIBS \
		VTK_INSTALL_NO_DOCUMENTATION VTK_USE_SYSTEM_EXPAT VTK_USE_SYSTEM_TIFF \
		VTK_USE_SYSTEM_PNG VTK_USE_SYSTEM_JPEG VTK_USE_SYSTEM_FREETYPE VTK_USE_SYSTEM_ZLIB \
		Module_vtkTestingCore Module_vtkTestingRendering
CMAKE_ARGS+=	-DVTK_INSTALL_LIBRARY_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_ARCHIVE_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_QT_DIR=/${QT_LIBDIR_REL}/plugins/designer \
		-DSTAGEDIR=${STAGEDIR}

VTK_SHORT_VER=	${PORTVERSION:R}

DOCSDIR=	${PREFIX}/share/doc/vtk-${VTK_SHORT_VER}
DATADIR=	${PREFIX}/share/vtk-${VTK_SHORT_VER}

# Options
OPTIONS_DEFINE=	DESIGNER DOCS OSMESA QT5 EXAMPLES
OPTIONS_DEFAULT=	MPI QT5
OSMESA_DESC=	Use Mesa for off-screen rendering
DESIGNER_DESC=	Build the Qt Designer plugin
OPTIONS_SUB=	yes

# Options groups
#VTK_GROUPS=	Imaging MPI Qt Rendering StandAlone Views
VTK_GROUPS=	MPI
VTK_WRAPS=	JAVA TCLTK
OPTIONS_GROUP=	Groups Wrapping
OPTIONS_GROUP_Groups=${VTK_GROUPS}
OPTIONS_GROUP_Wrapping=${VTK_WRAPS}
.for g in ${VTK_GROUPS}
$g_DESC=	Build the $g group
.endfor
.for w in ${VTK_WRAPS}
$w_DESC=	$w wrapping
.endfor

QT5_USES=		qt:5
QT5_USE=		QT=core,gui,sql,uiplugin,widgets,x11extras,qmake_build,buildtools_build
QT5_CMAKE_ON=		-DVTK_QT_VERSION:STRING="5" \
			-DCMAKE_PREFIX_PATH:STRING=${LOCALBASE}/lib/qt5 \
			-DVTK_Group_Qt:BOOL=ON

DESIGNER_CMAKE_BOOL=	QT_DESIGNER_PLUGIN
DESIGNER_USE=		QT=designer
DESIGNER_IMPLIES=	QT5

MPI_LIB_DEPENDS=	libmpi.so:net/openmpi
MPI_CMAKE_ON=		-DMPIEXEC=${LOCALBASE}/mpi/openmpi/bin/mpiexec

OSMESA_CMAKE_ARGS=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
			-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
			-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so \
			-DOPENGL_gl_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so \
			-DVTK_USE_X:BOOL=OFF
OSMESA_LIB_DEPENDS=	libOSMesa.so:graphics/libosmesa

# Wrapping
JAVA_CATEGORIES=	java
JAVA_VARS=		USE_JAVA=yes
JAVA_CMAKE_BOOL=	VTK_WRAP_JAVA Module_vtkWrappingJava
JAVA_CMAKE_ON=		-DJAVA_INCLUDE_PATH:PATH=${JAVA_HOME}/include \
			-DJAVA_AWT_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ARCH}/libjawt.so \
			-DJAVA_JVM_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ATCH}/libjava.so

TCLTK_USES=		tk
TCLTK_CMAKE_BOOL=	VTK_WRAP_TCL VTK_Group_Tk
TCLTK_CMAKE_ON=		-DTCL_INCLUDE_PATH:PATH=${TCL_INCLUDEDIR} \
			-DTK_INCLUDE_PATH:PATH=${TK_INCLUDEDIR}  \
			-DVTK_INSTALL_TCL_DIR=lib/vtk-${VTK_SHORT_VER}

DOCS_CMAKE_BOOL=	BUILD_DOCUMENTATION
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

# Mangling so that it will build when science/netcdf is installed.
post-patch:
	@${MV} ${WRKSRC}/ThirdParty/netcdf/vtknetcdf/include/netcdf.h \
		${WRKSRC}/ThirdParty/netcdf/vtknetcdf/include/xxxnetcdf.h
	@${FIND} ${WRKSRC}/ThirdParty/netcdf -type f | ${XARGS} ${REINPLACE_CMD} \
		-E 's/[[:<:]]netcdf\.h[[:>:]]/xxxnetcdf.h/'

.include <bsd.port.options.mk>

.for g in ${VTK_GROUPS}
.  if ${PORT_OPTIONS:M${g}}
CMAKE_ARGS+=	-DVTK_Group_${g}:BOOL=ON
.  else
CMAKE_ARGS+=	-DVTK_Group_${g}:BOOL=OFF
.  endif
.endfor

.if !${PORT_OPTIONS:MOSMESA}
USE_GL=		gl glu
.endif

post-install: # autoplist: thousands of files, complex dependencies on options
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
