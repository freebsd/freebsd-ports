# Ports collection makefile for:	zabbix
# Date created:		Jun 18 2003
# Whom:			Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PORTVERSION=	1.1.7
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application and network monitoring solution

.ifdef(ZABBIX_AGENT_ONLY)
PKGNAMESUFFIX=	-agent
CATEGORIES=	net
CONFLICTS=	zabbix-[0-9]*
.else
CONFLICTS=	zabbix-agent-[0-9]*
OPTIONS=	PGSQL "Use a PostgreSQL backend" off \
		MYSQL "Use a MySQL backend" on \
		FPING "Use fping for pinging hosts" on
.endif

USE_GMAKE=	yes
CONFIGURE_ARGS+=--enable-agent
.ifdef(ZABBIX_AGENT_ONLY)
PKGNAMESUFFIX=	-agent
PLIST=		""
.else # ZABBIX_AGENT_ONLY
CONFIGURE_ARGS+=--enable-server
# TODO add snmp knob
LIB_DEPENDS=	netsnmp.10:${PORTSDIR}/net-mgmt/net-snmp
USE_PHP=	gd snmp sockets pcre
SUB_FILES=	pkg-message
.endif # ZABBIX_AGENT_ONLY

.include <bsd.port.pre.mk>

.ifndef(WITHOUT_FPING)
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
.endif

.ifndef(ZABBIX_AGENT_ONLY)
.ifndef(WITH_PGSQL)
.ifdef(WITHOUT_MYSQL)
IGNORE=		you should configure to use either a MySQL or PostgreSQL backend
.endif
.endif

.ifdef(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pgsql.so:${PORTSDIR}/${pgsql_DEPENDS}
.endif
.ifndef(WITHOUT_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/mysql.so:${PORTSDIR}/${mysql_DEPENDS}
.endif
CONFIGURE_ARGS+=--with-net-snmp
.endif # ZABBIX_AGENT_ONLY

USE_RC_SUBR=	zabbix_agentd.sh
.ifndef(ZABBIX_AGENT_ONLY)
USE_RC_SUBR+=	zabbix_server.sh
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include

ZABBIX_BIN=		agent agentd get sender
ZABBIX_CFG=		agent agentd
.ifndef(ZABBIX_AGENT_ONLY)
ZABBIX_BIN+=	server
ZABBIX_CFG+=	server
.endif
ZABBIX_BINFILES=	${ZABBIX_BIN:S|^|zabbix_|:C|.+|&/&|:S|agentd/|agent/|}
ZABBIX_CFGFILES=	${ZABBIX_CFG:S|^|zabbix_|:S|$|.conf|}
PLIST_FILES=	${ZABBIX_BIN:S|^|bin/zabbix_|} \
		${ZABBIX_CFG:S|^|etc/zabbix/zabbix_|:S|$|.conf.sample|}

post-patch:
	@${FIND} ${WRKSRC}/src -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -Ee 's|(/etc/zabbix)|${PREFIX}\1|;s|/usr/sbin|${LOCALBASE}/sbin|'
.ifdef WITHOUT_FPING
	@${ECHO} 'DisablePinger=yes' >> ${WRKSRC}/misc/conf/zabbix_server.conf
.endif

.if ${ARCH} == "amd64"
post-configure:
	${ECHO_CMD} "#define HAVE_VA_COPY 1" >> ${WRKSRC}/include/config.h
.endif

do-install:
	@${ECHO_CMD} '@unexec rmdir %D/etc/zabbix 2>/dev/null || true' >> ${TMPPLIST}
	${INSTALL_PROGRAM} ${ZABBIX_BINFILES:S,^,${WRKSRC}/src/,} ${PREFIX}/bin/
	${INSTALL} -d ${PREFIX}/etc/zabbix/
.for FILE in ${ZABBIX_CFGFILES}
	${INSTALL_DATA} ${WRKSRC}/misc/conf/${FILE} ${PREFIX}/etc/zabbix/${FILE}.sample
.endfor
.ifndef(ZABBIX_AGENT_ONLY)
	${INSTALL} -d ${DATADIR}/create/
	${CP} -Rf ${WRKSRC}/frontends/ ${WRKSRC}/upgrades/dbpatches ${DATADIR}/
	${CP} -Rf ${WRKSRC}/create/ ${DATADIR}/create/
	${INSTALL_SCRIPT} ${MASTERDIR}/scripts/dbsetup.sh ${DATADIR}/create/
.endif
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.ifndef(ZABBIX_AGENT_ONLY)
	@${CAT} ${PKGMESSAGE}
.endif

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,.*/rc.d/.+,,g \
		;s,@dirrm share/man(/.*)?$$,,g \
		;s,share/zabbix,%%DATADIR%%,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.post.mk>
