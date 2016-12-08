# Created by: Leonhard Wimmer <leo@mediatomb.cc>
# $FreeBSD$

PORTNAME=	mediatomb
PORTVERSION=	0.12.1
PORTREVISION=	13
CATEGORIES=	net multimedia
MASTER_SITES=	SF/${PORTNAME}/MediaTomb/${PORTVERSION}

MAINTAINER=	leo@mediatomb.cc
COMMENT=	UPnP AV MediaServer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS=	--with-search="${LOCALBASE}" \
		--disable-inotify
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread"
USES=		compiler:gcc-c++11-lib iconv
USE_RC_SUBR=	mediatomb

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
METADATA_DESC=	Metadata extractor
TAG_DESC=	Tag library
OPTIONS_DEFAULT=	SQLITE MYSQL JS LIBEXIF TAGLIB FFMPEG FFMPEGTHUMBNAILER \
			EXTERNAL_TRANSCODING CURL
DB_DESC=			Database backend
JS_DESC=			JavaScript (SpiderMonkey) support
TAGLIB_DESC=			taglib support
FFMPEG_DESC=			ffmpeg metadata extraction support
FFMPEGTHUMBNAILER_DESC=		ffmpeg thumbnailer support
EXTERNAL_TRANSCODING_DESC=	external transcoding support
ID3LIB_DESC=			id3lib support
LIBEXTRACTOR_DESC=		libextractor support

SQLITE_USES=	sqlite
MYSQL_USES=	mysql

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--enable-sqlite3 \
			--with-sqlite3-h="${LOCALBASE}/include" \
			--with-sqlite3-libs="${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--disable-sqlite3
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--enable-mysql \
			--with-mysql-cfg="${LOCALBASE}/bin/mysql_config"
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if ${PORT_OPTIONS:MJS}
CONFIGURE_ARGS+=	--enable-libjs \
			--with-js-h="${LOCALBASE}/include" \
			--with-js-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		libjs.so:lang/spidermonkey17
.else
CONFIGURE_ARGS+=	--disable-libjs
.endif

.if ${PORT_OPTIONS:MLIBEXIF}
CONFIGURE_ARGS+=	--enable-libexif \
			--with-libexif-h="${LOCALBASE}/include" \
			--with-libexif-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		libexif.so:graphics/libexif
.else
CONFIGURE_ARGS+=	--disable-libexif
.endif

.if ${PORT_OPTIONS:MEXTERNAL_TRANSCODING}
CONFIGURE_ARGS+=	--enable-external-transcoding
.else
CONFIGURE_ARGS+=	--disable-external-transcoding
.endif

.if ${PORT_OPTIONS:MFFMPEGTHUMBNAILER}
CONFIGURE_ARGS+=	--enable-ffmpegthumbnailer \
			--with-ffmpegthumbnailer-h="${LOCALBASE}/include" \
			--with-ffmpegthumbnailer-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		libffmpegthumbnailer.so:multimedia/ffmpegthumbnailer
.else
CONFIGURE_ARGS+=	--disable-ffmpegthumbnailer
.endif

# CURL is only useful in combination with EXTERNAL_TRANSCODING
.if ${PORT_OPTIONS:MCURL} && ${PORT_OPTIONS:MEXTERNAL_TRANSCODING}
CONFIGURE_ARGS+=	--enable-curl \
			--with-curl-cfg="${LOCALBASE}/bin/curl-config"
LIB_DEPENDS+=	libcurl.so:ftp/curl
.else
CONFIGURE_ARGS+=	--disable-curl
.endif

.if ${PORT_OPTIONS:MFFMPEG}
CONFIGURE_ARGS+=	--enable-ffmpeg
LIB_DEPENDS+=		libavformat.so:multimedia/ffmpeg
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif

.if ${PORT_OPTIONS:MLIBEXTRACTOR}
CONFIGURE_ARGS+=	--enable-libextractor \
			--with-extractor-h="${LOCALBASE}/include" \
			--with-extractor-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		libextractor.so:textproc/libextractor
.else
CONFIGURE_ARGS+=	--disable-libextractor
.endif

.if ${PORT_OPTIONS:MID3LIB}
CONFIGURE_ARGS+=	--enable-id3lib \
			--with-id3lib-h="${LOCALBASE}/include" \
			--with-id3lib-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		libid3.so:audio/id3lib
.else
CONFIGURE_ARGS+=	--disable-id3lib
.endif

.if ${PORT_OPTIONS:MTAGLIB}
CONFIGURE_ARGS+=	--enable-taglib \
			--with-taglib-cfg="${LOCALBASE}/bin/taglib-config"
LIB_DEPENDS+=		libtag.so:audio/taglib
.else
CONFIGURE_ARGS+=	--disable-taglib
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-tombdebug
.else
CONFIGURE_ARGS+=	--disable-tombdebug
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mediatomb
	${MKDIR} ${STAGEDIR}/var/log/mediatomb
	${MKDIR} ${STAGEDIR}/var/db/mediatomb
	@${INSTALL} ${COPY} ${WRKDIR}/config.xml.dist ${STAGEDIR}${PREFIX}/etc/mediatomb/config.xml.dist

.include <bsd.port.post.mk>
