# Created by: bart <bart@bureau>
# $FreeBSD$

PORTNAME=	pdal
PORTVERSION=	0.9.8
CATEGORIES=	math databases graphics

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Library for translating and manipulating point cloud data

LICENSE=	BSD3CLAUSE

USES=	cmake compiler
compiler_ARGS=	c++11-lang
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
GH_PROJECT=	${GH_ACCOUNT}

OPTIONS_DEFINE=	GDAL GEOTIFF LIBXML2 EMBED_BOOST
OPTIONS_DEFAULT=	GDAL GEOTIFF LIBXML2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDAL}
CMAKE_ARGS+=	-DWITH_GDAL:BOOL=TRUE
LIB_DEPENDS+=	libgdal.so:${PORTSDIR}/graphics/gdal
PLIST_SUB+=	GDAL=""
.else
CMAKE_ARGS+=	-DWITH_GDAL:BOOL=FALSE
PLIST_SUB+=	GDAL="@comment "
.endif

.if ${PORT_OPTIONS:MGEOTIFF}
CMAKE_ARGS+=	-DWITH_GEOTIFF:BOOL=TRUE
LIB_DEPENDS+=	libgeotiff.so:${PORTSDIR}/graphics/libgeotiff
PLIST_SUB+=	GEOTIFF=""
.else
CMAKE_ARGS+=	-DWITH_GEOTIFF:BOOL=FALSE
PLIST_SUB+=	GEOTIFF="@comment "
.endif

.if ${PORT_OPTIONS:MLIBXML2}
CMAKE_ARGS+=	-DWITH_LIBXML2:BOOL=TRUE
LIB_DEPENDS+=	libxml2.so:${PORTSDIR}/textproc/libxml2
PLIST_SUB+=	LIBXML2=""
.else
CMAKE_ARGS+=	-DWITH_LIBXML2:BOOL=FALSE
PLIST_SUB+=	LIBXML2="@comment "
.endif

.if ${PORT_OPTIONS:MEMBED_BOOST}
CMAKE_ARGS+=	-DPDAL_EMBED_BOOST:BOOL=TRUE
PLIST_SUB+=	EMBED_BOOST=""
.else
CMAKE_ARGS+=	-DPDAL_EMBED_BOOST:BOOL=FALSE
LIB_DEPENDS+=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
PLIST_SUB+=	EMBED_BOOST="@comment "
.endif

.include <bsd.port.mk>
