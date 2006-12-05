# New ports collection makefile for:    vtk43-headers
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#

PORTEPOCH=	1

PKGNAMESUFFIX=	-headers

COMMENT=	The Visualization Toolkit C++ headers, CMake includes, Doxygen

MASTERDIR=	${.CURDIR}/../vtk43

DEPRECATED= Please use vtk 4.4 or 5.x.
EXPIRATION_DATE= 2007-02-01

.include "${MASTERDIR}/Makefile"

post-patch:
#	@${REINPLACE_CMD} -E 's|^.*LOAD_CMAKE_EXTENSIONS|#|g' \
#		${VTKSRCDIR}/VTKConfig.cmake.in ${VTKSRCDIR}/UseVTK.cmake.in
	@${REINPLACE_CMD} -E 's|lib/vtk\)|lib/vtk43\)|g ; s|lib/vtk/doxygen|share/vtk43/doxygen| ; s|lib/vtk/testing/HeaderTesting.py|share/examples/vtk43/Testing/Common/HeaderTesting.py| ; s|lib/vtk/testing|share/examples/vtk43/Testing/Common/Tcl|g' \
		${VTKSRCDIR}/vtkGenerateVTKConfig.cmake
	@${REINPLACE_CMD} -E 's|lib/vtk/doxygen|share/vtk43/doxygen|g' \
		${VTKSRCDIR}/Utilities/Doxygen/CMakeLists.txt

do-build:
#	cd ${WRKSRC}/CMake ; ${MAKE}

do-install: install-cnotice
	@${ECHO_MSG} "Installing headers to ${PREFIX}/include/vtk43 ..."
	${MKDIR} ${PREFIX}/include/vtk43
.for i in  ${VTK_KITS}
	@${INSTALL_DATA} ${VTKSRCDIR}/${i}/*.h ${PREFIX}/include/vtk43
.endfor
	@${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/vtk43
	@${MKDIR} ${PREFIX}/include/vtk43/vtkstd
	@${INSTALL_DATA} ${WRKSRC}/vtkstd/* ${PREFIX}/include/vtk43/vtkstd
	@${MKDIR} ${PREFIX}/include/vtk43/DICOMParser
	@${INSTALL_DATA} ${VTKSRCDIR}/Utilities/DICOMParser/*.h ${PREFIX}/include/vtk43/DICOMParser
	@${INSTALL_DATA} ${WRKSRC}/Utilities/DICOMParser/*.h ${PREFIX}/include/vtk43/DICOMParser

	@${ECHO_MSG} "Installing CMake includes to ${PREFIX}/lib/vtk43 ..."
	@${MKDIR} ${PREFIX}/lib/vtk43
.for i in Utilities/VTKConfig UseVTK VTKBuildSettings VTKLibraryDepends
	@${ECHO_MSG} "Installing ${i}.cmake ..."
	@${INSTALL_DATA} ${WRKSRC}/${i}.cmake ${PREFIX}/lib/vtk43
.endfor
	@${MKDIR} ${PREFIX}/lib/vtk43/CMake
	@${ECHO_MSG} "Installing vtkLoadCMakeExtensions.cmake ..."
	@${INSTALL_DATA} ${VTKSRCDIR}/CMake/vtkLoadCMakeExtensions.cmake ${PREFIX}/lib/vtk43/CMake

	@${ECHO_MSG} "Installing CMake extensions to ${PREFIX}/lib/vtk43/CMake :"
.for i in GENERATE_JAVA_DEPENDENCIES MAKE_INSTANTIATOR2 WRAP_JAVA2 WRAP_PYTHON2 WRAP_TCL2
	@${ECHO_MSG} "Installing libcmVTK_${i}.so ..."
	@${INSTALL_DATA} ${WRKSRC}/CMake/libcmVTK_${i}.so ${PREFIX}/lib/vtk43/CMake
.endfor

	@${ECHO_MSG} "Installing Doxygen to ${PREFIX}/share/vtk43/doxygen :"
	@cd ${WRKSRC}/Utilities/Doxygen ; ${MAKE} install

.include <bsd.port.post.mk>
