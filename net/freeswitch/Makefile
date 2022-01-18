# Created by: Corey Smith <corsmith@gmail.com>

PORTNAME=	freeswitch
PORTVERSION=	1.10.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://files.freeswitch.org/releases/freeswitch/ \
		https://files.freeswitch.org/releases/sounds/:sounds
DISTFILES=	${PORTNAME}-${PORTVERSION}.-release${EXTRACT_SUFX}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Multi-protocol soft switch for telephony applications

LICENSE=	MPL11

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	gdiff:textproc/diffutils
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libcurl.so:ftp/curl \
		libavformat.so:multimedia/ffmpeg \
		libpcre.so:devel/pcre \
		libspeexdsp.so:audio/speexdsp \
		libspeex.so:audio/speex \
		libldns.so:dns/ldns \
		libopus.so:audio/opus \
		libsndfile.so:audio/libsndfile \
		libfreetype.so:print/freetype2 \
		libodbc.so:databases/unixODBC \
		libpng.so:graphics/png \
		libjbig.so:graphics/jbigkit \
		libtiff.so:graphics/tiff \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		compiler:c11 cpe gmake iconv jpeg libedit autoreconf libtool lua \
		perl5 pkgconfig shebangfix ssl
USE_LDCONFIG=	yes
USE_RC_SUBR=	freeswitch
BINARY_ALIAS=	diff=gdiff
MAKE_JOBS_UNSAFE=yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.-release

SHEBANG_FILES=	scripts/fsxs.in

CONFLICTS_BUILD=	xmlrpc-c

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-zrtp
CFLAGS+=	-Wno-error -I${LUA_INCDIR}

USERS=		${PORTNAME}
GROUPS=		${USERS}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		X11 EXAMPLES PGSQL
OPTIONS_DEFAULT=	8K 16K ENGLISH PGSQL
OPTIONS_MULTI=		BITRATE LANGUAGE
OPTIONS_MULTI_BITRATE=	8K 16K 32K 48K
OPTIONS_MULTI_LANGUAGE=	CHINESE_HK CHINESE_SIM BRAZILIAN ENGLISH ENGLISH_CA FRENCH_CA RUSSIAN SWEDISH
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

X11_DESC=		graphics/ImageMagick[-nox11] dependency
8K_DESC=		8kHz Audio Files
16K_DESC=		16kHz Audio Files
32K_DESC=		32kHz Audio Files
48K_DESC=		48kHz Audio Files
BRAZILIAN_DESC=		Brazilian Portuguese Language Sounds
CHINESE_HK_DESC=	Chinese Traditional Language Sounds
CHINESE_SIM_DESC=	Chinese Simplified Language Sounds
ENGLISH_DESC=		US English Language Sounds
ENGLISH_CA_DESC=	Canadian English Language Sounds
FRENCH_CA_DESC=		French Canadian Language Sounds
RUSSIAN_DESC=		Russian Language Sounds
SWEDISH_DESC=		Swedish Language Sounds

8K_VARS=	BITRATES+=8000
16K_VARS=	BITRATES+=16000
32K_VARS=	BITRATES+=32000
48K_VARS=	BITRATES+=48000

PGSQL_USES=	pgsql
PGSQL_CONFIGURE_ENABLE=	core-pgsql-support core-pgsql-pkgconfig
PGSQL_CONFIGURE_ENV_OFF=	ac_cv_lib_pq_PQgetvalue=false

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
EXTRADISTFILES+=	${EDPRE}-en-us-callie-${rate}-${EDPOST}
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

# Patch out mod_signalwire as it requires libks that isn't available, yet.
post-patch:
		${REINPLACE_CMD} -Ee 's|^(applications/mod_signalwire)|#\1|' \
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

.include <bsd.port.mk>
