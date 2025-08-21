PORTNAME=	labplot
DISTVERSION=	2.11.80
PORTREVISION=	2
CATEGORIES=	math kde
MASTER_SITES=	KDE/stable/${PORTNAME}/
DIST_SUBDIR=	KDE/invent.kde.org

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Data plotting and function analysis tool by KDE
WWW=		https://labplot.kde.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libQXlsxQt6.so:devel/qxlsx@qt6 \
		libgsl.so:math/gsl \
		liblz4.so:archivers/liblz4 \
		libmarkdown.so:textproc/discount \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libzstd.so:archivers/zstd

USES=		bison cmake compiler:c++17-lang desktop-file-utils eigen:3 \
		kde:6 pkgconfig qt:6 shared-mime-info xorg gettext
USE_KDE=	archive completion config configwidgets coreaddons crash \
		i18n iconthemes kio newstuff parts purpose service \
		syntaxhighlighting textwidgets userfeedback widgetsaddons \
		xmlgui \
		doctools:build ecm:build
USE_QT=		base mqtt serialport svg
USE_XORG=	x11 xcb

KDE_INVENT=	110f258e44a45354c5219e497409a22185fa2933 education labplot

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=		CANTOR FITS FFTW3 HDF5 LIBCERF MATLAB NETCDF ORCUS \
			ORIGINLAB READSTAT
OPTIONS_DEFAULT:=	${OPTIONS_DEFINE}

CANTOR_DESC=		KDE Cantor support
CANTOR_LIB_DEPENDS=	libcantorlibs.so:math/cantor \
			libspectre.so:print/libspectre
CANTOR_CMAKE_BOOL=	ENABLE_CANTOR

FFTW3_DESC=		Speedier FFTs in the numerical and stats lib (NSL)
FFTW3_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW3_CMAKE_BOOL=	ENABLE_FFTW

FITS_DESC=		Flexible Image Transport System (FITS) data support
FITS_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
FITS_CMAKE_BOOL=	ENABLE_FITS

HDF5_DESC=		Reading and writing self-describing array data
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CMAKE_BOOL=	ENABLE_HDF5

LIBCERF_DESC=		Complex error functions support
LIBCERF_LIB_DEPENDS=	libcerf.so:math/libcerf
LIBCERF_CMAKE_BOOL=	ENABLE_LIBCERF

MATLAB_DESC=		MATLAB MAT file support
MATLAB_LIB_DEPENDS=	libmatio.so:math/matio
MATLAB_CMAKE_BOOL=	ENABLE_MATIO

NETCDF_DESC=		Interfaces for array-oriented data access
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
NETCDF_CMAKE_BOOL=	ENABLE_NETCDF

ORCUS_DESC=		Spreadsheet processing filters (via liborcus)
ORCUS_LIB_DEPENDS=	libixion-0.20.so:textproc/libixion \
			liborcus-0.20.so:devel/liborcus
ORCUS_CMAKE_BOOL=	ENABLE_ORCUS

ORIGINLAB_DESC=		OriginLab project files support
ORIGINLAB_LIB_DEPENDS=	liborigin.so:math/liborigin
ORIGINLAB_CMAKE_BOOL=	ENABLE_LIBORIGIN

READSTAT_DESC=		SAS, SPSS, Stata data support
READSTAT_LIB_DEPENDS=	libreadstat.so:math/readstat
READSTAT_USES=		iconv
READSTAT_CMAKE_BOOL=	ENABLE_READSTAT

post-patch:
# workaround for undefined version, to be fixed upstream
	${REINPLACE_CMD} 's,QXLSX_VERSION_STRING,"1.5.0",' \
		${WRKSRC}/src/frontend/AboutDialog.cpp

.include <bsd.port.mk>
