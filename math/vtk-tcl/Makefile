# New ports collection makefile for:    vtk-tcl
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#

CATEGORIES+=	tcl84 tk84
PKGNAMESUFFIX=	-tcl

COMMENT=	The Visualization Toolkit Tcl libs

LIB_DEPENDS=	vtkCommon.${LIBVER}:${PORTSDIR}/math/vtk \
		tcl84:${PORTSDIR}/lang/tcl84 \
		tk84:${PORTSDIR}/x11-toolkits/tk84

MASTERDIR=	${.CURDIR}/../vtk
WRAP=		TCL
BINARIES=	vtk vtkWrapTcl

USE_PYTHON=	yes
TCL_INCLUDE_DIR=${PREFIX}/include/tcl8.4
TK_INCLUDE_DIR=	${PREFIX}/include/tk8.4

CXXFLAGS+=	-DUSE_NON_CONST \
		-DUSE_COMPOSITELESS_PHOTO_PUT_BLOCK	# for TCL/TK 8.4

CMAKE_DEFS=	-DVTK_WRAP_TCL:BOOL=ON \
		-DTCL_INCLUDE_PATH:PATH=${TCL_INCLUDE_DIR} \
		-DTK_INCLUDE_PATH:PATH=${TK_INCLUDE_DIR}

.include "${MASTERDIR}/Makefile"

post-patch: patch-common

do-install: install-cnotice install-binaries install-libs
	cd ${WRKSRC}/Wrapping/Tcl ; ${MAKE} install

.include <bsd.port.post.mk>
