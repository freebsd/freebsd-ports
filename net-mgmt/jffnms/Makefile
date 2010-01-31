# Ports collection makefile for:  jffnms
# Date created:			  Aug 21 2003
# Whom:				  Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	jffnms
PORTVERSION=	0.8.3
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very advanced network monitoring and control system

RUN_DEPENDS=	neato:${PORTSDIR}/graphics/graphviz \
		rrdtool:${PORTSDIR}/databases/rrdtool10 \
		nmap:${PORTSDIR}/security/nmap \
		${LOCALBASE}/sbin/tmpwatch:${PORTSDIR}/sysutils/tmpwatch

USE_PHP=	gd snmp sockets
USE_MYSQL=	yes

CRONTAB?=	/usr/bin/crontab

SUB_FILES=	jffnms.cron jffnms_db.sh pkg-message
SUB_LIST=	DISTNAME=${DISTNAME}

do-build:

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -R ${WRKSRC}/* ${WWWDIR}
	@${CHOWN} -R www:www ${WWWDIR}
	@${INSTALL_DATA} ${WRKDIR}/jffnms.cron ${WWWDIR}/jffnms.cron
	@${INSTALL_SCRIPT} ${WRKDIR}/jffnms_db.sh ${WWWDIR}/jffnms_db.sh
	@${CRONTAB} -u www ${WWWDIR}/jffnms.cron

post-install:
	@${CAT} ${PKGMESSAGE}
#
#	!!! Maintainer only !!!
#
packinglist: pkg-plist.new
pkg-plist.new:
	@${ECHO_MSG} '---> Making ${@}'
	@${FIND} '${WWWDIR}' -type f | \
	${SED} -e 's|^${WWWDIR}|%%WWWDIR%%|' | \
		${SORT} -t / > ${@}
	@${FIND} '${WWWDIR}' -type d | \
		${SORT} -rt / | \
		${SED} -e 's|^${WWWDIR}|@dirrm %%WWWDIR%%|' >> ${@}
	@${ECHO} "@exec crontab -u www %%WWWDIR%%/jffnms.cron" >> ${@}
	@${ECHO} "@unexec crontab -u www -l | sed 's|.*JFFNMS.*||' | crontab -u www -" >> ${@}

.include <bsd.port.mk>
