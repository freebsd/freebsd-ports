# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	labplot
PORTVERSION=	2.4.0
PORTREVISION=	3
DISTVERSIONSUFFIX=-kf5
CATEGORIES=	math kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Data plotting and function analysis tool for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgsl.so:math/gsl

OPTIONS_DEFINE=		FITS FFTW3 HDF5 NETCDF
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
FITS_DESC=		Flexible Image Transport System Data Format (FITS) Library
FITS_CMAKE_BOOL=	ENABLE_FITS
FITS_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
FFTW3_DESC=		Build with FFTW support
FFTW3_CMAKE_BOOL=	ENABLE_FFTW
FFTW3_LIB_DEPENDS=	libfftw3.so:math/fftw3
HDF5_DESC=		Build with HDF5 support
HDF5_CMAKE_BOOL=	ENABLE_HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
NETCDF_DESC=		Build with NetCDF support
NETCDF_CMAKE_BOOL=	ENABLE_NETCDF
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf

USES=		cmake:outsource desktop-file-utils kde:5 shared-mime-info tar:xz
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm guiaddons i18n iconthemes itemviews \
		jobwidgets kdelibs4support kio newstuff notifications parts \
		service solid sonnet textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui
USE_QT5=	core dbus gui network printsupport svg widgets xml \
		buildtools_build qmake_build

DATADIR=	${PREFIX}/share/labplot2

.include <bsd.port.mk>
