# $FreeBSD$

PORTNAME=	asterisk
PORTVERSION=	11.13.1
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/
PKGNAMESUFFIX=	11

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open Source PBX and telephony toolkit

LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex \
		libnewt.so:${PORTSDIR}/devel/newt \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

ONLY_FOR_ARCHS=	i386 amd64 powerpc sparc64

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-uuid=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/openh323
CFLAGS+=	-I${LOCALBASE}/include
USE_GCC=	yes
USE_GNOME=	libxml2
USES=		bison cpe gmake
CPE_VENDOR=	digium
USE_RC_SUBR=	asterisk
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		OSVERSION=${OSVERSION} \
		NOISY_BUILD=YES \
		DOCSDIR=${DOCSDIR} \
		ASTCFLAGS="${CFLAGS}"

CONFLICTS_BUILD=	linuxthreads-*
CONFLICTS_INSTALL=	asterisk*-1.4* asterisk*-1.6* asterisk*-1.8*

OPTIONS_DEFINE=	VORBIS PGSQL MYSQL ODBC RADIUS SNMP FREETDS XMPP SQLITE GSM \
		CURL SPANDSP EXCHANGE NEWG711 SRTP LUA LDAP OOH323
OPTIONS_DEFAULT=	VORBIS ODBC PGSQL RADIUS SNMP FREETDS \
		XMPP GSM SQLITE CURL LUA

OPTIONS_DEFINE_i386=	DAHDI
OPTIONS_DEFINE_amd64=	DAHDI
OPTIONS_DEFINE_sparc64=	DAHDI

OPTIONS_DEFAULT_i386=	DAHDI
OPTIONS_DEFAULT_amd64=	DAHDI
OPTIONS_DEFAULT_sparc64=	DAHDI

EXCHANGE_DESC?=	Exchange calendar support
NEWG711_DESC?=	New G711 Codec
SRTP_DESC?=	SecureRTP support
OOH323_DESC?=	ooh323 support
DAHDI_DESC?=	DAHDI support
XMPP_DESC?=	XMPP/GTALK support

OPTIONS_SUB=	yes
OOH323_LIB_DEPENDS=	libpt_r.so:${PORTSDIR}/devel/pwlib \
			libh323_r.so:${PORTSDIR}/net/openh323
DAHDI_CONFIGURE_ON=	--with-dahdi --with-openr2
DAHDI_CONFIGURE_OFF=	--without-dahdi --without-openr2
DAHDI_BUILD_DEPENDS=	libpri>=1.4.10:${PORTSDIR}/misc/libpri \
			${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi
DAHDI_LIB_DEPENDS=	libpri.so:${PORTSDIR}/misc/libpri \
			libopenr2.so:${PORTSDIR}/misc/openr2
ODBC_CONFIGURE_WITH=	unixodbc
ODBC_CONFIGURE_ON=	--with-ltdl
ODBC_LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC \
			libltdl.so:${PORTSDIR}/devel/libltdl
FREETDS_CONFIGURE_ON=	--with-tds=${LOCALBASE}
FREETDS_CONFIGURE_OFF=	--without-tds
FREETDS_LIB_DEPENDS=	libsybdb.so:${PORTSDIR}/databases/freetds
PGSQL_CONFIGURE_WITH=	postgres
PGSQL_USES=		pgsql
MYSQL_CONFIGURE_WITH=	mysqlclient
MYSQL_USE=		MYSQL=yes
VORBIS_CONFIGURE_WITH=	ogg
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
RADIUS_CONFIGURE_WITH=	radius
RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:${PORTSDIR}/net/radiusclient
SNMP_CONFIGURE_WITH=	netsnmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
XMPP_CONFIGURE_WITH=	iksemel
XMPP_LIB_DEPENDS=	libiksemel.so:${PORTSDIR}/textproc/iksemel
SQLITE_CONFIGURE_WITH=	sqlite
SQLITE_LIB_DEPENDS=	libsqlite.so:${PORTSDIR}/databases/sqlite2
GSM_CONFIGURE_WITH=	gsm
GSM_LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm
CURL_CONFIGURE_ON=	--with-libcurl
CURL_CONFIGURE_OFF=	--with-libcurl=no
CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
SPANDSP_CONFIGURE_WITH=	spandsp
SPANDSP_LIB_DEPENDS=	libspandsp.so.2:${PORTSDIR}/comms/spandsp-devel
EXCHANGE_CONFIGURE_OFF=	--without-neon --without-neon29
EXCHANGE_LIB_DEPENDS=	libneon.so:${PORTSDIR}/www/neon29
SRTP_CONFIGURE_WITH=	srtp
SRTP_BUILD_DEPENDS=	libsrtp>=1.4.4:${PORTSDIR}/net/libsrtp
LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua:51
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR}
LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

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
PLIST_SUB+=	ASTERISK_USER=${ASTERISK_USER}
PLIST_SUB+=	ASTERISK_GROUP=${ASTERISK_GROUP}
PLIST_SUB+=	VARDIR=${VARDIR}

post-extract:
	${FIND} ${WRKSRC} -name '*.d' -delete

post-patch:
	${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/musiconhold.conf.sample

post-configure:
	@cd ${WRKSRC} && ${MAKE_CMD} menuselect.makeopts
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
	@cd ${WRKSRC} && ./menuselect/menuselect --enable  G711_NEW_ALGORITHM menuselect.makeopts
.endif

post-install:
	@${RM} ${STAGEDIR}${ETCDIR}/*.conf ${STAGEDIR}${ETCDIR}/extensions.ael ${STAGEDIR}${ETCDIR}/extensions.lua

.include <bsd.port.post.mk>
