# Ports collection makefile for:  zabbix
# Date created:			  Jun 18 2003
# Whom:				  Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PORTVERSION=	1.0b10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S|b|beta|}

MAINTAINER=	asa@gascom.ru
COMMENT=	Very advanced network monitoring system

.ifdef(ZABBIX_AGENT_ONLY)
PKGNAMESUFFIX=	-agent
PLIST=		${MASTERDIR}/pkg-plist.agent
PKGMESSAGE=	nonexistent
.else
CONFIGURE_ARGS=	--with-mysql --with-net-snmp

LIB_DEPENDS=	netsnmp.5:${PORTSDIR}/net/net-snmp \
		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
BUILD_DEPENDS=	mysql:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	safe_mysqld:${PORTSDIR}/databases/mysql323-server
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include

ZABBIX_BINARIES=zabbix_agent zabbix_agentd zabbix_sender
ZABBIX_CONFIGS=	zabbix_agent.conf zabbix_agentd.conf
.ifndef(ZABBIX_AGENT_ONLY)
ZABBIX_BINARIES+=zabbix_suckerd zabbix_trapper zabbix_trapperd
ZABBIX_CONFIGS+=zabbix_suckerd.conf zabbix_trapper.conf zabbix_trapperd.conf
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
	${INSTALL_DATA} ${MASTERDIR}/scripts/dbsetup.sh \
			${PREFIX}/share/zabbix/create
	${CP} -Rf ${WRKSRC}/frontends/* ${PREFIX}/share/zabbix
	${CP} -Rf ${WRKSRC}/create/* ${PREFIX}/share/zabbix/create
	${CP} -Rf ${WRKSRC}/upgrades/dbpatches ${PREFIX}/share/zabbix
	${INSTALL_SCRIPT} ${MASTERDIR}/scripts/dbsetup.sh \
			${PREFIX}/share/zabbix/create
	${INSTALL_SCRIPT} ${MASTERDIR}/scripts/zabbix.sh.sample \
			${PREFIX}/etc/rc.d
.endif
	${INSTALL_SCRIPT} ${MASTERDIR}/scripts/zabbix-agent.sh.sample \
			${PREFIX}/etc/rc.d
	${SH} ${PKGINSTALL}

.include <bsd.port.mk>
