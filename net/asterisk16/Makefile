# $FreeBSD$

PORTNAME=	asterisk
PORTVERSION=	16.16.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://downloads.asterisk.org/pub/telephony/%SUBDIR%/:DEFAULT,g729
MASTER_SITE_SUBDIR=	asterisk/ \
			asterisk/old-releases/ \
			sounds/releases/:g729
PKGNAMESUFFIX=	16
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open Source PBX and telephony toolkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le sparc64

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libjansson.so:devel/jansson

USES=		bison compiler:c11 cpe gmake gnome iconv libedit localbase \
		shebangfix sqlite ssl ncurses
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_RC_SUBR=	asterisk
USE_GITHUB=	nodefault

EXTRACT_ONLY:=	${DISTNAME}${EXTRACT_SUFX}

PJSIP_VERSION=	2.10
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir=${DATADIR} \
		--with-ilbc=internal \
		--with-crypto=${OPENSSLBASE} \
		--with-ssl=${OPENSSLBASE} \
		--with-externals-cache=${DISTDIR}/${DIST_SUBDIR}

CPE_VENDOR=	digium

SHEBANG_FILES=	agi/agi-test.agi \
		agi/jukebox.agi \
		contrib/scripts/astversion
LDFLAGS+=	-L.
MAKE_ENV=	PTHREAD_LIBS="-lpthread" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OSVERSION=${OSVERSION} \
		DOCSDIR=${DOCSDIR} \
		ASTCFLAGS="${CFLAGS}" \
		ASTLDFLAGS="${LDFLAGS}"
MAKE_ARGS+=	NOISY_BUILD=yes \
		ASTDATADIR=${DATADIR}

CONFLICTS=		ossp-uuid-[0-9]*
CONFLICTS_BUILD=	linuxthreads-*
CONFLICTS_INSTALL=	asterisk13 asterisk18

OPTIONS_DEFINE=			ASTVERSION BACKTRACE CURL EXCHANGE FREETDS G729 LDAP LUA MACRO \
				MP3PLAYER OOH323 OPTIMIZED_CFLAGS PJSIP PORTAUDIO RADIUS SNMP \
				SPANDSP SRTP SYSINFO URIPARSER XMLDOC XMPP
OPTIONS_DEFAULT=		CURL FREETDS GSM LUA MACRO MP3PLAYER NEWT ODBC OPUS MYSQL PGSQL \
				PJSIP PORTAUDIO RADIUS SNMP SPANDSP SPEEX SRTP URIPARSER \
				VORBIS XMLDOC

OPTIONS_DEFINE_i386=		DAHDI
OPTIONS_DEFINE_amd64=		DAHDI
OPTIONS_DEFINE_sparc64=		DAHDI

OPTIONS_DEFAULT_i386=		DAHDI XMPP
OPTIONS_DEFAULT_amd64=		DAHDI XMPP
OPTIONS_DEFAULT_sparc64=	DAHDI XMPP
OPTIONS_DEFAULT_powerpc=	XMPP

OPTIONS_GROUP=			CODECS
OPTIONS_GROUP_CODECS=		GSM NEWG711 OPUS SPEEX VORBIS
CODECS_DESC=			Encoder/Decoder (Codec) Support

OPTIONS_GROUP+=			DATABASE
OPTIONS_GROUP_DATABASE=		MYSQL ODBC PGSQL
DATABASE_DESC=			Database Support

OPTIONS_MULTI=			MENU
OPTIONS_MULTI_MENU=		NCURSES NEWT
MENU_DESC=			Menuselect Interface Backend
NEWT_DESC=			Newt User Interface

ASTERISK_CORE_G729_SOUNDS=	asterisk-core-sounds-en-g729-1.5.tar.gz
ASTERISK_MOH_G729_SOUNDS=	asterisk-moh-opsound-g729-2.03.tar.gz
G729_DISTFILES=			${ASTERISK_CORE_G729_SOUNDS}:g729 \
				${ASTERISK_MOH_G729_SOUNDS}:g729

ASTVERSION_DESC?= Install astversion (requires bash)
BACKTRACE_DESC?= Stack backtrace support via (lib)execinfo
DAHDI_DESC?=	DAHDI support
EXCHANGE_DESC?=	Exchange calendar support
G729_DESC?=	Install G.729 format sounds for Music-on-Hold (MoH)
MACRO_DESC?=	Enable app_macro (deprecated)
MP3PLAYER_DESC=	Install MP3 Player for Music-On-Hold (mpg123)
NEWG711_DESC?=	New G711 Codec
OOH323_DESC?=	ooh323 support
OPUS_DESC?=	Opus Codec
PJSIP_DESC?=	Build the PJSIP based SIP channel
SRTP_DESC?=	SecureRTP support
SYSINFO_DESC?=	Use devel/libsysinfo to get system information
URIPARSER_DESC?= Use RFC 3986 compliant uriparser library
XMLDOC_DESC?=	Build and install XML documentation
XMPP_DESC?=	XMPP/GTALK support

OPTIONS_SUB=		yes

ASTVERSION_RUN_DEPENDS=		bash:shells/bash

BACKTRACE_CONFIGURE_WITH=	execinfo

CURL_CONFIGURE_WITH=	libcurl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

DAHDI_CONFIGURE_WITH=	dahdi openr2
DAHDI_LIB_DEPENDS=	libpri.so:misc/libpri \
			libopenr2.so:misc/openr2 \
			libtonezone.so:misc/dahdi

EXCHANGE_CONFIGURE_OFF=	--without-neon --without-neon29
EXCHANGE_LIB_DEPENDS=	libneon.so:www/neon \
			libexpat.so:textproc/expat2
EXCHANGE_USES=		gettext-runtime

FREETDS_CONFIGURE_ON=	--with-tds=${LOCALBASE}
FREETDS_CONFIGURE_OFF=	--without-tds
FREETDS_LIB_DEPENDS=	libsybdb.so:databases/freetds

GSM_CONFIGURE_WITH=	gsm
GSM_LIB_DEPENDS=	libgsm.so:audio/gsm

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR}

MYSQL_CONFIGURE_WITH=	mysqlclient
MYSQL_USES=		mysql

MP3PLAYER_RUN_DEPENDS=	mpg123:audio/mpg123

NCURSES_USES=		ncurses
NEWT_LIB_DEPENDS=	libnewt.so:devel/newt

ODBC_CONFIGURE_WITH=	unixodbc
ODBC_CONFIGURE_ON=	--with-ltdl
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC \
			libltdl.so:devel/libltdl

OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_EXTRACT_ONLY=	${DISTFILE_opus}
OPUS_GH_TUPLE=		traud:asterisk-opus:83e1b458c77e0e287adeca494eeb79edb077b0ff:opus

PGSQL_CONFIGURE_WITH=	postgres
PGSQL_USES=		pgsql

PJSIP_CONFIGURE_WITH=	pjproject pjproject-bundled
PJSIP_USES=		pkgconfig
PJSIP_LIB_DEPENDS=	libsrtp2.so:net/libsrtp2 \
			libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp
PJSIP_GH_TUPLE=		pjsip:pjproject:${PJSIP_VERSION}:pjsip

PORTAUDIO_CONFIGURE_WITH=	portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

RADIUS_CONFIGURE_WITH=	radius
RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient

SNMP_CONFIGURE_WITH=	netsnmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp \
			libpkg.so:${PKG_ORIGIN}

SPANDSP_CONFIGURE_WITH=	spandsp
SPANDSP_LIB_DEPENDS=	libspandsp.so:comms/spandsp \
			libtiff.so:graphics/tiff

SPEEX_CONFIGURE_WITH=	speex
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp

SRTP_CONFIGURE_WITH=	srtp
SRTP_LIB_DEPENDS=	libsrtp2.so:net/libsrtp2

SYSINFO_LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

URIPARSER_CONFIGURE_WITH=	uriparser
URIPARSER_LIB_DEPENDS=	liburiparser.so:net/uriparser

VORBIS_CONFIGURE_WITH=	ogg
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg

XMLDOC_CONFIGURE_ENABLE=	xmldoc

XMPP_CONFIGURE_WITH=	iksemel
XMPP_LIB_DEPENDS=	libiksemel.so:textproc/iksemel

ASTERISK_USER?=		asterisk
ASTERISK_GROUP?=	asterisk

USERS=	${ASTERISK_USER}
GROUPS=	${ASTERISK_GROUP} dahdi

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv_open=no \
		ac_cv_lib_iconv_libiconv_open=no
.endif

.if ${PREFIX} == ${LOCALBASE}
VARDIR=/var
.else
VARDIR=${PREFIX}/var
.endif

SUB_LIST+=	ASTERISK_USER=${ASTERISK_USER}
PLIST_SUB+=	ASTERISK_USER=${ASTERISK_USER} \
		ASTERISK_GROUP=${ASTERISK_GROUP} \
		VARDIR=${VARDIR}

post-extract:
	@${FIND} ${WRKSRC} -name '*.d' -delete

post-extract-G729-on:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${ASTERISK_CORE_G729_SOUNDS} ${WRKSRC}/sounds
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${ASTERISK_MOH_G729_SOUNDS} ${WRKSRC}/sounds

post-extract-OPUS-on:
	${CP} ${WRKSRC_opus}/include/asterisk/* ${WRKSRC}/include/asterisk
	${CP} ${WRKSRC_opus}/codecs/* ${WRKSRC}/codecs
	${CP} ${WRKSRC_opus}/res/* ${WRKSRC}/res

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/samples/musiconhold.conf.sample
.if exists(${FILESDIR}/.asterisk.makeopts)
	${CP} ${FILESDIR}/.asterisk.makeopts ${WRKSRC}/menuselect.makeopts
.endif

post-patch-SYSINFO-on:
	@${REINPLACE_CMD} -e 's/%%LIBSYSINFO%%/-lsysinfo/' ${WRKSRC}/main/Makefile

post-patch-SYSINFO-off:
	@${REINPLACE_CMD} -e '/#define HAVE_SYSINFO 1/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/%%LIBSYSINFO%%/d' ${WRKSRC}/main/Makefile

post-configure:
	@cd ${WRKSRC} && ${MAKE_CMD} menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --disable res_timing_kqueue menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable chan_mgcp menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable res_pktccops menuselect.makeopts

post-configure-MACRO-on:
	@cd ${WRKSRC} && ./menuselect/menuselect --enable app_macro menuselect.makeopts

post-configure-MYSQL-on:
	@cd ${WRKSRC} && ./menuselect/menuselect --enable res_config_mysql menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable app_mysql menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable cdr_mysql menuselect.makeopts

post-configure-OOH323-on:
	@cd ${WRKSRC} && ./menuselect/menuselect --enable chan_ooh323 menuselect.makeopts

post-configure-NEWG711-on:
	@cd ${WRKSRC} && ./menuselect/menuselect --enable G711_NEW_ALGORITHM menuselect.makeopts

post-configure-OPTIMIZED_CFLAGS-off:
	@cd ${WRKSRC} && ./menuselect/menuselect --disable BUILD_NATIVE menuselect.makeopts

post-configure-OPUS-on:
	@cd ${WRKSRC} && ./menuselect/menuselect --enable codec_opus_open_source menuselect.makeopts

post-install:
	@${RM} ${STAGEDIR}${ETCDIR}/*.conf ${STAGEDIR}${ETCDIR}/extensions.ael ${STAGEDIR}${ETCDIR}/extensions.lua
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/ast[a-f]* ${STAGEDIR}${PREFIX}/lib/*.so.* ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules/*.so ${STAGEDIR}${DATADIR}/agi-bin/eagi-*
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules -type f -name '*.so' | ${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/sounds -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/moh -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}

	(cd ${STAGEDIR} && \
		${ECHO} "@owner ${ASTERISK_USER}" >> ${TMPPLIST} && \
		${ECHO} "@group ${ASTERISK_GROUP}" >> ${TMPPLIST} && \
		${FIND} var/spool/${PORTNAME}/voicemail/default -type f | ${SED} "s,^,/," >> ${TMPPLIST} && \
		${FIND} var/spool/${PORTNAME}/voicemail/ -type d | ${SED} "s,^,@dir /," >> ${TMPPLIST} && \
		${ECHO} "@owner" >> ${TMPPLIST} && \
		${ECHO} "@group" >> ${TMPPLIST});

post-install-ASTVERSION-off:
	@${RM} ${STAGEDIR}${PREFIX}/sbin/astversion

.include <bsd.port.post.mk>
