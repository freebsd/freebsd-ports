PORTNAME=	orthanc-mysql
DISTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://orthanc.uclouvain.be/downloads/sources/orthanc-mysql/:mysql \
		https://orthanc.uclouvain.be/downloads/sources/orthanc/:orthanc \
		https://orthanc.uclouvain.be/downloads/third-party-downloads/:thirdparty
DISTFILES=	OrthancMySQL-${PORTVERSION}.tar.gz:mysql \
		Orthanc-${ORTHANC_VER}.tar.gz:orthanc \
		e2fsprogs-1.44.5.tar.gz:thirdparty
DIST_SUBDIR=	orthanc
EXTRACT_ONLY=	OrthancMySQL-${PORTVERSION}.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Orthanc plugin to use MySQL/MariaDB for indexing or storage
WWW=		https://www.orthanc-server.com/static.php?page=mysql

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCDatabasePlugin.h:science/orthanc \
		googletest>0:devel/googletest
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libjsoncpp.so:devel/jsoncpp \
		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	Orthanc:science/orthanc

USES=		cmake localbase mysql:client python:build ssl
USE_LDCONFIG=	${DATADIR}/plugins

WRKSRC=		${WRKDIR}/OrthancMySQL-${PORTVERSION}

CMAKE_ARGS=	-DORTHANC_FRAMEWORK_ROOT=${WRKSRC}/MySQL/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}/OrthancFramework/Sources \
		-DORTHANC_FRAMEWORK_SOURCE=path
CMAKE_OFF=	DBUILD_UNIT_TESTS USE_SYSTEM_ORTHANC_SDK USE_SYSTEM_UUID
CMAKE_SOURCE_PATH=	${WRKSRC}/MySQL

CFLAGS+=	-DORTHANC_ENABLE_LOGGING_PLUGIN -DNDEBUG
CXXFLAGS+=	-I${LOCALBASE}/include -DNDEBUG

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include "${.CURDIR}/../../science/orthanc/version.mk"

post-extract:
		${MKDIR} ${WRKSRC}/MySQL/ThirdPartyDownloads
		${CP} ${DISTDIR}/${DIST_SUBDIR}/e2fsprogs-1.44.5.tar.gz ${WRKSRC}/MySQL/ThirdPartyDownloads
		${CP} ${DISTDIR}/${DIST_SUBDIR}/Orthanc-${ORTHANC_VER}.tar.gz ${WRKSRC}/MySQL/ThirdPartyDownloads
		${TAR} -C ${WRKSRC}/MySQL/ThirdPartyDownloads -xf ${WRKSRC}/MySQL/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}.tar.gz

.include <bsd.port.mk>
