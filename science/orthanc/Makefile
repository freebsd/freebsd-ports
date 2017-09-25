# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	orthanc
PORTVERSION=	1.1.0
PORTREVISION=	8
CATEGORIES=	science graphics net www
MASTER_SITES=	http://orthanc-server.com/downloads/get.php?path=/orthanc/:main \
		http://www.montefiore.ulg.ac.be/~jodogne/Orthanc/ThirdPartyDownloads/:mongoose
DISTFILES=	Orthanc-${PORTVERSION}.tar.gz:main \
		mongoose-3.8.tgz:mongoose
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mp39590@gmail.com
COMMENT=	RESTful DICOM server for healthcare and medical research

# GPLv3 license, with the OpenSSL exception.
LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjsoncpp.so:devel/jsoncpp \
		libuuid.so:misc/e2fsprogs-libuuid \
		libboost_filesystem.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_locale.so:devel/boost-libs \
		libdcmdsig.so:devel/dcmtk \
		libcharls.so:devel/dcmtk \
		libdcmjpls.so:devel/dcmtk \
		libsqlite3.so:databases/sqlite3 \
		libpng16.so:graphics/png \
		libgtest.so:devel/googletest \
		libpugixml.so:textproc/pugixml

BROKEN_powerpc64=	fails to configure: CMake: Looking for C++ include pugixml.hpp - not found

CMAKE_ARGS=	-DDCMTK_LIBRARIES="dcmdsig;charls;dcmjpls" \
		-DDCMTK_DIR="${LOCALBASE}" \
		-DDCMTK_DICTIONARY_DIR="${LOCALBASE}/share/dcmtk" \
		-DUSE_SYSTEM_MONGOOSE=OFF \
		-DUNIT_TESTS_WITH_HTTP_CONNEXIONS=OFF

USES=		cmake:outsource dos2unix jpeg lua:51 python:build ssl
CFLAGS+=	-I${LOCALBASE}/include
DOS2UNIX_FILES=	CMakeLists.txt
USE_LDCONFIG=	yes
USE_RC_SUBR=	orthanc
WRKSRC=		${WRKDIR}/Orthanc-${PORTVERSION}
USERS=		orthanc
GROUPS=		orthanc
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

# This is mongoose sources, downloaded from Orthanc author homepage.  Orthanc
# requires mongoose webserver, but after version 3.8, mongoose developers has
# changed the license from MIT to GPLv2 only. This action made illegal to
# combine new mongoose versions with GPLv3 only Orthanc.
# We download sources manually and pass USE_SYSTEM_MONGOOSE=OFF to Orthanc
# cmake variables to tell that mongoose is not presented on the host OS and
# should be build together with the software instead.
# https://www.mail-archive.com/mongoose-users@googlegroups.com/msg00625.html
post-patch:
	${MKDIR} ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/mongoose-3.8.tgz ${WRKSRC}/ThirdPartyDownloads
	# Orthanc hardcodes /usr/local paths for libs and includes.
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Resources/CMake/*.cmake

# There is no way to disable building of test units without a patch, on other
# hand it brings only one build dependency (devel/googletest) and running it was
# helpful in early bug detection in Debian.
# Some tests require connections to be made to the outside world, this is
# definitely unsupported behaviour and therefor those tests are disabled with
# cmake variable above (-DUNIT_TESTS_WITH_HTTP_CONNEXIONS=OFF).
post-build:
	@cd ${BUILD_WRKSRC} && ./UnitTests

post-install:
	${MKDIR} ${STAGEDIR}/var/db/orthanc/db/db-v5
	${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Resources/Configuration.json
	${CP} ${WRKSRC}/Resources/Configuration.json ${STAGEDIR}${ETCDIR}/orthanc.json.sample
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/plugins/libServeFolders.so.${PORTVERSION}

.include <bsd.port.mk>
