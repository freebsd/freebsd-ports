# Created by: Mykola Khotyaintsev <ko@irfu.se>
# $FreeBSD$

PORTNAME=	vtk
PORTVERSION=	5.10.1
PORTREVISION=	5
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${PORTVERSION:R}/
PKGNAMESUFFIX=	5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Visualization Toolkit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

WRKSRC=		${WRKDIR}/VTK${PORTVERSION}

CONFLICTS=	vtk-4*

SUB_FILES=	vtk.3

USES=		alias cmake:outsource jpeg
USE_XORG=	xt
USE_LDCONFIG=	${PREFIX}/lib/vtk-${PORTVERSION:R}
CXXFLAGS+=	-DUSE_INTERP_ERRORLINE

OPTIONS_DEFINE=	SHARED THEORA VTKMPEG2 GL2PS OSMESA QT4 JAVA \
		PYTHON TCLTK DBGLEAKS LEGACY DOCS
OPTIONS_DEFAULT=SHARED GL2PS QT4 TCLTK LEGACY

SHARED_DESC=	Build shared libraries
VTKMPEG2_DESC=	Patented MPEG2 encoder module
GL2PS_DESC=	OpenGL to PostScript conversion module
OSMESA_DESC=	Use Mesa for off-screen rendering
DBGLEAKS_DESC=	Build leak checking support
LEGACY_DESC=	Include legacy code

PLIST_SUB+=	VER1="${PORTVERSION}" \
		VER2="${PORTVERSION:R}" \
		VER3="${PORTVERSION:R:R}"

PORTDOCS=	README.html

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

.if ${PORT_OPTIONS:MSHARED}
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

.if ${PORT_OPTIONS:MVTKMPEG2}
LIB_DEPENDS+=	libvtkMPEG2Encode.so:multimedia/vtkmpeg2encode
PLIST_SUB+=	MPEG=""
CMAKE_ARGS+=	-DVTK_USE_PATENTED:BOOL=ON \
		-DVTK_USE_MPEG2_ENCODER:BOOL=ON \
		-DvtkMPEG2Encode_INCLUDE_PATH=${LOCALBASE}/include/vtk-${PORTVERSION:R} \
		-DvtkMPEG2Encode_LIBRARIES=${LOCALBASE}/lib/libvtkMPEG2Encode.so
.else
PLIST_SUB+=	MPEG="@comment "
.endif

.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora
PLIST_SUB+=	THEORA=""
CMAKE_ARGS+=	-DVTK_USE_OGGTHEORA_ENCODER:BOOL=ON
.else
PLIST_SUB+=	THEORA="@comment "
CMAKE_ARGS+=	-DVTK_USE_OGGTHEORA_ENCODER:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGL2PS}
LIB_DEPENDS+=	libgl2ps.so:print/gl2ps
CMAKE_ARGS+=	-DVTK_USE_GL2PS:BOOL=ON
PLIST_SUB+=	GL2PS=""
.else
PLIST_SUB+=	GL2PS="@comment "
.endif

.if ${PORT_OPTIONS:MOSMESA}
LIB_DEPENDS+=	libOSMesa.so:graphics/libosmesa
CMAKE_ARGS+=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
		-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
		-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so \
		-DOPENGL_gl_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so \
		-DVTK_USE_X:BOOL=OFF
PLIST_SUB+=	X11="@comment "
.else
USE_GL=		yes
CMAKE_ARGS+=	-DVTK_USE_X:BOOL=ON
PLIST_SUB+=	X11=""
.endif

.if ${PORT_OPTIONS:MQT4}
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

.if ${PORT_OPTIONS:MPYTHON}
IGNORE=		python wrapping does not stage properly
.if ${PORT_OPTIONS:MSHARED} == ""
IGNORE=		python wrapping requires shared libraries.\
		Run make config again and enable the SHARED option
.endif
USES+=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	VTK
# INSTALLS_EGGINFO support has been removed
# INSTALLS_EGGINFO=	yes
CMAKE_ARGS+=	-DVTK_WRAP_PYTHON:BOOL=ON \
		-DVTK_PYTHON_SETUP_ARGS:STRING='--prefix="${PREFIX}"'
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DVTK_WRAP_PYTHON:BOOL=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MTCLTK}
CMAKE_ARGS+=	-DVTK_WRAP_TCL:BOOL=ON
PLIST_SUB+=	TCLTK=""
.else
CMAKE_ARGS+=	-DVTK_WRAP_TCL:BOOL=OFF
PLIST_SUB+=	TCLTK="@comment "
.endif

# Used by both tcl/tk and python
.if ${PORT_OPTIONS:MTCLTK} || ${PORT_OPTIONS:MPYTHON}
USES+=		tk
CMAKE_ARGS+=	-DVTK_USE_TK:BOOL=ON \
		-DTCL_INCLUDE_PATH=${TCL_INCLUDEDIR} \
		-DTK_INCLUDE_PATH=${TK_INCLUDEDIR}
PLIST_SUB+=	WRAP_PYTHON_OR_TCLTK="" \
		TCLTK_VER="${TCL_VER}"
.else
PLIST_SUB+=	WRAP_PYTHON_OR_TCLTK="@comment "
.endif

.if ${PORT_OPTIONS:MJAVA}
.if ${PORT_OPTIONS:MSHARED} == ""
IGNORE=		java wrapping requires shared libraries.\
		Run make config again and enable the SHARED option
.endif
.if ${ARCH} == "amd64"
CXXFLAGS+=	-fPIC
.endif
CATEGORIES+=	java
USE_JAVA=	yes
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.6+
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
.if ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MTCLTK} || ${PORT_OPTIONS:MJAVA}
PLIST_SUB+=	WRAPPING=""
.else
PLIST_SUB+=	WRAPPING="@comment "
.endif

.if ${PORT_OPTIONS:MDBGLEAKS}
CMAKE_ARGS+=	-DVTK_DEBUG_LEAKS:BOOL=ON
.else
CMAKE_ARGS+=	-DVTK_DEBUG_LEAKS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MLEGACY}
CMAKE_ARGS+=	-DVTK_LEGACY_REMOVE:BOOL=OFF
PLIST_SUB+=	LEGACY=""
.else
CMAKE_ARGS+=	-DVTK_LEGACY_REMOVE:BOOL=ON
PLIST_SUB+=	LEGACY="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
	    ${WRKSRC}/Hybrid/vtkVRMLImporter.cxx
#	${REINPLACE_CMD} -e '222s|)|) \&\& !defined(__FreeBSD__)|' \
#	    ${WRKSRC}/Utilities/kwsys/SharedForward.h.in
	${REINPLACE_CMD} -e '25,30d' ${WRKSRC}/Wrapping/Python/setup.py.in
.if ${PORT_OPTIONS:MSHARED}
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|g' \
	    ${WRKSRC}/IO/vtkPNGReader.cxx
.endif

post-configure:
.if ${PORT_OPTIONS:MJAVA}
	${REINPLACE_CMD} -e 's|-ljawt$$||' \
	    ${CONFIGURE_WRKSRC}/Wrapping/Java/CMakeFiles/VTKJavaExecutable.dir/link.txt
.endif

pre-install:
.if ${PORT_OPTIONS:MPYTHON}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKDIR}/vtk.3 ${STAGEDIR}${PREFIX}/man/man3
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}
.endif

LIBS_TOFIX=	vtkNetCDF_cxx vtkhdf5 vtkhdf5_hl
LIBDIR=		${PREFIX}/lib/vtk-${PORTVERSION:R}/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/qt4/plugins/designer/libQVTKWidgetPlugin.so
# Ports system wants us to conform to lib.so.x format, but VTK5
# only installs lib.so.x.y and lib.so.x.y.z.
.if ${PORT_OPTIONS:MSHARED}
	@for lib in ${LIBS_TOFIX}; do \
		${INSTALL_LIB} ${STAGEDIR}${LIBDIR}/lib$$lib.so ${STAGEDIR}${LIBDIR}/lib$$lib.so.${PORTVERSION}; \
		${LN} -sf lib$$lib.so.${PORTVERSION} ${STAGEDIR}${LIBDIR}/lib$$lib.so.${PORTVERSION:R}; \
	done
	@cd ${STAGEDIR}${LIBDIR}; \
	for lib in *.so; do \
	    ${RM} -f $$lib; \
	    ${LN} -sf $$lib.${PORTVERSION} $$lib.${PORTVERSION:R}; \
	    ${LN} -sf $$lib.${PORTVERSION:R} $$lib.${PORTVERSION:R:R}; \
	    ${LN} -sf $$lib.${PORTVERSION:R:R} $$lib; \
	done
.if ${PORT_OPTIONS:MQT4}
	@cd ${STAGEDIR}${LIBDIR}; \
	for lib in libQVTK*.so; do \
	    ${RM} -f $$lib; \
	    ${LN} -sf $$lib.${PORTVERSION} $$lib; \
	    ${LN} -sf $$lib.${PORTVERSION} $$lib.${PORTVERSION:R:R}; \
	done
.endif
.endif

.if ${PORT_OPTIONS:MVTKMPEG2}
	@${ECHO_CMD}
	@${ECHO_CMD} "This port uses the patented MPEG2 encoder."
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
