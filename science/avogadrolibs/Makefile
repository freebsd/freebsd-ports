# $FreeBSD$

PORTNAME=	avogadrolibs
DISTVERSION=	1.93.0
CATEGORIES=	science

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	cf9d82575796d5fcabb153bdebde26843d81d83e.patch:-p1 \
		ea813f683cdd9865994c0ba94a24325e04b9f8fb.patch:-p1 \

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Avogadro2 libraries for chemical editor and visualization applications

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/mmtf.hpp:science/mmtf-cpp

USES=		cmake compiler:c++11-lang eigen:3,build,run # eigen needs to be 'run' because it is written into cmake files
USE_GITHUB=	yes
GH_ACCOUNT=	OpenChemistry
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		HDF5 LIBARCHIVE LIBMSYM MOLEQUEUE OPENGL QT5 SPGLIB VTK
OPTIONS_DEFAULT=	LIBARCHIVE LIBMSYM MOLEQUEUE OPENGL QT5 SPGLIB
OPTIONS_SUB=		yes

HDF5_CMAKE_BOOL=	USE_HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libsz.so:science/szip

LIBARCHIVE_DESC=	Enable optional Libarchive features
LIBARCHIVE_CMAKE_BOOL=	USE_LIBARCHIVE
LIBARCHIVE_USES=	libarchive
LIBARCHIVE_IMPLIES=	QT5

LIBMSYM_DESC=		Enable optional features using libmsym
LIBMSYM_CMAKE_BOOL=	USE_LIBMSYM
LIBMSYM_LIB_DEPENDS=	libmsym.so:science/libmsym

MOLEQUEUE_DESC=		Enable the MoleQueue dependent functionality
MOLEQUEUE_CMAKE_BOOL=	USE_MOLEQUEUE
MOLEQUEUE_LIB_DEPENDS=	libMoleQueueClient.so:misc/molequeue
MOLEQUEUE_IMPLIES=	QT5

OPENGL_CMAKE_BOOL=	USE_OPENGL
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glew,glu

QT5_CMAKE_BOOL=		USE_QT
QT5_USES=		qt:5
QT5_USE=		QT=core,concurrent,gui,network,widgets,buildtools_build,qmake_build
QT5_IMPLIES=		OPENGL

SPGLIB_DESC=		Enable optional features using spglib
SPGLIB_CMAKE_BOOL=	USE_SPGLIB
SPGLIB_LIB_DEPENDS=	libsymspg.so:science/spglib

VTK_DESC=		Enable libraries that use VTK
VTK_CMAKE_BOOL=		USE_VTK
VTK_LIB_DEPENDS=	libvtksys-8.2.so:math/vtk8
VTK_IMPLIES=		QT5
VTK_BROKEN=		Needs https://github.com/psavery/genXrdPattern, etc

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
