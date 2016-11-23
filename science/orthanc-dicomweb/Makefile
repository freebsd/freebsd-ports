# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	orthanc-dicomweb
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	science net
MASTER_SITES=	http://orthanc-server.com/downloads/get.php?path=/plugin-dicom-web/
DISTNAME=	OrthancDicomWeb-${PORTVERSION}
DIST_SUBDIR=	orthanc

MAINTAINER=	mp39590@gmail.com
COMMENT=	WADO and DICOMweb support for Orthanc

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCPlugin.h:science/orthanc
LIB_DEPENDS=	libgdcmCommon.so:devel/gdcm \
		libboost_filesystem.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_locale.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libuuid.so:misc/e2fsprogs-libuuid \
		libpugixml.so:textproc/pugixml \
		libgtest.so:devel/googletest

USES=		cmake:outsource localbase python:build
WRKSRC=		${WRKDIR}/OrthancDicomWeb-${PORTVERSION}

PLIST_FILES=	share/orthanc/plugins/libOrthancDicomWeb.so \
		share/orthanc/plugins/libOrthancDicomWeb.so.${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Orthanc/Resources/CMake/*.cmake

do-test:
	@cd ${BUILD_WRKSRC} && ./UnitTests

.include <bsd.port.mk>
