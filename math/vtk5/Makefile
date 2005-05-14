# New ports collection makefile for:    vtk
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#
# By default
#
# There are some options to tune VTK towards your specific needs.
# You can activate a feature by typing something like
# "make -DKNOB" or "make KNOB=yes" instead of just "make"
#
# WITH_TESTING		build the testing binaries (only for vtk and vtk-java port)
#

PORTNAME=	vtk
PORTVERSION=	4.4
CATEGORIES=	math graphics
MASTER_SITES=	http://ovt.irfu.se/vtk/files/
DISTFILES?=	VTK-${PORTVERSION}-LatestRelease.tar.gz

MAINTAINER=	ko@irfu.se
COMMENT?=	The Visualization Toolkit shared libs

USE_REINPLACE=	yes

LIBVER=		1
VTKSRCDIR=	${WRKDIR}/VTK
TESTINGDIR=	${EXAMPLESDIR}/Testing
VTKDATAROOT=	${EXAMPLESDIR}/VTKData
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PLIST=		${.CURDIR}/pkg-plist
FILESDIR=	${.CURDIR}/files

VTK_KITS=	Common Filtering Graphics Hybrid IO Imaging Rendering Parallel Patented

PLIST_SUB+=	LIBVER=${LIBVER} PKGNAME=${PKGNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"does not compile on amd64"
.endif

.if defined(WRAP) || !defined(PKGNAMESUFFIX) || ${PKGNAMESUFFIX}=="-headers"

PATCH_WRKSRC=	${WRKDIR}/VTK
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-build

BUILD_DEPENDS+=	${CMAKE}:${PORTSDIR}/devel/cmake

LIB_DEPENDS+=	expat.5:${PORTSDIR}/textproc/expat2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

.if defined(WITH_TESTING) && (!defined(PKGNAMESUFFIX) || ${PKGNAMESUFFIX}=="-java")
RUN_DEPENDS+=	${VTKDATAROOT}/VTKData.readme:${PORTSDIR}/math/vtk-data
BUILD_DEPENDS+=	${VTKDATAROOT}/VTKData.readme:${PORTSDIR}/math/vtk-data
.endif

USE_GMAKE=	yes
USE_GL=		yes
INSTALLS_SHLIB=	yes

CMAKE?=		${LOCALBASE}/bin/cmake
CXXFLAGS+=	-Wno-deprecated
CMAKE_DEFS+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DBUILD_SHARED_LIBS:BOOL=ON \
		-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_SHARED_LINKER_FLAGS:STRING="${LINKERFLAGS}" \
		-DCMAKE_EXE_LINKER_FLAGS:STRING="${LINKERFLAGS} ${PTHREAD_LIBS}" \
		-DCMAKE_THREAD_LIBS:STRING="${PTHREAD_LIBS}"\
		-DCMAKE_USE_PTHREADS:BOOL=ON \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS} ${PTHREAD_CFLAGS}" \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		-DVTK_USE_RENDERING:BOOL=ON \
		-DVTK_USE_HYBRID:BOOL=ON \
		-DVTK_USE_PARALLEL:BOOL=ON \
		-DVTK_USE_PATENTED:BOOL=ON \
		-DVTK_USE_SYSTEM_EXPAT:BOOL=ON \
		-DVTK_USE_SYSTEM_JPEG:BOOL=ON \
		-DVTK_USE_SYSTEM_PNG:BOOL=ON \
		-DVTK_USE_SYSTEM_TIFF:BOOL=ON \
		-DVTK_USE_SYSTEM_ZLIB:BOOL=ON \
		-DVTK_DATA_ROOT:PATH=${VTKDATAROOT}

.if defined(WITH_TESTING)
CMAKE_DEFS+=	-DBUILD_TESTING:BOOL=ON
PLIST_SUB+=	TESTING_ONLY=""
.else
CMAKE_DEFS+=	-DBUILD_TESTING:BOOL=OFF
PLIST_SUB+=	TESTING_ONLY="@comment "
.endif

################################# vtk port start #############################################

.ifndef(PKGNAMESUFFIX)

EXTRA_LIBS=	DICOMParser freetype ftgl

.if defined(WITH_TESTING)
BINARIES=	${VTK_KITS:C/Parallel//:C/Patented//:S/$/CxxTests/}
BINARIES+=	TestCxxFeatures TestInstantiator TimeRenderer TimeRenderer2 ParallelIsoTest
BINARIES+=	SocketClient SocketServer GenericCommunicator ThreadedCommunicator TestPStream
.endif

.ifndef(WITH_TESTING)
pre-everything::
	@${ECHO_MSG} "---------------------- N   O   T   E ------------------------"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to build C++ Testing binaries press Ctrl-C now"
	@${ECHO_MSG} "and execute \"make WITH_TESTING=yes\""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "-------------------------------------------------------------"
.endif

post-patch: patch-common

do-install: install-cnotice install-binaries install-libs

.endif

################################# vtk port end #############################################

pre-configure:
	${MKDIR} ${WRKSRC}

do-configure:
	cd ${WRKSRC} && ${CMAKE} ${VTKSRCDIR} ${CMAKE_DEFS}

patch-common:
	@${FIND} ${VTKSRCDIR} -name "*.cxx" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|g'
	@${REINPLACE_CMD} -E 's|lib/vtk\)|lib\)|g' \
		${VTKSRCDIR}/vtkGenerateVTKConfig.cmake
.if defined(WRAP)
# No need to build many libs, such as: vtkCommon,... Better link to those ones installed by vtk port.
# Patch (MAIN_KIT_LIB = [Common_LIB Filtering_LIB ...]:
# ${VTKSRCDIR}/CMakeLists.txt :
#       -SUBDIRS(Wrapping Utilities)
#       +SUBDIRS(Wrapping)
#
# ${VTKSRCDIR}/[Common Filtering IO ...]/CMakeLists.txt :
#       -ADD_LIBRARY(vtk${KIT} ...
#       +FIND_LIBRARY(MAIN_KIT_LIB NAMES vtk${KIT} PATHS ${PREFIX}/lib)
#
#       -TARGET_LINK_LIBRARIES(vtk${KIT}Python vtk${KIT} ...
#       +TARGET_LINK_LIBRARIES(vtk${KIT}Python ${MAIN_KIT_LIB} ...
#
#	Sometimes 	TARGET_LINK_LIBRARIES(vtk${KIT}Python vtk${KIT} can be separated to two lines:
#			TARGET_LINK_LIBRARIES(vtk${KIT}Python
#						vtk${KIT}
#	-^[spaces or tabs]vtk${KIT}[spaces or tabs]$
#	+[space]${MAIN_KIT_LIB}
#
#       -TARGET_LINK_LIBRARIES(vtk${KIT} ${KIT_LIBS})
#
# ${VTKSRCDIR}/[Common Filtering IO ...]/Tests/CMakeLists.txt :
#       -SUBDIRS(Cxx)
#
	@${REINPLACE_CMD} -E 's|SUBDIRS\(Wrapping Utilities\)|SUBDIRS\(Wrapping\)|g' \
		${VTKSRCDIR}/CMakeLists.txt

	@for dir in ${VTK_KITS} ; do \
		${ECHO_MSG} "Patching ${WRKDIR}/${VTKSRCDIR}/$$dir/CMakeLists.txt ..." ; \
		${REINPLACE_CMD} -E 's|ADD_LIBRARY *\(vtk\$$\{KIT\} .*$$|FIND_LIBRARY\('$$dir'_LIB NAMES vtk\$$\{KIT\} PATHS ${PREFIX}/lib\)|g ; s|TARGET_LINK_LIBRARIES *\(vtk\$$\{KIT\}${WRAP} vtk\$$\{KIT\}|TARGET_LINK_LIBRARIES\(vtk\$$\{KIT\}${WRAP} \$$\{'$$dir'_LIB\}|g ; s|^[ \t]*vtk\$$\{KIT\}[ \t]*$$| \$$\{'$$dir'_LIB\}|g ; s|TARGET_LINK_LIBRARIES *\(vtk\$$\{KIT\} .*$$||g' \
			${VTKSRCDIR}/$$dir/CMakeLists.txt ; \
	done

.if defined(WITH_TESTING)
	@for dir in ${VTK_KITS} ; do \
		${ECHO_MSG} "Patching ${VTKSRCDIR}/$$dir/Testing/CMakeLists.txt ..." ; \
		${REINPLACE_CMD} -E 's|SUBDIRS *\(Cxx\).*$$||g' \
			${VTKSRCDIR}/$$dir/Testing/CMakeLists.txt ; \
	done
.endif
.endif	#end of patch-common

install-binaries:
.if defined(BINARIES)
	@${ECHO_MSG} "Installing binaries to ${PREFIX}/bin :"
.for i in ${BINARIES}
	@${ECHO_MSG} "Installing ${i} ..."
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${i} ${PREFIX}/bin
.endfor
.endif

install-libs:
	@${ECHO_MSG} "Installing shared libraries to ${PREFIX}/lib ..."
.for i in ${VTK_KITS:S/$/${WRAP}/} ${EXTRA_LIBS}
	@${ECHO_MSG} "Installing libvtk${i}.so ..."
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/libvtk${i}.so \
			${PREFIX}/lib/libvtk${i}.so.${LIBVER}
	@${LN} -sf ${PREFIX}/lib/libvtk${i}.so.${LIBVER} \
			${PREFIX}/lib/libvtk${i}.so
.endfor

.endif

install-cnotice:
	@${ECHO_MSG} "Installing copyright notice to ${DOCSDIR} ..."
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${VTKSRCDIR}/README.html ${DOCSDIR}
	@${INSTALL_DATA} ${VTKSRCDIR}/vtkLogo.jpg ${DOCSDIR}
	@${ECHO_MSG} -e "A list of the patented classes.\n\n" > ${WRKDIR}/README.patented-classes
	@cd ${VTKSRCDIR} ; ${LS} Patented/*.h >> ${WRKDIR}/README.patented-classes
	@${INSTALL_DATA} ${WRKDIR}/README.patented-classes ${DOCSDIR}

print-pkg-message:
	@if ${TEST} -f ${PKGMESSAGE} ; then \
	${ECHO_MSG} -e "-- V T K - N O T E ----------------------------------------------------\n\n" ; \
	${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' ; \
	${ECHO_MSG} -e "\n\n-----------------------------------------------------------------------" ; \
	fi

post-install: print-pkg-message

.ifndef(PKGNAMESUFFIX)
.include <bsd.port.post.mk>
.endif
