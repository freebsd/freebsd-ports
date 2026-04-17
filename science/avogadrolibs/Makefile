PORTNAME=	avogadrolibs
DISTVERSION=	2.0.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Avogadro2 libraries for chemical editor and visualization applications
WWW=		https://www.openchemistry.org/projects/avogadro2/ \
		https://github.com/OpenChemistry/avogadrolibs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest \
		molequeue>0:misc/molequeue

USES=		cmake:testing compiler:c++17-lang eigen:3,build,run localbase # eigen needs to be 'run' because it is written into cmake files
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OpenChemistry
GH_TUPLE=	OpenChemistry:molecules:8a37883:molecules/../molecules \
		OpenChemistry:crystals:7adea78:crystals/../crystals \
		OpenChemistry:fragments:2e29d17:fragments/../fragments

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	ENABLE_TESTING

OPTIONS_DEFINE=		HDF5 LIBARCHIVE LIBMSYM MMTF OPENGL QT SPGLIB VTK
OPTIONS_DEFAULT=	HDF5 LIBARCHIVE LIBMSYM MMTF OPENGL QT SPGLIB VTK
OPTIONS_SUB=		yes

HDF5_CMAKE_BOOL=	USE_HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5

LIBARCHIVE_DESC=	Enable optional Libarchive features
LIBARCHIVE_CMAKE_BOOL=	USE_LIBARCHIVE
LIBARCHIVE_USES=	libarchive
LIBARCHIVE_IMPLIES=	QT

LIBMSYM_DESC=		Enable optional features using libmsym
LIBMSYM_CMAKE_BOOL=	USE_LIBMSYM
LIBMSYM_LIB_DEPENDS=	libmsym.so:science/libmsym
LIBMSYM_IMPLIES=	QT # enables the 'symmetry' Qt plugin

MMTF_DESC=		Enable optional features using mmtf
MMTF_CMAKE_BOOL=	USE_MMTF
MMTF_BUILD_DEPENDS=	mmtf-cpp>0:science/mmtf-cpp \
			${LOCALBASE}/include/boost/predef/other/endian.h:devel/boost-libs # needed by /usr/local/include/msgpack/sysdep.hpp:102 while boost is an optional dependency there

OPENGL_CMAKE_BOOL=	USE_OPENGL
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glew

QT_CMAKE_BOOL=		USE_QT
QT_USES=		qt:6
QT_USE=			QT=base,svg,tools:build
QT_LIB_DEPENDS=		libJKQTPlotter6.so:graphics/jkqtplotter@qt6
QT_IMPLIES=		OPENGL

SPGLIB_DESC=		Enable optional features using spglib
SPGLIB_CMAKE_BOOL=	USE_SPGLIB
SPGLIB_CMAKE_ON=	-DSPGLIB_INCLUDE_DIR=${LOCALBASE}/include
SPGLIB_LIB_DEPENDS=	libsymspg.so:science/spglib
SPGLIB_IMPLIES=		QT # USE_SPGLIB only installs header file without USE_QT, and also installs SpaceGroup.a with USE_QT, see https://github.com/OpenChemistry/avogadrolibs/issues/610

VTK_DESC=		Enable libraries that use VTK
VTK_USES=		xorg
VTK_USE=		XORG=x11
VTK_CMAKE_BOOL=		USE_VTK
VTK_LIB_DEPENDS=	libvtksys-${VTK_VER}.so:math/vtk${VTK_VER:R} \
			libfreetype.so:print/freetype2
VTK_IMPLIES=		QT

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

# tests as of 1.100.0: 100% tests passed, 0 tests failed out of 27

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
