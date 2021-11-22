PORTNAME=	vtk
DISTVERSION=	9.1.0
CATEGORIES=	math graphics
MASTER_SITES=	https://vtk.org/files/release/${VTK_SHORT_VER}/
PKGNAMESUFFIX=	9
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization toolkit

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2

USES=		alias cmake compiler:c++11-lang gl jpeg localbase xorg
USE_LDCONFIG=	${PREFIX}/lib/vtk-${VTK_SHORT_VER}
USE_XORG=	ice x11 xt xext sm xcursor xfixes xrender

CMAKE_ON=	BUILD_SHARED_LIBS \
		VTK_INSTALL_NO_DOCUMENTATION VTK_USE_SYSTEM_EXPAT VTK_USE_SYSTEM_TIFF \
		VTK_USE_SYSTEM_PNG VTK_USE_SYSTEM_JPEG VTK_USE_SYSTEM_FREETYPE VTK_USE_SYSTEM_ZLIB \
		Module_vtkTestingCore Module_vtkTestingRendering
CMAKE_ARGS=	-DVTK_INSTALL_LIBRARY_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_ARCHIVE_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_QT_DIR=/${QT_LIBDIR_REL}/plugins/designer \
		-DSTAGEDIR=${STAGEDIR}

CFLAGS+=	-Du_int=unsigned # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=259975

VTK_SHORT_VER=	${PORTVERSION:R}

DOCSDIR=	${PREFIX}/share/doc/vtk-${VTK_SHORT_VER}
DATADIR=	${PREFIX}/share/vtk-${VTK_SHORT_VER}

# Options
OPTIONS_DEFINE=	DESIGNER DOCS OSMESA PYTHON QT5 EXAMPLES
OPTIONS_DEFAULT=	MPI PYTHON QT5 # vtk python binding is needed by other packages, and is unfortunately is unseparable. It is a candidate to be a subpackage.
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

PYTHON_USES=		python:3.6+
PYTHON_CMAKE_BOOL=	VTK_WRAP_PYTHON
PYTHON_CMAKE_ON=	-DVTK_PYTHON_VERSION=${PYTHON_MAJOR_VER}
PYTHON_VARS=		SUB_FILES=PKG-INFO SUB_LIST=PORTVERSION=${PORTVERSION}

QT5_USES=		qt:5
QT5_USE=		QT=core,declarative,gui,network,opengl,sql,uiplugin,widgets,x11extras,qmake_build,buildtools_build
QT5_CMAKE_ON=		-DCMAKE_PREFIX_PATH:STRING=${LOCALBASE}/lib/qt5 \
			-DVTK_GROUP_ENABLE_Qt:STRING=YES \
			-DVTK_MODULE_ENABLE_VTK_GUISupportQt:STRING=YES

DESIGNER_CMAKE_BOOL=	QT_DESIGNER_PLUGIN
DESIGNER_USE=		QT=designer
DESIGNER_IMPLIES=	QT5

MPI_LIB_DEPENDS=	libmpi.so:net/openmpi
MPI_CMAKE_ON=		-DMPIEXEC=${LOCALBASE}/mpi/openmpi/bin/mpiexec

OSMESA_CMAKE_ON=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
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
USES+=		gl
USE_GL=		gl glu
.endif

CONFLICTS=	vtk6 vtk8

do-install-PYTHON-on: # cmake doesn't install pip's .egg-info: https://gitlab.kitware.com/vtk/vtk/-/issues/18087
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/vtk-${DISTVERSION}-py${PYTHON_VER}.egg-info
	@${INSTALL_DATA} ${WRKDIR}/PKG-INFO ${STAGEDIR}${PYTHON_SITELIBDIR}/vtk-${DISTVERSION}-py${PYTHON_VER}.egg-info

post-install: # autoplist: thousands of files, complex dependencies on options
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
