# Ports collection makefile for:	zabbix-agent
# Date created:		Jun 18 2003
# Whom:			Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PORTVERSION=	1.6.6
PORTEPOCH=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/ZABBIX%20Latest%20Stable/${PORTVERSION}
PKGNAMESUFFIX=	-agent

MAINTAINER=	ports@christianserving.org
COMMENT=	Application and network monitoring solution

USE_GMAKE=	yes
USE_RC_SUBR=	zabbix_agentd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-agent --disable-server
MAKE_ARGS=	ARCH=freebsd
.ifndef WITHOUT_IPV6
CONFIGURE_ARGS+=--enable-ipv6
.endif

ZABBIX_BIN=	agent agentd get sender
ZABBIX_CFG=	agent agentd
ZABBIX_BINFILES=${ZABBIX_BIN:S|^|zabbix_|:C|.+|&/&|:S|agentd/|agent/|}
ZABBIX_CFGFILES=${ZABBIX_CFG:S|^|zabbix_|:S|$|.conf|}
PLIST_FILES=	${ZABBIX_BIN:S|^|bin/zabbix_|} \
		${ZABBIX_CFG:S|^|%%ETCDIR%%/zabbix_|:S|$|.conf.sample|}

post-patch:
	@${FIND} ${WRKSRC}/src/ -type f|${XARGS} \
		${REINPLACE_CMD} -e 's|/etc/zabbix|${ETCDIR}|;s|/usr/sbin|${LOCALBASE}/sbin|'

do-install:
	@${ECHO_CMD} '@unexec ${RMDIR} %D/${ETCDIR_REL} 2>/dev/null || true' >> ${TMPPLIST}
	@${INSTALL_PROGRAM} ${ZABBIX_BINFILES:S,^,${WRKSRC}/src/,} ${PREFIX}/bin/
	@${INSTALL} -d ${ETCDIR}/
	@for i in ${ZABBIX_CFGFILES};do\
		${INSTALL_DATA} ${WRKSRC}/misc/conf/$$i ${ETCDIR}/$$i.sample;done
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
