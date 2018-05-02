# Created by: Leonhard Wimmer <leo@mediatomb.cc>
# $FreeBSD$

PORTNAME=	mediatomb
PORTVERSION=	0.12.1
PORTREVISION=	21
CATEGORIES=	net multimedia
MASTER_SITES=	SF/${PORTNAME}/MediaTomb/${PORTVERSION}

MAINTAINER=	leo@mediatomb.cc
COMMENT=	UPnP AV MediaServer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
LDFLAGS+=	-lpthread ${ICONV_LIB}
CONFIGURE_ARGS=	--with-search="${LOCALBASE}" \
		--disable-inotify
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread"
USES=		compiler:gcc-c++11-lib iconv localbase:ldflags
USE_RC_SUBR=	mediatomb

# Workaround for FreeBSD 10, whose libc++ does not have an overload for C++14's
# `operator delete(void*, size_t)'. Since GCC 6 uses -std=gnu++14 by default,
# linking fails when a dependency (such as taglib) is built with clang and
# lacking the overload. FreeBSD >= 11 is fine.
USE_CXXSTD=	gnu++11

USERS=		mediatomb
GROUPS=		${USERS}

SUB_FILES=	config.xml.dist \
		pkg-install \
		pkg-deinstall

SUB_LIST=	MEDIATOMB_USER=${USERS} \
		MEDIATOMB_GROUP=${GROUPS} \
		MEDIATOMB_DIR=${DESTDIR}/var/db/mediatomb

OPTIONS_DEFINE=	JS LIBEXIF FFMPEGTHUMBNAILER \
		EXTERNAL_TRANSCODING CURL DEBUG
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	SQLITE MYSQL
OPTIONS_RADIO=	METADATA TAG
OPTIONS_RADIO_METADATA=	FFMPEG LIBEXTRACTOR
OPTIONS_RADIO_TAG=	TAGLIB ID3LIB
OPTIONS_DEFAULT=	SQLITE MYSQL JS LIBEXIF TAGLIB FFMPEG FFMPEGTHUMBNAILER \
			EXTERNAL_TRANSCODING CURL

METADATA_DESC=			Metadata extractor
TAG_DESC=			Tag library

DB_DESC=			Database backend
JS_DESC=			JavaScript (SpiderMonkey) support
TAGLIB_DESC=			taglib support
FFMPEG_DESC=			ffmpeg metadata extraction support
FFMPEGTHUMBNAILER_DESC=		ffmpeg thumbnailer support
EXTERNAL_TRANSCODING_DESC=	external transcoding support
ID3LIB_DESC=			id3lib support
LIBEXTRACTOR_DESC=		libextractor support

SQLITE_USES=			sqlite
SQLITE_CONFIGURE_ENABLE=	sqlite3
SQLITE_CONFIGURE_ON=		--with-sqlite3-h="${LOCALBASE}/include" \
				--with-sqlite3-libs="${LOCALBASE}/lib"

MYSQL_USES=			mysql
MYSQL_CONFIGURE_ENABLE=		mysql
MYSQL_CONFIGURE_ON=		--with-mysql-cfg="${LOCALBASE}/bin/mysql_config"

JS_CONFIGURE_ENABLE=		libjs
JS_CONFIGURE_ON=		--with-js-h="${LOCALBASE}/include/js-1.7" \
				--with-js-libs="${LOCALBASE}/lib"
JS_LIB_DEPENDS=			libjs.so:lang/spidermonkey17

LIBEXIF_CONFIGURE_ENABLE=	libexif
LIBEXIF_CONFIGURE_ON=		--with-libexif-h="${LOCALBASE}/include" \
				--with-libexif-libs="${LOCALBASE}/lib"
LIBEXIF_LIB_DEPENDS=		libexif.so:graphics/libexif

EXTERNAL_TRANSCODING_CONFIGURE_ENABLE=	external-transcoding

FFMPEGTHUMBNAILER_CONFIGURE_ENABLE=	ffmpegthumbnailer
FFMPEGTHUMBNAILER_CONFIGURE_ON=		--with-ffmpegthumbnailer-h="${LOCALBASE}/include" \
					--with-ffmpegthumbnailer-libs="${LOCALBASE}/lib"
FFMPEGTHUMBNAILER_LIB_DEPENDS=		libffmpegthumbnailer.so:multimedia/ffmpegthumbnailer

# CURL is only useful in combination with EXTERNAL_TRANSCODING
CURL_IMPLIES=			EXTERNAL_TRANSCODING
CURL_CONFIGURE_ENABLE=		curl
CURL_CONFIGURE_ON=		--with-curl-cfg="${LOCALBASE}/bin/curl-config"
CURL_LIB_DEPENDS=		libcurl.so:ftp/curl

FFMPEG_CONFIGURE_ENABLE=	ffmpeg
FFMPEG_LIB_DEPENDS=		libavformat.so:multimedia/ffmpeg

LIBEXTRACTOR_CONFIGURE_ENABLE=	libextractor
LIBEXTRACTOR_CONFIGURE_ON=	--with-extractor-h="${LOCALBASE}/include" \
				--with-extractor-libs="${LOCALBASE}/lib"
LIBEXTRACTOR_LIB_DEPENDS=	libextractor.so:textproc/libextractor
LIBEXTRACTOR_BROKEN=		LIBEXTRACTOR option fails to configure (checking for EXTRACTOR_getKeywords in -lextractor... no)

ID3LIB_CONFIGURE_ENABLE=	id3lib
ID3LIB_CONFIGURE_ON=		--with-id3lib-h="${LOCALBASE}/include" \
				--with-id3lib-libs="${LOCALBASE}/lib"
ID3LIB_LIB_DEPENDS=		libid3.so:audio/id3lib

TAGLIB_CONFIGURE_ENABLE=	taglib
TAGLIB_CONFIGURE_ON=		--with-taglib-cfg="${LOCALBASE}/bin/taglib-config"
TAGLIB_LIB_DEPENDS=		libtag.so:audio/taglib

DEBUG_CONFIGURE_ENABLE=		tombdebug

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mediatomb
	@${MKDIR} ${STAGEDIR}/var/log/mediatomb
	@${MKDIR} ${STAGEDIR}/var/db/mediatomb
	${INSTALL_DATA} ${WRKDIR}/config.xml.dist ${STAGEDIR}${PREFIX}/etc/mediatomb/config.xml.dist

.include <bsd.port.mk>
