# New ports collection makefile for:    vtk-python
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#

CATEGORIES+=	python
PKGNAMESUFFIX=	-python

COMMENT=	The Visualization Toolkit Python libs

LIB_DEPENDS=	vtkCommon.${LIBVER}:${PORTSDIR}/math/vtk \
		tcl84:${PORTSDIR}/lang/tcl84 \
		tk84:${PORTSDIR}/x11-toolkits/tk84

MASTERDIR=	${.CURDIR}/../vtk

WRAP=		Python
BINARIES=	vtkWrapPython vtkpython
EXTRA_LIBS=	RenderingPythonTkWidgets

USE_PYTHON=	yes
TCL_INCLUDE_DIR=${PREFIX}/include/tcl8.4
TK_INCLUDE_DIR=	${PREFIX}/include/tk8.4

CXXFLAGS+=	-DUSE_NON_CONST \
		-DUSE_COMPOSITELESS_PHOTO_PUT_BLOCK \
		-I${TCL_INCLUDE_DIR} # -Ds for TCL/TK 8.4, -I for libvtkRenderingPythonTkWidgets.so build

LINKERFLAGS=	-L${PREFIX}/lib	# to link vtkpython to vtk libs

CMAKE_DEFS=	-DVTK_WRAP_PYTHON:BOOL=ON \
		-DPYTHON_INCLUDE_PATH:PATH=${PYTHON_INCLUDEDIR} \
		-DPYTHON_LIBRARY:FILEPATH=${PYTHON_LIBDIR}/config/lib${PYTHON_VERSION}.a \
		-DTCL_INCLUDE_PATH:PATH=${TCL_INCLUDE_DIR} \
		-DTK_INCLUDE_PATH:PATH=${TK_INCLUDE_DIR}

PLIST_SUB+=	VTK_PTH_LOCATION_DIR=${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"

post-patch: patch-common

do-install: install-cnotice install-binaries install-libs
	@${ECHO_MSG} "Installing vtk site package to ${PREFIX}/lib/vtk/python ..."
	@${MKDIR} ${PREFIX}/lib/vtk
.for i in "" vtk/ vtk/gtk/ vtk/qt/ vtk/test/ vtk/tk/ vtk/util/ vtk/wx/
	@${MKDIR} ${PREFIX}/lib/vtk/python/${i}
	@${INSTALL_DATA} ${VTKSRCDIR}/Wrapping/Python/${i}*.py ${PREFIX}/lib/vtk/python/${i}
.endfor
	@${ECHO} ${PREFIX}/lib/vtk/python > ${PYTHON_SITELIBDIR}/vtk.pth
	@${PYTHON_CMD}  -c "import compileall; compileall.compile_dir( '${PREFIX}/lib/vtk/python' );"
	@${PYTHON_CMD} -Oc "import compileall; compileall.compile_dir( '${PREFIX}/lib/vtk/python' );"

.for i in ${VTK_KITS:S/$/Python/} ${EXTRA_LIBS}
	@${LN} -sf ${PREFIX}/lib/libvtk${i}.so \
		${PREFIX}/lib/vtk/python/libvtk${i}.so
.endfor

.include <bsd.port.post.mk>
