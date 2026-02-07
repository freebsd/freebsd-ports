PORTNAME=	kst
DISTVERSIONPREFIX=	v
DISTVERSION=	${KST_VERSION}
DISTVERSIONSUFFIX=	-${KST_DATE}
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data viewing and plotting tool
WWW=		https://kst-plot.kde.org

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
		buildtools:build linguisttools:build qmake:build
USE_LDCONFIG=	yes

KST_VERSION=	2.1
KST_DATE=	2024-10-20
KDE_INVENT=	${DISTVERSIONFULL} graphics kst-plot

CMAKE_ARGS=	-Dkst_install_prefix=${PREFIX} \
		-Dkst_pch=off \
		-DCMAKE_DISABLE_FIND_PACKAGE_Getdata=ON

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
