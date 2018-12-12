# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kst
DISTVERSION=	${KST_VERSION}.${KST_DATE}
PORTREVISION=	1
CATEGORIES=	science kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data viewing and plotting tool

LICENSE=	GPLv2 GFDL LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING-DOCS
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libgsl.so:math/gsl \
		libtiff.so:graphics/tiff

KST_VERSION=	2.0.8
KST_DATE=	20181123

USES=		cmake:outsource desktop-file-utils pkgconfig \
		shared-mime-info
_USE_QT4=	corelib gui xml designer network svg linguisttools_build \
		qmake_build moc_build rcc_build uic_build
_USE_QT5=	concurrent core gui network printsupport svg widgets xml \
		buildtools_build linguisttools_build qmake_build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Kst-plot
GH_TAGNAME=	c5dddb1

CMAKE_ARGS=	-Dkst_install_prefix=${PREFIX} \
		-Dkst_pch=off \
		-Dkst_version_string=${KST_VERSION} \
		-Dkst_revision=${KST_DATE} \
		-DCMAKE_DISABLE_FIND_PACKAGE_Getdata=ON

PLIST_SUB=	SHLIB_VER=${KST_VERSION}

OPTIONS_DEFINE=	FITS MATLAB NETCDF
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5
OPTIONS_SUB=	yes

FITS_DESC=	Support for data in FITS format
FITS_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
FITS_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_CFITSIO=ON

MATLAB_DESC=	Support for data in MATLAB format
MATLAB_LIB_DEPENDS=	libmatio.so:math/matio
MATLAB_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Matio=ON

NETCDF_DESC=	Support for data in NetCDF format (broken)
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
NETCDF_IGNORE=	does not support NetCDF 4
NETCDF_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Netcdf=ON

TOOLKIT_DESC=	Qt toolkit
QT4_USES=	qt:4
QT4_USE=	${_USE_QT4:S/^/QT=/}
QT5_USES=	compiler:c++11-lang qt:5
QT5_USE=	${_USE_QT5:S/^/QT=/}
QT5_CMAKE_ON=	-Dkst_qt5=on

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

.include <bsd.port.mk>
