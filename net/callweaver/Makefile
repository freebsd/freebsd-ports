# New ports collection makefile for:	callweaver
# Date created:				28 June 2009
# Whom:					Alexander V. Chernikov <melifaro@ipfw.ru>
# $FreeBSD$
#

PORTNAME=	callweaver
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://devs.callweaver.org/release/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Open source IP PBX

LIB_DEPENDS=	spandsp.2:${PORTSDIR}/comms/spandsp-devel \
		popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pic
USE_RC_SUBR=	callweaver

USERS=		callweaver
GROUPS=		callweaver

MAN8=		callweaver.8 safe_callweaver.8

OPTIONS=	SIPTCP		"Enable SIP TCP/TLS support" on \
		POSTGRES	"Enable PostgreSQL support" off \
		MYSQL		"Enable MySQL support" off \
		EXTUDP		"Enable extented UDP support for multi-homed" off \
		ZAPTEL		"Enable Zapata Telefony" off \
		FAX		"Enable audio/T.38 app_fax/chan_fax/FaxGateway/etc" on \
		SPEEX		"Build  speex codec" on \
		VORBIS		"Enable VORBIS/Vorbis format support" on \
		MEETME		"Build  app_meetme (requires ZAPTEL)" off \
		LDAP		"Build  app_ldap application" off \
		SNMP		"Enable SNMP support (broken)" off \
		DEBUG		"Enable debug support" off

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-man-pages
.else
CONFIGURE_ARGS+=	--without-man-pages
.endif

.if defined(WITH_SIPTCP)
CONFIGURE_ARGS+=	--enable-sip-tcp-support
PLIST_SUB+=	TLS=""
.else
CONFIGURE_ARGS+=	--disable-sip-tcp-support
PLIST_SUB+=	TLS="@comment "
.endif

.if defined(WITH_POSTGRES)
USE_PGSQL=	yes
PG_INC=	`${LOCALBASE}/bin/pg_config --includedir`
PG_LIB=	`${LOCALBASE}/bin/pg_config --libdir`
CONFIGURE_ARGS+=	--enable-postgresql --with-cdr_pgsql --with-pgsql-inc="${PG_INC}" --with-pgsql-inc="${PG_LIB}"
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--enable-mysql --with-cdr_mysql
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_EXTUDP)
CONFIGURE_ARGS+=	--enable-udpfromto
.endif

.if defined(WITH_MEETME)
WITH_ZAPTEL=yes
CONFIGURE_ARGS+=	--with-app_meetme
PLIST_SUB+=	MEETME=""
.else
CONFIGURE_ARGS+=	--without-app_meetme
PLIST_SUB+=	MEETME="@comment "
.endif

.if defined(WITH_ZAPTEL)
CONFIGURE_ARGS+=	--enable-zaptel --with-chan_zap
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/zaptel/zaptel.h:${PORTSDIR}/misc/zaptel
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/zaptel/zaptel.h:${PORTSDIR}/misc/zaptel
PLIST_SUB+=	ZAPTEL=""
.else
CONFIGURE_ARGS+=	--disable-zaptel --without-chan_zap
PLIST_SUB+=	ZAPTEL="@comment "
.endif

.if defined(WITH_FAX)
FAXDEV_PATH=	/var/run/fax
CONFIGURE_ARGS+=	--with-app_t38gateway --with-app_txfax --with-app_rxfax --with-chan_fax --with-app_faxdetect --with-tiff-includes="${LOCALBASE}/include/" --with-tiff-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	FAX=""
.else
CONFIGURE_ARGS+=	--without-app_t38gateway --without-app_txfax --without-app_rxfax --without-chan_fax --without-app_faxdetect
PLIST_SUB+=	FAX="@comment "
.endif

#.if defined(WITH_ODBC)
#CONFIGURE_ARGS+=	--enable-odbc
#LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
#.else
#CONFIGURE_ARGS+=	--disable-odbc
#.endif

.if defined(WITH_SPEEX)
CONFIGURE_ARGS+=	--with-codec_speex
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
PLIST_SUB+=	SPEEX=""
.else
CONFIGURE_ARGS+=	--without-codec_speex
PLIST_SUB+=	SPEEX="@comment "
.endif

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--with-format_oggvorbis
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--without-format_oggvorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--enable-openldap --with-ldap-dir="${LOCALBASE}"
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=	--disable-openldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if defined(WITH_SNMP)
LIB_DEPENDS+=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-res_snmp
PLIST_SUB+=	SNMP=""
.else
CONFIGURE_ARGS+=	--without-res_snmp
PLIST_SUB+=	SNMP="@comment "
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-optimization --enable-debug
.endif

post-install:
.if defined(WITH_FAX)
	@${MKDIR} ${FAXDEV_PATH}
	@${CHOWN} ${CWUSER}:${CWGROUP} ${FAXDEV_PATH}
	@${REINPLACE_CMD} -i "" -e 's?/dev/fax/?${FAXDEV_PATH}?' ${PREFIX}/etc/${PORTNAME}/chan_fax.conf*
.endif

.include <bsd.port.post.mk>
