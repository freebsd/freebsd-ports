# Created by: Pedro Giffuni

PORTNAME=	elmerfem
PORTVERSION=	8.4.20200708
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	henrik@gulbra.net
COMMENT=	Multiphysical simulation software

LICENSE=	GPLv2

LIB_DEPENDS=	libmetis.so:math/metis \
		libmpich.so:net/mpich \
		libopenblas.so:math/openblas \
		libparpack.so:math/arpack-ng

USES=		cmake compiler:c++11-lang fortran
USE_GITHUB=	yes
GH_ACCOUNT=	ElmerCSC
GH_TAGNAME=	679a882b
USE_LDCONFIG=	${PREFIX}/lib/elmersolver

ALL_TARGET=	# empty

CMAKE_ARGS=	-DELMER_FEM_REVISION:STRING=${GH_TAGNAME}

LDFLAGS+=	-L${LOCALBASE}/lib
FCPPFLAGS+=	-ansi

CMAKE_ARGS+=	-DHAVE_INTTYPES_H=ON
.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
.endif

OPTIONS_DEFINE=		GUI OCC
OPTIONS_DEFAULT=	GUI OCC
OPTIONS_SUB=		yes
OCC_IMPLIES=		GUI

GUI_DESC=		Build with ElmerGUI (Graphical User Interface)
GUI_CMAKE_BOOL=		WITH_ELMERGUI WITH_PARAVIEW
GUI_CMAKE_ON=		-DQWT_LIBRARY=${QT_LIBDIR}/libqwt6.so \
			-DQWT_INCLUDE_DIR=${QT_INCDIR}/qwt6 \
			-DDESIRED_QT_VERSION=5 \
			-DWITH_QT5:BOOL=TRUE \
			-DQT_FOUND:BOOL=TRUE
GUI_LIB_DEPENDS=	libqwt6.so:x11-toolkits/qwt6
GUI_USES=		gl jpeg qt:5 xorg
GUI_USE=		gl=gl,glu xorg=ice,sm,x11,xext,xt qt=${QT5_LIBS:ts,}

OCC_DESC=		Use OpenCASCADE for CAD import in ElmerGUI
OCC_CMAKE_BOOL=		WITH_OCC
OCC_CMAKE_ON=		-DVTK_DIR=${LOCALBASE}/lib/vtk-8.2/cmake/vtk-8.2
OCC_LIB_DEPENDS=	libexpat.so:textproc/expat2 \
			libfreetype.so:print/freetype2 \
			libpng.so:graphics/png \
			libpython3.7m.so:lang/python37 \
			libtiff.so:graphics/tiff \
			libTKernel.so:cad/opencascade \
			libvtksys-8.2.so:math/vtk8

QT5_LIBS=	buildtools_build concurrent core declarative gui location \
		network opengl printsupport qmake_build script sensors \
		sql svg webchannel webkit widgets xml

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS_${ARCH}=	-fPIC
CXXFLAGS_${ARCH}= -fPIC
FCFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (REAL(8)/COMPLEX(8)).
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

post-patch:
	@${RM} -r ${WRKSRC}/elmergrid/src/metis-5.1.0
	@${REINPLACE_CMD} -e 's,"metis.*/metis\.h",<metis.h>,' \
		${WRKSRC}/elmergrid/src/femelmer.c

post-patch-OCC-on:
	@${REINPLACE_CMD} -e "s|\$${VERSION}|`${PKG_QUERY} '%v' opencascade`|" \
		"${WRKSRC}/cmake/Modules/FindOCE.cmake"
	@${REINPLACE_CMD} -e 's|$${INCLUDE}|${LOCALBASE}/include/OpenCASCADE|' \
		"${WRKSRC}/cmake/Modules/FindOCE.cmake"

post-install:
	${LN} -sf ElmerSolver_mpi ${STAGEDIR}${PREFIX}/bin/ElmerSolver
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ElmerGrid

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.post.mk>
