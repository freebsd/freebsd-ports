# Created by: Corey Smith <corsmith@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch
PORTVERSION=	1.6.8
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/releases/freeswitch/ \
		http://files.freeswitch.org/releases/sounds/:sounds
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	corsmith@gmail.com
COMMENT=	Multi-protocol soft switch for telephony applications

LICENSE=	MPL

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libspeex.so:audio/speex \
		libldns.so:dns/ldns \
		libopus.so:audio/opus \
		libsndfile.so:audio/libsndfile

CONFLICTS_BUILD=	xmlrpc-c-*

BROKEN_FreeBSD_9=	Fails in configure due to compiler issues
ONLY_FOR_ARCHS=	amd64

USES=		gmake jpeg pkgconfig lua perl5 libtool shebangfix tar:xz
USE_LDCONFIG=	yes

ALL_MODULES_DESC=	Build all modules
8K_DESC=	8kHz Audio Files
16K_DESC=	16kHz Audio Files
32K_DESC=	32kHz Audio Files
48K_DESC=	48kHz Audio Files
ENGLISH_DESC=	US English Language Sounds
FRENCH_DESC=	French Canadian Language Sounds
RUSSIAN_DESC=	Russian Language Sounds

OPTIONS_DEFINE=		ALL_MODULES
OPTIONS_MULTI=		BITRATE LANGUAGE
OPTIONS_MULTI_BITRATE=	8K 16K 32K 48K
OPTIONS_MULTI_LANGUAGE=	ENGLISH FRENCH RUSSIAN
OPTIONS_DEFAULT=	8K 16K ENGLISH
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=		yes

ALL_MODULES_EXTRA_PATCHES=	${FILESDIR}/extrapatch-modules.conf

GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-strip
SHEBANG_FILES=		scripts/fsxs.in
USE_RC_SUBR=		freeswitch

USERS=		${PORTNAME}
GROUPS=		${USERS}
SUB_FILES=	pkg-message

CFLAGS+=	-Wno-c11-extensions -Wno-deprecated-declarations \
		-Wno-zero-length-array -Wno-incompatible-pointer-types

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-zrtp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALL_MODULES}
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:audio/ladspa \
		${LOCALBASE}/bin/aclocal:devel/automake
RUN_DEPENDS+=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS+=	libavformat.so:multimedia/ffmpeg \
		libopencv_legacy.so:graphics/opencv \
		libhiredis.so:databases/hiredis \
		libmemcached.so:databases/libmemcached \
		libSoundTouch.so:audio/soundtouch \
		libasound.so:audio/alsa-lib \
		libportaudio.so:audio/portaudio \
		libmp4v2.so:multimedia/mp4v2 \
		libshout.so:audio/libshout \
		libmpg123.so:audio/mpg123 \
		libmp3lame.so:audio/lame \
		libnetsnmp.so:net-mgmt/net-snmp \
		libvlc.so:multimedia/vlc \
		libyaml.so:textproc/libyaml \
		libMagickWand-6.so:graphics/ImageMagick-nox11
USE_OPENLDAP=	yes
USE_OPENSSL=	yes
.endif

EDPRE=	freeswitch-sounds
EDPOST=	1.0.51.tar.gz

.if ${PORT_OPTIONS:M8K}
BITRATES+=	8000
.endif
.if ${PORT_OPTIONS:M16K}
BITRATES+=	16000
.endif
.if ${PORT_OPTIONS:M32K}
BITRATES+=	32000
.endif
.if ${PORT_OPTIONS:M48K}
BITRATES+=	48000
.endif

.for rate in ${BITRATES}
EXTRADISTFILES+=	${EDPRE}-music-${rate}-${EDPOST}
.if ${PORT_OPTIONS:MENGLISH}
EXTRADISTFILES+=	${EDPRE}-en-us-callie-${rate}-${EDPOST}
.endif
.if ${PORT_OPTIONS:MFRENCH}
EXTRADISTFILES+=	${EDPRE}-fr-ca-june-${rate}-${EDPOST}
.endif
.if ${PORT_OPTIONS:MRUSSIAN}
EXTRADISTFILES+=	${EDPRE}-ru-RU-elena-${rate}-${EDPOST}
.endif
.endfor

.for distfile in ${EXTRADISTFILES}
DISTFILES+=	${distfile}:sounds
.endfor

post-install:
		${MKDIR} ${STAGEDIR}${DATADIR}/sounds
.for distfile in ${EXTRADISTFILES}
		${TAR} --cd ${STAGEDIR}${DATADIR}/sounds -xf ${DISTDIR}/${distfile}
.endfor
		${FIND} ${STAGEDIR}${DATADIR}/sounds -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}
		${RM} -r ${STAGEDIR}${ETCDIR}
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/freeswitch/mod/mod_png.so
		(cd ${WRKSRC}/conf && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
