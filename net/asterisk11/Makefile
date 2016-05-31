# $FreeBSD$

PORTNAME=	asterisk
PORTVERSION=	11.22.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/%SUBDIR%/:main,g729
MASTER_SITE_SUBDIR=	asterisk/:main \
			asterisk/old-releases/:main \
			sounds/releases/:g729
PKGNAMESUFFIX=	11
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open Source PBX and telephony toolkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

EXTRACT_ONLY:=	${DISTNAME}${EXTRACT_SUFX}

ONLY_FOR_ARCHS=	i386 amd64 powerpc sparc64 armv6

USES=		bison cpe gmake iconv localbase ncurses shebangfix sqlite
USE_CSTD=	gnu89
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	asterisk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-crypto=${OPENSSLBASE} \
			--with-ssl=${OPENSSLBASE}

CPE_VENDOR=	digium

SHEBANG_FILES=	agi/agi-test.agi \
		agi/jukebox.agi

MAKE_ENV=	PTHREAD_LIBS="-lpthread" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OSVERSION=${OSVERSION} \
		DOCSDIR=${DOCSDIR} \
		ASTCFLAGS="${CFLAGS}" \
		ASTLDFLAGS="${LDFLAGS}"
MAKE_ARGS+=	NOISY_BUILD=yes \
		ASTDATADIR=${DATADIR}

CONFLICTS_BUILD=	linuxthreads-* pjsip-*
CONFLICTS_INSTALL=	asterisk*-1.8* asterisk*-13*

OPTIONS_DEFINE=			BACKTRACE CURL EXCHANGE FREETDS LDAP LUA \
				MP3PLAYER OOH323 RADIUS SNMP SPANDSP SRTP \
				SYSINFO UUID XMPP
OPTIONS_DEFAULT=		BACKTRACE CURL FREETDS GSM LUA MP3PLAYER \
				NEWT MYSQL ODBC PGSQL RADIUS SNMP SPANDSP SPEEX \
				SQLITE2 UUID VORBIS

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
ASTERISK_CORE_G729_SOUNDS=	asterisk-core-sounds-en-g729-1.5.tar.gz
ASTERISK_MOH_G729_SOUNDS=	asterisk-moh-opsound-g729-2.03.tar.gz

G729_DESC=			Install G.729 format sounds
G729_DISTFILES=			${ASTERISK_CORE_G729_SOUNDS}:g729 \
				${ASTERISK_MOH_G729_SOUNDS}:g729

BACKTRACE_DESC= Stack backtrace support via (lib)execinfo
BASE_DESC=	Use base compiler (experimental)
DAHDI_DESC=	DAHDI support
EXCHANGE_DESC=	Exchange calendar support
MP3PLAYER_DESC=	Install MP3 Player for Music-On-Hold (mpg123)
NEWG711_DESC=	New G711 codec
OOH323_DESC=	ooh323 support
SRTP_DESC=	SecureRTP support
SYSINFO_DESC=	Use devel/libsysinfo to get system information
UUID_DESC=	libuuid support (required for ICE and TURN in RTP)
XMPP_DESC=	XMPP/GTALK support

OPTIONS_SUB=		yes

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
MYSQL_USES=		mysql

MP3PLAYER_RUN_DEPENDS=	mpg123:audio/mpg123

NCURSES_USES=		ncurses
NEWT_LIB_DEPENDS=	libnewt.so:devel/newt

ODBC_CONFIGURE_WITH=	unixodbc
ODBC_CONFIGURE_ON=	--with-ltdl
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC \
			libltdl.so:devel/libltdl

OOH323_CPPFLAGS=	-I${LOCALBASE}/include/openh323
OOH323_LIB_DEPENDS=	libpt_r.so:devel/pwlib \
			libh323_r.so:net/openh323
OOH323_MAKE_ENV=	OPENH323DIR=${LOCALBASE}/share/openh323

PGSQL_CONFIGURE_WITH=	postgres
PGSQL_USES=		pgsql

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
SRTP_BUILD_DEPENDS=	libsrtp>=1.4.4:net/libsrtp

SYSINFO_LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

UUID_LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid
UUID_CONFIGURE_ON=	--with-uuid=${LOCALBASE}
UUID_CONFIGURE_OFF=	--disable-uuid
UUID_CONFLICTS=		ossp-uuid-[0-9]*

VORBIS_CONFIGURE_WITH=	ogg
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

XMPP_CONFIGURE_WITH=	iksemel
XMPP_LIB_DEPENDS=	libiksemel.so:textproc/iksemel

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
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure
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

pre-build:
	@${MKDIR} ${WRKSRC}/res/pjproject/pjnath/lib ${WRKSRC}/res/pjproject/pjlib-util/lib \
		${WRKSRC}/res/pjproject/pjlib/lib

post-install:
	@${RM} ${STAGEDIR}${ETCDIR}/*.conf ${STAGEDIR}${ETCDIR}/extensions.ael ${STAGEDIR}${ETCDIR}/extensions.lua
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules -type f -name '*.so' | ${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/sounds -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/moh -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}

	(cd ${STAGEDIR} && \
		${FIND} var/spool/${PORTNAME}/voicemail/default -type f | ${SED} "s,^,/," >> ${TMPPLIST} && \
		${FIND} var/spool/${PORTNAME}/voicemail/ -type d | ${SED} "s,^,@dir /," >> ${TMPPLIST});

.include <bsd.port.post.mk>
