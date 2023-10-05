PORTNAME=	orthanc-webviewer
DISTVERSION=	2.8
PORTREVISION=	8
CATEGORIES=	science
MASTER_SITES=	https://www.orthanc-server.com/downloads/get.php?path=/plugin-webviewer/:main \
		https://www.orthanc-server.com/downloads/get.php?path=/orthanc/:framework \
		http://orthanc.osimis.io/ThirdPartyDownloads/WebViewer/:thirdpartywebviewer \
		http://orthanc.osimis.io/ThirdPartyDownloads/:thirdparty
DISTFILES=	OrthancWebViewer-${PORTVERSION}.tar.gz:main \
		jsPanel-2.3.3-fixed.zip:thirdpartywebviewer \
		cornerstone-0.11.0.zip:thirdpartywebviewer \
		jquery-ui-1.11.3.zip:thirdpartywebviewer \
		pako-0.2.5.zip:thirdpartywebviewer \
		js-url-1.8.6.zip:thirdpartywebviewer \
		Orthanc-1.11.0.tar.gz:framework \
		e2fsprogs-1.44.5.tar.gz:thirdparty
DIST_SUBDIR=	orthanc
EXTRACT_ONLY=	OrthancWebViewer-${PORTVERSION}.tar.gz

MAINTAINER=	maintainer.freebsd@xpoundit.com
COMMENT=	Orthanc plugin to extend Orthanc with a Web viewer of medical images
WWW=		https://www.orthanc-server.com/static.php?page=web-viewer

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCPlugin.h:science/orthanc
LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libgdcmCommon.so:devel/gdcm \
		libicudata.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libopenjp2.so:graphics/openjpeg \
		libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	Orthanc:science/orthanc

USES=		cmake localbase python:build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DORTHANC_FRAMEWORK_ROOT=${WRKSRC}/ThirdPartyDownloads/Orthanc-1.11.0/OrthancFramework/Sources \
		-DORTHANC_FRAMEWORK_SOURCE=path
CMAKE_OFF=	USE_SYSTEM_UUID

CFLAGS+=	-I${LOCALBASE}/include -DORTHANC_ENABLE_LOGGING_PLUGIN -DNDEBUG
CXXFLAGS+=	-DNDEBUG

WRKSRC=		${WRKDIR}/OrthancWebViewer-${PORTVERSION}

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-extract:
	${MKDIR} ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/jsPanel-2.3.3-fixed.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/cornerstone-0.11.0.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/jquery-ui-1.11.3.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/pako-0.2.5.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/js-url-1.8.6.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/e2fsprogs-1.44.5.tar.gz ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/Orthanc-1.11.0.tar.gz ${WRKSRC}/ThirdPartyDownloads
	${TAR} -C ${WRKSRC}/ThirdPartyDownloads -xf ${WRKSRC}/ThirdPartyDownloads/Orthanc-1.11.0.tar.gz

post-build:
	@cd ${BUILD_WRKSRC} && ./UnitTests

.include <bsd.port.mk>
