# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	orthanc-portgresql
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	science graphics
MASTER_SITES=	http://orthanc-server.com/downloads/get.php?path=/plugin-postgresql/
DISTNAME=	OrthancPostgreSQL-${PORTVERSION}
DIST_SUBDIR=	orthanc

MAINTAINER=	mp39590@gmail.com
COMMENT=	PostgreSQL plugin for Orthanc

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	orthanc>=0.9.4:science/orthanc
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp

## UnitTests require running PostgreSQL server, so it's pointless to build/run them
CMAKE_ARGS=	-DBUILD_UNIT_TESTS=OFF

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		cmake:outsource pgsql python:build
WRKSRC=		${WRKDIR}/OrthancPostgreSQL-${PORTVERSION}

PLIST_FILES=	share/orthanc/plugins/libOrthancPostgreSQLIndex.so \
		share/orthanc/plugins/libOrthancPostgreSQLIndex.so.${PORTVERSION} \
		share/orthanc/plugins/libOrthancPostgreSQLStorage.so \
		share/orthanc/plugins/libOrthancPostgreSQLStorage.so.${PORTVERSION}

post-extract:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Resources/CMake/*.cmake

.include <bsd.port.mk>
