PORTNAME=	zabbix7
DISTVERSION=	7.0.18
PORTREVISION?=	0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://cdn.zabbix.com/zabbix/sources/stable/${DISTVERSION:R}/
PKGNAMESUFFIX?=	-server
DISTNAME=	zabbix-${DISTVERSION}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Enterprise-class open source distributed monitoring (${PKGNAMESUFFIX:S/^-//})
WWW=		https://www.zabbix.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	${PORTNAME}[0-9]${PKGNAMESUFFIX} \
			zabbix[0-6][0-9]${PKGNAMESUFFIX}

ZABBIX_BUILD=	${PKGNAMESUFFIX:S/^-//:S/-$//}

.if ${ZABBIX_BUILD} != "frontend" # frontend only needs the version/distribution settings
USES=		iconv pkgconfig
.if ${ZABBIX_BUILD} != "agent"
CONFIGURE_ARGS+=	--cache-file=${WRKSRC}/config.cache \
			--with-libevent=${LOCALBASE} \
			--with-libxml2
LIB_DEPENDS+=		libevent.so:devel/libevent
USE_RC_SUBR=		zabbix_${ZABBIX_BUILD}
# -server and -proxy depends on libxml2
.if ${ZABBIX_BUILD} != "java"
USES+=		gnome
USE_GNOME=	libxml2
.endif
.else
USE_RC_SUBR=		zabbix_${ZABBIX_BUILD}d
.endif

USERS=		zabbix
GROUPS=		zabbix

.if ${ZABBIX_BUILD} == "proxy"
PLIST_SUB=	PROXY=""
.else
PLIST_SUB=	PROXY="@comment "
.endif
.if ${ZABBIX_BUILD} == "server"
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

PLIST_SUB+=	DISTVERSION=${DISTVERSION} \
		ZABBIX_BUILD=${ZABBIX_BUILD}
SUB_LIST=	ZABBIX_BUILD=${ZABBIX_BUILD}

MAKE_ARGS+=		ARCH=freebsd
GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=	--datadir=${ETCDIR} \
			--enable-${ZABBIX_BUILD} \
			--sysconfdir=${ETCDIR} \
			--with-iconv=${ICONV_PREFIX}

PORTSCOUT=	limit:^7\.0\.

.if ${ZABBIX_BUILD} != "java"
OPTIONS_DEFAULT+=	PCRE2
OPTIONS_SINGLE+=	PCRE
OPTIONS_SINGLE_PCRE=	PCRE1 PCRE2
PCRE_DESC=		PCRE library to use
PCRE1_DESC=		Use PCRE v1 library
PCRE2_DESC=		Use PCRE v2 library

PCRE1_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE1_CONFIGURE_WITH=	libpcre
PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_CONFIGURE_WITH=	libpcre2

.if ${ZABBIX_BUILD} != "agent"
CPPFLAGS+=	-I${LOCALBASE}/include

SUB_FILES=	pkg-message

OPTIONS_DEFAULT+=	CURL FPING IPMI IPV6 MYSQL OPENSSL SNMP SSH UNIXODBC
OPTIONS_DEFINE=		CURL FPING IPMI IPV6 LDAP NMAP SNMP SSH UNIXODBC
OPTIONS_SINGLE+=	DB SSL
OPTIONS_SINGLE_DB=	MDB5 MDB6 MYSQL MYSQLDV ORACLE PGSQL
.if ${ZABBIX_BUILD} == "proxy"
OPTIONS_SINGLE_DB+=	SQLITE
.endif
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_SUB=		yes

FPING_DESC=	Build/install fping for ping checks
IPMI_DESC=	Support for IPMI checks
LDAP_DESC=	Support for LDAP server checks
NMAP_DESC=	Build/install nmap for o/s detection
SNMP_DESC=	Support for SNMP checks
SSH_DESC=	Support for SSH-based checks
UNIXODBC_DESC=	Support for database checks via ODBC
MYSQL_DESC=	MySQL 8.0 database support
MYSQLDV_DESC=	MYSQL DEFAULT_VERSIONS= (poudriere)

FPING_RUN_DEPENDS=	fping:net/fping

IPMI_CONFIGURE_WITH=	openipmi
IPMI_LIB_DEPENDS=	libOpenIPMI.so:sysutils/openipmi

LDAP_CONFIGURE_WITH=	ldap
LDAP_USES=		ldap

MYSQL_CONFIGURE_ON=	--with-mysql
MYSQL_USES+=		compiler:c11 mysql:80

MYSQLDV_CONFIGURE_ON=	--with-mysql
MYSQLDV_USES+=		compiler:c11 mysql

MDB5_CONFIGURE_ON=	--with-mysql=${LOCALBASE}/bin/mysql_config
MDB5_USES+=		compiler:c11 mysql:105m
MDB5_DESC=		Mariadb 10.5 database support

MDB6_CONFIGURE_ON=	--with-mysql=${LOCALBASE}/bin/mysql_config
MDB6_USES+=		compiler:c11 mysql:106m
MDB6_DESC=		Mariadb 10.6 database support

ORACLE_CONFIGURE_WITH=	oracle

PGSQL_CONFIGURE_WITH=	postgresql
PGSQL_USES+=		pgsql

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	net-snmp

SQLITE_CONFIGURE_WITH=	sqlite3
SQLITE_USES+=		sqlite:3

SSH_CONFIGURE_WITH=	ssh2
SSH_LIB_DEPENDS=	libssh2.so:security/libssh2

UNIXODBC_CONFIGURE_WITH=	unixodbc
UNIXODBC_LIB_DEPENDS=		libodbc.so:databases/unixODBC
.elif ${ZABBIX_BUILD} == "agent"
OPTOINS_DEFINE+=		PCRE
OPTIONS_SINGLE+=		SSL
OPTIONS_SINGLE_SSL=		GNUTLS OPENSSL
.endif # if ${ZABBIX_BUILD} != "agent"

CURL_DESC=		Support for web monitoring
CURL_CONFIGURE_WITH=	libcurl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

IPV6_CONFIGURE_ENABLE=	ipv6

MODBUS_DESC=		Support for Modbus checks
MODBUS_CONFIGURE_WITH=	libmodbus
MODBUS_LIB_DEPENDS=	libmodbus.so:comms/libmodbus

NMAP_RUN_DEPENDS=	nmap:security/nmap \
			sudo:security/sudo

OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_USES=		ssl
OPENSSL_VARS=		BROKEN_SSL="libressl libressl-devel" \
			BROKEN_SSL_REASON="PSK is not provided by LibreSSL"

GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

.endif # if ${ZABBIX_BUILD} != "java"

.if ${ZABBIX_BUILD} == "java"
USES+=         java
JAVA_VERSION=	11+
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -rl "/etc/zabbix" ${WRKSRC} \
	  | ${XARGS} ${REINPLACE_CMD} -e 's#/usr/local/etc#${ETCDIR}#g'

	@${REINPLACE_CMD} -e 's#/usr/sbin/fping#${LOCALBASE}/sbin/fping#g' \
		${WRKSRC}/conf/zabbix_*.conf \
		${WRKSRC}/src/zabbix_proxy/proxy.c \
		${WRKSRC}/src/zabbix_server/server.c

.if ${ZABBIX_BUILD} == "server"
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_server.pid#/var/run/zabbix/zabbix_server.pid#g' \
		${WRKSRC}/conf/zabbix_server.conf \
		${WRKSRC}/src/zabbix_server/server.c
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_server.log#/var/log/zabbix/zabbix_server.log#g' \
		${WRKSRC}/conf/zabbix_server.conf
.endif

.if ${ZABBIX_BUILD} == "proxy"
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_proxy.pid#/var/run/zabbix/zabbix_proxy.pid#g' \
		${WRKSRC}/conf/zabbix_proxy.conf \
		${WRKSRC}/src/zabbix_proxy/proxy.c
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_proxy.log#/var/log/zabbix/zabbix_proxy.log#g' \
		${WRKSRC}/conf/zabbix_proxy.conf
.endif

.if ${ZABBIX_BUILD} == "agent"
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_agentd.pid#/var/run/zabbix/zabbix_agentd.pid#g' \
		${WRKSRC}/conf/zabbix_agentd.conf \
		${WRKSRC}/src/zabbix_agent/zabbix_agentd.c
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_agentd.log#/var/log/zabbix/zabbix_agentd.log#g' \
		${WRKSRC}/conf/zabbix_agentd.conf
.endif

.if ${ZABBIX_BUILD} == "java"
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_java.pid#/var/run/zabbix/zabbix_java.pid#g' \
		${WRKSRC}/src/zabbix_java/settings.sh
.endif

.if ${ZABBIX_BUILD} != "agent"
.  for d in mysql oracle postgresql
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/traceroute|/usr/sbin/traceroute|g' \
		-e 's|sudo /usr/bin/nmap|sudo ${LOCALBASE}/bin/nmap|g' \
		${WRKSRC}/database/${d}/data.sql
.  endfor
.endif
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -or -name '*.orig' \) \
		-exec ${RM} {} +

pre-configure:
	@echo "ac_cv_env_PKG_CONFIG_set=${LOCALBASE}/bin/pkgconf" > ${WRKSRC}/config.cache

post-install:
.if ${ZABBIX_BUILD} == "java"
	${MV} ${STAGEDIR}${PREFIX}/sbin/zabbix_java/settings.sh \
		${STAGEDIR}${PREFIX}/sbin/zabbix_java/settings.sh.sample
	@${MKDIR} ${STAGEDIR}/var/run/zabbix
.endif

.if ${ZABBIX_BUILD} != "agent" && ${ZABBIX_BUILD} != "java"
	${MKDIR} ${STAGEDIR}${DATADIR}/${ZABBIX_BUILD:Q}/database
	${FIND} ${WRKSRC}/database -name 'Makefile*' -delete
	(cd ${WRKSRC}/database/ && \
		${COPYTREE_SHARE} "mysql oracle postgresql sqlite3" \
		${STAGEDIR}${DATADIR}/${ZABBIX_BUILD:Q}/database/)

	${MV} ${STAGEDIR}${ETCDIR}/zabbix_${ZABBIX_BUILD}.conf \
		${STAGEDIR}${ETCDIR}/zabbix_${ZABBIX_BUILD}.conf.sample
.endif

.if ${ZABBIX_BUILD} == "agent"
	${MV} ${STAGEDIR}${ETCDIR}/zabbix_${ZABBIX_BUILD}d.conf \
		${STAGEDIR}${ETCDIR}/zabbix_${ZABBIX_BUILD}d.conf.sample
.endif

.if ${ZABBIX_BUILD} == "proxy"
	${MV} ${STAGEDIR}${LOCALBASE}/bin/zabbix_js \
		${STAGEDIR}${LOCALBASE}/bin/zabbix_proxy_js
.endif

.else # frontend
.include <bsd.port.pre.mk>
.endif

.include <bsd.port.post.mk>
