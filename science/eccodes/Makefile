PORTNAME=	eccodes
PORTVERSION=	2.42.0
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	science
MASTER_SITES=	https://confluence.ecmwf.int/download/attachments/45757960/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ECMWF API for WMO FM-92 GRIB and FM-94 BUFR messages
WWW=		https://confluence.ecmwf.int/display/ECC \
		https://github.com/ecmwf/eccodes

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	ecCodes only supports 64 bit platforms

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnetcdf.so:science/netcdf \
		libpng.so:graphics/png

USES=		cmake localbase perl5 shebangfix

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=BOTH
CMAKE_OFF=	ENABLE_ALIGN_MEMORY \
		ENABLE_ECCODES_OMP_THREADS \
		ENABLE_EXTRA_TESTS \
		ENABLE_FORTRAN \
		ENABLE_MEMFS \
		ENABLE_MEMORY_MANAGEMENT \
		ENABLE_PYTHON
CMAKE_ON=	ECCODES_INSTALL_EXTRA_TOOLS \
		ENABLE_ECCODES_THREADS \
		ENABLE_EXAMPLES \
		ENABLE_INSTALL_ECCODES_DEFINITIONS \
		ENABLE_JPG \
		ENABLE_NETCDF \
		ENABLE_PNG
USE_CSTD=	c99
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	grib_api

PORTSCOUT=	site:https://confluence.ecmwf.int/display/ECC/Releases

SHEBANG_FILES=	tools/bufr_compare_dir

OPTIONS_DEFINE=	AEC
OPTIONS_SINGLE=	JPEG
OPTIONS_SINGLE_JPEG=	JASPER OPENJPEG
OPTIONS_DEFAULT=AEC OPENJPEG
AEC_DESC=	Adaptive Entropy Coding support

AEC_CMAKE_BOOL=		ENABLE_AEC
AEC_LIB_DEPENDS=	libaec.so:science/libaec
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

.include <bsd.port.mk>
