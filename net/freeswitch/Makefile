PORTNAME=	freeswitch
DISTVERSION=	1.11.1
CATEGORIES=	net
MASTER_SITES=	https://files.freeswitch.org/releases/freeswitch/ \
		https://files.freeswitch.org/releases/sounds/:sounds
DISTFILES=	${PORTNAME}-${PORTVERSION}.-release${EXTRACT_SUFX}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Multi-protocol soft switch for telephony applications
WWW=		https://freeswitch.org

LICENSE=	MPL11

BROKEN_i386=	error: expected ')'
ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le

BUILD_DEPENDS=	gdiff:textproc/diffutils \
		doxygen:devel/doxygen \
		erlang>=21.3:lang/erlang
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libcurl.so:ftp/curl \
		libavformat.so:multimedia/ffmpeg6 \
		libpcre2-8.so:devel/pcre2 \
		libspeexdsp.so:audio/speexdsp \
		libspeex.so:audio/speex \
		libldns.so:dns/ldns \
		libopus.so:audio/opus \
		libsndfile.so:audio/libsndfile \
		libfreetype.so:print/freetype2 \
		libodbc.so:databases/unixODBC \
		libpng.so:graphics/png \
		libjbig.so:graphics/jbigkit \
		libshout.so:audio/libshout \
		libuuid.so:misc/libuuid \
		libmariadb.so:databases/mariadb-connector-c \
		libspandsp.so:comms/spandsp \
		libsofia-sip-ua.so:net/sofia-sip
RUN_DEPENDS=	erlang>=21.3:lang/erlang

USES=		compiler:c11 cpe gmake iconv jpeg libedit autoreconf \
		libtool lua:53 openal perl5 pkgconfig shebangfix ssl tar:xz
JAVA_VERSION=	11

USE_LDCONFIG=	yes
USE_RC_SUBR=	freeswitch

SHEBANG_FILES=	scripts/fsxs.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-zrtp

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-Wno-error -I${LUA_INCDIR}

CONFLICTS_BUILD=	xmlrpc-c

BINARY_ALIAS=	diff=gdiff
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.-release

USERS=		${PORTNAME}
GROUPS=		${USERS}

OPTIONS_DEFINE=		X11 EXAMPLES PGSQL ALL_MODULES
OPTIONS_DEFAULT=	8K 16K ENGLISH PGSQL
OPTIONS_MULTI=		BITRATE LANGUAGE
OPTIONS_MULTI_BITRATE=	8K 16K 32K 48K
OPTIONS_MULTI_LANGUAGE=	CHINESE_HK CHINESE_SIM BRAZILIAN ENGLISH ENGLISH_CA FRENCH_CA RUSSIAN SWEDISH
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=		yes

16K_DESC=		16kHz Audio Files
32K_DESC=		32kHz Audio Files
48K_DESC=		48kHz Audio Files
8K_DESC=		8kHz Audio Files
BRAZILIAN_DESC=		Brazilian Portuguese Language Sounds
CHINESE_HK_DESC=	Chinese Traditional Language Sounds
CHINESE_SIM_DESC=	Chinese Simplified Language Sounds
ENGLISH_CA_DESC=	Canadian English Language Sounds
ENGLISH_DESC=		US English Language Sounds
FRENCH_CA_DESC=		French Canadian Language Sounds
RUSSIAN_DESC=		Russian Language Sounds
SWEDISH_DESC=		Swedish Language Sounds
X11_DESC=		graphics/ImageMagick[-nox11] dependency

16K_VARS=	BITRATES+=16000
32K_VARS=	BITRATES+=32000
48K_VARS=	BITRATES+=48000
8K_VARS=	BITRATES+=8000
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_ENABLE=	core-pgsql-support core-pgsql-pkgconfig
PGSQL_CONFIGURE_ENV_OFF=	ac_cv_lib_pq_PQgetvalue=false

ALL_MODULES_BUILD_DEPENDS=	${LOCALBASE}/bin/aclocal:devel/automake \
				${LOCALBASE}/bin/erl:lang/erlang \
				${LOCALBASE}/bin/bash:shells/bash \
				${LOCALBASE}/bin/php:lang/php85
ALL_MODULES_CFLAGS=		-I${LOCALBASE}/include/openh323/ \
				-I${JAVA_HOME}/include/ \
				-I${JAVA_HOME}/include/freebsd
ALL_MODULES_CONFLICTS_BUILD=	apr
ALL_MODULES_EXTRA_PATCHES=	${FILESDIR}/extrapatch-modules.conf
ALL_MODULES_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg6 \
				libbrotlidec.so:archivers/brotli \
				libbrotlienc.so:archivers/brotli \
				libhiredis.so:databases/hiredis \
				libldap.so:net/openldap26-client \
				libasound.so:audio/alsa-lib \
				libcodec2.so:audio/codec2 \
				libflite.so:audio/flite \
				libgumbo.so:devel/gumbo \
				libhiredis.so:databases/hiredis \
				libilbc.so:net/ilbc \
				libmemcached.so:databases/libmemcached \
				libmongoc-1.0.so:devel/mongo-c-driver \
				libmp3lame.so:audio/lame \
				libmpg123.so:audio/mpg123 \
				libopencore-amrnb.so:audio/opencore-amr \
				libopencore-amrwb.so:audio/opencore-amr \
				libopusenc.so:audio/libopusenc \
				libopusfile.so:audio/opusfile \
				libphp.so:lang/php85 \
				librabbitmq.so:net/rabbitmq-c \
				libshout.so:audio/libshout \
				libsrtp2.so:net/libsrtp2 \
				libtpl.so:devel/libtpl \
				libvlc.so:multimedia/vlc \
				libvpx.so:multimedia/libvpx \
				libx264.so:multimedia/libx264 \
				libyuv.so:graphics/libyuv
ALL_MODULES_USE=		XORG=x11 OPENLDAP=yes
ALL_MODULES_USES=		java xorg # required by mod_unimrcp

# install-strip causes `make stage' to fail:
# libtool: install: strip --strip-debug /wrkdirs/usr/ports/net/freeswitch/work/stage/usr/local/lib/libfreeswitch.a
# strip: file format not recognized
# INSTALL_TARGET=		install-strip

.include <bsd.port.options.mk>

EDPRE=	freeswitch-sounds
EDPOST=	1.0.51.tar.gz
#Swedish lang sounds are older/lower version.
EDPOST_SV=	1.0.50.tar.gz
EDPOST_MUSIC=	1.0.52.tar.gz

.for rate in ${BITRATES}
EXTRADISTFILES+=	${EDPRE}-music-${rate}-${EDPOST_MUSIC}
.if ${PORT_OPTIONS:MBRAZILIAN}
EXTRADISTFILES+=	${EDPRE}-pt-BR-karina-${rate}-${EDPOST}
.endif
.if ${PORT_OPTIONS:MCHINESE_SIM}
EXTRADISTFILES+=	${EDPRE}-zh-cn-sinmei-${rate}-${EDPOST}
.endif
.if ${PORT_OPTIONS:MCHINESE_HK}
EXTRADISTFILES+=	${EDPRE}-zh-hk-sinmei-${rate}-${EDPOST}
.endif
.if ${PORT_OPTIONS:MENGLISH}
EXTRADISTFILES+=	${EDPRE}-en-us-callie-${rate}-${EDPOST_MUSIC}
.endif
.if ${PORT_OPTIONS:MENGLISH_CA}
EXTRADISTFILES+=	${EDPRE}-en-ca-june-${rate}-${EDPOST}
.endif
.if ${PORT_OPTIONS:MFRENCH_CA}
EXTRADISTFILES+=	${EDPRE}-fr-ca-june-${rate}-${EDPOST}
.endif
.if ${PORT_OPTIONS:MRUSSIAN}
EXTRADISTFILES+=	${EDPRE}-ru-RU-elena-${rate}-${EDPOST}
.endif
.if ${PORT_OPTIONS:MSWEDISH}
EXTRADISTFILES+=	${EDPRE}-sv-se-jakob-${rate}-${EDPOST_SV}
.endif
.endfor

.for distfile in ${EXTRADISTFILES}
DISTFILES+=	${distfile}:sounds
.endfor

# Patch out mod_signalwire & mod_verto as they require libks that isn't available, yet.
post-patch:
		${REINPLACE_CMD} -Ee 's|^(applications/mod_signalwire)|#\1|' \
			${WRKSRC}/modules.conf
		${REINPLACE_CMD} -Ee 's|^(endpoints/mod_verto)|#\1|' \
			${WRKSRC}/modules.conf
		${REINPLACE_CMD} -Ee 's|^#(formats/mod_shout)|\1|' \
			${WRKSRC}/modules.conf

post-patch-PGSQL-off:
		${REINPLACE_CMD} -Ee 's|^(databases/mod_pgsql)|#\1|' ${WRKSRC}/modules.conf

post-install:
		${MKDIR} ${STAGEDIR}${DATADIR}/sounds
.for distfile in ${EXTRADISTFILES}
		${TAR} --cd ${STAGEDIR}${DATADIR}/sounds -xf ${DISTDIR}/${distfile}
.endfor
		${FIND} ${STAGEDIR}${DATADIR}/sounds -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}
		${RM} -r ${STAGEDIR}${ETCDIR}
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/freeswitch/mod/mod_*.so \
			${STAGEDIR}${PREFIX}/lib/libfreeswitch.so.1.0.0
		(cd ${WRKSRC}/conf && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include "${.CURDIR:H:H}/multimedia/ffmpeg6/override.mk"
.include <bsd.port.mk>
