# Ports collection makefile for:  zabbix
# Date created:			  Jun 18 2003
# Whom:				  Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PORTVERSION=	1.0
PORTREVISION=	4
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

.ifdef(ZABBIX_AGENT_ONLY)
PKGNAMESUFFIX=	-agent
PLIST=		${MASTERDIR}/pkg-plist.agent
.else # ZABBIX_AGENT_ONLY
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
CONFIGURE_ARGS=	--with-mysql
.endif
CONFIGURE_ARGS+=--with-net-snmp
.endif # ZABBIX_AGENT_ONLY

USE_RC_SUBR=	zabbix_agent.sh
.if !defined(ZABBIX_AGENT_ONLY)
USE_RC_SUBR+=	zabbix_suckerd.sh
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include

ZABBIX_BINARIES=	zabbix_agent zabbix_agentd zabbix_sender
ZABBIX_CONFIGS=		zabbix_agent.conf zabbix_agentd.conf
.ifndef(ZABBIX_AGENT_ONLY)
ZABBIX_BINARIES+=	zabbix_suckerd zabbix_trapper zabbix_trapperd
ZABBIX_CONFIGS+=	zabbix_suckerd.conf zabbix_trapper.conf zabbix_trapperd.conf
.endif

pre-patch:
.ifndef(ZABBIX_AGENT_ONLY)
post-patch:
	@${REINPLACE_CMD} 's|%LOCALBASE%|${LOCALBASE}|' ${WRKSRC}/src/zabbix_sucker/zabbix_sucker.c
.ifdef WITHOUT_FPING
	@${ECHO} 'DisablePinger=yes' >> ${WRKSRC}/misc/conf/zabbix_suckerd.conf
.endif
.endif # ZABBIX_AGENT_ONLY

.if ${ARCH} == "amd64"
post-configure:
	${ECHO_CMD} "#define HAVE_VA_COPY 1" >> ${WRKSRC}/include/config.h
.endif

do-install:
.for FILE in ${ZABBIX_BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${FILE} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/etc/zabbix
	${LN} -sf ${PREFIX}/etc/zabbix /etc/zabbix
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

.include <bsd.port.post.mk>
