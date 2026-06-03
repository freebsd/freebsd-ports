PORTNAME=	orthanc-webviewer
DISTVERSION=	2.10
CATEGORIES=	science
MASTER_SITES=	https://orthanc.uclouvain.be/downloads/sources/orthanc-webviewer/:webviewer \
		https://orthanc.uclouvain.be/downloads/sources/orthanc/:orthanc \
		https://orthanc.uclouvain.be/downloads/third-party-downloads/web-viewer/:thirdpartyweb \
		https://orthanc.uclouvain.be/downloads/third-party-downloads/:thirdparty
DISTFILES=	OrthancWebViewer-${PORTVERSION}.tar.gz:webviewer \
		jsPanel-2.3.3-fixed.zip:thirdpartyweb \
		cornerstone-0.11.0.zip:thirdpartyweb \
		jquery-ui-1.11.3.zip:thirdpartyweb \
		pako-0.2.5.zip:thirdpartyweb \
		js-url-1.8.6.zip:thirdpartyweb \
		Orthanc-${ORTHANC_VER}.tar.gz:orthanc \
		e2fsprogs-1.44.5.tar.gz:thirdparty
DIST_SUBDIR=	orthanc
EXTRACT_ONLY=	OrthancWebViewer-${PORTVERSION}.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Orthanc web viewer plugin
WWW=		https://www.orthanc-server.com/static.php?page=web-viewer

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCPlugin.h:science/orthanc \
		googletest>0:devel/googletest
LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	Orthanc:science/orthanc

USES=		cmake localbase python:build
USE_LDCONFIG=	${DATADIR}/plugins

CMAKE_ARGS=	-DORTHANC_FRAMEWORK_ROOT=${WRKSRC}/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}/OrthancFramework/Sources \
		-DORTHANC_FRAMEWORK_SOURCE=path
CMAKE_OFF=	USE_SYSTEM_UUID

CFLAGS+=	-I${LOCALBASE}/include -DORTHANC_ENABLE_LOGGING_PLUGIN -DNDEBUG
CXXFLAGS+=	-DNDEBUG

WRKSRC=		${WRKDIR}/OrthancWebViewer-${PORTVERSION}

PLIST_SUB=	DISTVERSION=${DISTVERSION}

# Build fails with 1.12.8 and 1.12.9
ORTHANC_VER=	1.12.7

post-extract:
	${MKDIR} ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/jsPanel-2.3.3-fixed.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/cornerstone-0.11.0.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/jquery-ui-1.11.3.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/pako-0.2.5.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/js-url-1.8.6.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/e2fsprogs-1.44.5.tar.gz ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/Orthanc-${ORTHANC_VER}.tar.gz ${WRKSRC}/ThirdPartyDownloads
	${TAR} -C ${WRKSRC}/ThirdPartyDownloads -xf ${WRKSRC}/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}.tar.gz

post-build:
	@cd ${BUILD_WRKSRC} && ./UnitTests

.include <bsd.port.mk>
