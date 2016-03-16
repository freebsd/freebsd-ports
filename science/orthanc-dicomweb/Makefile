# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	orthanc-dicomweb
PORTVERSION=	0.2
CATEGORIES=	science net
MASTER_SITES=	http://orthanc-server.com/downloads/get.php?path=/plugin-dicom-web/
DISTNAME=	OrthancDicomWeb-${PORTVERSION}
DIST_SUBDIR=	orthanc

MAINTAINER=	mp39590@gmail.com
COMMENT=	WADO and DICOMweb support for Orthanc

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCPlugin.h:${PORTSDIR}/science/orthanc \
		gtest-config:${PORTSDIR}/devel/googletest
LIB_DEPENDS=	libgdcmCommon.so:${PORTSDIR}/devel/gdcm \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		libboost_regex.so:${PORTSDIR}/devel/boost-libs \
		libboost_locale.so:${PORTSDIR}/devel/boost-libs \
		libjsoncpp.so:${PORTSDIR}/devel/jsoncpp \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libpugixml.so:${PORTSDIR}/textproc/pugixml

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		cmake:outsource python:build
WRKSRC=		${WRKDIR}/OrthancDicomWeb-${PORTVERSION}

PLIST_FILES=	share/orthanc/plugins/libOrthancDicomWeb.so \
		share/orthanc/plugins/libOrthancDicomWeb.so.${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Orthanc/Resources/CMake/*.cmake

do-test:
	@cd ${BUILD_WRKSRC} && ./UnitTests

.include <bsd.port.mk>
