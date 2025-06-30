PORTNAME=	pdal
DISTVERSION=	2.8.4
PORTREVISION=	3
CATEGORIES=	math databases graphics
MASTER_SITES=	https://github.com/PDAL/PDAL/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Library for translating and manipulating point cloud data
WWW=		https://www.pdal.io

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libproj.so:graphics/proj \
		libboost_thread.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libgeotiff.so:graphics/libgeotiff \
		liblaszip.so:archivers/laszip \
		libzstd.so:archivers/zstd \
		${LIB_DEPENDS_${ARCH}}
LIB_DEPENDS_aarch64=	libunwind.so:devel/libunwind
LIB_DEPENDS_amd64=	libunwind.so:devel/libunwind
LIB_DEPENDS_armv7=	libunwind.so:devel/libunwind
LIB_DEPENDS_i386=	libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64=	libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64le=libunwind.so:devel/libunwind

USES=		cmake compiler:c++11-lib gnome pathfix pkgconfig ssl tar:bz2
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:tu}-${DISTVERSION}-src

CMAKE_ON=	WITH_LASZIP #LASZIP is recommended
CMAKE_OFF=	WITH_TESTS

OPTIONS_DEFINE=	BASH \
		ICEBRIDGE PGPOINTCLOUD LAZPERF MBIO \

OPTIONS_DEFAULT=	BASH \
			ICEBRIDGE PGPOINTCLOUD LAZPERF MBIO

#Plugins with lib not in port:
#RivLib, Matlab, MrSID, CPD, GeoWave, GreyHound, HexBin, NITF (nitro)
OPTIONS_SUB=	yes

BASH_DESC=		BASH completion
ICEBRIDGE_DESC=		Enable Icebridge plugin
LAZPERF_DESC=		Enable LAZPerf plugin
MBIO_DESC=		Enable MBIO plugin
PGPOINTCLOUD_DESC=	Enable Coherent PostgreSQL Point Cloud plugin

BASH_CMAKE_BOOL=	WITH_COMPLETION
BASH_RUN_DEPENDS=	bash:shells/bash

ICEBRIDGE_CMAKE_BOOL=	BUILD_PLUGIN_ICEBRIDGE
ICEBRIDGE_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libsz.so:science/libaec

LAZPERF_CMAKE_BOOL=	WITH_LAZPERF
LAZPERF_LIB_DEPENDS=	liblazperf.so:archivers/lazperf

MBIO_CMAKE_BOOL=	BUILD_PLUGIN_MBIO

PGPOINTCLOUD_CMAKE_BOOL=	BUILD_PLUGIN_PGPOINTCLOUD
PGPOINTCLOUD_USES=	pgsql

CXXFLAGS_powerpc64=	-mvsx

pre-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions

.include <bsd.port.mk>
