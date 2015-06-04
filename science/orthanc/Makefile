# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	orthanc
PORTVERSION=	0.8.6
CATEGORIES=	science graphics net
MASTER_SITES=	SF/orthancserver/:main \
		http://www.montefiore.ulg.ac.be/~jodogne/Orthanc/ThirdPartyDownloads/:mongoose
DISTFILES=	Orthanc-${PORTVERSION}.tar.gz:main \
		mongoose-3.8.tgz:mongoose
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mp39590@gmail.com
COMMENT=	RESTful DICOM server for healthcare and medical research

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libjsoncpp.so:${PORTSDIR}/devel/jsoncpp \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libglog.so:${PORTSDIR}/devel/glog \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libdcmimage.so:${PORTSDIR}/devel/dcmtk \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libpugixml.so:${PORTSDIR}/textproc/pugixml

CMAKE_ARGS=	-DDCMTK_LIBRARIES="dcmdsig;charls;dcmjpls" \
		-DDCMTK_DICTIONARY_DIR="${LOCALBASE}/share/dcmtk" \
		-DUSE_SYSTEM_MONGOOSE=OFF \
		-DBUILD_UNIT_TESTS=OFF

USES=		cmake:outsource python:build lua:51 dos2unix
DOS2UNIX_FILES=	CMakeLists.txt
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/jsoncpp
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	orthanc
WRKSRC=		${WRKDIR}/Orthanc-${PORTVERSION}
USERS=		orthanc
GROUPS=		orthanc

# This is mongoose sources, downloaded from Orthanc author homepage.  Orthanc
# requires mongoose webserver, but after version 3.8, mongoose developers has
# changed the license from MIT to GPLv2 only. This action made illegal to
# combine new mongoose versions with GPLv3 only Orthanc.
# We download sources manually and pass USE_SYSTEM_MONGOOSE=OFF to Orthanc
# cmake variables to tell that mongoose is not presented on the host OS and
# should be build together with the software instead.
# https://www.mail-archive.com/mongoose-users@googlegroups.com/msg00625.html
post-extract:
	${MKDIR} ${WRKSRC}/ThirdPartyDownloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/mongoose-3.8.tgz ${WRKSRC}/ThirdPartyDownloads

post-install:
	${MKDIR} ${STAGEDIR}/var/db/orthanc/db/db-v5
	${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	${WRKSRC}/Resources/Configuration.json > ${STAGEDIR}${ETCDIR}/orthanc.json.sample

.include <bsd.port.mk>
