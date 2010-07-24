# New ports collection makefile for:	mediatomb
# Date created:			29 March 2007
# Whom:					Leonhard Wimmer <leo@mediatomb.cc>
#
# $FreeBSD$
#

PORTNAME=	mediatomb
PORTVERSION=	0.12.1
PORTREVISION=	1
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
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		CFLAGS="${CFLAGS}"
USE_RC_SUBR=	mediatomb.sh

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

OPTIONS=	SQLITE3 "sqlite3 support" on \
		MYSQL "MySQL support" on \
		JS "JavaScript (SpiderMonkey) support" on \
		LIBEXIF "libexif support" on \
		TAGLIB "taglib support" on \
		FFMPEG "ffmpeg metadata extraction support" on \
		FFMPEGTHUMBNAILER "ffmpeg thumbnailer support" on \
		EXTERNAL_TRANSCODING "external transcoding support" on \
		CURL "curl support" on \
		ID3LIB "id3lib support" off \
		LIBEXTRACTOR "libextractor support" off \
		DEBUG "debug build" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SQLITE3) && defined(WITHOUT_MYSQL)
IGNORE=	is useless without a database. Please (re)run 'make config' and choose either SQLITE3 or MYSQL
.endif

.if defined(WITH_SQLITE3)
CONFIGURE_ARGS+=	--enable-sqlite3 \
			--with-sqlite3-h="${LOCALBASE}/include" \
			--with-sqlite3-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
.else
CONFIGURE_ARGS+=	--disable-sqlite3
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--enable-mysql \
			--with-mysql-cfg="${LOCALBASE}/bin/mysql_config"
LIB_DEPENDS+=		mysqlclient_r:${PORTSDIR}/databases/mysql50-client
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if defined(WITH_JS)
CONFIGURE_ARGS+=	--enable-libjs \
			--with-js-h="${LOCALBASE}/include" \
			--with-js-libs="${LOCALBASE}/lib"
BUILD_DEPENDS+=		${LOCALBASE}/lib/libjs.so:${PORTSDIR}/lang/spidermonkey
RUN_DEPENDS+=		${LOCALBASE}/lib/libjs.so:${PORTSDIR}/lang/spidermonkey
.else
CONFIGURE_ARGS+=	--disable-libjs
.endif

.if defined(WITH_LIBEXIF)
CONFIGURE_ARGS+=	--enable-libexif \
			--with-libexif-h="${LOCALBASE}/include" \
			--with-libexif-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		exif:${PORTSDIR}/graphics/libexif
.else
CONFIGURE_ARGS+=	--disable-libexif
.endif

.if defined(WITH_EXTERNAL_TRANSCODING)
CONFIGURE_ARGS+=	--enable-external-transcoding
.else
CONFIGURE_ARGS+=	--disable-external-transcoding
.endif

.if defined(WITH_FFMPEGTHUMBNAILER)
CONFIGURE_ARGS+=	--enable-ffmpegthumbnailer \
			--with-ffmpegthumbnailer-h="${LOCALBASE}/include" \
			--with-ffmpegthumbnailer-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		ffmpegthumbnailer:${PORTSDIR}/multimedia/ffmpegthumbnailer
.else
CONFIGURE_ARGS+=	--disable-ffmpegthumbnailer
.endif

# CURL is only useful in combination with EXTERNAL_TRANSCODING
.if defined(WITH_CURL) && defined(WITH_EXTERNAL_TRANSCODING)
CONFIGURE_ARGS+=	--enable-curl \
			--with-curl-cfg="${LOCALBASE}/bin/curl-config"
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--disable-curl
.endif

.if defined(WITH_FFMPEG) && defined(WITH_LIBEXTRACTOR)
IGNORE=	cannot be compiled with both, ffmpeg and libextractor. Please (re)run 'make config' and deselect either FFMPEG or LIBEXTRACTOR
.endif

.if defined(WITH_FFMPEG)
CONFIGURE_ARGS+=	--enable-ffmpeg
LIB_DEPENDS+=		avformat:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif

.if defined(WITH_LIBEXTRACTOR)
CONFIGURE_ARGS+=	--enable-libextractor \
			--with-extractor-h="${LOCALBASE}/include" \
			--with-extractor-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		extractor:${PORTSDIR}/textproc/libextractor
.else
CONFIGURE_ARGS+=	--disable-libextractor
.endif

.if defined(WITH_ID3LIB) && defined(WITH_TAGLIB)
IGNORE=	cannot be compiled with both, taglib and id3lib. Please (re)run 'make config' and deselect either TAGLIB or ID3LIB
.endif

.if defined(WITH_ID3LIB)
CONFIGURE_ARGS+=	--enable-id3lib \
			--with-id3lib-h="${LOCALBASE}/include" \
			--with-id3lib-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=		id3:${PORTSDIR}/audio/id3lib
.else
CONFIGURE_ARGS+=	--disable-id3lib
.endif

.if defined(WITH_TAGLIB)
CONFIGURE_ARGS+=	--enable-taglib \
			--with-taglib-cfg="${LOCALBASE}/bin/taglib-config"
LIB_DEPENDS+=		tag:${PORTSDIR}/audio/taglib
.else
CONFIGURE_ARGS+=	--disable-taglib
.endif

.if defined(WITH_DEBUG)
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
	@${MKDIR} -m ${MEDIATOMB_MASK} -p ${MEDIATOMB_DIR}
	@${CHOWN} ${MEDIATOMB_USER}:${MEDIATOMB_GROUP} ${MEDIATOMB_DIR}

.include <bsd.port.post.mk>
