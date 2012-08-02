# New ports collection makefile for:	asterisk
# Date created:				17 October 2003
# Whom:					Maxim Sobolev <sobomax@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	10.7.0
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/
PKGNAMESUFFIX=	10

MAINTAINER=	flo@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		newt.52:${PORTSDIR}/devel/newt \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		sqlite3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

ONLY_FOR_ARCHS=	i386 amd64 powerpc sparc64

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gsm=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/openh323
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_BISON=	build
USE_RC_SUBR=	asterisk.sh
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		OSVERSION=${OSVERSION} \
		NOISY_BUILD=YES \
		DOCSDIR=${DOCSDIR} \
		ASTCFLAGS="${CFLAGS}"
MAN8=		asterisk.8 astgenkey.8 autosupport.8 safe_asterisk.8
CONFLICTS_BUILD=	linuxthreads-*
CONFLICTS_INSTALL=	asterisk*-1.4* asterisk*-1.6* asterisk*-1.8*

OPTIONS_DEFINE= VORBIS PGSQL MYSQL RADIUS SNMP H323 FREETDS JABBER SQLITE GSM \
		CURL SPANDSP EXCHANGE NEWG711 SRTP LUA LDAP ODBC OOH323
OPTIONS_DEFAULT= VORBIS ODBC UNIXODBC PGSQL RADIUS SNMP H323 FREETDS JABBER GSM \
		SQLITE CURL

OPTIONS_SINGLE=	ODBC
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC

EXCHANGE_DESC?=	Exchange calendar support
NEWG711_DESC?=	New G711 Codec
SRTP_DESC?=	SecureRTP support
OOH323_DESC?=	ooh323 support

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

.if ${ARCH} == "i386" || ${ARCH} == "amd64" || ${ARCH} == "sparc64"
OPTIONS_DEFINE+=	DAHDI
OPTIONS_DEFAULT+=	DAHDI
DAHDI_DESC?=	DAHDI support
.endif

SUB_LIST+=	ASTERISK_USER=${ASTERISK_USER}
PLIST_SUB+=	ASTERISK_USER=${ASTERISK_USER}
PLIST_SUB+=	ASTERISK_GROUP=${ASTERISK_GROUP}
PLIST_SUB+=	VARDIR=${VARDIR}

.if ${PORT_OPTIONS:MH323}
PLIST_SUB+=	WITH_H323=""
CONFIGURE_ARGS+=	--with-h323=${LOCALBASE}
LIB_DEPENDS+=	pt_r.1:${PORTSDIR}/devel/pwlib \
		h323_r.1:${PORTSDIR}/net/openh323
.else
PLIST_SUB+=	WITH_H323="@comment "
CONFIGURE_ARGS+=	--without-h323
.endif

.if ${PORT_OPTIONS:MDAHDI}
PLIST_SUB+=	WITH_DAHDI=""
CONFIGURE_ARGS+=	--with-dahdi --with-openr2
BUILD_DEPENDS+=	libpri>=1.4.10:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri\
		openr2.4:${PORTSDIR}/misc/openr2
.else
PLIST_SUB+=	WITH_DAHDI="@comment "
CONFIGURE_ARGS+=	--without-dahdi --without-openr2
.endif

#
# WITH_FREETDS, WITH_PGSQL and WITH_SQLITE can also be added to MAKE_ENV
# similarly
.if empty(PORT_OPTIONS:MUNIXODBC)
CONFIGURE_ARGS+=	--without-unixodbc
.endif
.if empty(PORT_OPTIONS:MIODBC)
CONFIGURE_ARGS+=	--without-iodbc
.endif
.if empty(PORT_OPTIONS:MUNIXODBC) && empty(PORT_OPTIONS:MIODBC)
PLIST_SUB+=	WITH_ODBC="@comment "
.endif
.if ${PORT_OPTIONS:MUNIXODBC} || ${PORT_OPTIONS:MIODBC}
PLIST_SUB+=	WITH_ODBC=""
USE_AUTOTOOLS=	libltdl
.if ${PORT_OPTIONS:MUNIXODBC}
CONFIGURE_ARGS+=	--with-unixodbc --with-ltdl
LIB_DEPENDS+=	odbc.2:${PORTSDIR}/databases/unixODBC
.elif ${PORT_OPTIONS:MIODBC}
CONFIGURE_ARGS+=	--with-iodbc --with-ltdl
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
.endif
.endif

.if ${PORT_OPTIONS:MFREETDS}
PLIST_SUB+=	WITH_FREETDS=""
CONFIGURE_ARGS+=	--with-tds=${LOCALBASE}
LIB_DEPENDS+=	tds.5:${PORTSDIR}/databases/freetds
.else
PLIST_SUB+=	WITH_FREETDS="@comment "
CONFIGURE_ARGS+=	--without-tds
.endif

.if ${PORT_OPTIONS:MPGSQL}
PLIST_SUB+=	WITH_PGSQL=""
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgres
.else
PLIST_SUB+=	WITH_PGSQL="@comment "
CONFIGURE_ARGS+=	--without-postgres
.endif

.if ${PORT_OPTIONS:MMYSQL}
PLIST_SUB+=	WITH_MYSQL=""
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.else
PLIST_SUB+=	WITH_MYSQL="@comment "
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MVORBIS}
PLIST_SUB+=	WITH_VORBIS=""
CONFIGURE_ARGS+=	--with-ogg
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.else
PLIST_SUB+=	WITH_VORBIS="@comment "
CONFIGURE_ARGS+=	--without-ogg
.endif

.if ${PORT_OPTIONS:MRADIUS}
PLIST_SUB+=	WITH_RADIUS=""
CONFIGURE_ARGS+=	--with-radius
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
.else
PLIST_SUB+=	WITH_RADIUS="@comment "
CONFIGURE_ARGS+=	--without-radius
.endif

.if ${PORT_OPTIONS:MSNMP}
PLIST_SUB+=	WITH_SNMP=""
CONFIGURE_ARGS+=	--with-netsnmp
LIB_DEPENDS+=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp
.else
PLIST_SUB+=	WITH_SNMP="@comment "
CONFIGURE_ARGS+=	--without-netsnmp
.endif

.if ${PORT_OPTIONS:MJABBER}
PLIST_SUB+=	WITH_JABBER=""
CONFIGURE_ARGS+=	--with-iksemel
LIB_DEPENDS+=	iksemel.4:${PORTSDIR}/textproc/iksemel
.else
PLIST_SUB+=	WITH_JABBER="@comment "
CONFIGURE_ARGS+=	--without-iksemel
.endif

.if ${PORT_OPTIONS:MSQLITE}
PLIST_SUB+=	WITH_SQLITE=""
CONFIGURE_ARGS+=	--with-sqlite
LIB_DEPENDS+=	sqlite:${PORTSDIR}/databases/sqlite2
.else
PLIST_SUB+=	WITH_SQLITE="@comment "
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if ${PORT_OPTIONS:MGSM}
PLIST_SUB+=	WITH_GSM=""
CONFIGURE_ARGS+=	--with-gsm
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm
.else
PLIST_SUB+=	WITH_GSM="@comment "
CONFIGURE_ARGS+=	--without-gsm
.endif

.if ${PORT_OPTIONS:MCURL}
PLIST_SUB+=	WITH_CURL=""
CONFIGURE_ARGS+=	--with-libcurl
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.else
PLIST_SUB+=	WITH_CURL="@comment "
CONFIGURE_ARGS+=	--with-libcurl=no
.endif

.if ${PORT_OPTIONS:MSPANDSP}
PLIST_SUB+=	WITH_SPANDSP=""
CONFIGURE_ARGS+=	--with-spandsp
LIB_DEPENDS+=	spandsp.2:${PORTSDIR}/comms/spandsp-devel
.else
PLIST_SUB+=	WITH_SPANDSP="@comment "
CONFIGURE_ARGS+=	--without-spandsp
.endif

.if ${PORT_OPTIONS:MEXCHANGE}
LIB_DEPENDS+=	neon.27:${PORTSDIR}/www/neon29
PLIST_SUB+=	WITH_EXCHANGE=""
.else
CONFIGURE_ARGS+=	--without-neon --without-neon29
PLIST_SUB+=	WITH_EXCHANGE="@comment "
.endif

.if ${PORT_OPTIONS:MSRTP}
PLIST_SUB+=	WITH_SRTP=""
BUILD_DEPENDS+=	libsrtp>=1.4.4:${PORTSDIR}/net/libsrtp
CONFIGURE_ARGS+=	--with-srtp
.else
PLIST_SUB+=	WITH_SRTP="@comment "
CONFIGURE_ARGS+=	--without-srtp
.endif

.if ${PORT_OPTIONS:MLUA}
CONFIGURE_ARGS+=	--with-lua
CFLAGS+=	-I${LUA_INCDIR}
USE_LUA=	yes
LDFLAGS+=	-L${LUA_LIBDIR}
PLIST_SUB+=	WITH_LUA=""
.else
CONFIGURE_ARGS+=	--without-lua
PLIST_SUB+=	WITH_LUA="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=	--with-ldap
USE_OPENLDAP=	yes
PLIST_SUB+=	WITH_LDAP=""
.else
CONFIGURE_ARGS+=	--without-ldap
PLIST_SUB+=	WITH_LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MOOH323}
PLIST_SUB+=	WITH_OOH323=""
.else
PLIST_SUB+=	WITH_OOH323="@comment "
.endif

post-extract:
	${FIND} ${WRKSRC} -name '*.d' -delete

post-patch:
	${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/musiconhold.conf.sample

post-configure:
.if !empty(PORT_OPTIONS:MMYSQL) || !empty(PORT_OPTIONS:MNEWG711) || !empty(PORT_OPTIONS:MOOH323)
	@cd ${WRKSRC} && make menuselect.makeopts
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
.endif

post-install:
	@${CHOWN} -R ${ASTERISK_USER}:${ASTERISK_GROUP} ${VARDIR}/db/asterisk ${VARDIR}/log/asterisk ${VARDIR}/spool/asterisk

.include <bsd.port.post.mk>
