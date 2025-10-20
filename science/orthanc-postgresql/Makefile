PORTNAME=	orthanc-postgresql
DISTVERSION=	4.0
PORTREVISION=	12
CATEGORIES=	science
MASTER_SITES=	https://www.orthanc-server.com/downloads/get.php?path=/plugin-postgresql/:main \
		https://www.orthanc-server.com/downloads/get.php?path=/orthanc/:framework \
		https://orthanc.osimis.io/ThirdPartyDownloads/:thirdparty
DISTFILES=	OrthancPostgreSQL-${PORTVERSION}.tar.gz:main \
		Orthanc-1.9.3.tar.gz:framework \
		e2fsprogs-1.44.5.tar.gz:thirdparty
DIST_SUBDIR=	orthanc
EXTRACT_ONLY=	OrthancPostgreSQL-${PORTVERSION}.tar.gz

MAINTAINER=	maintainer.freebsd@xpoundit.com
COMMENT=	Orthanc plugin to use PostgreSQL for indexing or storage
WWW=		https://www.orthanc-server.com/static.php?page=postgresql

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to build with boost-1.86+

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCDatabasePlugin.h:science/orthanc
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libgdcmCommon.so:devel/gdcm \
		libjsoncpp.so:devel/jsoncpp \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	Orthanc:science/orthanc

USES=		cmake compiler:c11 localbase pgsql:11+ python:build ssl
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/OrthancPostgreSQL-${PORTVERSION}

CMAKE_SOURCE_PATH=	${WRKSRC}/PostgreSQL
CMAKE_OFF=	BUILD_UNIT_TESTS USE_SYSTEM_ORTHANC_SDK USE_SYSTEM_UUID
CMAKE_ARGS=	-DORTHANC_FRAMEWORK_ROOT=${WRKSRC}/PostgreSQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancFramework/Sources \
		-DORTHANC_FRAMEWORK_SOURCE=path
CXXFLAGS+=	-I${LOCALBASE}/include -DNDEBUG
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-DORTHANC_ENABLE_LOGGING_PLUGIN -DNDEBUG

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-extract:
		${MKDIR} ${WRKSRC}/PostgreSQL/ThirdPartyDownloads
		${CP} ${DISTDIR}/${DIST_SUBDIR}/e2fsprogs-1.44.5.tar.gz ${WRKSRC}/PostgreSQL/ThirdPartyDownloads
		${CP} ${DISTDIR}/${DIST_SUBDIR}/Orthanc-1.9.3.tar.gz ${WRKSRC}/PostgreSQL/ThirdPartyDownloads
		${TAR} -C ${WRKSRC}/PostgreSQL/ThirdPartyDownloads -xf ${WRKSRC}/PostgreSQL/ThirdPartyDownloads/Orthanc-1.9.3.tar.gz

.include <bsd.port.mk>
