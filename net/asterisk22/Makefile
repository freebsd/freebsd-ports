PORTNAME=	asterisk
DISTVERSION=	22.4.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://downloads.asterisk.org/pub/telephony/%SUBDIR%/:DEFAULT,g729
MASTER_SITE_SUBDIR=	asterisk/ \
			asterisk/old-releases/ \
			sounds/releases/:g729
PKGNAMESUFFIX=	22
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${ASTERISK_CORE_G729_SOUNDS}:g729 \
		${ASTERISK_MOH_G729_SOUNDS}:g729
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	o.kryvulia@flex-it.com.ua
COMMENT=	Open Source PBX and telephony toolkit
WWW=		https://www.asterisk.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libuuid.so:misc/libuuid

USES=		bison compiler:c11 cpe gmake gnome iconv libedit localbase \
		ncurses pkgconfig shebangfix sqlite ssl
CPE_VENDOR=	digium
USE_GITHUB=	nodefault
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_RC_SUBR=	asterisk

SHEBANG_FILES=	agi/agi-test.agi \
		agi/jukebox.agi \
		contrib/scripts/astversion \
		contrib/scripts/ast_coredumper

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir=${DATADIR} \
		--with-crypto=${OPENSSLBASE} \
		--with-externals-cache=${DISTDIR}/${DIST_SUBDIR} \
		--with-ilbc=internal \
		--with-ssl=${OPENSSLBASE}

MAKE_ARGS+=	ASTDATADIR=${DATADIR} \
		NOISY_BUILD=yes
MAKE_ENV=	ASTCFLAGS="${CFLAGS}" \
		ASTLDFLAGS="${LDFLAGS}" \
		DOCSDIR=${DOCSDIR} \
		MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION} \
		PTHREAD_LIBS="-lpthread" \
		PWLIBDIR=${LOCALBASE}/share/pwlib

LDFLAGS+=	-L. -Wl,--undefined-version

CONFLICTS=		ossp-uuid
CONFLICTS_BUILD=	linuxthreads
CONFLICTS_INSTALL=	asterisk18 asterisk20

USERS=	${ASTERISK_USER}
GROUPS=	${ASTERISK_GROUP} dahdi

OPTIONS_DEFINE=			ASTVERSION BACKTRACE CURL EXCHANGE FREETDS G729 LDAP LUA \
				MP3PLAYER OOH323 OPTIMIZED_CFLAGS PJSIP PORTAUDIO RADIUS SNMP \
				SPANDSP SRTP SYSINFO URIPARSER XMLDOC XMPP
OPTIONS_DEFINE_aarch64=		GEOLOCATION
OPTIONS_DEFINE_amd64=		DAHDI GEOLOCATION
OPTIONS_DEFINE_i386=		DAHDI GEOLOCATION
OPTIONS_DEFINE_powerpc=		DAHDI
OPTIONS_DEFINE_powerpc64=	DAHDI
OPTIONS_DEFINE_powerpc64le=	DAHDI
OPTIONS_DEFAULT=		CURL FREETDS GSM LUA MP3PLAYER NEWT ODBC OPUS MYSQL PGSQL \
				PJSIP PORTAUDIO RADIUS SNMP SPANDSP SPEEX SRTP URIPARSER \
				VORBIS XMLDOC
OPTIONS_DEFAULT_amd64=		DAHDI XMPP
OPTIONS_DEFAULT_i386=		DAHDI XMPP
OPTIONS_DEFAULT_powerpc=	DAHDI XMPP
OPTIONS_DEFAULT_powerpc64=	DAHDI XMPP
OPTIONS_DEFAULT_powerpc64le=	DAHDI XMPP

OPTIONS_GROUP=			CODECS DATABASE
OPTIONS_GROUP_CODECS=		GSM NEWG711 OPUS SPEEX VORBIS
OPTIONS_GROUP_DATABASE=		MYSQL ODBC PGSQL

OPTIONS_MULTI=			MENU
OPTIONS_MULTI_MENU=		NCURSES NEWT
OPTIONS_SUB=		yes

ASTVERSION_DESC=	Install astversion (requires bash)
BACKTRACE_DESC=	Stack backtrace support via (lib)execinfo
CODECS_DESC=	Encoder/Decoder (Codec) Support
DAHDI_DESC=	DAHDI support
DATABASE_DESC=	Database Support
EXCHANGE_DESC=	Exchange calendar support
G729_DESC=	Install G.729 format sounds for Music-on-Hold (MoH)
GEOLOCATION_DESC=	Enable SIP Geolocation support
MENU_DESC=	Menuselect Interface Backend
MP3PLAYER_DESC=	Install MP3 Player for Music-On-Hold (mpg123)
NEWG711_DESC=	New G711 Codec
NEWT_DESC=	Newt User Interface
OOH323_DESC=	ooh323 support
OPUS_DESC=	Opus Codec
PJSIP_DESC=	Build the PJSIP based SIP channel
SRTP_DESC=	SecureRTP support
SYSINFO_DESC=	Use devel/libsysinfo to get system information
URIPARSER_DESC=	Use RFC 3986 compliant uriparser library
XMLDOC_DESC=	Build and install XML documentation
XMPP_DESC=	XMPP/GTALK support

ASTVERSION_RUN_DEPENDS=	bash:shells/bash

BACKTRACE_CONFIGURE_WITH=	execinfo

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl

DAHDI_LIB_DEPENDS=	libpri.so:misc/libpri \
			libopenr2.so:misc/openr2 \
			libtonezone.so:misc/dahdi
DAHDI_CONFIGURE_WITH=	dahdi openr2

EXCHANGE_LIB_DEPENDS=	libexpat.so:textproc/expat2 \
			libneon.so:www/neon
EXCHANGE_USES=		gettext-runtime
EXCHANGE_CONFIGURE_OFF=	--without-neon --without-neon29

FREETDS_LIB_DEPENDS=	libsybdb.so:databases/freetds
FREETDS_CONFIGURE_ON=	--with-tds=${LOCALBASE}
FREETDS_CONFIGURE_OFF=	--without-tds

GEOLOCATION_USE=	GNOME=libxslt

GSM_LIB_DEPENDS=	libgsm.so:audio/gsm
GSM_CONFIGURE_WITH=	gsm

LDAP_USES=		ldap
LDAP_CONFIGURE_WITH=	ldap

LUA_USES=		lua
LUA_CONFIGURE_WITH=	lua
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR}

MP3PLAYER_RUN_DEPENDS=	mpg123:audio/mpg123

MYSQL_LIB_DEPENDS=	libzstd.so:archivers/zstd \
			libunwind.so:devel/libunwind
MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysqlclient

NCURSES_USES=		ncurses

NEWT_LIB_DEPENDS=	libnewt.so:devel/newt

ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC \
			libltdl.so:devel/libltdl
ODBC_CONFIGURE_ON=	--with-ltdl
ODBC_CONFIGURE_WITH=	unixodbc

OPUS_EXTRACT_ONLY=	${DISTFILE_opus}
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_GH_TUPLE=		traud:asterisk-opus:83e1b458c77e0e287adeca494eeb79edb077b0ff:opus

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgres

PJSIP_LIB_DEPENDS=	libsrtp2.so:net/libsrtp2 \
			libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp
PJSIP_GH_TUPLE=		pjsip:pjproject:${PJSIP_VERSION}:pjsip
PJSIP_CONFIGURE_WITH=	pjproject pjproject-bundled

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_WITH=	portaudio

RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient
RADIUS_CONFIGURE_WITH=	radius

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp \
			libpkg.so:${PKG_ORIGIN}
SNMP_CONFIGURE_WITH=	netsnmp

SPANDSP_LIB_DEPENDS=	libspandsp.so:comms/spandsp \
			libtiff.so:graphics/tiff
SPANDSP_CONFIGURE_WITH=	spandsp

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp
SPEEX_CONFIGURE_WITH=	speex

SRTP_LIB_DEPENDS=	libsrtp2.so:net/libsrtp2
SRTP_CONFIGURE_WITH=	srtp

SYSINFO_LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

URIPARSER_LIB_DEPENDS=	liburiparser.so:net/uriparser
URIPARSER_CONFIGURE_WITH=	uriparser

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CONFIGURE_WITH=	ogg

XMLDOC_CONFIGURE_ENABLE=	xmldoc

XMPP_LIB_DEPENDS=	libiksemel.so:textproc/iksemel
XMPP_CONFIGURE_WITH=	iksemel

ASTERISK_CORE_G729_SOUNDS=	asterisk-core-sounds-en-g729-1.6.tar.gz
ASTERISK_MOH_G729_SOUNDS=	asterisk-moh-opsound-g729-2.03.tar.gz

ASTERISK_USER=	asterisk
ASTERISK_GROUP=	asterisk

PJSIP_VERSION=	2.15.1

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500026
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-third-party_pjproject_Makefile
.endif

.if (${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base) || \
	${SSL_DEFAULT:Mopenssl3*}
LIB_DEPENDS+=	libgnutls.so:security/gnutls
CFLAGS+=	-DOPENSSL_API_COMPAT=0x10100000L
LDFLAGS+=	-lgnutls
.endif

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=	ac_cv_lib_iconv_iconv_open=no \
			ac_cv_lib_iconv_libiconv_open=no
.endif

.if ${PREFIX} == ${LOCALBASE}
VARDIR=		/var
.else
VARDIR=		${PREFIX}/var
.endif

SUB_LIST+=	ASTERISK_USER=${ASTERISK_USER}
PLIST_SUB+=	ASTERISK_GROUP=${ASTERISK_GROUP} \
		ASTERISK_USER=${ASTERISK_USER} \
		VARDIR=${VARDIR}

.if ${PORT_OPTIONS:MGEOLOCATION}
.if ${ARCH} == i386
LLD_EMULATION=	elf_i386
.elif ${ARCH} == amd64
LLD_EMULATION=	elf_x86_64
.elif ${ARCH} == aarch64
LLD_EMULATION=	aarch64elf
.endif
.endif

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
	@${REINPLACE_CMD} -e 's/@XMLSTARLET@//' ${WRKSRC}/makeopts.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/main/term.c
.if exists(${FILESDIR}/.asterisk.makeopts)
	${CP} ${FILESDIR}/.asterisk.makeopts ${WRKSRC}/menuselect.makeopts
.endif

post-patch-GEOLOCATION-on:
	@${REINPLACE_CMD} -e 's/%%LLD_EMULATION%%/${LLD_EMULATION}/' ${WRKSRC}/Makefile.rules

post-patch-SYSINFO-on:
	@${REINPLACE_CMD} -e 's/%%LIBSYSINFO%%/-lsysinfo/' ${WRKSRC}/main/Makefile

post-patch-SYSINFO-off:
	@${REINPLACE_CMD} -e '/#define HAVE_SYSINFO 1/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/%%LIBSYSINFO%%/d' ${WRKSRC}/main/Makefile

post-configure:
	@cd ${WRKSRC} && ${MAKE_CMD} menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --disable res_timing_kqueue menuselect.makeopts

post-configure-GEOLOCATION-on:
	@cd ${WRKSRC} && ./menuselect/menuselect --enable res_geolocation menuselect.makeopts

post-configure-GEOLOCATION-off:
	@cd ${WRKSRC} && ./menuselect/menuselect --disable res_geolocation menuselect.makeopts

post-configure-MYSQL-on:
	@cd ${WRKSRC} && ./menuselect/menuselect --enable res_config_mysql menuselect.makeopts

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
