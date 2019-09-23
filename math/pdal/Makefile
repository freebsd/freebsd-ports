# Created by: bart <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	pdal
DISTVERSION=	2.0.1
CATEGORIES=	math databases graphics

MAINTAINER=	lbartoletti@tuxfamily.org
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
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++11-lib pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
GH_PROJECT=	${GH_ACCOUNT}

CMAKE_ON=	WITH_LASZIP #LASZIP is recommended

OPTIONS_DEFINE=	BASH \
		ICEBRIDGE PGPOINTCLOUD SQLITE MBIO \
		PYTHON TESTS
OPTIONS_DEFAULT=	PYTHON PGPOINTCLOUD SQLITE
#Option without port
#lazperf
#Plugins with lib not in port:
#RivLib, Matlab, MrSID, CPD, GeoWave, GreyHound, HexBin, NITF (nitro)
OPTIONS_SUB=	yes

PGPOINTCLOUD_DESC=	Enable Coherent PostgreSQL Point Cloud plugin
PGPOINTCLOUD_CMAKE_ON=	-DBUILD_PLUGIN_PGPOINTCLOUD:BOOL=TRUE
PGPOINTCLOUD_USES=	pgsql
PGPOINTCLOUD_CMAKE_OFF=	-DBUILD_PLUGIN_PGPOINTCLOUD:BOOL=FALSE

SQLITE_DESC=	Enable SQLite plugin
SQLITE_CMAKE_ON=	-DBUILD_PLUGIN_SQLITE:BOOL=TRUE
SQLITE_USES=	sqlite
SQLITE_CMAKE_OFF=	-DBUILD_PLUGIN_SQLITE:BOOL=FALSE

PYTHON_DESC=	Enable Python plugin
PYTHON_CMAKE_ON=	-DBUILD_PLUGIN_PYTHON:BOOL=TRUE
PYTHON_USES=	python
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY}
PYTHON_CMAKE_OFF=	-DBUILD_PLUGIN_PYTHON:BOOL=FALSE

TESTS_DESC=	Enable Tests
TESTS_CMAKE_ON=	-DBUILD_PLUGIN_TESTS:BOOL=TRUE
TESTS_CMAKE_OFF=	DBUILD_PLUGIN_TESTS:BOOL=FALSE

ICEBRIDGE_DESC=	Enable Icebridge plugin
ICEBRIDGE_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libsz.so:science/szip
ICEBRIDGE_CMAKE_ON=	-DBUILD_PLUGIN_ICEBRIDGE:BOOL=TRUE
ICEBRIDGE_CMAKE_OFF=	-DBUILD_PLUGIN_ICEBRIDGE:BOOL=FALSE

MBIO_DESC=	Enable MBIO plugin
MBIO_CMAKE_ON=		-DBUILD_PLUGIN_MBIO:BOOL=TRUE
MBIO_CMAKE_OFF=		-DBUILD_PLUGIN_MBIO:BOOL=FALSE

BASH_DESC=	BASH completion
BASH_CMAKE_ON=	-DWITH_COMPLETION:BOOL=TRUE
BASH_RUN_DEPENDS=	bash:shells/bash
BASH_CMAKE_OFF=	-DWITH_COMPLETION:BOOL=FALSE

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/scripts/bash-completion/pdal \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions

.include <bsd.port.mk>
