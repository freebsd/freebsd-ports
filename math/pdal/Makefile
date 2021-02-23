# Created by: bart <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdal
DISTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	math databases graphics

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Library for translating and manipulating point cloud data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libboost_thread.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libgeotiff.so:graphics/libgeotiff \
		libxml2.so:textproc/libxml2 \
		liblaszip.so:archivers/laszip \
		libzstd.so:archivers/zstd \
		${LIB_DEPENDS_${ARCH}}
LIB_DEPENDS_aarch64=	libunwind.so:devel/libunwind
LIB_DEPENDS_amd64=	libunwind.so:devel/libunwind
LIB_DEPENDS_i386=	libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64=	libunwind.so:devel/libunwind

USES=		cmake compiler:c++11-lib pathfix pkgconfig ssl
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
GH_PROJECT=	${GH_ACCOUNT}

CMAKE_ON=	WITH_LASZIP #LASZIP is recommended

OPTIONS_DEFINE=	BASH \
		ICEBRIDGE PGPOINTCLOUD LAZPERF MBIO \
		TESTS
#OPTIONS_DEFAULT=	PGPOINTCLOUD LAZPERF
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
#Plugins with lib not in port:
#RivLib, Matlab, MrSID, CPD, GeoWave, GreyHound, HexBin, NITF (nitro)
OPTIONS_SUB=	yes

BASH_DESC=		BASH completion
ICEBRIDGE_DESC=		Enable Icebridge plugin
LAZPERF_DESC=		Enable LAZPerf plugin
MBIO_DESC=		Enable MBIO plugin
PGPOINTCLOUD_DESC=	Enable Coherent PostgreSQL Point Cloud plugin
TESTS_DESC=		Enable Tests

BASH_CMAKE_BOOL=	WITH_COMPLETION
BASH_RUN_DEPENDS=	bash:shells/bash

ICEBRIDGE_CMAKE_BOOL=	BUILD_PLUGIN_ICEBRIDGE
ICEBRIDGE_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libsz.so:science/szip

LAZPERF_CMAKE_BOOL=	WITH_LAZPERF
LAZPERF_BUILD_DEPENDS=	${LOCALBASE}/include/laz-perf/las.hpp:archivers/lazperf

MBIO_CMAKE_BOOL=	BUILD_PLUGIN_MBIO

PGPOINTCLOUD_CMAKE_BOOL=	BUILD_PLUGIN_PGPOINTCLOUD
PGPOINTCLOUD_USES=	pgsql

TESTS_CMAKE_BOOL=	BUILD_PLUGIN_TESTS

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/scripts/bash-completion/pdal \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions

.include <bsd.port.mk>
