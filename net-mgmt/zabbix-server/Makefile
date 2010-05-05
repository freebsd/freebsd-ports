# New ports collection makefile for:	zabbix-server
# Date created:		2009-12-09
# Whom:			Jim Riggs <ports@christianserving.org>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PORTVERSION=	1.8.2
PORTREVISION?=	1
PORTEPOCH=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/zabbix/ZABBIX%20Latest%20Stable/${PORTVERSION}
PKGNAMESUFFIX?=	-server

MAINTAINER=	ports@christianserving.org
COMMENT=	Enterprise-class open source distributed monitoring (${PKGNAMESUFFIX:S/^-//})

CONFLICTS=	${PKGBASE}-1.[0-6]*

.if ${PKGNAMESUFFIX} != "-agent"
CONFLICTS+=	${PORTNAME}-1.[0-6]*
.endif

ZABBIX_BUILD=	${PKGNAMESUFFIX:S/^-//}

.if ${ZABBIX_BUILD} != "frontend" # frontend only needs the version/distribution settings
.if ${ZABBIX_BUILD} != "agent"
MAN8=		${PORTNAME}_${ZABBIX_BUILD}.8
USE_RC_SUBR=	${PORTNAME}_${ZABBIX_BUILD}
.else
USE_ICONV=	yes
MAN1=		${PORTNAME}_get.1 ${PORTNAME}_sender.1
MAN8=		${PORTNAME}_${ZABBIX_BUILD}d.8
USE_RC_SUBR=	${PORTNAME}_${ZABBIX_BUILD}d
.endif

USERS=		zabbix
GROUPS=		zabbix

PLIST_SUB=	ZABBIX_BUILD=${ZABBIX_BUILD}
SUB_LIST=	ZABBIX_BUILD=${ZABBIX_BUILD} ZABBIX_REQUIRE=${ZABBIX_REQUIRE}

MAKE_ARGS+=	ARCH=freebsd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-${ZABBIX_BUILD}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.if ${ZABBIX_BUILD} != "agent"
LIB_DEPENDS=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp \
		curl:${PORTSDIR}/ftp/curl

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=	--with-net-snmp

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options
OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		SQLITE "Use SQLite backend" off \
		IPV6 "Support for IPv6" on \
		LDAP "Support for checking LDAP servers" on \
		JABBER "Use jabber media type" on \
		FPING "Use fping for pinging hosts" on \
		SSH "Use libssh2 for SSH-based checks" off

.include <bsd.port.options.mk>

.ifndef WITHOUT_MYSQL
ZABBIX_REQUIRE=	" mysql"
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.elifdef WITH_PGSQL
ZABBIX_REQUIRE=	" postgresql"
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql
.elifdef WITH_SQLITE
ZABBIX_REQUIRE=
USE_SQLITE=	3
CONFIGURE_ARGS+=	--with-sqlite3
.else
IGNORE=		zabbix requires a database backend
.endif

.ifndef WITHOUT_LDAP
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap
.endif

.ifndef WITHOUT_JABBER
LIB_DEPENDS+=	iksemel:${PORTSDIR}/textproc/iksemel
CONFIGURE_ARGS+=	--with-jabber
.endif

.ifndef WITHOUT_FPING
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
.endif

.ifdef WITH_SSH
LIB_DEPENDS+=	ssh2:${PORTSDIR}/security/libssh2
CONFIGURE_ARGS+=	--with-ssh2
.endif
.endif # if ${ZABBIX_BUILD} != "agent"

.ifdef WITH_IPV6
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	@${GREP} -rl "/etc/zabbix" ${WRKSRC} \
	  | ${XARGS} ${REINPLACE_CMD} -e 's#/etc/zabbix#${ETCDIR}#g' \
	  && ${FIND} ${WRKSRC} -type f -name '*.bak' -exec ${RM} -f {} +
	@${REINPLACE_CMD} -e 's#/usr/sbin/fping#${LOCALBASE}/sbin/fping#g' ${WRKSRC}/misc/conf/${PORTNAME}_*.conf

.if ${ZABBIX_BUILD} != "agent"
.ifdef WITHOUT_FPING
	@${ECHO} 'DisablePinger=yes' >> ${WRKSRC}/misc/conf/${PORTNAME}_${ZABBIX_BUILD}.conf
.endif
.endif

post-install:
	@${INSTALL} -d ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/misc/conf/${PORTNAME}_${ZABBIX_BUILD}.conf ${ETCDIR}/${PORTNAME}_${ZABBIX_BUILD}.conf.sample

.if ${ZABBIX_BUILD} == "agent"
	@${INSTALL_DATA} ${WRKSRC}/misc/conf/${PORTNAME}_${ZABBIX_BUILD}d.conf ${ETCDIR}/${PORTNAME}_${ZABBIX_BUILD}d.conf.sample
.endif

.if ${ZABBIX_BUILD} != "agent"
	@cd ${WRKSRC}/upgrades/ && ${COPYTREE_SHARE} dbpatches ${DATADIR}/${ZABBIX_BUILD}/upgrades/
	@cd ${WRKSRC}/create/ && ${COPYTREE_SHARE} "data schema" ${DATADIR}/${ZABBIX_BUILD}/create/
	@${CAT} ${PKGMESSAGE}
.endif
.endif # if ${ZABBIX_BUILD} != "frontend"

.include <bsd.port.mk>
