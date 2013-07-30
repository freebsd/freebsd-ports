# Created by: Alexander V. Chernikov <melifaro@ipfw.ru>
# $FreeBSD$

PORTNAME=	callweaver
PORTVERSION=	1.2.1
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://devs.callweaver.org/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Open source IP PBX

LIB_DEPENDS=	spandsp.2:${PORTSDIR}/comms/spandsp-devel \
		popt.0:${PORTSDIR}/devel/popt

USES=		gmake
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pic
USE_RC_SUBR=	callweaver
USE_CSTD=	gnu89
CFLAGS+=	-Wno-return-type

CWUSER=		callweaver
CWGROUP=	callweaver

USERS=		${CWUSER}
GROUPS=		${CWGROUP}
PLIST_SUB+=	CWUSER=${CWUSER} CWGROUP=${CWGROUP}

MAN8=		callweaver.8 safe_callweaver.8

OPTIONS_DEFINE=	SIPTCP PGSQL MYSQL EXTUDP ZAPTEL FAX SPEEX VORBIS MEETME LDAP SNMP DEBUG
OPTIONS_DEFAULT=	SIPTCP FAX SPEEX VORBIS
SIPTCP_DESC=	SIP TCP/TLS support
EXTUDP_DESC=	extented UDP support for multi-homed
ZAPTEL_DESC=	Zapata Telefony
FAX_DESC=	audio/T.38 app_fax/chan_fax/FaxGateway/etc
MEETME_DESC=	Build  app_meetme (requires ZAPTEL)
LDAP_DESC=	Build  app_ldap application
SNMP_DESC=	SNMP support (broken)

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--with-readme --with-license --with-credits
.else
CONFIGURE_ARGS+=	--without-readme --without-license --without-credits
.endif

.if ${PORT_OPTIONS:MSIPTCP}
CONFIGURE_ARGS+=	--enable-sip-tcp-support
PLIST_SUB+=	TLS=""
.else
CONFIGURE_ARGS+=	--disable-sip-tcp-support
PLIST_SUB+=	TLS="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
PG_INC=	`${LOCALBASE}/bin/pg_config --includedir`
PG_LIB=	`${LOCALBASE}/bin/pg_config --libdir`
CONFIGURE_ARGS+=	--enable-postgresql --with-cdr_pgsql --with-pgsql-inc="${PG_INC}" --with-pgsql-inc="${PG_LIB}"
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--enable-mysql --with-cdr_mysql
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MEXTUDP}
CONFIGURE_ARGS+=	--enable-udpfromto
.endif

.if ${PORT_OPTIONS:MMEETME}
WITH_ZAPTEL=yes
CONFIGURE_ARGS+=	--with-app_meetme
PLIST_SUB+=	MEETME=""
.else
CONFIGURE_ARGS+=	--without-app_meetme
PLIST_SUB+=	MEETME="@comment "
.endif

.if ${PORT_OPTIONS:MZAPTEL}
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

.if ${PORT_OPTIONS:MFAX}
FAXDEV_PATH=	/var/run/fax
CONFIGURE_ARGS+=	--with-app_t38gateway --with-app_txfax --with-app_rxfax --with-chan_fax --with-app_faxdetect --with-tiff-includes="${LOCALBASE}/include/" --with-tiff-libs="${LOCALBASE}/lib"
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	FAX=""
.else
CONFIGURE_ARGS+=	--without-app_t38gateway --without-app_txfax --without-app_rxfax --without-chan_fax --without-app_faxdetect
PLIST_SUB+=	FAX="@comment "
.endif

#.if ${PORT_OPTIONS:MODBC}
#CONFIGURE_ARGS+=	--enable-odbc
#LIB_DEPENDS+=	odbc.2:${PORTSDIR}/databases/unixODBC
#.else
#CONFIGURE_ARGS+=	--disable-odbc
#.endif

.if ${PORT_OPTIONS:MSPEEX}
CONFIGURE_ARGS+=	--with-codec_speex
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
PLIST_SUB+=	SPEEX=""
.else
CONFIGURE_ARGS+=	--without-codec_speex
PLIST_SUB+=	SPEEX="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
CONFIGURE_ARGS+=	--with-format_oggvorbis
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--without-format_oggvorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--enable-openldap --with-ldap-dir="${LOCALBASE}"
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=	--disable-openldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-res_snmp
PLIST_SUB+=	SNMP=""
.else
CONFIGURE_ARGS+=	--without-res_snmp
PLIST_SUB+=	SNMP="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--disable-optimization --enable-debug
.endif

post-install:
.if ${PORT_OPTIONS:MFAX}
	@${MKDIR} ${FAXDEV_PATH}
	@${CHOWN} ${CWUSER}:${CWGROUP} ${FAXDEV_PATH}
	@${REINPLACE_CMD} -i "" -e 's?/dev/fax/?${FAXDEV_PATH}?' ${PREFIX}/etc/${PORTNAME}/chan_fax.conf*
.endif

.include <bsd.port.post.mk>
