# New ports collection makefile for:	vtk5
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
# Repocopied from math/vtk by:	Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	vtk
PORTVERSION=	5.0.4
PORTREVISION=	5
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${PORTVERSION:R}/ \
		http://www.neuro.mcw.edu/Ports/distfiles/VTK5/
DISTNAME?=	vtk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Visualization Toolkit

LIB_DEPENDS=	expat.[5-6]:${PORTSDIR}/textproc/expat2 \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

LATEST_LINK=	vtk5

USE_QT_VER=	3
USE_TCL=	84
USE_TK=		84
USE_PYTHON=	yes
INSTALLS_EGGINFO=	yes

VTKSRCDIR=	${WRKDIR}/VTK
VTKDATAROOT=	${EXAMPLESDIR}/VTKData
PYDISTUTILS_PKGNAME=	VTK

CONFLICTS=	vtk-4* vtk-5.0.[012356789]*
NO_FILTER_SHLIBS=	yes

VTK_KITS=	Common Filtering GenericFiltering Graphics \
		Hybrid IO Imaging Parallel Rendering VolumeRendering \
		Widgets

SUB_FILES=	pkg-message vtk.3
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_CMAKE=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_LDCONFIG=	yes

OPTIONS=	MANGLEDMESA	"Use off-screen (Mangled) Mesa" Off \
		VTKMPEG2	"Install patented MPEG2 encoder module" Off \
		GL2PS           "Install support conversion OpenGL to PostScript" On

PLIST_SUB=	VER=${PORTVERSION} VER1=${PORTVERSION:R} VER2=${PORTVERSION:R:R}

MAN3=		vtk.3

.include <bsd.port.pre.mk>

CMAKE_USE_PTHREAD=	yes
CMAKE_SOURCE_PATH=	../VTK
CMAKE_ARGS+=	${VTKSRCDIR} \
		-DBUILD_SHARED_LIBS:BOOL=ON \
		-DBUILD_DOCUMENTATION:BOOL=ON \
		-DBUILD_TESTING:BOOL=OFF \
		-DVTK_USE_RENDERING:BOOL=ON \
		-DVTK_USE_HYBRID:BOOL=ON \
		-DVTK_USE_PARALLEL:BOOL=ON \
		-DVTK_USE_SYSTEM_EXPAT:BOOL=ON \
		-DVTK_USE_SYSTEM_JPEG:BOOL=ON \
		-DVTK_USE_SYSTEM_PNG:BOOL=ON \
		-DVTK_USE_SYSTEM_TIFF:BOOL=ON \
		-DVTK_USE_SYSTEM_ZLIB:BOOL=ON \
		-DVTK_USE_GUISUPPORT:BOOL=ON \
		-DVTK_USE_QVTK:BOOL=ON \
		-DVTK_WRAP_PYTHON:BOOL=ON \
		-DVTK_WRAP_TCL:BOOL=ON \
		-DTCL_INCLUDE_PATH=${TCL_INCLUDEDIR} \
		-DTK_INCLUDE_PATH=${TK_INCLUDEDIR} \
		-DDESIRED_QT_VERSION:STRING=3 \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T:BOOL=ON \
		-DVTK_DATA_ROOT:PATH=${VTKDATAROOT} \
		-DOPENGL_INCLUDE_DIR:PATH=${LOCALBASE}/include \
		-DOPENGL_gl_LIBRARY:FILEPATH=${LOCALBASE}/lib/libGL.so \
		-DOPENGL_glu_LIBRARY:FILEPATH=${LOCALBASE}/lib/libGLU.so

.if defined(WITH_MANGLEDMESA)
LIB_DEPENDS+=	MesaGL.14:${PORTSDIR}/graphics/mesagl
CMAKE_ARGS+=	-DVTK_OPENGL_HAS_OSMESA:BOOL=OFF	\
		-DVTK_USE_MANGLED_MESA:BOOL=ON \
		-DMANGLED_MESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
		-DMANGLED_MESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libMesaGL.so \
		-DMANGLED_OSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
		-DMANGLED_OSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libMesaOSMesa.so
#.else
#CMAKE_ARGS+=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
#		-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so
.endif

.if defined(WITH_VTKMPEG2)
LIB_DEPENDS+=	vtkMPEG2Encode.5:${PORTSDIR}/multimedia/vtkmpeg2encode
PLIST_FILES+=	include/vtk-5.0/vtkMPEG2Writer.h
CMAKE_ARGS+=	-DvtkMPEG2Encode_INCLUDE_PATH=${LOCALBASE}/include/vtk-5.0 \
		-DvtkMPEG2Encode_LIBRARIES=vtkMPEG2Encode \
		-DVTK_USE_PATENTED:BOOL=ON \
		-DVTK_USE_MPEG2_ENCODER:BOOL=ON
.endif

.if defined(WITH_GL2PS)
LIB_DEPENDS+=	gl2ps.1:${PORTSDIR}/print/gl2ps
CMAKE_ARGS+=	-DVTK_USE_GL2PS:BOOL=ON
PLIST_FILES+=	include/vtk-5.0/vtkGL2PSExporter.h
.endif

post-extract:
		${MKDIR} ${WRKSRC}
		${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
		${VTKSRCDIR}/Hybrid/vtkVRMLImporter.cxx

# FSL links directly to libQVTKWidgetPlugin.so, so put it in a standard
# library directory.
pre-install:
	${MKDIR} ${PREFIX}/lib/vtk-5.0
	${INSTALL_DATA} ${WRKSRC}/bin/libQVTKWidgetPlugin.so ${PREFIX}/lib
	${INSTALL_MAN} ${WRKDIR}/vtk.3 ${MANPREFIX}/man/man3
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${VTKSRCDIR}/README.html ${DOCSDIR}
.endif

# Ports system wants us to conform to lib.so.x format, but VTK5
# only installs lib.so.x.y and lib.so.5.x.y.z.
post-install:
	@for lib in ${PREFIX}/lib/libvtk*.so ${PREFIX}/lib/libQVTK*.so; do \
		${RM} -f $$lib; \
		${LN} -sf $$lib.${PORTVERSION} $$lib; \
		${LN} -sf $$lib.${PORTVERSION} $$lib.5; \
	done
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.if defined(WITH_VTKMPEG2)
	@${ECHO_CMD} "This port uses the patented MPEG2 encoder."
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
