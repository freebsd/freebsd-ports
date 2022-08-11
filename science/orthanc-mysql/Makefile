PORTNAME=	orthanc-mysql
DISTVERSION=	4.3
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://www.orthanc-server.com/downloads/get.php?path=/plugin-mysql/:main \
		https://www.orthanc-server.com/downloads/get.php?path=/orthanc/:framework \
		https://orthanc.osimis.io/ThirdPartyDownloads/:thirdparty
DISTFILES=	OrthancMySQL-${PORTVERSION}.tar.gz:main \
		Orthanc-1.9.3.tar.gz:framework \
		e2fsprogs-1.44.5.tar.gz:thirdparty
DIST_SUBDIR=	orthanc
EXTRACT_ONLY=	OrthancMySQL-${PORTVERSION}.tar.gz

MAINTAINER=	maintainer.freebsd@xpoundit.com
COMMENT=	Orthanc plugin to use MySQL/MariaDB for indexing or storage

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCDatabasePlugin.h:science/orthanc
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libgdcmCommon.so:devel/gdcm \
		libjsoncpp.so:devel/jsoncpp \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	Orthanc:science/orthanc

USES=		cmake localbase mysql:client python:build ssl
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/OrthancMySQL-${PORTVERSION}

CMAKE_ARGS=	-DORTHANC_FRAMEWORK_ROOT=${WRKSRC}/MySQL/ThirdPartyDownloads/Orthanc-1.9.3/OrthancFramework/Sources \
		-DORTHANC_FRAMEWORK_SOURCE=path
CMAKE_OFF=	DBUILD_UNIT_TESTS USE_SYSTEM_ORTHANC_SDK USE_SYSTEM_UUID
CMAKE_SOURCE_PATH=	${WRKSRC}/MySQL

CFLAGS+=	-DORTHANC_ENABLE_LOGGING_PLUGIN -DNDEBUG
CXXFLAGS+=	-I${LOCALBASE}/include -DNDEBUG

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-extract:
		${MKDIR} ${WRKSRC}/MySQL/ThirdPartyDownloads
		${CP} ${DISTDIR}/${DIST_SUBDIR}/e2fsprogs-1.44.5.tar.gz ${WRKSRC}/MySQL/ThirdPartyDownloads
		${CP} ${DISTDIR}/${DIST_SUBDIR}/Orthanc-1.9.3.tar.gz ${WRKSRC}/MySQL/ThirdPartyDownloads
		${TAR} -C ${WRKSRC}/MySQL/ThirdPartyDownloads -xf ${WRKSRC}/MySQL/ThirdPartyDownloads/Orthanc-1.9.3.tar.gz

.include <bsd.port.mk>
