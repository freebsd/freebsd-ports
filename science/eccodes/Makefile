# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eccodes
PORTVERSION=	2.8.0
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	science
MASTER_SITES=	https://software.ecmwf.int/wiki/download/attachments/45757960/ \
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
USES=		cmake:outsource shebangfix #pathfix perl5
#CONFIGURE_ARGS=	--enable-pthread --with-netcdf=${LOCALBASE} --with-png-support
#GNU_CONFIGURE=	yes
#INSTALL_TARGET=	install-strip
#USES=		autoreconf libtool pathfix perl5

SHEBANG_FILES=	tools/bufr_compare_dir
SHEBANG_LANG=	ksh

AEC_CMAKE_BOOL=		ENABLE_AEC
AEC_LIB_DEPENDS=	libaec.so:science/libaec
#JASPER_CONFIGURE_ON=	--with-jasper=${LOCALBASE}
JASPER_CMAKE_BOOL=	ENABLE_JPG
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
#OPENJPEG_CONFIGURE_ON=	--with-openjpeg=${LOCALBASE}
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

x-post-patch:
	@${REINPLACE_CMD} -e '/default_perl_install/ s|$${prefix}|${LOCALBASE}/bin|; /rpms\//d' ${WRKSRC}/configure.ac

x-post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/grib1to2 ${STAGEDIR}${PREFIX}/bin/grib1to2

.include <bsd.port.mk>
