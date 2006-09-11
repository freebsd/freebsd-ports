# Ports collection makefile for:  zabbix
# Date created:			  Jun 18 2003
# Whom:				  Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PORTVERSION=	1.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES?=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	asa@gascom.ru
COMMENT=	Very advanced network monitoring system

.ifndef(ZABBIX_AGENT_ONLY)
OPTIONS=	PGSQL "Use a PostgreSQL backend" off \
		MYSQL "Use a MySQL backend" on \
		FPING "Use fping for pinging hosts" on
.endif

USE_GMAKE=	yes
CONFIGURE_ARGS+=--enable-agent
.ifdef(ZABBIX_AGENT_ONLY)
PKGNAMESUFFIX=	-agent
PLIST=		${MASTERDIR}/pkg-plist.agent
.else # ZABBIX_AGENT_ONLY
CONFIGURE_ARGS+=--enable-server
# TODO add snmp knob
LIB_DEPENDS=	netsnmp.9:${PORTSDIR}/net-mgmt/net-snmp
USE_PHP=	gd snmp sockets
SUB_FILES=	pkg-message
.endif # ZABBIX_AGENT_ONLY

.include <bsd.port.pre.mk>

.ifndef(WITHOUT_FPING)
RUN_DEPENDS+=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping
.endif

.ifndef(ZABBIX_AGENT_ONLY)
.ifndef(WITH_PGSQL)
.ifdef(WITHOUT_MYSQL)
IGNORE=		You should configure to use either a MySQL or PostgreSQL backend
.endif
.endif

.ifdef(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql
.endif
.ifndef(WITHOUT_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
.endif
CONFIGURE_ARGS+=--with-net-snmp
.endif # ZABBIX_AGENT_ONLY

USE_RC_SUBR=	zabbix_agentd.sh
.if !defined(ZABBIX_AGENT_ONLY)
USE_RC_SUBR+=	zabbix_server.sh
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include

ZABBIX_BINARIES=	zabbix_agent/zabbix_agent \
			zabbix_agent/zabbix_agentd \
			zabbix_get/zabbix_get \
			zabbix_sender/zabbix_sender
ZABBIX_CONFIGS=		zabbix_agent.conf zabbix_agentd.conf
.ifndef(ZABBIX_AGENT_ONLY)
ZABBIX_BINARIES+=	zabbix_server/zabbix_server
ZABBIX_CONFIGS+=	zabbix_server.conf
.endif

post-patch:
	@${REINPLACE_CMD} 's|%PREFIX%|${PREFIX}|' ${WRKSRC}/src/zabbix_agent/zabbix_agent.c
	@${REINPLACE_CMD} 's|%PREFIX%|${PREFIX}|' ${WRKSRC}/src/zabbix_agent/zabbix_agentd.c
.ifndef(ZABBIX_AGENT_ONLY)
	@${REINPLACE_CMD} 's|%LOCALBASE%|${LOCALBASE}|;s|%PREFIX%|${PREFIX}|' ${WRKSRC}/src/zabbix_server/server.c
.ifdef WITHOUT_FPING
	@${ECHO} 'DisablePinger=yes' >> ${WRKSRC}/misc/conf/zabbix_server.conf
.endif
.endif # ZABBIX_AGENT_ONLY

.if ${ARCH} == "amd64"
post-configure:
	${ECHO_CMD} "#define HAVE_VA_COPY 1" >> ${WRKSRC}/include/config.h
.endif

do-install:
.for FILE in ${ZABBIX_BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${FILE} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/etc/zabbix
.for FILE in ${ZABBIX_CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/misc/conf/${FILE} \
			${PREFIX}/etc/zabbix/${FILE}.sample
.endfor
.ifndef(ZABBIX_AGENT_ONLY)
	${MKDIR} ${PREFIX}/share/zabbix
	${MKDIR} ${PREFIX}/share/zabbix/create
	${CP} -Rf ${WRKSRC}/frontends/* ${PREFIX}/share/zabbix
	${CP} -Rf ${WRKSRC}/create/* ${PREFIX}/share/zabbix/create
	${CP} -Rf ${WRKSRC}/upgrades/dbpatches ${PREFIX}/share/zabbix
	${INSTALL_SCRIPT} ${MASTERDIR}/scripts/dbsetup.sh \
			${PREFIX}/share/zabbix/create
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
