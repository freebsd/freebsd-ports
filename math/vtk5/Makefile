# New ports collection makefile for:	vtk5
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
# Repocopied from math/vtk by:	Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	vtk
PORTVERSION=	5.8.0
PORTREVISION=	3
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${PORTVERSION:R}/ \
		http://www.neuro.mcw.edu/Ports/distfiles/VTK5/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The Visualization Toolkit

LIB_DEPENDS=	expat.[5-6]:${PORTSDIR}/textproc/expat2 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

LATEST_LINK=	vtk5

WRKSRC=		${WRKDIR}/VTK

CONFLICTS=	vtk-4*

SUB_FILES=	vtk.3

USE_CMAKE=	yes
USE_XORG=	xt
USE_LDCONFIG=	${PREFIX}/lib/vtk-${PORTVERSION:R}
MAKE_JOBS_SAFE=	yes

OPTIONS=	SHARED		"Build shared libraries" On \
		VTKMPEG2	"Install patented MPEG2 encoder module" Off \
		GL2PS           "Install support conversion OpenGL to PostScript" On \
		OSMESA		"Use Mesa for off-screen rendering" Off \
		QT		"Enable Qt gui support" On \
		WRAP_JAVA	"Enable Java wrapping" Off \
		WRAP_PYTHON	"Enable Python wrapping" On \
		WRAP_TCLTK	"Enable Tcl/Tk wrapping" On

PLIST_SUB+=	VER1="${PORTVERSION}" \
		VER2="${PORTVERSION:R}" \
		VER3="${PORTVERSION:R:R}"

MAN3=		vtk.3
PORTDOCS=	README.html

CMAKE_OUTSOURCE=	yes

CMAKE_ARGS+=	-DBUILD_DOCUMENTATION:BOOL=ON \
		-DBUILD_TESTING:BOOL=OFF \
		-DKWSYS_LFS_DISABLE:BOOL=ON \
		-DVTK_USE_PARALLEL:BOOL=ON \
		-DVTK_USE_GUISUPPORT:BOOL=ON \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T:BOOL=ON \
		-DVTK_DATA_ROOT:PATH=${EXAMPLESDIR}/VTKData \
		-DOPENGL_INCLUDE_DIR:PATH=${LOCALBASE}/include \
		-DOPENGL_gl_LIBRARY:FILEPATH=${LOCALBASE}/lib/libGL.so \
		-DOPENGL_glu_LIBRARY:FILEPATH=${LOCALBASE}/lib/libGLU.so

.include <bsd.port.options.mk>

.if defined(WITH_SHARED)
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DVTK_USE_SYSTEM_EXPAT:BOOL=ON \
		-DVTK_USE_SYSTEM_JPEG:BOOL=ON \
		-DVTK_USE_SYSTEM_PNG:BOOL=ON \
		-DVTK_USE_SYSTEM_TIFF:BOOL=ON \
		-DVTK_USE_SYSTEM_ZLIB:BOOL=ON
PLIST_SUB+=	SHARED="" \
		STATIC="@comment "
.else
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=OFF \
		-DVTK_USE_SYSTEM_EXPAT:BOOL=OFF \
		-DVTK_USE_SYSTEM_JPEG:BOOL=OFF \
		-DVTK_USE_SYSTEM_PNG:BOOL=OFF \
		-DVTK_USE_SYSTEM_TIFF:BOOL=OFF \
		-DVTK_USE_SYSTEM_ZLIB:BOOL=OFF
PLIST_SUB+=	SHARED="@comment " \
		STATIC=""
.endif

.if defined(WITH_VTKMPEG2)
LIB_DEPENDS+=	vtkMPEG2Encode:${PORTSDIR}/multimedia/vtkmpeg2encode
PLIST_SUB+=	MPEG=""
CMAKE_ARGS+=	-DVTK_USE_PATENTED:BOOL=ON \
		-DVTK_USE_MPEG2_ENCODER:BOOL=ON \
		-DvtkMPEG2Encode_INCLUDE_PATH=${LOCALBASE}/include/vtk-5.8 \
		-DvtkMPEG2Encode_LIBRARIES=${LOCALBASE}/lib/libvtkMPEG2Encode.so
.else
PLIST_SUB+=	MPEG="@comment "
.endif

.if defined(WITH_GL2PS)
LIB_DEPENDS+=	gl2ps:${PORTSDIR}/print/gl2ps
CMAKE_ARGS+=	-DVTK_USE_GL2PS:BOOL=ON
PLIST_SUB+=	GL2PS=""
.else
PLIST_SUB+=	GL2PS="@comment "
.endif

.if defined(WITH_OSMESA)
LIB_DEPENDS+=	OSMesa32:${PORTSDIR}/graphics/libosmesa
CMAKE_ARGS+=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
		-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
		-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa32.so \
		-DOPENGL_gl_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa32.so \
		-DOPENGL_glu_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSGLU.so \
		-DVTK_USE_X:BOOL=OFF
PLIST_SUB+=	X11="@comment "
.else
USE_GL=		yes
CMAKE_ARGS+=	-DVTK_USE_X:BOOL=ON
PLIST_SUB+=	X11=""
.endif

.if defined(WITH_QT)
USE_QT4=	corelib designer gui opengl qmake_build uic_build \
		moc_build rcc_build
CMAKE_ARGS+=	-DVTK_USE_GUISUPPORT:BOOL=ON \
   		-DVTK_USE_QVTK:BOOL=ON \
   		-DVTK_USE_QT:BOOL=ON \
   		-DDESIRED_QT_VERSION:STRING=4 \
		-DQT_QMAKE_EXECUTABLE:FILEPATH=${QMAKE} \
		-DVTK_INSTALL_QT_DIR:FILEPATH=/lib/qt4/plugins/designer
PLIST_SUB+=	QT=""
.else
CMAKE_ARGS+=	-DVTK_USE_GUISUPPORT:BOOL=OFF
PLIST_SUB+=	QT="@comment "
.endif

.if defined(WITH_WRAP_PYTHON)
.if !defined(WITH_SHARED)
IGNORE=		python wrapping requires shared libraries.\
		Run make config again and enable the SHARED option
.endif
USE_PYTHON=	yes
PYDISTUTILS_PKGNAME=	VTK
INSTALLS_EGGINFO=	yes
CMAKE_ARGS+=	-DVTK_WRAP_PYTHON:BOOL=ON \
   		-DVTK_PYTHON_SETUP_ARGS:STRING='--prefix="${PREFIX}"'
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DVTK_WRAP_PYTHON:BOOL=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_WRAP_TCLTK)
CMAKE_ARGS+=	-DVTK_WRAP_TCL:BOOL=ON
PLIST_SUB+=	TCLTK=""
.else
CMAKE_ARGS+=	-DVTK_WRAP_TCL:BOOL=OFF
PLIST_SUB+=	TCLTK="@comment "
.endif

# Used by both tcl/tk and python
.if defined(WITH_WRAP_TCLTK) || defined(WITH_WRAP_PYTHON)
USE_TCL=	84+
USE_TK=		84+
CMAKE_ARGS+=	-DVTK_USE_TK:BOOL=ON \
		-DTCL_INCLUDE_PATH=${TCL_INCLUDEDIR} \
		-DTK_INCLUDE_PATH=${TK_INCLUDEDIR}
PLIST_SUB+=	WRAP_PYTHON_OR_TCLTK="" \
		TCLTK_VER="${TCL_VER}"
.else
PLIST_SUB+=	WRAP_PYTHON_OR_TCLTK="@comment "
.endif

.if defined(WITH_WRAP_JAVA)
.if !defined(WITH_SHARED)
IGNORE=		java wrapping requires shared libraries.\
		Run make config again and enable the SHARED option
.endif
.if ${ARCH} == "amd64"
CXXFLAGS+=	-fPIC
.endif
USE_JAVA=	yes
JAVA_VENDOR=	freebsd openjdk
JAVA_VERSION=	1.5+
CMAKE_ARGS+=	-DVTK_WRAP_JAVA:BOOL=ON \
    		-DJAVA_AWT_INCLUDE_PATH:FILEPATH=${JAVA_HOME}/include \
    		-DJAVA_INCLUDE_PATH:FILEPATH=${JAVA_HOME}/include \
    		-DJAVA_INCLUDE_PATH2:FILEPATH=${JAVA_HOME}/include/freebsd \
		-DJAVA_AWT_LIBRARY:FILEPATH=${JAVA_HOME}/jre/lib/${ARCH}/libjawt.so \
		-DJAVA_JVM_LIBRARY:FILEPATH=${JAVA_HOME}/jre/lib/${ARCH}/server/libjvm.so
PLIST_SUB+=	JAVA=""
.else
PLIST_SUB+=	JAVA="@comment "
.endif

# Wrapping
.if defined(WITH_WRAP_PYTHON) || defined(WITH_WRAP_TCLTK) || defined(WITH_WRAP_JAVA)
PLIST_SUB+=	WRAPPING=""
.else
PLIST_SUB+=	WRAPPING="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
	    ${WRKSRC}/Hybrid/vtkVRMLImporter.cxx
#	${REINPLACE_CMD} -e '222s|)|) \&\& !defined(__FreeBSD__)|' \
#	    ${WRKSRC}/Utilities/kwsys/SharedForward.h.in
	${REINPLACE_CMD} -e '25,30d' ${WRKSRC}/Wrapping/Python/setup.py.in
.if defined(WITH_SHARED)
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|g' \
	    ${WRKSRC}/IO/vtkPNGReader.cxx
.endif

post-configure:
.if defined(WITH_WRAP_JAVA)
	${REINPLACE_CMD} -e 's|-ljawt$$||' \
	    ${CONFIGURE_WRKSRC}/Wrapping/Java/CMakeFiles/VTKJavaExecutable.dir/link.txt
.endif

pre-install:
.if defined(WITH_PYTHON)
	${MKDIR} ${PYTHONPREFIX_SITELIBDIR}
.endif
	${MKDIR} ${MANPREFIX}/man/man3
	${INSTALL_MAN} ${WRKDIR}/vtk.3 ${MANPREFIX}/man/man3
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

LIBS_TOFIX=	vtkNetCDF_cxx vtkhdf5
LIBDIR=		${PREFIX}/lib/vtk-${PORTVERSION:R}/

post-install:
# Ports system wants us to conform to lib.so.x format, but VTK5
# only installs lib.so.x.y and lib.so.x.y.z.
.if defined(WITH_SHARED)
	@for lib in ${LIBS_TOFIX}; do \
		${CP} ${LIBDIR}/lib$$lib.so ${LIBDIR}/lib$$lib.so.${PORTVERSION}; \
	done
	@for lib in ${LIBDIR}/*.so; do \
	    ${RM} -f $$lib; \
		 ${LN} -sf $$lib.${PORTVERSION} $$lib.${PORTVERSION:R}; \
		 ${LN} -sf $$lib.${PORTVERSION:R} $$lib.${PORTVERSION:R:R}; \
		 ${LN} -sf $$lib.${PORTVERSION:R:R} $$lib; \
	done
.if defined(WITH_QT)
	@for lib in ${LIBDIR}/libQVTK*.so; do \
	    ${RM} -f $$lib; \
	    ${LN} -sf $$lib.${PORTVERSION} $$lib; \
	    ${LN} -sf $$lib.${PORTVERSION} $$lib.${PORTVERSION:R:R}; \
	done
.endif
.endif
.if defined(WITH_VTKMPEG2)
	@${ECHO_CMD}
	@${ECHO_CMD} "This port uses the patented MPEG2 encoder."
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
