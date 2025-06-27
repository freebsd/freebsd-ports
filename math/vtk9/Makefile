PORTNAME=	vtk
DISTVERSION=	9.5.0
CATEGORIES=	math graphics
MASTER_SITES=	https://vtk.org/files/release/${VTK_SHORT_VER}/
PKGNAMESUFFIX=	9
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization toolkit
WWW=		https://vtk.org \
		https://gitlab.kitware.com/vtk/vtk \
		https://github.com/Kitware/VTK

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	\
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		alias cmake compiler:c++11-lang jpeg localbase xorg
USE_LDCONFIG=	${PREFIX}/lib/vtk-${VTK_SHORT_VER}
USE_XORG=	ice x11 xt xext sm xcursor xfixes xrender

CFLAGS_powerpc64le=	-DSQLITE_BYTEORDER=1234
CMAKE_ON=	BUILD_SHARED_LIBS \
		VTK_INSTALL_NO_DOCUMENTATION \
		Module_vtkTestingCore Module_vtkTestingRendering
.for m in expat freetype hdf5 jpeg netcdf png tiff zlib # mpi4py should be here, but this fails, see https://gitlab.kitware.com/vtk/vtk/-/issues/18693
CMAKE_ON+=	VTK_MODULE_USE_EXTERNAL_VTK_${m}
.endfor
CMAKE_ARGS=	-DVTK_INSTALL_LIBRARY_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_ARCHIVE_DIR=lib/vtk-${VTK_SHORT_VER} \
		-DVTK_INSTALL_QT_DIR=/${QT_LIBDIR_REL}/plugins/designer \
		-DSTAGEDIR=${STAGEDIR}
		# all build options are documented here: https://gitlab.kitware.com/vtk/vtk/blob/master/Documentation/dev/build.md
		# all modules can be obtailed by: find . -name vtk.module
		# there's also CMake/vtkWrapSettings.cmake with options

# disable finding Qt6
CMAKE_ON+=	CMAKE_DISABLE_FIND_PACKAGE_Qt6

# enable all modules
#CMAKE_ON+=	VTK_BUILD_ALL_MODULES

VTK_SHORT_VER=	${PORTVERSION:R}

DOCSDIR=	${PREFIX}/share/doc/vtk-${VTK_SHORT_VER}
DATADIR=	${PREFIX}/share/vtk-${VTK_SHORT_VER}

# Options
OPTIONS_DEFINE=	DESIGNER DOCS OMPI OSMESA PYTHON QT5 EXAMPLES
OPTIONS_DEFAULT=	OMPI PYTHON QT5 # vtk python binding is needed by other packages, and is unfortunately is unseparable. It is a candidate to be a subpackage.
OSMESA_DESC=	Use Mesa for off-screen rendering
OMPI_DESC=	OpenMPI (Message Passing Interface) support
DESIGNER_DESC=	Build the Qt Designer plugin
OPTIONS_SUB=	yes

# Option groups that enable groups of modules in VTK
VTK_GROUPS=		JAVA TCLTK
OPTIONS_GROUP=		GROUPS
OPTIONS_GROUP_GROUPS=	${VTK_GROUPS}
GROUPS_DESC=		Groups
.for w in ${VTK_GROUPS}
$w_DESC=		Enable $w group
.endfor

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	VTK_WRAP_PYTHON
PYTHON_CMAKE_ON=	-DVTK_PYTHON_VERSION=${PYTHON_MAJOR_VER} -DPython3_EXECUTABLE=${PYTHON_CMD}
PYTHON_VARS=		SUB_FILES=PKG-INFO SUB_LIST=PORTVERSION=${PORTVERSION}

QT5_USES=		qt:5
QT5_USE=		QT=core,declarative,gui,network,opengl,sql,uiplugin,widgets,x11extras,qmake,buildtools # qmake and buildtools should be with :build, but see https://gitlab.kitware.com/vtk/vtk/-/issues/18705
QT5_CMAKE_ON=		-DVTK_GROUP_ENABLE_Qt:STRING=YES \
			-DCMAKE_PREFIX_PATH:STRING=${LOCALBASE}/lib/qt5

#QT6_USES=		qt:6
#QT6_USE=		QT=base,declarative,tools:build
#QT6_CMAKE_ON=		-DVTK_GROUP_ENABLE_Qt:STRING=YES \
			-DCMAKE_PREFIX_PATH:STRING=${LOCALBASE}/lib/qt5

DESIGNER_CMAKE_BOOL=	QT_DESIGNER_PLUGIN
DESIGNER_USE=		QT=designer
DESIGNER_IMPLIES=	QT5

OMPI_CMAKE_BOOL=	VTK_USE_MPI
OMPI_USES=		mpi:openmpi
OMPI_CMAKE_ON=		-DMPI_HOME=${LOCALBASE}/mpi/openmpi
OMPI_LDFLAGS=		${MPI_LIBS}

OSMESA_CMAKE_ON=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
			-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
			-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so \
			-DOPENGL_gl_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so \
			-DVTK_USE_X:BOOL=OFF
OSMESA_LIB_DEPENDS=	libOSMesa.so:graphics/libosmesa

JAVA_USES=		java
JAVA_CMAKE_BOOL=	VTK_WRAP_JAVA
JAVA_CMAKE_ON=		-DJAVA_INCLUDE_PATH:PATH=${JAVA_HOME}/include \
			-DJAVA_AWT_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ARCH}/libjawt.so \
			-DJAVA_JVM_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ARCH}/libjava.so

TCLTK_USES=		tk
TCLTK_CMAKE_ON=		-DVTK_GROUP_ENABLE_Tk:STRING=YES \
			-DTCL_INCLUDE_PATH:PATH=${TCL_INCLUDEDIR} \
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

.if ${PORT_OPTIONS:MPYTHON} && ${PORT_OPTIONS:MOMPI}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py>0:net/py-mpi4py@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py>0:net/py-mpi4py@${PY_FLAVOR}
.endif

CONFLICTS=	vtk6 vtk8

do-install-PYTHON-on:
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} -f ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} -f ${STAGEDIR}${PYTHON_SITELIBDIR}
	# cmake doesn't install pip's .egg-info: https://gitlab.kitware.com/vtk/vtk/-/issues/18087
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/vtk-${DISTVERSION}-py${PYTHON_VER}.egg-info
	@${INSTALL_DATA} ${WRKDIR}/PKG-INFO ${STAGEDIR}${PYTHON_SITELIBDIR}/vtk-${DISTVERSION}-py${PYTHON_VER}.egg-info
	# workaround for: VTK installs mpi4py which makes it to conflict with the standalone mpi4py package, see https://gitlab.kitware.com/vtk/vtk/-/issues/18691
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/mpi4py

post-install: # autoplist: thousands of files, complex dependencies on options
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
