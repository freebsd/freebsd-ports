# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eccodes
PORTVERSION=	2.8.2
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	science
MASTER_SITES=	https://confluence.ecmwf.int/download/attachments/45757960/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ECMWF API for WMO FM-92 GRIB and FM-94 BUFR messages

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnetcdf.so:science/netcdf \
		libpng.so:graphics/png

OPTIONS_DEFINE=	AEC
OPTIONS_SINGLE=	JPEG
OPTIONS_SINGLE_JPEG=	JASPER OPENJPEG
OPTIONS_DEFAULT=OPENJPEG
AEC_DESC=	Adaptive Entropy Coding support

PORTSCOUT=	site:https://software.ecmwf.int/wiki/display/ECC/Releases

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=BOTH
CMAKE_OFF=	ENABLE_ECCODES_OMP_THREADS ENABLE_FORTRAN ENABLE_MEMFS ENABLE_PYTHON
CMAKE_ON=	ENABLE_ECCODES_THREADS ENABLE_NETCDF ENABLE_PNG
USE_LDCONFIG=	yes
USES=		cmake shebangfix

SHEBANG_FILES=	tools/bufr_compare_dir

AEC_CMAKE_BOOL=		ENABLE_AEC
AEC_LIB_DEPENDS=	libaec.so:science/libaec
JASPER_CMAKE_BOOL=	ENABLE_JPG
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

.include <bsd.port.mk>
