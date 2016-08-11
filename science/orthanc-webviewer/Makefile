# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	orthanc-webviewer
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	science graphics
MASTER_SITES=	http://orthanc-server.com/downloads/get.php?path=/plugin-webviewer/:main \
		http://www.montefiore.ulg.ac.be/~jodogne/Orthanc/ThirdPartyDownloads/WebViewer/:thirdparty
DISTFILES=	OrthancWebViewer-${PORTVERSION}.tar.gz:main \
		jsPanel-2.3.3-fixed.zip:thirdparty \
		cornerstone-0.8.4.zip:thirdparty \
		jquery-ui-1.11.3.zip:thirdparty \
		pako-0.2.5.zip:thirdparty \
		js-url-1.8.6.zip:thirdparty
DIST_SUBDIR=	orthanc

MAINTAINER=	mp39590@gmail.com
COMMENT=	Web viewer plugin for Orthanc

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCPlugin.h:science/orthanc \
		gtest-config:devel/googletest
LIB_DEPENDS=	libgdcmCommon.so:devel/gdcm \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libsqlite3.so:databases/sqlite3 \
		libuuid.so:misc/e2fsprogs-libuuid

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		cmake:outsource python:build
WRKSRC=		${WRKDIR}/OrthancWebViewer-${PORTVERSION}

PLIST_FILES=	share/orthanc/plugins/libOrthancWebViewer.so \
		share/orthanc/plugins/libOrthancWebViewer.so.${PORTVERSION}

post-extract:
	${MKDIR} ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/jsPanel-2.3.3-fixed.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/cornerstone-0.8.4.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/jquery-ui-1.11.3.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/pako-0.2.5.zip ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/js-url-1.8.6.zip ${WRKSRC}/ThirdPartyDownloads

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Orthanc/Resources/CMake/*.cmake

post-build:
	@cd ${BUILD_WRKSRC} && ./UnitTests

.include <bsd.port.mk>
