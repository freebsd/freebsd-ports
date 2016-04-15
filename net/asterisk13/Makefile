# $FreeBSD$

PORTNAME=	asterisk
PORTVERSION=	13.8.1
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/%SUBDIR%/:main,g729
MASTER_SITE_SUBDIR=	asterisk/:main \
			asterisk/old-releases/:main \
			sounds/releases/:g729
PKGNAMESUFFIX=	13
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open Source PBX and telephony toolkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libjansson.so:devel/jansson

EXTRACT_ONLY:=	${DISTNAME}${EXTRACT_SUFX}

ONLY_FOR_ARCHS=	i386 amd64 powerpc sparc64 armv6

USES=		bison cpe gmake iconv localbase ncurses shebangfix sqlite
USE_CSTD=	gnu89
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	asterisk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datarootdir=${DATADIR} \
			--with-crypto=${OPENSSLBASE} \
			--with-ssl=${OPENSSLBASE}

CPE_VENDOR=	digium

SHEBANG_FILES=	agi/agi-test.agi \
		agi/jukebox.agi \
		contrib/scripts/astversion

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
CONFLICTS_INSTALL=	asterisk*-1.8* asterisk*-11*

OPTIONS_DEFINE=			ASTVERSION BACKTRACE CURL EXCHANGE FREETDS LDAP LUA \
				MP3PLAYER OOH323 PJSIP PORTAUDIO RADIUS SNMP \
				SPANDSP SRTP SYSINFO XMPP
OPTIONS_DEFAULT=		CURL FREETDS GSM LUA MP3PLAYER NEWT ODBC PGSQL PJSIP \
				PORTAUDIO RADIUS SNMP SPANDSP SPEEX SQLITE2 VORBIS

OPTIONS_DEFINE_i386=		DAHDI
OPTIONS_DEFINE_amd64=		DAHDI
OPTIONS_DEFINE_sparc64=		DAHDI

OPTIONS_DEFAULT_i386=		DAHDI GCC XMPP
OPTIONS_DEFAULT_amd64=		DAHDI GCC XMPP
OPTIONS_DEFAULT_sparc64=	DAHDI GCC XMPP
OPTIONS_DEFAULT_powerpc=	GCC XMPP
OPTIONS_DEFAULT_armv6=		BASE 

OPTIONS_GROUP=			CODECS
OPTIONS_GROUP_CODECS=		GSM NEWG711 SPEEX VORBIS
CODECS_DESC=			Encoder/Decoder (Codec) Support

OPTIONS_SINGLE=			COMPILER
OPTIONS_SINGLE_COMPILER=	BASE GCC
COMPILER_DESC=			Compiler to use

OPTIONS_GROUP+=			DATABASE
OPTIONS_GROUP_DATABASE=		MYSQL ODBC PGSQL SQLITE2
DATABASE_DESC=			Database Support

OPTIONS_MULTI=			MENU
OPTIONS_MULTI_MENU=		NCURSES NEWT
MENU_DESC=			Menuselect Interface Backend
NEWT_DESC=			Newt User Interface

OPTIONS_GROUP+=			SOUNDS
OPTIONS_GROUP_SOUNDS=		G729
SOUNDS_DESC=			Core and Music-on-Hold (MoH) Sound Files
G729_DESC=			Install G.729 format sounds
ASTERISK_CORE_G729_SOUNDS=	asterisk-core-sounds-en-g729-1.5.tar.gz
ASTERISK_MOH_G729_SOUNDS=	asterisk-moh-opsound-g729-2.03.tar.gz
G729_DISTFILES=			${ASTERISK_CORE_G729_SOUNDS}:g729 \
				${ASTERISK_MOH_G729_SOUNDS}:g729

ASTVERSION_DESC?= Install astversion (requires bash)
BACKTRACE_DESC?= Stack backtrace support via (lib)execinfo
BASE_DESC=	Use base compiler (experimental)
DAHDI_DESC?=	DAHDI support
EXCHANGE_DESC?=	Exchange calendar support
MP3PLAYER_DESC=	Install MP3 Player for Music-On-Hold (mpg123)
NEWG711_DESC?=	New G711 Codec
OOH323_DESC?=	ooh323 support
PJSIP_DESC?=	Build the PJSIP based SIP channel
SRTP_DESC?=	SecureRTP support
SYSINFO_DESC?=	Use devel/libsysinfo to get system information
XMPP_DESC?=	XMPP/GTALK support

OPTIONS_SUB=		yes

ASTVERSION_RUN_DEPENDS=		bash:shells/bash

BACKTRACE_CONFIGURE_WITH=	execinfo
BACKTRACE_USES=			execinfo

CURL_CONFIGURE_ON=	--with-libcurl
CURL_CONFIGURE_OFF=	--with-libcurl=no
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

DAHDI_CONFIGURE_ON=	--with-dahdi --with-openr2
DAHDI_CONFIGURE_OFF=	--without-dahdi --without-openr2
DAHDI_BUILD_DEPENDS=	libpri>=1.4.10:misc/libpri \
			${LOCALBASE}/include/dahdi/user.h:misc/dahdi
DAHDI_LIB_DEPENDS=	libpri.so:misc/libpri \
			libopenr2.so:misc/openr2

EXCHANGE_CONFIGURE_OFF=	--without-neon --without-neon29
EXCHANGE_LIB_DEPENDS=	libneon.so:www/neon

FREETDS_CONFIGURE_ON=	--with-tds=${LOCALBASE}
FREETDS_CONFIGURE_OFF=	--without-tds
FREETDS_LIB_DEPENDS=	libsybdb.so:databases/freetds

GCC_USE=		GCC=yes

GSM_CONFIGURE_WITH=	gsm
GSM_LIB_DEPENDS=	libgsm.so:audio/gsm

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua:51
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR}

MYSQL_CONFIGURE_WITH=	mysqlclient
MYSQL_USE=		MYSQL=yes

MP3PLAYER_RUN_DEPENDS=	mpg123:audio/mpg123

NCURSES_USES=		ncurses
NEWT_LIB_DEPENDS=	libnewt.so:devel/newt

ODBC_CONFIGURE_WITH=	unixodbc
ODBC_CONFIGURE_ON=	--with-ltdl
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC \
			libltdl.so:devel/libltdl

OOH323_CPPFLAGS=	-I${LOCALBASE}/include/openh323
OOH323_LIB_DEPENDS=     libpt_r.so:devel/pwlib \
			libh323_r.so:net/openh323
OOH323_MAKE_ENV=	OPENH323DIR=${LOCALBASE}/share/openh323

PGSQL_CONFIGURE_WITH=	postgres
PGSQL_USES=		pgsql

PJSIP_CONFIGURE_WITH=	pjproject
PJSIP_USES=		pkgconfig

PORTAUDIO_CONFIGURE_WITH=	portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

RADIUS_CONFIGURE_WITH=	radius
RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient

SNMP_CONFIGURE_WITH=	netsnmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

SPANDSP_CONFIGURE_WITH=	spandsp
SPANDSP_LIB_DEPENDS=	libspandsp.so:comms/spandsp

SPEEX_CONFIGURE_WITH=	speex
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex

SQLITE2_CONFIGURE_WITH=	sqlite
SQLITE2_LIB_DEPENDS=	libsqlite.so:databases/sqlite2

SRTP_CONFIGURE_WITH=	srtp

SYSINFO_LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

VORBIS_CONFIGURE_WITH=	ogg
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

XMPP_CONFIGURE_WITH=	iksemel
XMPP_LIB_DEPENDS=	libiksemel.so:textproc/iksemel

ASTERISK_USER?=		asterisk
ASTERISK_GROUP?=	asterisk

USERS=	${ASTERISK_USER}
GROUPS=	${ASTERISK_GROUP} dahdi

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPJSIP} && ${PORT_OPTIONS:MSRTP}
LIB_DEPENDS+=	libpj.so:net/pjsip-extsrtp
.elif ${PORT_OPTIONS:MPJSIP} && ! ${PORT_OPTIONS:MSRTP}
LIB_DEPENDS+=   libpj.so:net/pjsip
.elif ! ${PORT_OPTIONS:MPJSIP} && ${PORT_OPTIONS:MSRTP}
LIB_DEPENDS+=   libsrtp.so:net/libsrtp
.endif

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

.if ${PORT_OPTIONS:MG729}
	${CP} ${DISTDIR}/${ASTERISK_CORE_G729_SOUNDS} ${WRKSRC}/sounds
	${CP} ${DISTDIR}/${ASTERISK_MOH_G729_SOUNDS} ${WRKSRC}/sounds
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/samples/musiconhold.conf.sample
.if ${PORT_OPTIONS:MSYSINFO}
	@${REINPLACE_CMD} -e 's/%%LIBSYSINFO%%/-lsysinfo/' ${WRKSRC}/main/Makefile
.else
	@${REINPLACE_CMD} -e '/#define HAVE_SYSINFO 1/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/%%LIBSYSINFO%%/d' ${WRKSRC}/main/Makefile
.endif

.if exists(${FILESDIR}/.asterisk.makeopts)
USER_MAKEOPTS_FILE=${FILESDIR}/.asterisk.makeopts
.else
USER_MAKEOPTS_FILE=
.endif

post-configure:
	@cd ${WRKSRC} && ${MAKE_CMD} menuselect.makeopts USER_MAKEOPTS="${USER_MAKEOPTS_FILE}"
	@cd ${WRKSRC} && ./menuselect/menuselect --disable res_timing_kqueue menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable chan_mgcp menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable res_pktccops menuselect.makeopts
.if ${PORT_OPTIONS:MMYSQL}
	@cd ${WRKSRC} && ./menuselect/menuselect --enable res_config_mysql menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable app_mysql menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable cdr_mysql menuselect.makeopts
.endif
.if ${PORT_OPTIONS:MOOH323}
	@cd ${WRKSRC} && ./menuselect/menuselect --enable chan_ooh323 menuselect.makeopts
.endif
.if ${PORT_OPTIONS:MNEWG711}
	@cd ${WRKSRC} && ./menuselect/menuselect --enable G711_NEW_ALGORITHM menuselect.makeopts
.endif

post-install:
	@${RM} ${STAGEDIR}${ETCDIR}/*.conf ${STAGEDIR}${ETCDIR}/extensions.ael ${STAGEDIR}${ETCDIR}/extensions.lua
.if ! ${PORT_OPTIONS:MASTVERSION}
	@${RM} ${STAGEDIR}${PREFIX}/sbin/astversion
.endif
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules -type f -name '*.so' | ${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/sounds -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/moh -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}

	(cd ${STAGEDIR} && \
		${FIND} var/spool/${PORTNAME}/voicemail/default -type f | ${SED} "s,^,/," >> ${TMPPLIST} && \
		${FIND} var/spool/${PORTNAME}/voicemail/ -type d | ${SED} "s,^,@dir /," >> ${TMPPLIST});

.include <bsd.port.post.mk>
