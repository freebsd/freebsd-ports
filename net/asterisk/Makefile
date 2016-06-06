# Created by: Maxim Sobolev <sobomax@portaone.com>
# $FreeBSD$

PORTNAME=	asterisk
PORTVERSION=	1.8.32.3
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/%SUBDIR%/:DEFAULT,g729
MASTER_SITE_SUBDIR=	asterisk/ \
			asterisk/old-releases/ \
			sounds/releases/:g729
PKGNAMESUFFIX=	18
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open Source PBX and telephony toolkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

EXTRACT_ONLY:=	${DISTNAME}${EXTRACT_SUFX}

DEPRECATED=	Asterisk 1.8 reached EOL on 2015-10-21
EXPIRATION_DATE=	2016-04-30

ONLY_FOR_ARCHS=	i386 amd64 powerpc sparc64

USES=		alias bison cpe gmake shebangfix
USE_CSTD=	gnu89
USE_GCC=	yes
USE_GNOME=	libxml2
USE_OPENSSL=	yes
USE_RC_SUBR=	asterisk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-crypto=${OPENSSLBASE} \
		--with-ssl=${OPENSSLBASE}

CPE_VENDOR=	digium

SHEBANG_FILES=	agi/agi-test.agi \
		agi/jukebox.agi
STRIP=

MAKE_ENV=	PTHREAD_LIBS="-lpthread" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OSVERSION=${OSVERSION} \
		DOCSDIR=${DOCSDIR} \
		ASTCFLAGS="${CFLAGS}" \
		ASTLDFLAGS="${LDFLAGS}"
MAKE_ARGS+=	NOISY_BUILD=yes \
		ASTDATADIR=${DATADIR}

CONFLICTS_BUILD=	linuxthreads-*
CONFLICTS_INSTALL=	asterisk*-11* asterisk*-13*

OPTIONS_DEFINE=		BACKTRACE CURL EXCHANGE FREETDS H323 JABBER LUA LDAP \
			MP3PLAYER OOH323 RADIUS SNMP SPANDSP SRTP SYSINFO
OPTIONS_DEFAULT=	BACKTRACE CURL FREETDS GSM H323 JABBER LUA NEWT MYSQL ODBC \
			PGSQL RADIUS SNMP SPANDSP SPEEX SQLITE VORBIS

OPTIONS_DEFINE_i386=	DAHDI
OPTIONS_DEFINE_amd64=	DAHDI
OPTIONS_DEFINE_sparc64=	DAHDI

OPTIONS_DEFAULT_i386=		DAHDI
OPTIONS_DEFAULT_amd64=		DAHDI
OPTIONS_DEFAULT_sparc64=	DAHDI

OPTIONS_GROUP=		CODECS
OPTIONS_GROUP_CODECS=	GSM NEWG711 SPEEX VORBIS
CODECS_DESC=		Encoder/Decoder (Codec) Support

OPTIONS_GROUP+=		DATABASE
OPTIONS_GROUP_DATABASE=	MYSQL ODBC PGSQL SQLITE
DATABASE_DESC=		Database Support

OPTIONS_MULTI=		MENU
OPTIONS_MULTI_MENU=	NCURSES NEWT
MENU_DESC=		Menuselect Interface Backend
NEWT_DESC=		Newt User Interface

OPTIONS_GROUP+=		SOUNDS
OPTIONS_GROUP_SOUNDS=	G729
SOUNDS_DESC=		Core and Music-on-Hold (MoH) Sound Files
ASTERISK_CORE_G729_SOUNDS=	asterisk-core-sounds-en-g729-1.4.26.tar.gz
ASTERISK_MOH_G729_SOUNDS=	asterisk-moh-opsound-g729-2.03.tar.gz

G729_DESC=			Install G.729 format sounds
G729_DISTFILES=			${ASTERISK_CORE_G729_SOUNDS}:g729 \
				${ASTERISK_MOH_G729_SOUNDS}:g729

OPTIONS_SUB=	yes

BACKTRACE_DESC=	Stack backtrace support via (lib)execinfo
DAHDI_DESC=	Digium Asterisk Hardware Device Interface (DAHDI) support
EXCHANGE_DESC=	Exchange calendar support
MP3PLAYER_DESC=	Install MP3 Player for Music-On-Hold (mpg123)
NEWG711_DESC=	Use the NEW G.711 (ulaw/alaw) codecs (slower, but cleaner)

OOH323_DESC=	ooh323 support
SRTP_DESC=	Secure Real-time Transport Protocol (SRTP RFC3711) support
SYSINFO_DESC=	Use devel/libsysinfo to get system information

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

GSM_CONFIGURE_WITH=	gsm
GSM_LIB_DEPENDS=	libgsm.so:audio/gsm

H323_CONFIGURE_WITH=	h323
H323_CPPFLAGS=		-I${LOCALBASE}/include/openh323
H323_LIB_DEPENDS=	libpt_r.so:devel/pwlib \
			libh323_r.so:net/openh323
H323_MAKE_ENV=		OPENH323DIR=${LOCALBASE}/share/openh323

ICONV_CONFIGURE_OFF=	--with-iconv=/dev/null --with-iconv=no
ICONV_CONFIGURE_WITH=	iconv
ICONV_USES=		iconv

JABBER_CONFIGURE_WITH=	iksemel
JABBER_LIB_DEPENDS=	libiksemel.so:textproc/iksemel

ODBC_CONFIGURE_WITH=	unixodbc
ODBC_CONFIGURE_ON=	--with-ltdl
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC \
			libltdl.so:devel/libltdl

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua:51
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR}

MP3PLAYER_RUN_DEPENDS=	mpg123:audio/mpg123

MYSQL_CONFIGURE_WITH=	mysqlclient
MYSQL_USES=		mysql

NCURSES_USES=		ncurses

NEWT_LIB_DEPENDS=	libnewt.so:devel/newt

PGSQL_CONFIGURE_WITH=	postgres
PGSQL_USES=		pgsql

RADIUS_CONFIGURE_WITH=	radius
RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient

SNMP_CONFIGURE_WITH=	netsnmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex

SQLITE_CONFIGURE_WITH=	sqlite
SQLITE_CONFIGURE_OFF=	--with-sqlite3=no
SQLITE_LIB_DEPENDS=	libsqlite.so:databases/sqlite2 \
			libsqlite3.so:databases/sqlite3

VORBIS_CONFIGURE_WITH=	ogg
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

SPANDSP_CONFIGURE_WITH=	spandsp
SPANDSP_LIB_DEPENDS=	libspandsp.so:comms/spandsp

SRTP_CONFIGURE_WITH=	srtp
SRTP_BUILD_DEPENDS=	libsrtp>=1.4.4:net/libsrtp

SYSINFO_LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

PORTSCOUT=	limit:^1\.8\.

ASTERISK_USER?=		asterisk
ASTERISK_GROUP?=	asterisk

USERS=	${ASTERISK_USER}
GROUPS=	${ASTERISK_GROUP} dahdi

.include <bsd.port.pre.mk>

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
	@${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/musiconhold.conf.sample
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
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules -type f -name '*.so' | ${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/sounds -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/moh -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}

	(cd ${STAGEDIR} && \
		${FIND} var/spool/${PORTNAME}/voicemail/default -type f | ${SED} "s,^,/," >> ${TMPPLIST} && \
		${FIND} var/spool/${PORTNAME}/voicemail/ -type d | ${SED} "s,^,@dir /," >> ${TMPPLIST});

.include <bsd.port.post.mk>
