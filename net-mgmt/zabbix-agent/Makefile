# Ports collection makefile for:	zabbix-agent
# Date created:		Jun 18 2003
# Whom:			Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PORTVERSION=	1.4.2
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
PKGNAMESUFFIX=	-agent

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application and network monitoring solution

USE_GMAKE=	yes
USE_RC_SUBR=	zabbix_agentd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-agent --disable-server
MAKE_ARGS=	ARCH=freebsd

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
	@${ECHO_CMD} '@unexec rmdir %D/${ETCDIR_REL} 2>/dev/null || true' >> ${TMPPLIST}
	@${INSTALL_PROGRAM} ${ZABBIX_BINFILES:S,^,${WRKSRC}/src/,} ${PREFIX}/bin/
	@${INSTALL} -d ${ETCDIR}/
	@for i in ${ZABBIX_CFGFILES};do\
		${INSTALL_DATA} ${WRKSRC}/misc/conf/$$i ${ETCDIR}/$$i.sample;done
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
