# Ports collection makefile for:  zabbix
# Date created:			  Jun 18 2003
# Whom:				  Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PORTVERSION=	1.0b13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S|b|beta|}

MAINTAINER=	asa@gascom.ru
COMMENT=	Very advanced network monitoring system

NOT_FOR_ARCHS=	amd64

.ifdef(ZABBIX_AGENT_ONLY)
PKGNAMESUFFIX=	-agent
PLIST=		${MASTERDIR}/pkg-plist.agent
PKGMESSAGE=	nonexistent
.else # ZABBIX_AGENT_ONLY
LIB_DEPENDS=	netsnmp.6:${PORTSDIR}/net/net-snmp
RUN_DEPENDS=	php:${PORTSDIR}/lang/php4-nms

.ifndef(WITHOUT_FPING)
RUN_DEPENDS+=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping
.endif

USE_MYSQL=	yes
CONFIGURE_ARGS=	--with-mysql --with-net-snmp
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif # ZABBIX_AGENT_ONLY

USE_REINPLACE=	yes
USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include

ZABBIX_BINARIES=	zabbix_agent zabbix_agentd zabbix_sender
ZABBIX_CONFIGS=		zabbix_agent.conf zabbix_agentd.conf
.ifndef(ZABBIX_AGENT_ONLY)
ZABBIX_BINARIES+=	zabbix_suckerd zabbix_trapper zabbix_trapperd
ZABBIX_CONFIGS+=	zabbix_suckerd.conf zabbix_trapper.conf zabbix_trapperd.conf
.endif

SCRIPT_REGEX=	-e 's|%PREFIX%|${PREFIX}|g' -e 's|%LOCALBASE%|${LOCALBASE}|g'

pre-patch:
.if !defined(ZABBIX_AGENT_ONLY)
	@${SED} ${SCRIPT_REGEX} ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${SED} ${SCRIPT_REGEX} ${PKGDIR}/scripts/zabbix.sh.sample > \
		${WRKDIR}/zabbix.sh.sample
.endif
	@${SED} ${SCRIPT_REGEX} ${PKGDIR}/scripts/zabbix-agent.sh.sample > \
		${WRKDIR}/zabbix-agent.sh.sample

.ifndef(ZABBIX_AGENT_ONLY)
post-patch:
	@${REINPLACE_CMD} 's|%LOCALBASE%|${LOCALBASE}|' ${WRKSRC}/src/zabbix_sucker/zabbix_sucker.c
.ifdef WITHOUT_FPING
	@${ECHO} 'DisablePinger=yes' >> ${WRKSRC}/misc/conf/zabbix_suckerd.conf
.endif
.endif # ZABBIX_AGENT_ONLY

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
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.ifndef(ZABBIX_AGENT_ONLY)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
