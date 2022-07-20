PORTNAME=	orthanc-dicomweb
DISTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://www.orthanc-server.com/downloads/get.php?path=/plugin-dicom-web/:main \
		https://www.orthanc-server.com/downloads/get.php?path=/orthanc/:framework \
		https://orthanc.osimis.io/ThirdPartyDownloads/:thirdparty \
		https://orthanc.osimis.io/ThirdPartyDownloads/dicom-web/:thirdpartydicomweb
DISTFILES=	OrthancDicomWeb-${PORTVERSION}.tar.gz:main
EXTRADISTFILES=	Orthanc-1.11.0.tar.gz:framework \
		e2fsprogs-1.44.5.tar.gz:thirdparty \
		bootstrap-4.3.1.zip:thirdpartydicomweb \
		vuejs-2.6.10.tar.gz:thirdpartydicomweb \
		axios-0.19.0.tar.gz:thirdpartydicomweb \
		Font-Awesome-4.7.0.tar.gz:thirdpartydicomweb \
		bootstrap-vue-2.0.0-rc.24-dist.tar.gz:thirdpartydicomweb \
		babel-polyfill-6.26.0.min.js.gz:thirdpartydicomweb
DISTFILES+=	${EXTRADISTFILES}
DIST_SUBDIR=	orthanc
EXTRACT_ONLY=	OrthancDicomWeb-${PORTVERSION}.tar.gz

MAINTAINER=	maintainer.freebsd@xpoundit.com
COMMENT=	Orthanc plugin to bring support of the DICOMweb standard into Orthanc

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/orthanc/OrthancCPlugin.h:science/orthanc
LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libgdcmCommon.so:devel/gdcm \
		libicudata.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libopenjp2.so:graphics/openjpeg \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	Orthanc:science/orthanc

USES=		cmake localbase python:build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DORTHANC_FRAMEWORK_ROOT=${WRKSRC}/ThirdPartyDownloads/Orthanc-1.11.0/OrthancFramework/Sources \
		-DORTHANC_FRAMEWORK_SOURCE=path
CMAKE_OFF=	USE_SYSTEM_UUID

CFLAGS+=	-DORTHANC_ENABLE_LOGGING_PLUGIN -DNDEBUG
CXXFLAGS+=	-DNDEBUG

WRKSRC=		${WRKDIR}/OrthancDicomWeb-${PORTVERSION}

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-extract:
	${MKDIR} ${WRKSRC}/ThirdPartyDownloads
.for f in ${EXTRADISTFILES:C/:[^:]*//}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${WRKSRC}/ThirdPartyDownloads
.endfor
	${TAR} -C ${WRKSRC}/ThirdPartyDownloads -xf ${WRKSRC}/ThirdPartyDownloads/Orthanc-1.11.0.tar.gz

do-test:
	@cd ${BUILD_WRKSRC} && ./UnitTests

.include <bsd.port.mk>
