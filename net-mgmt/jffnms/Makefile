# Ports collection makefile for:  jffnms
# Date created:			  Aug 21 2003
# Whom:				  Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	jffnms
PORTVERSION=	0.8.3
PORTREVISION=	4
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

JFFNMSDIR?=	share/jffnms
CRONTAB?=	/usr/bin/crontab

PLIST_SUB=	JFFNMSDIR=${JFFNMSDIR}

do-build:

do-install:
	@-${RM} ${WRKSRC}/engine/tmpwatch.sh.orig > /dev/null 2>&1
	@${MKDIR} ${PREFIX}/${JFFNMSDIR}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/${JFFNMSDIR}
	@${CHOWN} -R www:www ${PREFIX}/${JFFNMSDIR}
	@${SED} -e 's|%LOCALBASE%|${PREFIX}|g' \
		-e 's|%JFFNMSDIR%|${PREFIX}/${JFFNMSDIR}|g' ${FILESDIR}/jffnms.cron \
		> ${PREFIX}/${JFFNMSDIR}/jffnms.cron
	@${SED} -e 's|%JFFNMSDIR%|${PREFIX}/${JFFNMSDIR}|g' \
		-e 's|%JFFNMS%|${DISTNAME}|g' ${FILESDIR}/jffnms_db.sh \
		> ${PREFIX}/${JFFNMSDIR}/jffnms_db.sh
	@${CRONTAB} -u www ${PREFIX}/${JFFNMSDIR}/jffnms.cron
	@${SED} -e 's|%JFFNMSDIR%|${PREFIX}/${JFFNMSDIR}|g' ${PKGMESSAGE}

#
#	!!! Maintainer only !!!
#
packinglist: pkg-plist.new
pkg-plist.new:
	@${ECHO_MSG} '---> Making ${@}'
	@${FIND} '${PREFIX}/${JFFNMSDIR}' -type f | \
		${SED} -e 's|^${PREFIX}/${JFFNMSDIR}|%%JFFNMSDIR%%|' | \
		${SORT} -t / > ${@}
	@${FIND} '${PREFIX}/${JFFNMSDIR}' -type d | \
		${SORT} -rt / | \
		${SED} -e 's|^${PREFIX}/${JFFNMSDIR}|@dirrm %%JFFNMSDIR%%|' >> ${@}
	@${ECHO} "@exec crontab -u www %%JFFNMSDIR%%/jffnms.cron" >> ${@}
	@${ECHO} "@unexec crontab -u www -l | sed 's|.*JFFNMS.*||' | crontab -u www -" >> ${@}

.include <bsd.port.mk>
