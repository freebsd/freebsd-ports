# Created by: Leonhard Wimmer <leo@mediatomb.cc>
# $FreeBSD$

PORTNAME=	mediatomb
PORTVERSION=	0.12.1
PORTREVISION=	11
CATEGORIES=	net multimedia
MASTER_SITES=	SF/${PORTNAME}/MediaTomb/${PORTVERSION}

MAINTAINER=	leo@mediatomb.cc
COMMENT=	UPnP AV MediaServer

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

MAN1=		mediatomb.1
GNU_CONFIGURE=	yes
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--with-search="${LOCALBASE}" \
		--disable-inotify
CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
USE_RC_SUBR=	mediatomb

# --- configurable variables ---
MEDIATOMB_USER?=	mediatomb
MEDIATOMB_GROUP?=	mediatomb
MEDIATOMB_DIR?=		/var/mediatomb
MEDIATOMB_MASK?=	750
# ---

SUB_FILES=	config.xml.dist \
		pkg-install \
		pkg-deinstall

SUB_LIST=	MEDIATOMB_USER=${MEDIATOMB_USER} \
		MEDIATOMB_GROUP=${MEDIATOMB_GROUP} \
		MEDIATOMB_DIR=${MEDIATOMB_DIR} \
		MEDIATOMB_MASK=${MEDIATOMB_MASK}

PLIST_SUB=	MEDIATOMB_USER=${MEDIATOMB_USER} \
		MEDIATOMB_GROUP=${MEDIATOMB_GROUP} \
		MEDIATOMB_DIR=${MEDIATOMB_DIR} \
		MEDIATOMB_MASK=${MEDIATOMB_MASK} \

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

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--enable-sqlite3 \
			--with-sqlite3-h="${LOCALBASE}/include" \
			--with-sqlite3-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
.else
CONFIGURE_ARGS+=	--disable-sqlite3
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--enable-mysql \
			--with-mysql-cfg="${LOCALBASE}/bin/mysql_config"
USE_MYSQL=		yes
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if ${PORT_OPTIONS:MJS}
CONFIGURE_ARGS+=	--enable-libjs \
			--with-js-h="${LOCALBASE}/include" \
			--with-js-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		js:${PORTSDIR}/lang/spidermonkey17
.else
CONFIGURE_ARGS+=	--disable-libjs
.endif

.if ${PORT_OPTIONS:MLIBEXIF}
CONFIGURE_ARGS+=	--enable-libexif \
			--with-libexif-h="${LOCALBASE}/include" \
			--with-libexif-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		exif:${PORTSDIR}/graphics/libexif
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
LIB_DEPENDS+=		ffmpegthumbnailer:${PORTSDIR}/multimedia/ffmpegthumbnailer
.else
CONFIGURE_ARGS+=	--disable-ffmpegthumbnailer
.endif

# CURL is only useful in combination with EXTERNAL_TRANSCODING
.if ${PORT_OPTIONS:MCURL} && ${PORT_OPTIONS:MEXTERNAL_TRANSCODING}
CONFIGURE_ARGS+=	--enable-curl \
			--with-curl-cfg="${LOCALBASE}/bin/curl-config"
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--disable-curl
.endif

.if ${PORT_OPTIONS:MFFMPEG}
CONFIGURE_ARGS+=	--enable-ffmpeg
LIB_DEPENDS+=		avformat:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif

.if ${PORT_OPTIONS:MLIBEXTRACTOR}
CONFIGURE_ARGS+=	--enable-libextractor \
			--with-extractor-h="${LOCALBASE}/include" \
			--with-extractor-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		extractor:${PORTSDIR}/textproc/libextractor
.else
CONFIGURE_ARGS+=	--disable-libextractor
.endif

.if ${PORT_OPTIONS:MID3LIB}
CONFIGURE_ARGS+=	--enable-id3lib \
			--with-id3lib-h="${LOCALBASE}/include" \
			--with-id3lib-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		id3:${PORTSDIR}/audio/id3lib
.else
CONFIGURE_ARGS+=	--disable-id3lib
.endif

.if ${PORT_OPTIONS:MTAGLIB}
CONFIGURE_ARGS+=	--enable-taglib \
			--with-taglib-cfg="${LOCALBASE}/bin/taglib-config"
LIB_DEPENDS+=		tag:${PORTSDIR}/audio/taglib
.else
CONFIGURE_ARGS+=	--disable-taglib
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-tombdebug
.else
CONFIGURE_ARGS+=	--disable-tombdebug
.endif

pre-install:
		PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} -m ${MEDIATOMB_MASK} -p ${PREFIX}/etc/mediatomb
	@${CHOWN} ${MEDIATOMB_USER}:${MEDIATOMB_GROUP} ${PREFIX}/etc/mediatomb
	@${INSTALL} ${COPY} -o ${MEDIATOMB_USER} -g ${MEDIATOMB_GROUP} -m 640 ${WRKDIR}/config.xml.dist ${PREFIX}/etc/mediatomb/config.xml.dist
	@if [ ! -f ${PREFIX}/etc/mediatomb/config.xml ]; then \
		${CP} -p ${PREFIX}/etc/mediatomb/config.xml.dist ${PREFIX}/etc/mediatomb/config.xml ; \
	fi
	@${CHGRP} ${MEDIATOMB_GROUP} ${PREFIX}/bin/mediatomb
	@${CHMOD} a-x ${PREFIX}/bin/mediatomb
	@${CHMOD} g+x ${PREFIX}/bin/mediatomb
	@${MKDIR} -m ${MEDIATOMB_MASK} -p ${MEDIATOMB_DIR}
	@${CHOWN} ${MEDIATOMB_USER}:${MEDIATOMB_GROUP} ${MEDIATOMB_DIR}

.include <bsd.port.post.mk>
