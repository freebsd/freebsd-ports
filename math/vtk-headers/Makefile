# New ports collection makefile for:    vtk-headers
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-headers

COMMENT=	The Visualization Toolkit C++ headers, CMake includes, Doxygen

MASTERDIR=	${.CURDIR}/../vtk

.include "${MASTERDIR}/Makefile"

post-patch:
#	@${REINPLACE_CMD} -E 's|^.*LOAD_CMAKE_EXTENSIONS|#|g' \
#		${VTKSRCDIR}/VTKConfig.cmake.in ${VTKSRCDIR}/UseVTK.cmake.in
	@${REINPLACE_CMD} -E 's|lib/vtk\)|lib\)|g ; s|lib/vtk/doxygen|share/vtk/doxygen| ; s|lib/vtk/testing/HeaderTesting.py|share/examples/vtk/Testing/Common/HeaderTesting.py| ; s|lib/vtk/testing|share/examples/vtk/Testing/Common/Tcl|g' \
		${VTKSRCDIR}/vtkGenerateVTKConfig.cmake
	@${REINPLACE_CMD} -E 's|lib/vtk/doxygen|share/vtk/doxygen|g' \
		${VTKSRCDIR}/Utilities/Doxygen/CMakeLists.txt

do-build:
#	cd ${WRKSRC}/CMake ; ${MAKE}

do-install: install-cnotice
	@${ECHO_MSG} "Installing headers to ${PREFIX}/include/vtk ..."
	${MKDIR} ${PREFIX}/include/vtk
.for i in  ${VTK_KITS}
	@${INSTALL_DATA} ${VTKSRCDIR}/${i}/*.h ${PREFIX}/include/vtk
.endfor
	@${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/vtk
	@${MKDIR} ${PREFIX}/include/vtk/vtkstd
	@${INSTALL_DATA} ${WRKSRC}/vtkstd/* ${PREFIX}/include/vtk/vtkstd
	@${MKDIR} ${PREFIX}/include/vtk/DICOMParser
	@${INSTALL_DATA} ${VTKSRCDIR}/Utilities/DICOMParser/*.h ${PREFIX}/include/vtk/DICOMParser
	@${INSTALL_DATA} ${WRKSRC}/Utilities/DICOMParser/*.h ${PREFIX}/include/vtk/DICOMParser

	@${ECHO_MSG} "Installing CMake includes to ${PREFIX}/lib/vtk ..."
	@${MKDIR} ${PREFIX}/lib/vtk
.for i in Utilities/VTKConfig UseVTK VTKBuildSettings VTKLibraryDepends
	@${ECHO_MSG} "Installing ${i}.cmake ..."
	@${INSTALL_DATA} ${WRKSRC}/${i}.cmake ${PREFIX}/lib/vtk
.endfor
	@${MKDIR} ${PREFIX}/lib/vtk/CMake
	@${ECHO_MSG} "Installing vtkLoadCMakeExtensions.cmake ..."
	@${INSTALL_DATA} ${VTKSRCDIR}/CMake/vtkLoadCMakeExtensions.cmake ${PREFIX}/lib/vtk/CMake

	@${ECHO_MSG} "Installing CMake extensions to ${PREFIX}/lib/vtk/CMake :"
.for i in GENERATE_JAVA_DEPENDENCIES MAKE_INSTANTIATOR2 WRAP_JAVA2 WRAP_PYTHON2 WRAP_TCL2
	@${ECHO_MSG} "Installing libcmVTK_${i}.so ..."
	@${INSTALL_DATA} ${WRKSRC}/CMake/libcmVTK_${i}.so ${PREFIX}/lib/vtk/CMake
.endfor

	@${ECHO_MSG} "Installing Doxygen to ${PREFIX}/share/vtk/doxygen :"
	@cd ${WRKSRC}/Utilities/Doxygen ; ${MAKE} install

.include <bsd.port.post.mk>
