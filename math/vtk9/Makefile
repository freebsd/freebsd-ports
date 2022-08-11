PORTNAME=	vtk
DISTVERSION=	9.1.0
PORTREVISION=	4
CATEGORIES=	math graphics
MASTER_SITES=	https://vtk.org/files/release/${VTK_SHORT_VER}/
PKGNAMESUFFIX=	9
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization toolkit

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	\
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		alias cmake compiler:c++11-lang gl jpeg localbase xorg
USE_LDCONFIG=	${PREFIX}/lib/vtk-${VTK_SHORT_VER}
USE_XORG=	ice x11 xt xext sm xcursor xfixes xrender

CMAKE_ON=	BUILD_SHARED_LIBS \
		VTK_INSTALL_NO_DOCUMENTATION \
		Module_vtkTestingCore Module_vtkTestingRendering
.for m in expat freetype hdf5 jpeg netcdf png tiff zlib
CMAKE_ON+=	VTK_MODULE_USE_EXTERNAL_VTK_${m}
.endfor
CMAKE_ARGS=	-DVTK_INSTALL_LIBRARY_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_ARCHIVE_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_QT_DIR=/${QT_LIBDIR_REL}/plugins/designer \
		-DSTAGEDIR=${STAGEDIR}
		# all build options are documented here: https://gitlab.kitware.com/vtk/vtk/blob/master/Documentation/dev/build.md

VTK_SHORT_VER=	${PORTVERSION:R}

DOCSDIR=	${PREFIX}/share/doc/vtk-${VTK_SHORT_VER}
DATADIR=	${PREFIX}/share/vtk-${VTK_SHORT_VER}

# Options
OPTIONS_DEFINE=	DESIGNER DOCS MPI OSMESA PYTHON QT5 EXAMPLES
OPTIONS_DEFAULT=	MPI PYTHON QT5 # vtk python binding is needed by other packages, and is unfortunately is unseparable. It is a candidate to be a subpackage.
OSMESA_DESC=	Use Mesa for off-screen rendering
DESIGNER_DESC=	Build the Qt Designer plugin
OPTIONS_SUB=	yes

# Options groups
VTK_WRAPS=	JAVA TCLTK
OPTIONS_GROUP=	WRAPPING
OPTIONS_GROUP_WRAPPING=${VTK_WRAPS}
GROUPS_DESC=	Groups
WRAPPING_DESC=	Wrapping
.for w in ${VTK_WRAPS}
$w_DESC=	$w wrapping
.endfor

PYTHON_USES=		python:3.6+
PYTHON_CMAKE_BOOL=	VTK_WRAP_PYTHON
PYTHON_CMAKE_ON=	-DVTK_PYTHON_VERSION=${PYTHON_MAJOR_VER} -DPython3_EXECUTABLE=${PYTHON_CMD}
PYTHON_VARS=		SUB_FILES=PKG-INFO SUB_LIST=PORTVERSION=${PORTVERSION}

QT5_USES=		qt:5
QT5_USE=		QT=core,declarative,gui,network,opengl,sql,uiplugin,widgets,x11extras,qmake_build,buildtools_build
QT5_CMAKE_ON=		-DCMAKE_PREFIX_PATH:STRING=${LOCALBASE}/lib/qt5 \
			-DVTK_GROUP_ENABLE_Qt:STRING=YES \
			-DVTK_MODULE_ENABLE_VTK_GUISupportQt:STRING=YES

DESIGNER_CMAKE_BOOL=	QT_DESIGNER_PLUGIN
DESIGNER_USE=		QT=designer
DESIGNER_IMPLIES=	QT5

MPI_CMAKE_BOOL=		VTK_USE_MPI
MPI_LIB_DEPENDS=	libmpi.so:net/mpich
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

.include <bsd.port.options.mk>

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
