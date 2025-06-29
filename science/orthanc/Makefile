PORTNAME=	orthanc
DISTVERSION=	1.12.6
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	https://orthanc.uclouvain.be/downloads/sources/orthanc/
DISTNAME=	Orthanc-${PORTVERSION}

MAINTAINER=	maintainer.freebsd@xpoundit.com
COMMENT=	Lightweight DICOM server for healthcare and medical research
WWW=		https://www.orthanc-server.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	protoc:devel/protobuf

LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libcivetweb.so:www/civetweb \
		libcurl.so:ftp/curl \
		libdcmtkcharls.so:graphics/dcmtk \
		libgtest.so:devel/googletest \
		libicuuc.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libpng16.so:graphics/png \
		libprotobuf.so:devel/protobuf \
		libpugixml.so:textproc/pugixml \
		libtiff.so:graphics/tiff \
		libuuid.so:misc/libuuid

USES=		cmake gnome iconv jpeg lua python:build sqlite ssl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_RC_SUBR=	orthanc

# Keep in sync with graphics/dcmtk version
CMAKE_ARGS=	-DDCMTK_DICTIONARY_DIR:STRING=${LOCALBASE}/share/dcmtk-3.6.9
CMAKE_ON=	USE_SYSTEM_BOOST USE_SYSTEM_CIVETWEB USE_SYSTEM_DCMTK \
		USE_SYSTEM_GOOGLE_TEST USE_SYSTEM_JSONCPP USE_SYSTEM_LIBICONV \
		USE_SYSTEM_LIBJPEG USE_SYSTEM_LIBPNG USE_SYSTEM_LUA \
		USE_SYSTEM_OPENSSL USE_SYSTEM_PUGIXML USE_SYSTEM_SQLITE \
		USE_SYSTEM_UUID USE_SYSTEM_ZLIB
CMAKE_OFF=	BUILD_CONNECTIVITY_CHECKS UNIT_TESTS_WITH_HTTP_CONNEXIONS
CMAKE_SOURCE_PATH=	${WRKSRC}/OrthancServer

CFLAGS+=	-DNDEBUG
CXXFLAGS+=	-DNDEBUG

WRKSRC=		${WRKDIR}/Orthanc-${PORTVERSION}

USERS=		orthanc
GROUPS=		orthanc

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

post-install:
	${MKDIR} ${STAGEDIR}/var/db/orthanc/db/db-v5
	${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${CMAKE_SOURCE_PATH}/Resources/Configuration.json
	${CP} ${CMAKE_SOURCE_PATH}/Resources/Configuration.json ${STAGEDIR}${ETCDIR}/orthanc.json.sample

.include <bsd.port.mk>
