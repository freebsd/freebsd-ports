PORTNAME=	orthanc-dicomweb
DISTVERSION=	1.21
CATEGORIES=	science
MASTER_SITES=	https://orthanc.uclouvain.be/downloads/sources/orthanc-dicomweb/:dicomweb \
		https://orthanc.uclouvain.be/downloads/third-party-downloads/:thirdparty \
		https://orthanc.uclouvain.be/downloads/third-party-downloads/dicom-web/:thirdpartyweb \
		https://orthanc.uclouvain.be/downloads/sources/orthanc/:orthanc
DISTFILES=	OrthancDicomWeb-${PORTVERSION}.tar.gz:dicomweb
EXTRADISTFILES=	Orthanc-${ORTHANC_VER}.tar.gz:orthanc \
		e2fsprogs-1.44.5.tar.gz:thirdparty \
		bootstrap-5.3.3.zip:thirdparty \
		babel-polyfill-6.26.0.min.js.gz:thirdpartyweb \
		vuejs-2.6.10.tar.gz:thirdpartyweb \
		axios-0.19.0.tar.gz:thirdpartyweb \
		Font-Awesome-4.7.0.tar.gz:thirdpartyweb
DISTFILES+=	${EXTRADISTFILES}
DIST_SUBDIR=	orthanc
EXTRACT_ONLY=	OrthancDicomWeb-${PORTVERSION}.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Orthanc DICOMWeb plugin
WWW=		https://www.orthanc-server.com/static.php?page=dicomweb

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	orthanc>=${ORTHANC_VER}:science/orthanc \
		googletest>0:devel/googletest
LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	orthanc>=${ORTHANC_VER}:science/orthanc

USES=		cmake localbase python:build
# FIXME: Should plugins be moved to lib?
USE_LDCONFIG=	${DATADIR}/plugins

ORTHANC_VER=	1.12.9
CMAKE_ARGS=	-DORTHANC_FRAMEWORK_ROOT=${WRKSRC}/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}/OrthancFramework/Sources \
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
	${TAR} -C ${WRKSRC}/ThirdPartyDownloads -xf ${WRKSRC}/ThirdPartyDownloads/Orthanc-${ORTHANC_VER}.tar.gz

do-test:
	@cd ${BUILD_WRKSRC} && ./UnitTests

.include <bsd.port.mk>
