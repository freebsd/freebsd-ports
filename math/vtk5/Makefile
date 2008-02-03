# New ports collection makefile for:	vtk5
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
# Repocopied from math/vtk by:	Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	vtk
PORTVERSION=	5.0.3
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/5.0/ \
		http://www.neuro.mcw.edu/Ports/distfiles/VTK5/
DISTNAME?=	vtk-${PORTVERSION}

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	The Visualization Toolkit

BUILD_DEPENDS=	cmake>=2.2:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	expat.[5-6]:${PORTSDIR}/textproc/expat2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

LATEST_LINK=	vtk5

USE_QT_VER=	3
USE_TCL=	yes
USE_TK=		yes
USE_PYTHON=	yes
INSTALLS_EGGINFO=	yes

VTKSRCDIR=	${WRKDIR}/VTK
VTKDATAROOT=	${EXAMPLESDIR}/VTKData
PYDISTUTILS_PKGNAME=	VTK

CONFLICTS=	vtk-4* vtk-5.0.[012456789]*
NO_FILTER_SHLIBS=	yes

VTK_KITS=	Common Filtering GenericFiltering Graphics \
		Hybrid IO Imaging Parallel Rendering VolumeRendering \
		Widgets

SUB_FILES=	pkg-message vtk.3
PKGMESSAGE=	${WRKDIR}/pkg-message

PATCH_WRKSRC=	${WRKDIR}/VTK
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-build

USE_GMAKE=	yes
USE_GL=		yes
USE_LDCONFIG=	yes

OPTIONS=	VTKMPEG2	"Install patented MPEG2 encoder module" Off

PLIST_SUB=	VER=${PORTVERSION} VER1=${PORTVERSION:R} VER2=${PORTVERSION:R:R}

MAN3=		vtk.3

.include <bsd.port.pre.mk>

CMAKE?=		${LOCALBASE}/bin/cmake
CXXFLAGS+=	-Wno-deprecated
CMAKE_DEFS+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DBUILD_SHARED_LIBS:BOOL=ON \
		-DBUILD_DOCUMENTATION:BOOL=ON \
		-DBUILD_TESTING:BOOL=OFF \
		-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_SHARED_LINKER_FLAGS:STRING="${LINKERFLAGS}" \
		-DCMAKE_EXE_LINKER_FLAGS:STRING="${LINKERFLAGS} ${PTHREAD_LIBS}" \
		-DCMAKE_THREAD_LIBS:STRING="${PTHREAD_LIBS}"\
		-DCMAKE_USE_PTHREADS:BOOL=ON \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS} ${PTHREAD_CFLAGS}" \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		-DCMAKE_VERBOSE_MAKEFILE:BOOL=OFF \
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
		-DVTK_DATA_ROOT:PATH=${VTKDATAROOT}

.if defined(WITH_VTKMPEG2)
LIB_DEPENDS+=	vtkMPEG2Encode.5:${PORTSDIR}/multimedia/vtkmpeg2encode
PLIST_FILES+=	include/vtk-5.0/vtkMPEG2Writer.h
CMAKE_DEFS+=	-DvtkMPEG2Encode_INCLUDE_PATH=${LOCALBASE}/include/vtk-5.0 \
		-DvtkMPEG2Encode_LIBRARIES=vtkMPEG2Encode \
		-DVTK_USE_PATENTED:BOOL=ON \
		-DVTK_USE_MPEG2_ENCODER:BOOL=ON
.endif

post-extract:
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
		${VTKSRCDIR}/Hybrid/vtkVRMLImporter.cxx

do-configure:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${CMAKE} ${VTKSRCDIR} ${CMAKE_DEFS}

# FSL links directly to libQVTKWidgetPlugin.so, so put it in a standard
# library directory.
pre-install:
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${PREFIX}/lib/vtk-5.0
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${VTKSRCDIR}/README.html ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/bin/libQVTKWidgetPlugin.so ${PREFIX}/lib
	${INSTALL_MAN} ${WRKDIR}/vtk.3 ${MANPREFIX}/man/man3

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
