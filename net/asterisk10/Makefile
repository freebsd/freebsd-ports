# New ports collection makefile for:	asterisk
# Date created:				17 October 2003
# Whom:					Maxim Sobolev <sobomax@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk
DISTVERSION=	10.0.0-beta2
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		newt.52:${PORTSDIR}/devel/newt \
		execinfo:${PORTSDIR}/devel/libexecinfo
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
CONFLICTS_INSTALL=	asterisk*-1.2* asterisk*-1.4* asterisk*-1.6*

OPTIONS=	OGGVORBIS	"Enable Ogg Vorbis support" on \
		IODBC		"Enable iODBC support" off \
		UODBC		"Enable unixODBC support" on \
		POSTGRES	"Enable PostgreSQL support" on \
		MYSQL		"Enable MySQL support" off \
		RADIUS		"Enable RADIUS accounting support" on \
		SNMP		"Enable SNMP support" on \
		H323		"Enable H.323 support" on \
		FREETDS		"Enable FreeTDS support" on \
		JABBER		"Enable Jabber and Gtalk support" on \
		SQLITE          "Enable SQLITE support" on \
		GSM		"Enable GSM codec" on \
		CURL		"Enable CURL support" on \
		ILBC		"Enable iLBC codec" off \
		SPANDSP		"Enable Spandsp faxing support" off \
		EXCHANGE	"Enable Exchange calendar support" off \
		NEWG711		"Enable new G711 Codec" off	\
		SRTP		"Enable SecureRTP support" off	\
		LUA		"Enable LUA extensions support" off

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
OPTIONS+=	DAHDI		"Enable DAHDI support" on

.if defined(WITH_IODBC) && defined(WITH_UODBC)
IGNORE=	please select only one of iodbc or unixODBC
.endif

# Include this since we have altered OPTIONS.
.include <bsd.port.options.mk>
.endif

SUB_LIST+=	ASTERISK_USER=${ASTERISK_USER}
PLIST_SUB+=	ASTERISK_USER=${ASTERISK_USER}
PLIST_SUB+=	ASTERISK_GROUP=${ASTERISK_GROUP}
PLIST_SUB+=	VARDIR=${VARDIR}

.if !defined(WITH_H323)
PLIST_SUB+=	WITH_H323="@comment "
CONFIGURE_ARGS+=	--without-h323
.else
PLIST_SUB+=	WITH_H323=""
CONFIGURE_ARGS+=	--with-h323=${LOCALBASE}
LIB_DEPENDS+=	pt_r.1:${PORTSDIR}/devel/pwlib \
		h323_r.1:${PORTSDIR}/net/openh323
.endif

.if !defined(WITH_DAHDI)
PLIST_SUB+=	WITH_DAHDI="@comment "
CONFIGURE_ARGS+=	--without-dahdi
.else
PLIST_SUB+=	WITH_DAHDI=""
CONFIGURE_ARGS+=	--with-dahdi
BUILD_DEPENDS+=	libpri>=1.4.10:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
.endif

#
# WITH_FREETDS, WITH_PGSQL and WITH_SQLITE can also be added to MAKE_ENV
# similarly
.if !defined(WITH_UODBC)
CONFIGURE_ARGS+=	--without-unixodbc
.endif
.if !defined(WITH_IODBC)
CONFIGURE_ARGS+=	--without-iodbc
.endif
.if !defined(WITH_UODBC) && !defined(WITH_IODBC)
PLIST_SUB+=	WITH_ODBC="@comment "
.endif
.if defined(WITH_UODBC) || defined(WITH_IODBC)
PLIST_SUB+=	WITH_ODBC=""
USE_AUTOTOOLS=	libltdl
.if defined(WITH_UODBC)
CONFIGURE_ARGS+=	--with-unixodbc --with-ltdl
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
.elif defined(WITH_IODBC)
CONFIGURE_ARGS+=	--with-iodbc --with-ltdl
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
.endif
.endif

.if !defined(WITH_FREETDS)
PLIST_SUB+=	WITH_FREETDS="@comment "
CONFIGURE_ARGS+=	--without-tds
.else
PLIST_SUB+=	WITH_FREETDS=""
CONFIGURE_ARGS+=	--with-tds=${LOCALBASE}
LIB_DEPENDS+=	tds.5:${PORTSDIR}/databases/freetds
.endif

.if !defined(WITH_POSTGRES)
PLIST_SUB+=	WITH_POSTGRES="@comment "
CONFIGURE_ARGS+=	--without-postgres
.else
PLIST_SUB+=	WITH_POSTGRES=""
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgres
.endif

.if !defined(WITH_MYSQL)
PLIST_SUB+=	WITH_MYSQL="@comment "
CONFIGURE_ARGS+=	--without-mysql
.else
PLIST_SUB+=	WITH_MYSQL=""
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.endif

.if !defined(WITH_OGGVORBIS)
PLIST_SUB+=	WITH_OGGVORBIS="@comment "
CONFIGURE_ARGS+=	--without-ogg
.else
PLIST_SUB+=	WITH_OGGVORBIS=""
CONFIGURE_ARGS+=	--with-ogg
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

.if !defined(WITH_RADIUS)
PLIST_SUB+=	WITH_RADIUS="@comment "
CONFIGURE_ARGS+=	--without-radius
.else
PLIST_SUB+=	WITH_RADIUS=""
CONFIGURE_ARGS+=	--with-radius
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
.endif

.if !defined(WITH_SNMP)
PLIST_SUB+=	WITH_SNMP="@comment "
CONFIGURE_ARGS+=	--without-netsnmp
.else
PLIST_SUB+=	WITH_SNMP=""
CONFIGURE_ARGS+=	--with-netsnmp
LIB_DEPENDS+=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if !defined(WITH_JABBER)
PLIST_SUB+=	WITH_JABBER="@comment "
CONFIGURE_ARGS+=	--without-iksemel
.else
PLIST_SUB+=	WITH_JABBER=""
CONFIGURE_ARGS+=	--with-iksemel
LIB_DEPENDS+=	iksemel.4:${PORTSDIR}/textproc/iksemel
.endif

.if !defined(WITH_SQLITE)
PLIST_SUB+=	WITH_SQLITE="@comment "
CONFIGURE_ARGS+=	--without-sqlite \
			--with-sqlite3=no
.else
PLIST_SUB+=	WITH_SQLITE=""
CONFIGURE_ARGS+=	--with-sqlite
LIB_DEPENDS+=	sqlite:${PORTSDIR}/databases/sqlite2 \
		sqlite3:${PORTSDIR}/databases/sqlite3
.endif

.if !defined(WITH_ILBC)
PLIST_SUB+=	WITH_ILBC="@comment "
.else
PLIST_SUB+=	WITH_ILBC=""
EXTRA_PATCHES+=	${PATCHDIR}/ilbc_enable.diff
.endif

.if !defined(WITH_GSM)
PLIST_SUB+=	WITH_GSM="@comment "
CONFIGURE_ARGS+=	--without-gsm
.else
PLIST_SUB+=	WITH_GSM=""
CONFIGURE_ARGS+=	--with-gsm
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm
.endif

.if !defined(WITH_CURL)
PLIST_SUB+=	WITH_CURL="@comment "
CONFIGURE_ARGS+=	--with-libcurl=no
.else
PLIST_SUB+=	WITH_CURL=""
CONFIGURE_ARGS+=	--with-libcurl
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.endif

.if !defined(WITH_SPANDSP)
PLIST_SUB+=	WITH_SPANDSP="@comment "
CONFIGURE_ARGS+=	--without-spandsp
.else
PLIST_SUB+=	WITH_SPANDSP=""
CONFIGURE_ARGS+=	--with-spandsp
LIB_DEPENDS+=	spandsp.2:${PORTSDIR}/comms/spandsp-devel
.endif

.if !defined(WITH_EXCHANGE)
CONFIGURE_ARGS+=	--without-neon --without-neon29
PLIST_SUB+=	WITH_EXCHANGE="@comment "
.else
LIB_DEPENDS+=	neon.27:${PORTSDIR}/www/neon29
PLIST_SUB+=	WITH_EXCHANGE=""
.endif

.if !defined(WITH_SRTP)
PLIST_SUB+=	WITH_SRTP="@comment "
CONFIGURE_ARGS+=	--without-srtp
.else
PLIST_SUB+=	WITH_SRTP=""
BUILD_DEPENDS+=	libsrtp>=1.4.4:${PORTSDIR}/net/libsrtp
CONFIGURE_ARGS+=	--with-srtp
.endif

.if defined(WITH_LUA)
CONFIGURE_ARGS+=	--with-lua
CFLAGS+=	-I${LUA_INCDIR}
USE_LUA=	yes
LDFLAGS+=	-L${LUA_LIBDIR}
PLIST_SUB+=	WITH_LUA=""
.else
CONFIGURE_ARGS+=	--without-lua
PLIST_SUB+=	WITH_LUA="@comment "
.endif

post-extract:
	${MKDIR} ${WRKSRC}/codecs/ilbc
	${FIND} ${WRKSRC} -name '*.d' -delete

post-patch:
	${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/musiconhold.conf.sample

post-configure:
.if defined(WITH_MYSQL) || defined(WITH_NEWG711) || defined(WITH_ILBC)
	@cd ${WRKSRC} && make menuselect.makeopts
.if defined(WITH_MYSQL)
	@cd ${WRKSRC} && ./menuselect/menuselect --enable res_config_mysql menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable app_mysql menuselect.makeopts
	@cd ${WRKSRC} && ./menuselect/menuselect --enable cdr_mysql menuselect.makeopts
.endif
.if defined(WITH_NEWG711)
	@cd ${WRKSRC} && ./menuselect/menuselect --enable  G711_NEW_ALGORITHM menuselect.makeopts
.endif
.if defined(WITH_ILBC)
	@cd ${WRKSRC} && ./menuselect/menuselect --enable  codec_ilbc menuselect.makeopts
.endif
.endif

post-install:
	@${CHOWN} -R ${ASTERISK_USER}:${ASTERISK_GROUP} ${VARDIR}/db/asterisk ${VARDIR}/log/asterisk ${VARDIR}/spool/asterisk

.include <bsd.port.post.mk>
