# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kst
DISTVERSION=	2.0.8
CATEGORIES=	science kde
MASTER_SITES=	SF/${PORTNAME}/Kst%20${DISTVERSION:C/-r.*//}/
DISTNAME=	Kst-${DISTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data viewing and plotting tool

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		cmake:outsource pkgconfig
_USE_QT4=	gui xml designer svg linguisttools_build \
		qmake_build moc_build rcc_build uic_build
_USE_QT5=	concurrent network printsupport widgets xml \
		buildtools_build linguisttools_build qmake_build
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-Dkst_install_prefix=${PREFIX} \
		-Dkst_pch=off

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=	FITS MATLAB NETCDF
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT4
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
	${REINPLACE_CMD} -e '/^Exec=kst2/s,\(kst2\).*,\1 %f,' \
		${WRKSRC}/src/kst/kst2.desktop

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
