PORTNAME=	orthanc-postgresql
DISTVERSION=	9.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://orthanc.uclouvain.be/downloads/sources/orthanc-postgresql/:pgsql \
		https://orthanc.uclouvain.be/downloads/sources/orthanc/:orthanc \
		https://orthanc.uclouvain.be/downloads/third-party-downloads/:thirdparty
DISTFILES=	OrthancPostgreSQL-${PORTVERSION}.tar.gz:pgsql \
		Orthanc-${ORTHANC_VER}.tar.gz:orthanc \
		e2fsprogs-1.44.5.tar.gz:thirdparty
DIST_SUBDIR=	orthanc
EXTRACT_ONLY=	OrthancPostgreSQL-${PORTVERSION}.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Orthanc plugin to use PostgreSQL for indexing or storage
WWW=		https://www.orthanc-server.com/static.php?page=postgresql

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCDatabasePlugin.h:science/orthanc \
		googletest>0:devel/googletest
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	Orthanc:science/orthanc

USES=		cmake localbase pgsql:11+ python:build ssl
USE_LDCONFIG=	${DATADIR}/plugins

WRKSRC=		${WRKDIR}/OrthancPostgreSQL-${PORTVERSION}

CMAKE_SOURCE_PATH=	${WRKSRC}/PostgreSQL
CMAKE_OFF=	BUILD_UNIT_TESTS USE_SYSTEM_ORTHANC_SDK USE_SYSTEM_UUID
CMAKE_ARGS=	-DORTHANC_FRAMEWORK_ROOT=${WRKSRC}/PostgreSQL/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}/OrthancFramework/Sources \
		-DORTHANC_FRAMEWORK_SOURCE=path
CXXFLAGS+=	-I${LOCALBASE}/include -DNDEBUG
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-DORTHANC_ENABLE_LOGGING_PLUGIN -DNDEBUG

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include "${.CURDIR}/../../science/orthanc/version.mk"

post-extract:
		${MKDIR} ${WRKSRC}/PostgreSQL/ThirdPartyDownloads
		${CP} ${DISTDIR}/${DIST_SUBDIR}/e2fsprogs-1.44.5.tar.gz ${WRKSRC}/PostgreSQL/ThirdPartyDownloads
		${CP} ${DISTDIR}/${DIST_SUBDIR}/Orthanc-${ORTHANC_VER}.tar.gz ${WRKSRC}/PostgreSQL/ThirdPartyDownloads
		${TAR} -C ${WRKSRC}/PostgreSQL/ThirdPartyDownloads -xf ${WRKSRC}/PostgreSQL/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}.tar.gz

.include <bsd.port.mk>
