# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	elmerfem
PORTVERSION=	8.4.20200309
DISTVERSIONPREFIX=	release-
CATEGORIES=	science

MAINTAINER=	henrik@gulbra.net
COMMENT=	Multiphysical simulation software

LICENSE=	GPLv2

LIB_DEPENDS=	libmetis.so:math/metis \
		libmpich.so:net/mpich \
		libopenblas.so:math/openblas \
		libparpack.so:math/arpack-ng

USES=		cmake fortran tcl
USE_GITHUB=	yes
GH_ACCOUNT=	ElmerCSC
GH_TAGNAME=	39f692c
USE_LDCONFIG=	${PREFIX}/lib/elmersolver

ALL_TARGET=	# empty

CMAKE_ARGS=	-DELMER_FEM_REVISION:STRING=${GH_TAGNAME}

LDFLAGS+=	-L${LOCALBASE}/lib
FCPPFLAGS+=	-ansi

CMAKE_ARGS+=	-DHAVE_INTTYPES_H=ON
.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
.endif

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_LIB_DEPENDS=	libexpat.so:textproc/expat2 \
			libfreetype.so:print/freetype2 \
			libpng16.so:graphics/png \
			libpython2.7.so:lang/python27 \
			libqwt6.so:x11-toolkits/qwt6 \
			libtiff.so:graphics/tiff \
			libvtksys-6.2.so:math/vtk6
GUI_USES=		gl jpeg qt:5 xorg
GUI_USE=		gl=gl,glu xorg=ice,sm,x11,xext,xt \
			qt=buildtools_build,concurrent,core,declarative,gui,location,network,opengl,printsupport,qmake_build,script,sensors,sql,svg,webchannel,webkit,widgets,xml

GUI_CMAKE_BOOL=	WITH_ELMERGUI WITH_PARAVIEW WITH_QT5 QT_FOUND # WITH_OCC requires the QVTKWidget.h that is only provided by the math/vtk6 with QT5=yes
GUI_CMAKE_ON=	-DQWT_LIBRARY=${QT_LIBDIR}/libqwt6.so \
		-DQWT_INCLUDE_DIR=${QT_INCDIR}/qwt6 \
		-DDESIRED_QT_VERSION=5

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS_${ARCH}=	-fPIC
CXXFLAGS_${ARCH}= -fPIC
FCFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

post-patch:
	@${RM} -r ${WRKSRC}/elmergrid/src/metis-5.1.0
	@${REINPLACE_CMD} -e 's,"metis.*/metis\.h",<metis.h>,' \
		${WRKSRC}/elmergrid/src/femelmer.c

post-patch-GUI-on:
	#@${REINPLACE_CMD} -e "s|\$${VERSION}|`${PKG_QUERY} '%v' opencascade`|" \
	#	"${WRKSRC}/cmake/Modules/FindOCE.cmake"
	#@${REINPLACE_CMD} -e 's|$${INCLUDE}|${LOCALBASE}/include/OpenCASCADE|' \
	#	"${WRKSRC}/cmake/Modules/FindOCE.cmake"

post-install:
	${LN} -sf ElmerSolver_mpi ${STAGEDIR}${PREFIX}/bin/ElmerSolver
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ElmerGrid

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.post.mk>
