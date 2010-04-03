# New ports collection makefile for:	vtk5
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
# Repocopied from math/vtk by:	Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	vtk
PORTVERSION=	5.4.2
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${PORTVERSION:R}/ \
		http://www.neuro.mcw.edu/Ports/distfiles/VTK5/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The Visualization Toolkit

LIB_DEPENDS=	expat.[5-6]:${PORTSDIR}/textproc/expat2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

LATEST_LINK=	vtk5

WRKSRC=		${WRKDIR}/VTK

CONFLICTS=	vtk-4* vtk-5.0.[012356789]*

SUB_FILES=	vtk.3

USE_CMAKE=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	no

OPTIONS=	VTKMPEG2	"Install patented MPEG2 encoder module" Off \
		GL2PS           "Install support conversion OpenGL to PostScript" On \
		QT		"Enable Qt gui support" On \
		WRAP_PYTHON	"Enable Python wrapping" On \
		WRAP_TCLTK	"Enable Tcl/Tk wrapping" On

PLIST_SUB=	VER1="${PORTVERSION:R}" \
		VER2="${PORTVERSION}"

MAN3=		vtk.3
PORTDOCS=	README.html

CMAKE_USE_PTHREAD=	yes
CMAKE_OUTSOURCE=	yes

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
   		-DBUILD_SHARED_LIBS:BOOL=ON \
		-DBUILD_DOCUMENTATION:BOOL=ON \
		-DBUILD_TESTING:BOOL=OFF \
		-DVTK_USE_SYSTEM_EXPAT:BOOL=ON \
		-DVTK_USE_SYSTEM_JPEG:BOOL=ON \
		-DVTK_USE_SYSTEM_PNG:BOOL=ON \
		-DVTK_USE_SYSTEM_TIFF:BOOL=ON \
		-DVTK_USE_SYSTEM_ZLIB:BOOL=ON \
		-DVTK_USE_GUISUPPORT:BOOL=ON \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T:BOOL=ON \
		-DVTK_DATA_ROOT:PATH=${EXAMPLESDIR}/VTKData \
		-DOPENGL_INCLUDE_DIR:PATH=${LOCALBASE}/include \
		-DOPENGL_gl_LIBRARY:FILEPATH=${LOCALBASE}/lib/libGL.so \
		-DOPENGL_glu_LIBRARY:FILEPATH=${LOCALBASE}/lib/libGLU.so

.include <bsd.port.options.mk>

.if defined(WITH_VTKMPEG2)
LIB_DEPENDS+=	vtkMPEG2Encode.5:${PORTSDIR}/multimedia/vtkmpeg2encode
PLIST_SUB+=	MPEG=""
CMAKE_ARGS+=	-DVTK_USE_PATENTED:BOOL=ON \
		-DVTK_USE_MPEG2_ENCODER:BOOL=ON \
		-DvtkMPEG2Encode_INCLUDE_PATH=${LOCALBASE}/include/vtk-5.4 \
		-DvtkMPEG2Encode_LIBRARIES=${LOCALBASE}/lib/libvtkMPEG2Encode.so
.else
PLIST_SUB+=	MPEG="@comment "
.endif

.if defined(WITH_GL2PS)
LIB_DEPENDS+=	gl2ps.1:${PORTSDIR}/print/gl2ps
CMAKE_ARGS+=	-DVTK_USE_GL2PS:BOOL=ON
PLIST_SUB+=	GL2PS=""
.else
PLIST_SUB+=	GL2PS="@comment "
.endif

.if defined(WITH_QT)
USE_QT_VER=	4
QT_COMPONENTS=	qmake corelib assistant assistantclient designer uic
CMAKE_ARGS+=	-DVTK_USE_GUISUPPORT:BOOL=ON \
   		-DVTK_USE_QVTK:BOOL=ON \
   		-DDESIRED_QT_VERSION:STRING=4 \
		-DQT_QMAKE_EXECUTABLE:FILEPATH=${QMAKE}
PLIST_SUB+=	QT=""
.else
CMAKE_ARGS+=	-DVTK_USE_GUISUPPORT:BOOL=OFF
PLIST_SUB+=	QT="@comment "
.endif

.if defined(WITH_WRAP_PYTHON)
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
USE_TCL=	84+
USE_TK=		84+
CMAKE_ARGS+=	-DVTK_WRAP_TCL:BOOL=ON \
		-DTCL_INCLUDE_PATH=${TCL_INCLUDEDIR} \
		-DTK_INCLUDE_PATH=${TK_INCLUDEDIR}
PLIST_SUB+=	TCLTK="" \
		TCLTK_VER="${TCL_VER}"
.else
CMAKE_ARGS+=	-DVTK_WRAP_TCL:BOOL=OFF
PLIST_SUB+=	TCLTK="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
	    ${WRKSRC}/Hybrid/vtkVRMLImporter.cxx
	${REINPLACE_CMD} -e '222s|)|) \&\& !defined(__FreeBSD__)|' \
	    ${WRKSRC}/Utilities/kwsys/SharedForward.h.in
	${REINPLACE_CMD} -e '25,30d' ${WRKSRC}/Wrapping/Python/setup.py.in
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
	    ${WRKSRC}/IO/vtkPNGReader.cxx

# FSL links directly to libQVTKWidgetPlugin.so, so put it in a standard
# library directory.
pre-install:
	${MKDIR} ${PYTHONPREFIX_SITELIBDIR}
	${MKDIR} ${MANPREFIX}/man/man3
	${INSTALL_MAN} ${WRKDIR}/vtk.3 ${MANPREFIX}/man/man3
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

# Ports system wants us to conform to lib.so.x format, but VTK5
# only installs lib.so.x.y and lib.so.5.x.y.z.
post-install:
.if defined(WITH_VTKMPEG2)
	@${ECHO_CMD}
	@${ECHO_CMD} "This port uses the patented MPEG2 encoder."
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
