# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kst
DISTVERSION=	${KST_VERSION}.${KST_DATE}
CATEGORIES=	science

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data viewing and plotting tool

LICENSE=	GPLv2 GFDL LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING-DOCS
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libgsl.so:math/gsl \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 pkgconfig \
		qt:5 shared-mime-info
USE_QT=		concurrent core gui network printsupport svg widgets xml \
		buildtools_build linguisttools_build qmake_build
USE_LDCONFIG=	yes

KST_VERSION=	2.0.8
KST_DATE=	20210124
KST_COMMIT=	38eddb53
KDE_INVENT=	38eddb5322a1d557f9d86ea95d456d76272941e3 graphics kst-plot

CMAKE_ARGS=	-Dkst_install_prefix=${PREFIX} \
		-Dkst_pch=off \
		-Dkst_version_string=${KST_VERSION} \
		-Dkst_revision="${KST_COMMIT} ${KST_DATE}" \
		-DCMAKE_DISABLE_FIND_PACKAGE_Getdata=ON \
		-Dkst_qt5=on

PLIST_SUB=	SHLIB_VER=${KST_VERSION}

OPTIONS_DEFINE=	FITS HDF5 MATLAB NETCDF
OPTIONS_DEFAULT=	FITS HDF5 MATLAB
OPTIONS_SUB=	yes

FITS_DESC=	Support for data in FITS format
FITS_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
FITS_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_CFITSIO=ON

HDF5_DESC=	Support for data in HDF5 format
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_HDF5=ON

MATLAB_DESC=	Support for data in MATLAB format
MATLAB_LIB_DEPENDS=	libmatio.so:math/matio
MATLAB_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Matio=ON

NETCDF_DESC=	Support for data in NetCDF format (broken)
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
NETCDF_IGNORE=	does not support NetCDF 4
NETCDF_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Netcdf=ON

.include <bsd.port.mk>
