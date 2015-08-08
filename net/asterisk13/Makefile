# $FreeBSD$

PORTNAME=	asterisk
PORTVERSION=	13.5.0
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/
PKGNAMESUFFIX=	13

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open Source PBX and telephony toolkit

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libjansson.so:${PORTSDIR}/devel/jansson
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

ONLY_FOR_ARCHS=	i386 amd64 powerpc sparc64

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USES=		bison cpe gmake iconv localbase ncurses shebangfix
CPE_VENDOR=	digium
USE_RC_SUBR=	asterisk
MAKE_ENV=	PTHREAD_LIBS="-lpthread" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OSVERSION=${OSVERSION} \
		DOCSDIR=${DOCSDIR} \
		ASTCFLAGS="${CFLAGS}"
MAKE_ARGS+=	NOISY_BUILD=YES
CONFIGURE_ARGS+=	--datarootdir=${DATADIR} \
			--with-crypto=${OPENSSLBASE} \
			--with-ssl=${OPENSSLBASE}

SHEBANG_FILES=	agi/agi-test.agi \
		agi/jukebox.agi

CONFLICTS=		ossp-uuid-[0-9]*
CONFLICTS_BUILD=	linuxthreads-*
CONFLICTS_INSTALL=	asterisk*-1.8* asterisk*-11*

OPTIONS_DEFINE=			CURL EXCHANGE FREETDS GSM LDAP LUA MYSQL \
				NEWG711 ODBC OOH323 PGSQL PJSIP PORTAUDIO \
				RADIUS SNMP SPANDSP SPEEX SQLITE2 SRTP \
				SYSINFO VORBIS XMPP

OPTIONS_SINGLE=			COMPILER
OPTIONS_SINGLE_COMPILER=	BASE GCC
OPTIONS_DEFAULT=		CURL FREETDS GCC GSM LUA ODBC PGSQL PJSIP \
				PORTAUDIO RADIUS SNMP SPEEX SQLITE2 VORBIS \
				XMPP

OPTIONS_DEFINE_i386=		DAHDI
OPTIONS_DEFINE_amd64=		DAHDI
OPTIONS_DEFINE_sparc64=		DAHDI

OPTIONS_DEFAULT_i386=		DAHDI
OPTIONS_DEFAULT_amd64=		DAHDI
OPTIONS_DEFAULT_sparc64=	DAHDI

BASE_DESC=	Use base compiler (experimental)
DAHDI_DESC?=	DAHDI support
EXCHANGE_DESC?=	Exchange calendar support
GCC_DESC=	Use gcc from ports
NEWG711_DESC?=	New G711 Codec
OOH323_DESC?=	ooh323 support
PJSIP_DESC?=	Build the PJSIP based SIP channel
SRTP_DESC?=	SecureRTP support
SYSINFO_DESC?=	Use devel/libsysinfo to get system information
XMPP_DESC?=	XMPP/GTALK support

OPTIONS_SUB=		yes

CURL_CONFIGURE_ON=	--with-libcurl
CURL_CONFIGURE_OFF=	--with-libcurl=no
CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

DAHDI_CONFIGURE_ON=	--with-dahdi --with-openr2
DAHDI_CONFIGURE_OFF=	--without-dahdi --without-openr2
DAHDI_BUILD_DEPENDS=	libpri>=1.4.10:${PORTSDIR}/misc/libpri \
			${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi
DAHDI_LIB_DEPENDS=	libpri.so:${PORTSDIR}/misc/libpri \
			libopenr2.so:${PORTSDIR}/misc/openr2

EXCHANGE_CONFIGURE_OFF=	--without-neon --without-neon29
EXCHANGE_LIB_DEPENDS=	libneon.so:${PORTSDIR}/www/neon

FREETDS_CONFIGURE_ON=	--with-tds=${LOCALBASE}
FREETDS_CONFIGURE_OFF=	--without-tds
FREETDS_LIB_DEPENDS=	libsybdb.so:${PORTSDIR}/databases/freetds

GCC_USE=		GCC=yes

GSM_CONFIGURE_WITH=	gsm
GSM_LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua:51
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR}

MYSQL_CONFIGURE_WITH=	mysqlclient
MYSQL_USE=		MYSQL=yes

ODBC_CONFIGURE_WITH=	unixodbc
ODBC_CONFIGURE_ON=	--with-ltdl
ODBC_LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC \
			libltdl.so:${PORTSDIR}/devel/libltdl

OOH323_CPPFLAGS=	-I${LOCALBASE}/include/openh323
OOH323_LIB_DEPENDS=     libpt_r.so:${PORTSDIR}/devel/pwlib \
			libh323_r.so:${PORTSDIR}/net/openh323
OOH323_MAKE_ENV=	OPENH323DIR=${LOCALBASE}/share/openh323

PGSQL_CONFIGURE_WITH=	postgres
PGSQL_USES=		pgsql

PJSIP_CONFIGURE_WITH=	pjproject
PJSIP_USES=		pkgconfig

PORTAUDIO_CONFIGURE_WITH=	portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:${PORTSDIR}/audio/portaudio

RADIUS_CONFIGURE_WITH=	radius
RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:${PORTSDIR}/net/radiusclient

SNMP_CONFIGURE_WITH=	netsnmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp

SPANDSP_CONFIGURE_WITH=	spandsp
SPANDSP_LIB_DEPENDS=	libspandsp.so:${PORTSDIR}/comms/spandsp

SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_CONFIGURE_WITH=	speex

SQLITE2_CONFIGURE_WITH=	sqlite
SQLITE2_LIB_DEPENDS=	libsqlite.so:${PORTSDIR}/databases/sqlite2

SRTP_CONFIGURE_WITH=	srtp

SYSINFO_LIB_DEPENDS=	libsysinfo.so:${PORTSDIR}/devel/libsysinfo

VORBIS_CONFIGURE_WITH=	ogg
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

XMPP_CONFIGURE_WITH=	iksemel
XMPP_LIB_DEPENDS=	libiksemel.so:${PORTSDIR}/textproc/iksemel

ASTERISK_USER?=		asterisk
ASTERISK_GROUP?=	asterisk

USERS=	${ASTERISK_USER}
GROUPS=	${ASTERISK_GROUP} dahdi

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPJSIP} && ${PORT_OPTIONS:MSRTP}
LIB_DEPENDS+=	libpj.so:${PORTSDIR}/net/pjsip-extsrtp
.elif ${PORT_OPTIONS:MPJSIP} && ! ${PORT_OPTIONS:MSRTP}
LIB_DEPENDS+=   libpj.so:${PORTSDIR}/net/pjsip
.elif ! ${PORT_OPTIONS:MPJSIP} && ${PORT_OPTIONS:MSRTP}
LIB_DEPENDS+=   libsrtp.so:${PORTSDIR}/net/libsrtp
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

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/samples/musiconhold.conf.sample
.if ${PORT_OPTIONS:MSYSINFO}
	@${REINPLACE_CMD} -e 's/%%LIBSYSINFO%%/-lsysinfo/' ${WRKSRC}/main/Makefile
.else
	@${REINPLACE_CMD} -e '/#define HAVE_SYSINFO 1/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/%%LIBSYSINFO%%/d' ${WRKSRC}/main/Makefile
.endif

post-configure:
	@cd ${WRKSRC} && ${MAKE_CMD} menuselect.makeopts
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
	@cd ${WRKSRC} && ./menuselect/menuselect --enable  G711_NEW_ALGORITHM menuselect.makeopts
.endif

post-install:
	@${RM} ${STAGEDIR}${ETCDIR}/*.conf ${STAGEDIR}${ETCDIR}/extensions.ael ${STAGEDIR}${ETCDIR}/extensions.lua

.include <bsd.port.post.mk>
