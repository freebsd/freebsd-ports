PORTNAME=	avogadrolibs
DISTVERSION=	1.95.1
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Avogadro2 libraries for chemical editor and visualization applications

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang eigen:3,build,run # eigen needs to be 'run' because it is written into cmake files
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OpenChemistry
GH_TUPLE=	OpenChemistry:molecules:b1e16c5:molecules/../molecules \
		OpenChemistry:crystals:c3e2468:crystals/../crystals

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	ENABLE_TESTING

OPTIONS_DEFINE=		HDF5 LIBARCHIVE LIBMSYM MMTF OPENGL QT5 SPGLIB VTK
OPTIONS_DEFAULT=	LIBARCHIVE LIBMSYM MMTF OPENGL QT5 SPGLIB
OPTIONS_SUB=		yes

HDF5_CMAKE_BOOL=	USE_HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libsz.so:science/libaec

LIBARCHIVE_DESC=	Enable optional Libarchive features
LIBARCHIVE_CMAKE_BOOL=	USE_LIBARCHIVE
LIBARCHIVE_USES=	libarchive
LIBARCHIVE_IMPLIES=	QT5

LIBMSYM_DESC=		Enable optional features using libmsym
LIBMSYM_CMAKE_BOOL=	USE_LIBMSYM
LIBMSYM_LIB_DEPENDS=	libmsym.so:science/libmsym
LIBMSYM_IMPLIES=	QT5 # enables the 'symmetry' Qt plugin

MMTF_DESC=		Enable optional features using mmtf
MMTF_CMAKE_BOOL=	USE_MMTF
MMTF_BUILD_DEPENDS=	mmtf-cpp>0:science/mmtf-cpp

OPENGL_CMAKE_BOOL=	USE_OPENGL
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glew,glu

QT5_CMAKE_BOOL=		USE_QT
QT5_USES=		qt:5
QT5_USE=		QT=core,concurrent,gui,network,svg,widgets,buildtools_build,qmake_build
QT5_IMPLIES=		OPENGL

SPGLIB_DESC=		Enable optional features using spglib
SPGLIB_CMAKE_BOOL=	USE_SPGLIB
SPGLIB_CMAKE_ON=	-DSPGLIB_INCLUDE_DIR=${LOCALBASE}/include/spglib
SPGLIB_LIB_DEPENDS=	libsymspg.so:science/spglib
SPGLIB_IMPLIES=		QT5 # USE_SPGLIB only installs header file without USE_QT, and also installs SpaceGroup.a with USE_QT, see https://github.com/OpenChemistry/avogadrolibs/issues/610

VTK_DESC=		Enable libraries that use VTK
VTK_CMAKE_BOOL=		USE_VTK
VTK_LIB_DEPENDS=	libvtksys-8.2.so:math/vtk8
VTK_IMPLIES=		QT5
VTK_BROKEN=		Needs https://github.com/psavery/genXrdPattern, etc

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
