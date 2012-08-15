# New ports collection makefile for:	zabbix-server
# Date created:		2009-12-09
# Whom:			Jim Riggs <ports@christianserving.org>
#
# $FreeBSD$
#

PORTNAME=	zabbix2
PORTVERSION=	2.0.0
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/zabbix/ZABBIX%20Latest%20Stable/${PORTVERSION}
PKGNAMESUFFIX?=	-server
DISTNAME=	zabbix-${PORTVERSION}

MAINTAINER=	pakhom706@gmail.com
COMMENT=	Enterprise-class open source distributed monitoring (${PKGNAMESUFFIX:S/^-//})

LICENSE=	GPLv2

CONFLICTS=	${PKGBASE}-1.[0-8]*

.if ${PKGNAMESUFFIX} != "-agent"
CONFLICTS+=	${PORTNAME}-1.[0-8]*
.endif

ZABBIX_BUILD=	${PKGNAMESUFFIX:S/^-//}

.if ${ZABBIX_BUILD} != "frontend" # frontend only needs the version/distribution settings
.if ${ZABBIX_BUILD} != "agent"
MAN8+=		zabbix_${ZABBIX_BUILD}.8
USE_RC_SUBR=	zabbix_${ZABBIX_BUILD}
.else
MAN1+=		zabbix_get.1 zabbix_sender.1
MAN8+=		zabbix_${ZABBIX_BUILD}d.8
USE_RC_SUBR=	zabbix_${ZABBIX_BUILD}d
.endif

USE_ICONV=	yes

USERS=		zabbix
GROUPS=		zabbix

.if ${ZABBIX_BUILD} != "proxy"
PLIST_SUB=	PROXY="@comment "
.else
PLIST_SUB=	PROXY=""
.endif

PLIST_SUB+=	ZABBIX_BUILD=${ZABBIX_BUILD}
SUB_LIST=	ZABBIX_BUILD=${ZABBIX_BUILD} ZABBIX_REQUIRE=${ZABBIX_REQUIRE}

MAKE_ARGS+=	ARCH=freebsd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-${ZABBIX_BUILD} \
			--sysconfdir=${ETCDIR} \
			--datadir=${ETCDIR}

.if ${ZABBIX_BUILD} != "agent"
LIB_DEPENDS=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp \
		execinfo:${PORTSDIR}/devel/libexecinfo

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=	--with-net-snmp

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options

OPTIONS_DEFINE=	IPV6 FPING JABBER CURL LDAP IPMI SSH NMAP ODBC
OPTIONS_DEFAULT=	MYSQL IPV6 FPING JABBER CURL LDAP

CURL_DESC=	Support for web monitoring
FPING_DESC=	Build/install fping for ping checks
IPMI_DESC=	Support for IPMI checks
JABBER_DESC=	Support for Jabber media type
LDAP_DESC=	Support for LDAP server checks
NMAP_DESC=	Build/install nmap for o/s detection
SSH_DESC=	Support for SSH-based checks
ODBC_DESC=	Support for database checks via ODBC
IODBC_DESC=	Use iODBC for ODBC support
UNIXODBC_DESC=	Use UnixODBC for ODBC support

OPTIONS_SINGLE=	DB ODBC
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
ZABBIX_REQUIRE=	" mysql"
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
ZABBIX_REQUIRE=	" postgresql"
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgresql
.endif

.if ${PORT_OPTIONS:MSQLITE}
ZABBIX_REQUIRE=
USE_SQLITE=	3
CONFIGURE_ARGS+=	--with-sqlite3
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-libcurl
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap
.endif

.if ${PORT_OPTIONS:MIPMI}
LIB_DEPENDS+=	OpenIPMI:${PORTSDIR}/sysutils/openipmi
CONFIGURE_ARGS+=	--with-openipmi
.endif

.if ${PORT_OPTIONS:MJABBER}
LIB_DEPENDS+=	iksemel:${PORTSDIR}/textproc/iksemel
CONFIGURE_ARGS+=	--with-jabber
.endif

.if ${PORT_OPTIONS:MFPING}
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
.endif

.if ${PORT_OPTIONS:MSSH}
LIB_DEPENDS+=	ssh2:${PORTSDIR}/security/libssh2
CONFIGURE_ARGS+=	--with-ssh2
.endif

.if ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-unixodbc
.endif
.endif # if ${ZABBIX_BUILD} != "agent"

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${PORT_OPTIONS:MNMAP}
RUN_DEPENDS+=	nmap:${PORTSDIR}/security/nmap \
		sudo:${PORTSDIR}/security/sudo
.endif

post-patch:
	@${GREP} -rl "/etc/zabbix" ${WRKSRC} \
	  | ${XARGS} ${REINPLACE_CMD} -e 's#/etc/zabbix#${ETCDIR}#g'
	@${REINPLACE_CMD} -e 's#/usr/sbin/fping#${LOCALBASE}/sbin/fping#g' ${WRKSRC}/conf/zabbix_*.conf

.if ${ZABBIX_BUILD} != "agent"
.if empty(PORT_OPTIONS:MFPING)
	@${ECHO} 'DisablePinger=yes' >> ${WRKSRC}/conf/zabbix_${ZABBIX_BUILD}.conf
.endif
.for d in mysql oracle postgresql sqlite3
	@${REINPLACE_CMD} -e 's|/bin/ping|/sbin/ping|g; \
	                      s|/usr/bin/traceroute|/usr/sbin/traceroute|g; \
	                      s|sudo /usr/bin/nmap|sudo ${LOCALBASE}/bin/nmap|g;' \
	                      ${WRKSRC}/database/${d}/data.sql
.endfor
.endif
	@${REINPLACE_CMD} -Ee 's|(@sysconfdir@/(\$$\([A-Z]*_CONFIG\)))" ([|][|] cp "../../conf/\$$\([A-Z]*_CONFIG\)" "\$$\(DESTDIR\)@sysconfdir@)"|\1.sample" \3/\2.sample"|;' \
		${WRKSRC}/src/zabbix_${ZABBIX_BUILD}/Makefile.in
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -or -name '*.orig' \) -exec ${RM} -f {} +

post-install:
.if ${ZABBIX_BUILD} != "agent"
	@${MKDIR} "${DATADIR}/${ZABBIX_BUILD}/database"
	@cd ${WRKSRC}/upgrades/ && ${COPYTREE_SHARE} dbpatches ${DATADIR}/${ZABBIX_BUILD}/upgrades/
	@cd ${WRKSRC}/database/ && ${COPYTREE_SHARE} "ibm_db2 mysql oracle postgresql sqlite3" ${DATADIR}/${ZABBIX_BUILD}/database/
	@${CAT} ${PKGMESSAGE}
.endif
.endif # if ${ZABBIX_BUILD} != "frontend"

.include <bsd.port.mk>
