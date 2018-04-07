# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kst
DISTVERSION=	${KST_VERSION}.${KST_DATE}
CATEGORIES=	science kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data viewing and plotting tool

LIB_DEPENDS=	libgsl.so:math/gsl \
		libtiff.so:graphics/tiff

KST_VERSION=	2.0.8
KST_DATE=	20180405

USES=		cmake:outsource desktop-file-utils pkgconfig \
		shared-mime-info
_USE_QT4=	corelib gui xml designer network svg linguisttools_build \
		qmake_build moc_build rcc_build uic_build
_USE_QT5=	concurrent core gui network printsupport svg widgets xml \
		buildtools_build linguisttools_build qmake_build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Kst-plot
GH_TAGNAME=	6afa76a

CMAKE_ARGS+=	-Dkst_install_prefix=${PREFIX} \
		-Dkst_pch=off \
		-Dkst_version_string=${KST_VERSION} \
		-Dkst_revision=${KST_DATE}

PLIST_SUB=	SHLIB_VER=${KST_VERSION}

OPTIONS_DEFINE=	FITS MATLAB NETCDF
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5
OPTIONS_SUB=	yes

FITS_DESC=	Support for data in FITS format
FITS_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio

MATLAB_DESC=	Support for data in MATLAB format
MATLAB_LIB_DEPENDS=	libmatio.so:math/matio

NETCDF_DESC=	Support for data in NetCDF format (broken)
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
NETCDF_IGNORE=	does not support NetCDF 4

TOOLKIT_DESC=	Qt toolkit
QT4_USE=	${_USE_QT4:S/^/QT4=/}
QT5_USE=	${_USE_QT5:S/^/QT5=/}
QT5_CMAKE_ON=	-Dkst_qt5=on

post-patch:
	${REINPLACE_CMD} -e '/find_package(Getdata)/d' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

post-patch-FITS-off:
	${REINPLACE_CMD} -e '/find_package(CFITSIO)/d' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

post-patch-MATLAB-off:
	${REINPLACE_CMD} -e '/find_package(Matio)/d' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

post-patch-NETCDF-off:
	${REINPLACE_CMD} -e '/find_package(Netcdf)/d' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

.include <bsd.port.mk>
